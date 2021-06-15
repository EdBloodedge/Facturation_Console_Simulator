#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct libro{
  char a;
};

struct estudiante{

  struct libro novela;

}pepito;

int main(){

  char a = 's';

  pepito.novela.a = a;

  printf("%c", pepito.novela);


	return 0;

}
