#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#include "tokenizer.h"

/* Convenience macro to silence compiler warnings about unused function parameters. */
#define unused __attribute__((unused))
#define PATH_MAX 100
/* Whether the shell is connected to an actual terminal or not. */
bool shell_is_interactive;

/* File descriptor for the shell input */
int shell_terminal;

/* Terminal mode settings for the shell */
struct termios shell_tmodes;

/* Process group id for the shell */
pid_t shell_pgid;

int cmd_exit(struct tokens *tokens);
int cmd_help(struct tokens *tokens);
int cmd_pwd(struct tokens *tokens);
int cmd_cd(struct tokens *tokens);

/* Built-in command functions take token array (see parse.h) and return int */
typedef int cmd_fun_t(struct tokens *tokens);

/* Built-in command struct and lookup table */
typedef struct fun_desc {
  cmd_fun_t *fun;
  char *cmd;
  char *doc;
} fun_desc_t;

typedef struct env_struct {
  size_t num;
  char** env_array;
  } env_struct_t;


fun_desc_t cmd_table[] = {
  {cmd_help, "?", "show this help menu"},
  {cmd_exit, "exit", "exit the command shell"},
  {cmd_pwd, "pwd", "prints the current working directory to standard output"},
  {cmd_cd, "cd", "takes one argument, a directory path, and changes the current working directory to that directory"},
};

/* Prints a helpful description for the given command */
int cmd_help(unused struct tokens *tokens) {
  for (unsigned int i = 0; i < sizeof(cmd_table) / sizeof(fun_desc_t); i++)
    printf("%s - %s\n", cmd_table[i].cmd, cmd_table[i].doc);
  return 1;
}

/* Exits this shell */
int cmd_exit(unused struct tokens *tokens) {
  exit(0);
}
/* prints the current working directory to standard output */
int cmd_pwd(unused struct tokens *tokens) {
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("%s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
  return 0;
}

/* takes one argument, a directory path, and changes the current working directory to that directory */
int cmd_cd(unused struct tokens *tokens) {
   char line[100];
   fgets(line, 4096, stdin);
   //printf("try to cd to %s\n",line);  
   int len = strlen(line);
   line[len-1]='\0';
   if (chdir(line) != 0)  
    printf("chdir() to %s failed\n",line); 
    printf("ret = %i\n",errno);
   return 0;
}


/* Looks up the built-in command, if it exists. */
int lookup(char cmd[]) {
  for (unsigned int i = 0; i < sizeof(cmd_table) / sizeof(fun_desc_t); i++)
    if (cmd && (strcmp(cmd_table[i].cmd, cmd) == 0))
      return i;
  return -1;
}

/* Intialization procedures for this shell */
void init_shell() {
  /* Our shell is connected to standard input. */
  shell_terminal = STDIN_FILENO;

  /* Check if we are running interactively */
  shell_is_interactive = isatty(shell_terminal);

  if (shell_is_interactive) {
    /* If the shell is not currently in the foreground, we must pause the shell until it becomes a
     * foreground process. We use SIGTTIN to pause the shell. When the shell gets moved to the
     * foreground, we'll receive a SIGCONT. */
    while (tcgetpgrp(shell_terminal) != (shell_pgid = getpgrp()))
      kill(-shell_pgid, SIGTTIN);

    /* Saves the shell's process id */
    shell_pgid = getpid();

    /* Take control of the terminal */
    tcsetpgrp(shell_terminal, shell_pgid);

    /* Save the current termios to a variable, so it can be restored later. */
    tcgetattr(shell_terminal, &shell_tmodes);
  }
}

void get_env_array(env_struct_t* arg)
{
    char **array;
    const char *orig_path_var = getenv("PATH");
    char *path_var = strdup(orig_path_var ? orig_path_var : ""); // just in case PATH is NULL, very unlikely
    //printf("path_var is %s\n",path_var);    char *the_dot = ".";
    int j;
    int len=strlen(path_var);
    int nb_colons=0;
    char pathsep = ':';
    int current_colon = 0;

    // first count how many paths we have, and "split" almost like strtok would do
    for (j=0;j<len;j++)
    {
        if (path_var[j]==pathsep)
        {
            nb_colons++;
            path_var[j] = '\0';
        }       
    }

    // allocate the array of strings
    array=malloc((nb_colons+2) * sizeof(*array));

    array[0] = path_var;  // first path

    // rest of paths
    for (j=0;j<len;j++)
    {
        if (path_var[j]=='\0')
        {
            current_colon++;
            array[current_colon] = path_var+j+1;
            if (array[current_colon][0]=='\0')
            {
                // special case: add dot if path is empty
                //array[current_colon] = the_dot;
 		printf("empty found\n");
            }

        }
    }
    array[current_colon+1]=""; // add to support full path 
    /*
    for (j=0;j<nb_colons+1;j++)
    {
        printf("Path %d: <%s>\n",j,array[j]);
    }
    */
    arg->env_array = array;
    arg->num = nb_colons+2;
    //return array;
}

int fds[2];
int old_stdout;
void run_cmd(struct tokens* tokens, int token_start_idx)
{
      if(token_start_idx>0){
      // need to create pipe
      int rfd = fds[0];
      dup2(rfd,0);  // change the stdin to be rfd
      //char buf[3000];
      //sleep(1);
      //size_t readlen = read(rfd,buf,3000);
      
      //close(rfd);
      dup2(old_stdout,1); // restore the old_stdout
      fprintf(stderr,"%i:restore the old stdout\n",getpid());
      //fprintf(stderr,"%i,readlen is %i\n",getpid(),readlen);
      //fprintf(stderr,"%i,read from the pipe: %s\n",getpid(),buf);
      //fprintf(stderr,"%i,end of the buf print\n",getpid());
      
      }
      const char* s = getenv("PATH");
      //printf("PATH :%s\n",(s!=NULL)? s : "getenv returned NULL");
      char** args = (char**)malloc((tokens_get_length(tokens)+1)*sizeof(char*));
      env_struct_t env_var;
      get_env_array(&env_var);

      // begin pausing args
      for(int i = token_start_idx;i<tokens_get_length(tokens);i++){
	// handle for > or < stdout redirect
       if(!strcmp(tokens_get_token(tokens,i),">") || !strcmp(tokens_get_token(tokens,i),"<")){
        printf(">  or < found\n");
        args[i] = NULL;
        int out_fd;
        if(!strcmp(tokens_get_token(tokens,i),">")){
        if ((out_fd = open(tokens_get_token(tokens,i+1), O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) {
        exit(1);
        }	
	printf("open file is %s\n",tokens_get_token(tokens,i+1));
	dup2(out_fd, 1);
        }
        if(!strcmp(tokens_get_token(tokens,i),"<")){
        int in_fd;
	if ((in_fd = open(tokens_get_token(tokens,i+1), O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0){
           exit(1);
           }
         } 
        break;
       }
       else if(!strcmp(tokens_get_token(tokens,i),"|")){
	 fprintf(stderr,"pipe to make, fork first\n");
	 pipe(fds);
	 //fprintf(stderr,"write some message to pipe\n");
	 //size_t wlen = write(fds[1],"hello\n",6);
	 fprintf(stderr,"old fds[1] is %i\n",fds[1]);
	 old_stdout = dup(1);
	 dup2(fds[1],1);
	 fprintf(stderr,"old fds[1] after dup2 is %i\n",fds[1]);
	 //close(fds[1]);
	 token_start_idx = i;
         break;
       }
       // normal mode, not < > or |
       else
        {
       args[i-token_start_idx] = tokens_get_token(tokens,i);
       args[i-token_start_idx+1] = NULL;
       fprintf(stderr,"args[i] is %s, pid is %i\n",args[i-token_start_idx],getpid());
        }
       } 
      fprintf(stderr,"finished pausing args\n");
        int status;
        pid_t pid_num; 
      if(!strcmp(tokens_get_token(tokens,token_start_idx),"|")){
	fprintf(stderr,"pipe found, fork\n");
        //int status;
        pid_num = fork();
        if(pid_num>0){
          fprintf(stderr,"parent pid %i waiting\n",getpid());
          //wait(&status);
          //printf("child finished\n");
          }
         else if(pid_num == 0){
         fprintf(stderr,"child pid = %i running\n",getpid());
         run_cmd(tokens,token_start_idx+1);
         exit(0);
         }
        }
      // finished pausing args
      // begin execute progs
      //fprintf(stderr,"pid %i exec\n",getpid());
      //finished pausing args
      for(int i =0;i< env_var.num;i++){ // try the PATH to find the executables
      char filename[100];
      strcpy(filename,env_var.env_array[i]);
      strcat(filename,"/");
      strcat(filename,args[0]);
      //printf("args[0] is %s\n",filename);
      //finished searching for path
    
      if(execv(filename,args)==0){
        printf("This may never print\n");	
        break;
        }
      }
     /*
      char* args2[] = {"ls","-l",NULL};
      execv("/bin/ls",args2); 
      */
      perror("execv");      
      exit(1);
      }


int main(unused int argc, unused char *argv[]) {
  init_shell();

  static char line[4096];
  int line_num = 0;
  int to_fork = 0;
  env_struct_t env_var;
  get_env_array(&env_var);
  //printf("env_var[0] is %s\n",env_var.env_array[0]);
  //printf("array length is %i\n",env_var.num);

  /* Please only print shell prompts when standard input is not a tty */
  if (shell_is_interactive)
    fprintf(stdout, "%d: ", line_num);

  while (fgets(line, 4096, stdin)) {
    /* Split our line into words. */
    struct tokens *tokens = tokenize(line);
    struct tokens *t = tokens;
    /* Find which built-in function to run. */
    int fundex = lookup(tokens_get_token(tokens, 0));

    if (fundex >= 0) {
      cmd_table[fundex].fun(tokens);
    } else {
      int status,tcpid;
      /* REPLACE this to run commands as programs. */
      pid_t cpid=fork();
      if(cpid>0){
      fprintf(stderr,"t->tokens_length is %i\n",tokens_get_length(t));
      tcpid = wait(&status); // parents(shell process) wait
      }      
      else if(cpid == 0){
	      run_cmd(tokens, 0 ); // token start idx for first execution 
      }

 
      //fprintf(stdout, "This shell doesn't know how to run programs.\n");
    }

    if (shell_is_interactive)
      /* Please only print shell prompts when standard input is not a tty */
      fprintf(stdout, "%d: ", ++line_num);

    /* Clean up memory */
    tokens_destroy(tokens);
  }

  return 0;
}
