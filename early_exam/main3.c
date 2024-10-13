#include <stdio.h>
#include <stdlib.h>

typedef struct LE{

  int x;
  struct LE *next;
} ListElem;

typedef struct{

  ListElem *head, *tail;
} List;

int duplicateIf(List *list, int (*pred)(double));

int main(void){

  return 0;

}

int duplicateIf(List *list, int (*pred)(double)){
  ListElem *current = list->head;
  int elementsAdded = 0;

  while(current != NULL){
    if(pred(current->x)){

      ListElem *newElem = malloc(sizeof(ListElem));
      newElem->x = current->x;
      newElem->next = current->next;
      current->next = newElem;
      current = newElem;

      elementsAdded++;
    }else{

      current = current->next;
    }


  }

  return elementsAdded;
}
