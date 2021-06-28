#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pagina{

  float num;

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
	
	struct estudiante *A = &pepito;
	int a;
	int i = 10;
	float num;
	unsigned long int numi = 2;

	scanf("%f", &(A->novela.numero.num));
	
	printf("%f\n", A->novela.numero.num);
	
	numi = pepito.novela.numero.num;
	printf("%u\n", numi);

	for(a = 1000000000; a>10; a/=10){

		if(numi%a == numi){

			if(numi%(a/10) != numi){

				a = 1;

			}
		}
		i--;
	}

	i+=3;

	printf("%.2f tiene %d caracteres.", num, i);

	return 0;

}
