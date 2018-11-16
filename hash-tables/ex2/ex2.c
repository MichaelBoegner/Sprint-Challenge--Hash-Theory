#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  for(int i = 0; i < length; i++) {
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
    
    char *none = "NONE";

    route[0] = hash_table_retrieve(hash, none);
    
    if(strcmp(hash_table_retrieve(hash, tickets[i]->source), none) == 0) {
      route[length - 1] = tickets[i]->source; 
    } 

    if(hash_table_retrieve(hash, hash_table_retrieve(hash, tickets[i]->source))){
      route[i + 1] = tickets[i]->source; 
    }
  
  }
  destroy_hash_table(hash); 

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}