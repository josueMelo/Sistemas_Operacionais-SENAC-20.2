#include <stdio.h>
#include <stdlib.h>

void *aloca(int nbytes);
void libera(void *p);

typedef struct memory{
  int size;
}Memory;

int main(void) {
    int *p = (int *) aloca(4*sizeof(int));
    *p = 100;
    libera(p);
    printf("%d", *p);
}

void *aloca(int nbytes){
  Memory* memory = (Memory*) malloc(sizeof(nbytes));
  return memory;
}

void libera(void *p){
  free(p);
  p = NULL;
}