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

struct producto{

  int clave;
  float precio;
  char descripcion[50];

};
int main(){
  int a;

  if(scanf("%d", &a) == 0){

    printf("Si es cero");

  }


	return 0;

}
