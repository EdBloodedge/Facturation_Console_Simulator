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

}PRODUCTOS[25] = {
//PRODUCTOS

{45121503, 247.70, "Camaras desechables"},
{45121504, 6999.00, "Camaras digitales"},
{45121505, 13999.00, "Camaras cinematograficas"},
{45121506, 10569.00, "Camaras de video conferencia"},
{451215010, 24999.00, "Camaras aereas"},
{45121511, 10799.00, "Camaras de alta velocidad"},
{45121520, 1209.00, "Camaras web"},
{45121521, 354.00, "Camaras de inspeccion"},
{45121522, 950.17, "Camaras infrarrojas"},
{45121523, 3076.00, "Camaras astronomicas"},
{45121601, 1249.00, "Flashes o iluminacion para camaras"},
{45121602, 799.00, "Tripodes para camara"},
{45121603, 63.85, "Lentes para camara"},
{45121604, 267.24, "Oclusores para camaras"},
{45121605, 7400.00, "Marcos de pantalla"},

//SERVICIOS

{82131601, 650.00, "Servivios de fotografia aerea"},
{82131602, 6315.00, "Cinematografia"},
{82131603, 4950.00, "Servicios de produccion de videos"},
{82131604, 350.00, "Servicios de estudio fotografico o fotos fijas"},
{82131501, 750.00, "Elaboracion o reproduccion de pelicula fija"},
{82131502, 6315.00, "Elaboracion o reproduccion de peliculas de cine"},
{82131503, 2572.90, "Servicios de microficha"},
{82131504, 175.90, "Separacion de colores"},
{82131505, 3750.00, "Servicio de postproduccion de peliculas"},
{82131506, 2950.00, "Servicio de fotos de graduacion"}
};



int modificar(struct estudiante *a){

	a->novela.numero.num = 3;

}

int main(){

  int i, a, j;

Beep(659, 150);  
Beep(659, 300);  
Beep(659, 300);  
Beep(523, 150);  
Beep(659, 300);  
Beep(783, 450);  
Sleep(300);
Beep(392, 300);  

}
