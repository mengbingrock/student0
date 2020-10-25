/*
 * Implementation of the word_count interface using Pintos lists.
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
#error "PINTOS_LIST must be #define'd when compiling word_count_l.c"
#endif

#include "word_count.h"

void init_words(word_count_list_t *wclist) {
  /* TODO */
  list_init(wclist);
}

// /* Get length of a word count list. */ 
size_t len_words(word_count_list_t *wclist) {
  /* TODO */
	word_count_list_t* list_in_wclist = wclist;
	size_t list_s = list_size(list_in_wclist); 
	return list_s;
  return 0;
}
// /* Find a word in a word_count list. */
word_count_t *find_word(word_count_list_t *wclist, char *word) {
  /* TODO */
  struct list_elem *ele;
  word_count_list_t* list_in_wclist = wclist;
  for(ele = list_begin(list_in_wclist); ele != list_end(list_in_wclist); ele = list_next(ele)){
    word_count_t *wc = list_entry(ele, struct word_count, elem);
    char* word_in_word_count = wc->word;
    if(strcmp(word_in_word_count,word)==0){
	return wc;
    }
  }
  return NULL;
}

word_count_t *add_word(word_count_list_t *wclist, char *word) {
  /* TODO */
	word_count_t* added_word_count_t = find_word(wclist, word);
	if(added_word_count_t != NULL){
         added_word_count_t->count++;	
	}
	else
	{
	word_count_t *word_count_t_to_add = (word_count_t *)malloc(sizeof(*word_count_t_to_add));
	word_count_t_to_add->word = (char*)malloc((strlen(word)+1)*sizeof(char));
	strcpy(word_count_t_to_add->word,word);
        word_count_t_to_add->count=1;	
	list_push_back(wclist,&word_count_t_to_add->elem);
        added_word_count_t = word_count_t_to_add; 	
	}
  
  return added_word_count_t;
}

void fprint_words(word_count_list_t *wclist, FILE *outfile) {
  /* TODO */
	//printf("entered into fprint_words \n");
  struct list_elem* ele=list_head(wclist);
  for (ele = list_next(ele); ele != list_end(wclist); ele = list_next(ele) ) {
	  //printf("entered into the loop\n");
    word_count_t* wc = list_entry(ele,word_count_t,elem);
    fprintf(outfile, "%i\t%s\n", wc->count, wc->word);
  }
	//printf("left into fprint_words \n");
}

static bool less_list(const struct list_elem *ewc1,
                      const struct list_elem *ewc2, void *aux) {
  /* TODO */
	//printf("entered into less_list  \n");
  word_count_t* wc1;
  word_count_t* wc2;
  bool (*func_ptr)(word_count_t *, word_count_t *) = aux;
  wc1 = list_entry(ewc1,struct word_count,elem);
  wc2 = list_entry(ewc2,struct word_count,elem);
	//printf("left into less_list  \n");
  return (*func_ptr)(wc1,wc2);
}

void wordcount_sort(word_count_list_t *wclist,
                    bool less(const word_count_t *, const word_count_t *)) {

	//printf("entered into wordcount_sort \n");
  list_sort(wclist, less_list, less);
	//printf("left into wordcount_sort \n");
}
