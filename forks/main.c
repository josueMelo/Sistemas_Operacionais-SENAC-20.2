#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <errno.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 

float aleatorio(char c){
  //valores randomicos
  int a = rand()%1000;
  int b = rand()%1000;
  if(c=='r') { //char referente ao real intervalo
    if(a>b) return (float)b/a;
    else return (float)a/b;
  }
  return ((float)b / sqrt(a*a+b*b)); //qualquer coisa diferente irá retornar como sendo o cosseno
}

int main(int argc, char  *argv[])
{
  float soma = 0;
  int i, maximo, count =0;
  long seed = time(NULL);
  srand((unsigned)seed);

  printf("Insira o tamanho maximo: \n");
  scanf("%d", &maximo);
  if(maximo>1){
  if(maximo%2!=0) i = maximo/2;
  else i = (maximo/2)-1;
  }
  else{
    printf("Desculpe, insira um valor maior!\n");
    exit(0);
  }

  pid_t pid;
  pid = fork();
  if(pid<0){
    printf("ERRO, :(\n");
    perror(argv[0]);
    exit(errno);
  }

  else if(pid==0){
    int j = 0;
    for(; j<=i; j++) if(aleatorio('r') < aleatorio('c'))  count++;
    printf("Filho: %f\n", 2.0*(float)j /(1.0*count));
  }

  else{
    wait(NULL);
    int metade = i;
    for(; i<maximo; i++) if(aleatorio('r') < aleatorio('c')) count++;

    i -= metade;
    printf("Pai: %f\n", 2.0*(float)i /(1.0*count));

  }
}