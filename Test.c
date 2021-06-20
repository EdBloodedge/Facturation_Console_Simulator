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
  char descripcion[40];

}PRODUCTOS[25] = {
//PRODUCTOS

{45121503, 247.70, "Cámaras desechables"},
{45121504, 6999.00, "Cámaras digitales"},
{45121505, 13999.00, "Cámaras cinematográficas"},
{45121506, 10569.00, "Cámaras de video conferencia"},
{451215010, 24999.00, "Cámaras aéreas"},
{45121511, 10799.00, "Cámaras de alta velocidad"},
{45121520, 1209.00, "Cámaras web"},
{45121521, 354.00, "Cámaras de inspección"},
{45121522, 950.17, "Cámaras infrarrojas"},
{45121523, 3076.00, "Cámaras astronómicas"},
{45121601, 1249.00, "Flashes o iluminación para cámaras"},
{45121602, 799.00, "Tripodes para cámara"},
{45121603, 63.85, "Lentes para cámara"},
{45121604, 267.24, "Oclusores para cámaras"},
{45121605, 7400.00, "Marcos de pantalla"},

//SERVICIOS

{82131601, 6500.00, "Servivios de fotografía aérea"},
{82131602, 6315.00, "Cinematografía"},
{82131603, 4950.00, "Servicios de producción de vídeos"},
{82131604, 3500.00, "Servicios de estudio fotográfico o fotos fijas"},
{82131501, 7500.00, "Elaboración o reproducción de película fija"},
{82131502, 6315.00, "Elaboración o reproducción de películas de cine"},
{82131503, 2572.90, "Servicios de microficha"},
{82131504, 175.90, "Separación de colores"},
{82131505, 3750.00, "Servicio de postproducción de películas"},
{82131506, 2950.00, "Servicio de fotos de graduación"}
};

int modificar(struct estudiante *a){

	a->novela.numero.num = 3;

}

int main(){

  int i;

  for(i=0; i<25; i++){

    printf("%d:\nClave = %d\nDescripcion = %s\nPrecio = $%.2f\n\n", i, PRODUCTOS[i].clave, PRODUCTOS[i].descripcion, PRODUCTOS[i].precio);

  }


	return 0;

}
