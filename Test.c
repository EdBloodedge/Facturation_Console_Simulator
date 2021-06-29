#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

	char qr[10][20], car;
	int a;
	int i = 10;
	int j;
	float num;
  srand(time(NULL));



  for(i = 0; i<10; i++){
      for(a=0; a<20; a++){

        j = rand()%4;

        switch(j){

        	case 0:
        		qr[i][a] = 32;
        		break;

        	case 1:
        		qr[i][a] = 219;
        		break;

        	case 2:
        		qr[i][a] = 223;
        		break;

        	case 3:
        		qr[i][a] = 220;
        		break;


		}

      }

  }

	qr[0][0] = 219; qr[0][1] = 223; qr[0][2] = 223; qr[0][3] = 223; qr[0][4] = 223; qr[0][5] = 223; qr[0][6] = 219; qr[0][7] = 32;
  qr[1][0] = 219; qr[1][1] = 32; qr[1][2] = 219; qr[1][3] = 219; qr[1][4] = 219; qr[1][5] = 32; qr[1][6] = 219; qr[1][7] = 32;
  qr[2][0] = 219; qr[2][1] = 32; qr[2][2] = 223; qr[2][3] = 223; qr[2][4] = 223; qr[2][5] = 32; qr[2][6] = 219; qr[2][7] = 32;
  qr[3][0] = 223; qr[3][1] = 223; qr[3][2] = 223; qr[3][3] = 223; qr[3][4] = 223; qr[3][5] = 223; qr[3][6] = 223; qr[3][7] = 32;

  qr[0][12] = 32; qr[0][13] = 219; qr[0][14] = 223; qr[0][15] = 223; qr[0][16] = 223; qr[0][17] = 223; qr[0][18] = 223; qr[0][19] = 219;
  qr[1][12] = 32;qr[1][13] = 219; qr[1][14] = 32; qr[1][15] = 219; qr[1][16] = 219; qr[1][17] = 219; qr[1][18] = 32; qr[1][19] = 219;
  qr[2][12] = 32;  qr[2][13] = 219; qr[2][14] = 32; qr[2][15] = 223; qr[2][16] = 223; qr[2][17] = 223; qr[2][18] = 32; qr[2][19] = 219;
  qr[3][12] = 32;qr[3][13] = 223; qr[3][14] = 223; qr[3][15] = 223; qr[3][16] = 223; qr[3][17] = 223; qr[3][18] = 223; qr[3][19] = 223;

  qr[6][0] = 220; qr[6][1] = 220; qr[6][2] = 220; qr[6][3] = 220; qr[6][4] = 220; qr[6][5] = 220; qr[6][6] = 220; qr[6][7] = 32;
  qr[7][0] = 219; qr[7][1] = 32; qr[7][2] = 220; qr[7][3] = 220; qr[7][4] = 220; qr[7][5] = 32; qr[7][6] = 219; qr[7][7] = 32;
  qr[8][0] = 219; qr[8][1] = 32; qr[8][2] = 219; qr[8][3] = 219; qr[8][4] = 219; qr[8][5] = 32; qr[8][6] = 219; qr[8][7] = 32;
  qr[9][0] = 219; qr[9][1] = 220; qr[9][2] = 220; qr[9][3] = 220; qr[9][4] = 220; qr[9][5] = 220; qr[9][6] = 219; qr[9][7] = 32;

  for(i = 0; i<10; i++){
      for(a=0; a<20; a++){

	  printf("%c", qr[i][a]);

	  }
	  printf("\n");
	}

	return 0;

}
