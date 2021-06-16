#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct libro{
  char a;
};

struct estudiante{

  struct libro novela;
  int comida;

}pepito;

int modificar(struct estudiante *a){

	a->novela.a= 'a';

}

int main(){

  char a = 's';

  pepito.novela.a = a;
  pepito.comida = 1;

  printf("%c", pepito.novela);

  modificar(&(pepito));

  printf("%c", pepito.novela.a);


	return 0;

}
