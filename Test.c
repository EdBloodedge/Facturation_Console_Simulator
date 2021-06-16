#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pagina{

  int num;

};

struct libro{
  struct pagina numero;
};

struct estudiante{

  struct libro novela;
  int comida;

}pepito;

int modificar(struct estudiante *a){

	a->novela.numero.num = 3;

}

int main(){

  char a = 's';

  pepito.novela.numero.num = 1;
  pepito.comida = 1;

  printf("%d", pepito.novela.numero.num);

  modificar(&(pepito));

  printf("%d", pepito.novela.numero.num);


	return 0;

}
