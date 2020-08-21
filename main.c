#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNo{
  char id;
} DataNo;

typedef struct no{
  DataNo data;
  struct no* next;
}No;

typedef struct list{
  int size;
  No* head;
}List;

List* createList();
void push(List* list, DataNo data);
void imprimir(List* list);

List* createList(){
  List* list = (List*) malloc(sizeof(List));
  list->size = 0;
  list->head = NULL;
  return list;
}

void push(List* list, DataNo data){
  No* no = (No*) malloc(sizeof(No));
  no->data = data;
  no->next = list->head;
  list->head = no;
  list->size++;
}

void imprimir(List* list){
  No* pointer = list->head;
  printf("Nomes digitados:\n");
  while(pointer!=NULL){
    printf("%c", pointer->data.id);
    pointer = pointer->next;
  }
}

void inserir(List* list, DataNo data){
  char x;
  scanf("%c", &x);
  data.id = x;
  if(data.id=='!') return;
  push(list, data);
  inserir(list, data);
}

int main(void) {
  List* list = createList();
  DataNo data;

  printf("Digite e pressione ENTER para inserir um próximo nome. Para concluir digite '!':\n");
  inserir(list, data);
  imprimir(list);
  return 0;
}
