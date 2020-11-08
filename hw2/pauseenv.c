#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    const char **array;
    const char *orig_path_var = getenv("PATH");
    char *path_var = strdup(orig_path_var ? orig_path_var : ""); // just in case PATH is NULL, very unlikely
    const char *the_dot = ".";
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
    array=malloc((nb_colons+1) * sizeof(*array));

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
                array[current_colon] = the_dot;
            }

        }
    }
/*
    for (j=0;j<nb_colons+1;j++)
    {
        printf("Path %d: <%s>\n",j,array[j]);
    }
*/
    return(0);
}
