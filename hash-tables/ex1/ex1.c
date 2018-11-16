#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer * answer = malloc(sizeof(Answer));
  

  for(int i = 0; i < length; i++) {
    hash_table_insert(ht, weights[i], limit - weights[i]);

    if(hash_table_retrieve(ht, hash_table_retrieve(ht, weights[i])) ) {
      if(weights[i] > hash_table_retrieve(ht, weights[i])) {
        answer->index_1 = weights[i];
        answer->index_2 = hash_table_retrieve(ht, weights[i]); 
        return answer; 

      } else if(weights[i] < hash_table_retrieve(ht, weights[i])) {
        answer->index_1 = hash_table_retrieve(ht, weights[i]);
        answer->index_2 = weights[i];
        return answer;
        }

    } else {
      return NULL; 
    } 
  
  }   
}

//   for(int i = 0; i < length; i++) {
//     hash_table_insert(ht, weights[i], limit - weights[i]);
//     int value = hash_table_retrieve(ht, weights[i]); 
    
//     if( (value == weights[i]) && (value > weights[i]) ) {
//         printf("if statement running %d, %d", value, weights[i]);
//          answer->index_1 = value;
//          answer->index_2 = weights[i];
//          return answer; 
//     } else if((value == weights[i]) && (value < weights[i]) ) {
//         printf("if statement running %d, %d", value, weights[i]);
//          answer->index_1 = weights[i];
//          answer->index_2 = value;
//          return answer;
//     } else {
//       return NULL; 
//     }
//   }
// }

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}