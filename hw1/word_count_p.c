/*
 * Implementation of the word_count interface using Pintos lists and pthreads.
 *
 * You may modify this file, and are expected to modify it.
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

#ifndef PINTOS_LIST
#error "PINTOS_LIST must be #define'd when compiling word_count_lp.c"
#endif

#ifndef PTHREADS
#error "PTHREADS must be #define'd when compiling word_count_lp.c"
#endif

#include "word_count.h"

void init_words(word_count_list_t *wclist) {
  /* TODO */
  printf("wclist is %p\n",wclist);
  if(1){
  list_init(&wclist->lst);
  pthread_mutex_init(&wclist->lock, NULL);
  }

}

size_t len_words(word_count_list_t *wclist) {
  /* TODO */
  return list_size(&wclist->lst);
}

word_count_t *find_word(word_count_list_t *wclist, char *word) {
  /* TODO */
  struct list_elem *ele;
  //pthread_mutex_lock(&wclist->lock);
  for(ele = list_begin(&wclist->lst); ele != list_end(&wclist->lst); ele = list_next(ele)){
  word_count_t *wc = list_entry(ele, word_count_t, elem); 
  //pthread_mutex_unlock(&wclist->lock);
  char* word_in_word_count = wc->word;
  if(strcmp(word_in_word_count,word)==0){
     pthread_mutex_unlock(&wclist->lock);
     return wc;
    }
  }
  //pthread_mutex_unlock(&wclist->lock);
  return NULL;
}
word_count_t *add_word(word_count_list_t *wclist, char *word) {
  /* TODO */
//	printf("add word called, word to add is %s\n",word);
  word_count_t* added_word_count_t = find_word(wclist, word);
  if(added_word_count_t != NULL){
	  pthread_mutex_lock(&wclist->lock);
	  added_word_count_t->count++;
	  pthread_mutex_unlock(&wclist->lock);

  }
  else
  {
  //printf("%s not found, add new word_count\n",word);
  word_count_t *word_count_t_to_add = (word_count_t *)malloc(sizeof(*word_count_t_to_add));
  word_count_t_to_add->word = (char*)malloc((strlen(word)+1)*sizeof(char));
  strcpy(word_count_t_to_add->word,word);
  word_count_t_to_add->count=1;
  //pthread_mutex_lock(&wclist->lock);
  list_push_back(&wclist->lst,&word_count_t_to_add->elem);
  added_word_count_t = word_count_t_to_add;
  //pthread_mutex_unlock(&wclist->lock);
  }
  //pthread_mutex_unlock(&wclist->lock);
  pthread_mutex_unlock(&wclist->lock);
  return added_word_count_t;
}

void fprint_words(word_count_list_t *wclist, FILE *outfile) {
  /* TODO */
  struct list_elem *ele;
  for(ele = list_begin(&wclist->lst); ele != list_end(&wclist->lst); ele = list_next(ele)){
  word_count_t *wc = list_entry(ele, word_count_t, elem); 
  fprintf(outfile, "%i\t%s\n", wc->count, wc->word);
  }
}

static bool less_list(const struct list_elem *ewc1,const struct list_elem *ewc2, void *aux)
{
  word_count_t* wc1;
  word_count_t* wc2;
  bool (*func_ptr)(word_count_t *, word_count_t *) = aux;
  wc1 = list_entry(ewc1,word_count_t,elem);
  wc2 = list_entry(ewc2,word_count_t,elem);
  return (*func_ptr)(wc1,wc2);

}

void wordcount_sort(word_count_list_t *wclist,
                    bool less(const word_count_t *, const word_count_t *)){
  /* TODO */
  list_sort(&wclist->lst, less_list, less);
}



