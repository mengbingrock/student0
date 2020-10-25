/*
 * Word count application with one thread per input file.
 *
 * You may modify this file in any way you like, and are expected to modify it.
 * Your solution must read each input file from a separate thread. We encourage
 * you to make as few changes as necessary.
 */

/*
 * Copyright © 2019 University of California, Berkeley
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <pthread.h>

#include "word_count.h"
#include "word_helpers.h"

static  struct arg {
    word_count_list_t* arg1;
    FILE * arg2;
  } arg_struct; 


void* count_words_thread(void* args){
    struct arg *arguments  = (struct arg*)args;
    word_count_list_t* wclist = arguments->arg1;
    FILE* filein = arguments->arg2;
    count_words(wclist, filein);
    return NULL;
}

/*
 * main - handle command line, spawning one thread per file.
 */
int main(int argc, char *argv[]) {
  /* Create the empty data structure. */
  word_count_list_t word_counts;
  init_words(&word_counts);
  int rc;
  int nthreads = argc -1;
  pthread_t threads[10];

  if (argc <= 1) {
    /* Process stdin in a single thread. */
    count_words(&word_counts, stdin);
    //printf("thread created\n"); 
   }else{
    /* TODO */
    printf("begin thread to count words\n");
      arg_struct.arg1 = &word_counts;
    //count_words(&word_counts, fopen(argv[1],"r")); 
    for(int t = 0; t < nthreads; t++) {
      arg_struct.arg2 = fopen(argv[t+1],"r");
      //printf("argv[1] is %s\n",argv[t+1]);
      //printf("main: creating thread %i\n", t);
      rc = pthread_create(&threads[t], NULL, count_words_thread, (void *)&arg_struct);
      if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
      }
      //printf("sleep 3s to let thread finish\n");

      pthread_join(threads[t],NULL);    
      //sleep(1);
    }
  //printf("begbin wordount_sort\n");
  //sleep(3);
  /* Output final result of all threads' work. */
  wordcount_sort(&word_counts, less_count);
  fprint_words(&word_counts, stdout);
  }
  return 0;
}
