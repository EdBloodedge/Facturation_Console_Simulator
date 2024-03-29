/*
Integrantes del equipo:

Paulina Martinez Villarreal.
Manuel Antonio García Huerta.
Eduardo de Jesús García Ríos.

Materia:
Seminario de Solucion de Problemas de Programación.

Sección:D38

Maestra:
Thelma Isabel Morales Ramirez.

Proyecto Final: Sistema de Facturación Electrónica.

Nombre de la empresa: Los SAT-anes.
*/



#include <stdio.h>
#include <string.h> /* gets, strcmp */
#include <stdlib.h> /* system */
#include <time.h>


#define USUARIO "Perry"
#define CLAVE "ElOrnitorrinco"
#define QR "# ## #\n# ## #\n#    #\n #### "

#define USUARIO2 "Jaimito"
#define CLAVE2 "tangamandapio"
#define QR2 "#####\n  #  \n  #  \n ##  \n##   "

#define USUARIO3 "LosSATanes"
#define CLAVE3 "SATanes"
#define QR3 "#####\n#    #\n#    #\n#    #\n#####"

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define NumUsers 3 //N�mero de usuarios
#define LONGITUD 20 //Longitud usuario
#define LONGCLAVE 15 //Longitud clave
#define LimiteFact 20 //Cantidad maxima de facturas por usuario
#define MAX_INTENTOS 3
#define Tamanio 1 //Tama�o

#define MORAL1 "Regimen General"
#define MORAL2 "Sin Fines de Lucro"

#define FISCAL1 "Asalariados"
#define FISCAL2 "Honorarios"
#define FISCAL3 "Arrendamientos de Inmuebles"
#define FISCAL4 "Actividades Empresariales"
#define FISCAL5 "Incorporacion Fiscal"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INICIALIZACI�N DE ESTRUCTURAS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Domicilio
struct domicilio{

  char calle[20], colonia[20], ciudad[20], estado[20], pais[20];
  int numero, codigoPostal;

};

struct productos{
    float importe, precioUnitario;
    int cantidad, clave;
    char nombreDescripcion[50];
};

//Facturas
struct factura{

  char logo[20][10], nombreEmisor[37], RFCEmisor[15], nombreReceptor[30], RFCReceptor[15];
  int enviado, hora[128];
  float subtotal, IVA, total;
  char folio[15], emisorFiscales[30], receptorFiscales[30], firma[70];
  struct domicilio domEmisor, domReceptor;
  struct productos MASPRODUCTOS[5];

};

//Usuario.
struct Usuario{
  char usuario[LONGITUD+1], clave[LONGCLAVE+1], nombre[50], puesto[20], qr[50];
  int NumFacturas;
  struct factura facturas[LimiteFact];
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BASE DE DATOS DE PRODUCTOS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Productos
struct producto{

  int clave;
  float precio;
  char descripcion[50];

}PRODUCTOS[25] = {
//PRODUCTOS

{45121503, 247.70  , "Camaras desechables                               "},
{45121504, 6999.00 , "Camaras digitales                                 "},
{45121505, 13999.00, "Camaras cinematograficas                          "},
{45121506, 10569.00, "Camaras de video conferencia                      "},
{45121510, 24999.00, "Camaras aereas                                    "},
{45121511, 10799.00, "Camaras de alta velocidad                         "},
{45121520, 1209.00 , "Camaras web                                       "},
{45121521, 354.00  , "Camaras de inspeccion                             "},
{45121522, 950.17  , "Camaras infrarrojas                               "},
{45121523, 3076.00 , "Camaras astronomicas                              "},
{45121601, 1249.00 , "Flashes o iluminacion para camaras                "},
{45121602, 799.00  , "Tripodes para camara                              "},
{45121603, 63.85   , "Lentes para camara                                "},
{45121604, 267.24  , "Oclusores para camaras                            "},
{45121605, 7400.00 , "Marcos de pantalla                                "},

//SERVICIOS

{82131601, 6500.00 , "Servicios de fotografia aerea                     "},
{82131602, 6315.00 , "Cinematografia                                    "},
{82131603, 4950.00 , "Servicios de produccion de videos                 "},
{82131604, 3500.00 , "Servicios de estudio fotografico o fotos fijas    "},
{82131501, 7500.00 , "Elaboracion o reproduccion de pelicula fija       "},
{82131502, 6315.00 , "Elaboracion o reproduccion de peliculas de cine   "},
{82131503, 2572.90 , "Servicios de microficha                           "},
{82131504, 175.90  , "Separacion de colores                             "},
{82131505, 3750.00 , "Servicio de postproduccion de peliculas           "},
{82131506, 2950.00 , "Servicio de fotos de graduacion                   "}
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CREAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int crear(struct Usuario *A, int a, struct producto *B, int CopiarAnt){

  int copiar = 0, longi1 = 0, longi2 = 0, longitud1, longitud2,continuar=0, avanzar=0, NoLetras = 0, cantidad;
  char enye = 168, firmaDigital[70];
  int claveBuscada, k, salir, moral=0, fiscal=0, cantidadProductos=0, i, letraNumero=0, contador=0, moral2=0, fiscal2=0;

  system("CLS");
  if(CopiarAnt == 1){

    printf("%cDesea usar los datos de emisor de la factura anterior?\n1.-S%c\nOtra tecla.- No\n", 168, 161);
    scanf("%d", &copiar);
  }

  system("cls");
  printf("\t\t\t\t----Ingrese los siguientes datos.----\n");

  if(copiar == 1){

    strcpy(A->facturas[a].nombreEmisor, A->facturas[a-1].nombreEmisor);
    strcpy(A->facturas[a].RFCEmisor, A->facturas[a-1].RFCEmisor);
    strcpy(A->facturas[a].domEmisor.calle, A->facturas[a-1].domEmisor.calle);
    strcpy(A->facturas[a].domEmisor.ciudad, A->facturas[a-1].domEmisor.ciudad);
    strcpy(A->facturas[a].domEmisor.colonia, A->facturas[a-1].domEmisor.colonia);
    strcpy(A->facturas[a].domEmisor.estado, A->facturas[a-1].domEmisor.estado);
    strcpy(A->facturas[a].domEmisor.pais, A->facturas[a-1].domEmisor.pais);
    strcpy(A->facturas[a].emisorFiscales, A->facturas[a-1].emisorFiscales);
    A->facturas[a].domEmisor.numero = A->facturas[a-1].domEmisor.numero;
    A->facturas[a].domEmisor.codigoPostal = A->facturas[a-1].domEmisor.codigoPostal;
  } else {

    printf("-----DATOS DEL EMISOR------\n\nNombre de la empresa: ");
    fflush(stdin);
    gets(A->facturas[a].nombreEmisor);

    do{
        longi1 = 0;
        printf("RFC: ");
        fflush(stdin);
        gets(A->facturas[a].RFCEmisor);
        longitud1 = strlen(A->facturas[a].RFCEmisor);//Mide la longitud de la cadena
        if (longitud1<12 || longitud1>13){
            Beep(300,500); // 523 hertz (C5) for 500 milliseconds
            printf("\nEl RFC es incorrecto, vuelve a intentarlo\n");
            longi1=2;
        }

    }while (longi1 == 2);

    printf("\n\nDOMICILIO\n\n-Calle: ");
    fflush(stdin);
    gets(A->facturas[a].domEmisor.calle);
    printf("-N%cmero: ", 163);
    fflush(stdin);
    do{
      fflush(stdin);
      if(scanf("%d", &(A->facturas[a].domEmisor.numero)) == 0){
        printf("Valor ingresado no v%clido.\n\n", 160);
        Beep(300,500);
        NoLetras = 0;}
      else
        NoLetras = 1;
    }while(NoLetras == 0);
    printf("-Colonia: ");
    fflush(stdin);
    gets(A->facturas[a].domEmisor.colonia);
    printf("-C%cdigo postal: ", 162);
    fflush(stdin);
    do{
      fflush(stdin);
      if(scanf("%d", &(A->facturas[a].domEmisor.codigoPostal)) == 0){
        printf("Valor ingresado no v%clido.\n\n", 160);
        Beep(300,500);
        NoLetras = 0;}
      else
        NoLetras = 1;
    }while(NoLetras == 0);
    printf("-Ciudad: ");
    fflush(stdin);
    gets(A->facturas[a].domEmisor.ciudad);
    printf("-Estado o provincia: ");
    fflush(stdin);
    gets(A->facturas[a].domEmisor.estado);
    printf("-Pa%cs: ", 161);
    fflush(stdin);
    gets(A->facturas[a].domEmisor.pais);
    system("CLS");
}

  ////////// Datos de regimen fiscal/////////////

  if(longitud1 == 12){
    printf("\n-PERSONAS MORALES\n\n");
    do{
        printf("%cQu%c tipo de personas morales son? \n1)R%cgimen General \n2)Sin Fines de Lucro\n -> ", enye, 130, 130);
        scanf(" %d", &moral);
        switch(moral){
            case 1:
                strcpy(A->facturas[a].emisorFiscales, MORAL1);
                break;
            case 2:
                strcpy(A->facturas[a].emisorFiscales, MORAL2);
                break;
            default:
                Beep(300,500); // 523 hertz (C5) for 500 milliseconds
                printf("Opci%cn no v%clida\n", 162, 160);
                fflush( stdin );
                printf("\n\n");
                break;
            }
    }while(moral!=1 && moral!=2);
    }

  if(longitud1 == 13){
    printf("\n-PERSONAS FISCALES\n\n");
    do{
        printf("%cQu%c tipo de personas fiscales son? \n1)Persona Asalariada \n2)Honorarios \n3)Arrendamiento de Inmuebles \n4)Incorporaci%cn Fiscal \n5)Actividades Empresariales \n-> ", enye, 130, 162);
        scanf(" %d",&fiscal);
        switch(fiscal){
            case 1:
                strcpy(A->facturas[a].emisorFiscales, FISCAL1);
                break;
            case 2:
                strcpy(A->facturas[a].emisorFiscales, FISCAL2);
                break;
            case 3:
                strcpy(A->facturas[a].emisorFiscales, FISCAL3);
                break;
            case 4:
                strcpy(A->facturas[a].emisorFiscales, FISCAL4);
                break;
            case 5:
                strcpy(A->facturas[a].emisorFiscales, FISCAL5);
                break;
            default:
                Beep(300,500); // 523 hertz (C5) for 500 milliseconds
                printf("Opci%cn no v%clida\n", 162, 160);
                fflush( stdin );
                printf("\n\n");
                break;
        }
    }while(fiscal!=1 && fiscal!=2 && fiscal!=3 && fiscal!=4 && fiscal!=5);
    }
    system("CLS");

  printf("\n\n--------DATOS DEL RECEPTOR------\n\nNombre de la empresa: ");
  fflush(stdin);
  gets(A->facturas[a].nombreReceptor);


  do{
    longi2 = 0;
    printf("RFC: ");
    fflush(stdin);
    gets(A->facturas[a].RFCReceptor);
    longitud2 = strlen(A->facturas[a].RFCReceptor);//Mide la longitud de la cadena
    if (longitud2<12 || longitud2>13){
        Beep(300,500); // 523 hertz (C5) for 500 milliseconds
        printf("\nEl RFC es incorrecto, vuelve a intentarlo\n");
        longi2=2;
    }
  }while (longi2 == 2);

  printf("\nDOMICILICO\n\n-Calle: ");
  fflush(stdin);
  gets(A->facturas[a].domReceptor.calle);
  printf("-N%cmero: ", 163);
  fflush(stdin);
  do{
    fflush(stdin);
    if(scanf("%d", &(A->facturas[a].domReceptor.numero)) == 0){
      printf("Valor ingresado no v%clido.\n\n", 160);
      Beep(300,500);
      NoLetras = 0;}
    else
      NoLetras = 1;
  }while(NoLetras == 0);
  printf("-Colonia: ");
  fflush(stdin);
  gets(A->facturas[a].domReceptor.colonia);
  printf("-C%cdigo postal: ", 162);
  fflush(stdin);
  do{
    fflush(stdin);
    if(scanf("%d", &(A->facturas[a].domReceptor.codigoPostal)) == 0){
      printf("Valor ingresado no v%clido.\n\n", 160);
      Beep(300,500);
      NoLetras = 0;}
    else
      NoLetras = 1;
  }while(NoLetras == 0);
  printf("-Ciudad: ");
  fflush(stdin);
  gets(A->facturas[a].domReceptor.ciudad);
  printf("-Estado o provincia: ");
  fflush(stdin);
  gets(A->facturas[a].domReceptor.estado);
  printf("-Pa%cs: ", 161);
  fflush(stdin);
  gets(A->facturas[a].domReceptor.pais);


  system("CLS");
  if(longitud2 == 12){
    printf("\n-PERSONAS MORALES\n\n");
    do{
        printf("%cQue tipo de personas morales son? \n1)R%cgimen General \n2)Sin Fines De Lucro\n -> ",enye, 130);
        fflush(stdin);
        scanf(" %d", &moral2);
        switch(moral2){
            case 1:
                strcpy(A->facturas[a].receptorFiscales, MORAL1);
                break;
            case 2:
                strcpy(A->facturas[a].receptorFiscales, MORAL2);
                break;
            default:
                Beep(300,500); // 523 hertz (C5) for 500 milliseconds
                printf("Opci%cn no v%clida\n", 162, 160);
                fflush(stdin);
                printf("\n\n");
                break;
        }
    }while(moral2!=1 && moral2!=2);
    }

  if(longitud2 == 13){
    printf("\n-PERSONAS FISCALES\n\n");
    do{
        printf("%cQue tipo de personas fiscales son? \n1)Persona Asalariada \n2)Honorarios \n3)Arrendamiento de Inmuebles \n4)Incorporacion Fiscal \n5)Actividades Empresariales \n-> ",enye);
        scanf(" %d", & fiscal2);
        fflush(stdin);
        switch(fiscal2){
            case 1:
                strcpy(A->facturas[a].receptorFiscales, FISCAL1);
                break;
            case 2:
                strcpy(A->facturas[a].receptorFiscales, FISCAL2);
                break;
            case 3:
                strcpy(A->facturas[a].receptorFiscales, FISCAL3);
                break;
            case 4:
                strcpy(A->facturas[a].receptorFiscales, FISCAL4);
                break;
            case 5:
                strcpy(A->facturas[a].receptorFiscales, FISCAL5);
                break;
            default:
                Beep(300,500); // 523 hertz (C5) for 500 milliseconds
                printf("Opci%cn no v%clida\n", 162, 160);
                fflush(stdin);
                printf("\n\n");
                break;
        }
    }while(fiscal2!=1 && fiscal2!=2 && fiscal2!=3 && fiscal2!=4 && fiscal2!=5);
    }

//------------------------------DATOS DE LOS PRODUCTOS Y SERVICIOS---------------------------------------------

    printf("\n\n\n\n\t\t-------------PRODUCTOS Y SERVICIOS-----------\n\n");
    printf(" CLAVES           PRODUCTOS                                           PRECIOS\n\n");
    printf("45121503       C%cmaras desechables                                    $247.70\n", 160);
    printf("45121504       C%cmaras digitales                                      $6999.00\n", 160);
    printf("45121505       C%maras cinematogr%cficas                                $13999.00\n",160, 160);
    printf("45121506       C%cmaras de video conferencia                           $10569.00\n",160);
    printf("45121510       C%cmaras a%creas                                         $24999.00\n",160, 130);
    printf("45121511       C%cmaras de alta velocidad                              $10799.00\n",160);
    printf("45121520       C%cmaras de web                                         $1209.00\n",160);
    printf("45121521       C%cmaras de inspecci%cn                                  $354.00\n",160, 162);
    printf("45121522       C%cmaras infrarrojas                                    $950.17\n",160);
    printf("45121523       C%cmaras astron%cmicas                                   $3076.00\n",160, 162);
    printf("45121601       Flashes o iluminaci%cn para c%cmaras                     $1249.00\n",162, 160);
    printf("45121602       Tr%cpodes para c%cmaras (Tripi%cs para c%cmara)            $799.00\n",161, 160,130, 160);
    printf("45121603       Lentes para c%cmaras                                    $63.85\n", 160);
    printf("45121604       Oclusores para c%cmaras                                 $267.24\n",160);
    printf("45121605       Marcos de pantalla                                     $7400.00\n\n\n");

    printf(" CLAVES                SERVICIOS                                      PRECIOS\n\n");
    printf("82131601       Servicios de fotograf%ca a%crea                          $6500.00\n",161, 130);
    printf("82131602       Cinematograf%ca                                         $6315.00\n",161);
    printf("82131603       Servicios de producci%cn de v%cdeos                      $4950.00\n",162,161);
    printf("82131604       Servicios de estudio fotogr%cfico o fotos fijas         $3500.00\n",160);
    printf("82131501       Elaboraci%cn o reproducci%cn de pel%ccula fija            $7500.00\n",162, 162, 161);
    printf("82131502       Elaboraci%cn o reproducci%cn de pel%cculas de cine        $6315.00\n",162, 162, 161);
    printf("82131503       Servicios de microficha                                $2572.90\n");
    printf("82131504       Separaci%cn de colores                                  $175.90\n",162);
    printf("82131505       Servicio de posproducci%cn de pel%cculas                 $3750.00\n",162, 161);
    printf("82131506       Servicio de fotos de graduaci%cn                        $2950.00\n",162);

    do{
        salir=1;
        continuar=0;
        printf("\n\n\nIngrese la clave del producto(s) o servicio(s) que quieres comprar ->  ");
        fflush(stdin);
        if (scanf(" %d",&claveBuscada)==0){
            continuar=1;
        }
        for (k=0; k<=25; k++){
            if  (((B[k].clave) == claveBuscada) && (continuar==0)){
                    A->facturas[a].MASPRODUCTOS[cantidadProductos].clave=B[k].clave;
                    strcpy(A->facturas[a].MASPRODUCTOS[cantidadProductos].nombreDescripcion, B[k].descripcion);
                    A->facturas[a].MASPRODUCTOS[cantidadProductos].precioUnitario=B[k].precio;
                    printf("Producto/Servicio guardado\n");
                    do{
                        printf("\n\nCantidad: ");
                        fflush(stdin);
                        if (scanf("%d", &cantidad) == 0){
                            Beep(300,500);
                            printf("Cantidad no v%clida\n", 160);
                            avanzar=1;
                        }else if(cantidad < 1){
                            printf("Cantidad no v%clida\n", 160);
                            Beep(300,500);
                            avanzar=1;
                        }else{
                            avanzar=0;
                            A->facturas[a].MASPRODUCTOS[cantidadProductos].cantidad = cantidad;
                        }
                    }while(avanzar == 1);
                    k=26;
                    cantidadProductos++;
            }
            else if (k==25){
                Beep(300,500); // 523 hertz (C5) for 500 milliseconds
                printf("Clave no existente\n");
            }
        }

        if(k==27){
          printf("\n\n%cQuieres agregar otro producto? \n1)Si \nOtra tecla)No \n-> ", 168);
          if(scanf("%d", &salir) == 0){
            fflush(stdin);
            salir = 0;}
        } else if(k==26){
          salir = 1;
        }
    }while(salir==1);
    for (i=0; i<cantidadProductos; i++){
        if (A->facturas[a].MASPRODUCTOS[i].clave !=0){
            if (A->facturas[a].MASPRODUCTOS[i].cantidad>0){
                A->facturas[a].MASPRODUCTOS[i].importe=(A->facturas[a].MASPRODUCTOS[i].precioUnitario*A->facturas[a].MASPRODUCTOS[i].cantidad);
            }
        }
    }
    for (i=0; i<5; i++){
        A->facturas[a].subtotal+=A->facturas[a].MASPRODUCTOS[i].importe;
    }
    A->facturas[a].IVA=(A->facturas[a].subtotal*0.16);
    A->facturas[a].total=(A->facturas[a].subtotal+A->facturas[a].IVA);
    srand (time(NULL));
    do{
        letraNumero=rand() % 10;
        if (letraNumero>=0 && letraNumero<=5){
            firmaDigital[contador] = 48+ rand() % 10;
        }
        if (letraNumero>5 && letraNumero<10){
            firmaDigital[contador] = 65 + rand() % 25;
        }
        contador++;
    }while(contador<70);
    strcpy(A->facturas[a].firma, firmaDigital);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MOSTRAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int mostrar(struct Usuario A, int a){
    system("CLS");
    struct Usuario *DA = &A;
    int longitud1, longitud2, i, contadorCantidad=0;
//~~~~~~~~~~~~~~~~~~~~~~~~~~EMISOR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n\n----------EMISOR----------\n\nNombre de la empresa: %s\n", A.facturas[a].nombreEmisor);
    printf("RFC: %s\n", A.facturas[a].RFCEmisor);
    printf("Domicilio\n-Calle: %s\n", A.facturas[a].domEmisor.calle);
    printf("-N%cmero: %d\n", 163, A.facturas[a].domEmisor.numero);
    printf("-Colonia: %s\n", A.facturas[a].domEmisor.colonia);
    printf("-C%cdigo postal: %d\n", 162, A.facturas[a].domEmisor.codigoPostal);
    printf("-Ciudad: %s\n", A.facturas[a].domEmisor.ciudad);
    printf("-Estado o provincia: %s\n", A.facturas[a].domEmisor.estado);
    printf("-Pa%cs: %s\n", 161, A.facturas[a].domEmisor.pais);


//~~~~~~~~~~~~~~~~~~~~~~REGIMEN FISCAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    longitud1 = strlen(A.facturas[a].RFCEmisor);
    longitud2 = strlen(A.facturas[a].RFCReceptor);
    if(longitud1 == 12){
        printf("\n-PERSONAS MORALES\n\n");
        printf("\nLa persona moral es:  %s ", A.facturas[a].emisorFiscales);
        }

    if(longitud1 == 13){
        printf("\n-PERSONAS FISCALES\n\n");
        printf("\nLa persona fiscal es:  %s ", A.facturas[a].emisorFiscales);
        }


//~~~~~~~~~~~~~~~~~~~~~~~~~~RECEPTOR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n\n-----------RECEPTOR----------\n\nNombre de la empresa: %s\n", A.facturas[a].nombreReceptor);
    printf("RFC: %s\n", A.facturas[a].RFCReceptor);
    printf("\n\nDOMICILIO\n\n-Calle: %s\n", A.facturas[a].domReceptor.calle);
    printf("-N%cmero: %d\n", 163, A.facturas[a].domReceptor.numero);
    printf("-Colonia: %s\n", A.facturas[a].domReceptor.colonia);
    printf("-C%cdigo postal: %d\n", 162, A.facturas[a].domReceptor.codigoPostal);
    printf("-Ciudad: %s\n", A.facturas[a].domReceptor.ciudad);
    printf("-Estado o provincia: %s\n", A.facturas[a].domReceptor.estado);
    printf("-Pa%cs: %s\n", 161, A.facturas[a].domReceptor.pais);

    if(longitud2 == 12){
        printf("\n-PERSONAS MORALES\n\n");
        printf("\nLa persona moral es:  %s ", A.facturas[a].receptorFiscales);
        }

    if(longitud2 == 13){
        printf("\n-PERSONAS FISCALES\n\n");
        printf("\nLa persona fiscal es:  %s \n", A.facturas[a].receptorFiscales);
        }

    printf("\n____________________________________________________________________________________________________________________\n");
    printf("|            |              |                                                    |                 |\t\t    |\n|  Clave     | Cantidad     |\t\t Descripci%cn\t\t\t         | Precio Unitario |     Importe    |", 162);
     printf("\n|____________|______________|____________________________________________________|_________________|________________|\n");
   for (i=0; i<5; i++){
        if (A.facturas[a].MASPRODUCTOS[i].clave !=0){
         //  printf("\nProducto/Servicio %d", i+1);


            printf("| %d   |", A.facturas[a].MASPRODUCTOS[i].clave);
            printf("\t%d" , A.facturas[a].MASPRODUCTOS[i].cantidad);

            int x = 0,OperacionLong2;
            while (A.facturas[a].MASPRODUCTOS[i].cantidad != 0){
                A.facturas[a].MASPRODUCTOS[i].cantidad = A.facturas[a].MASPRODUCTOS[i].cantidad /10;
                x++;
            }

            OperacionLong2 = 10 - x;
			      int lon;
            for(lon=0; lon<=OperacionLong2; lon++) {
                        printf(" ");
                    }

            printf(" |  %s|", A.facturas[a].MASPRODUCTOS[i].nombreDescripcion);

            unsigned long int num = 2, s = 1;
            int r = 10;

            num = A.facturas[a].MASPRODUCTOS[i].precioUnitario;

            for(s = 1000000000; s>10; s/=10){

          		if(num%s == num){
          		  if(num%(s/10) != num)
          				s = 1;
          		}
          		r--;
          	}

            r = 12-r;

            for(r; r>0; r--)
              printf(" ");

            printf("$%.2f |", A.facturas[a].MASPRODUCTOS[i].precioUnitario);

            num = A.facturas[a].MASPRODUCTOS[i].importe;
            r = 10;

            for(s = 1000000000; s>10; s/=10){

          		if(num%s == num){
          		  if(num%(s/10) != num)
          				s = 1;
          		}
          		r--;
          	}

            r = 11-r;

            for(r; r>0; r--)
              printf(" ");

            printf("$%.2f |\n", A.facturas[a].MASPRODUCTOS[i].importe);

        }
   }
printf("|____________|______________|____________________________________________________|_________________|________________|\n");
    printf("\nSubTotal: $%.2f", A.facturas[a].subtotal);
    printf("\nIVA: $%.2f", A.facturas[a].IVA);
    printf("\n__________________________");
    printf("\nTotal: $%.2f\n", A.facturas[a].total);

    printf("\nHora: %s\n", A.facturas[a].hora);
    printf("Su folio: %s\n", A.facturas[a].folio);
    printf("\nFirma: %s\n", A.facturas[a].firma);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BUSCAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int buscar(struct Usuario *A, int cantidadFacturas, int MenuPrincipal){
    int k, encontrado=26, i, j, contadorCantidad=0;
    char folioBuscado[15];
    int longitud3;
    int OperacionLong;
    if (MenuPrincipal!=1){
        printf("\n\n\t\t\t\t\t   Facturas Disponibles\n\n");
        printf("__________________________________________________________________________________________________________________\n");
        printf("|    Folio      |\t\t Descripci%cn producto \t\t        | \t\tEmpresa\t\t\t  |\n", 162);
        printf("|_______________|_______________________________________________________|_________________________________________|\n");
        for (i=0; i<cantidadFacturas; i++){
            for (j=0; j<5; j++){
                if (A->facturas[i].MASPRODUCTOS[j].clave !=0){

                    printf("|%s", A->facturas[i].folio);
                    printf("\t|   %s", A->facturas[i].MASPRODUCTOS[j].nombreDescripcion);
                    printf("\t|   %s", A->facturas[i].nombreEmisor);

                    longitud3 = strlen(A->facturas[i].nombreEmisor);//Mide la longitud de la cadena
                    OperacionLong = 37 - longitud3;
					int lon;
                    for(lon=0; lon<=OperacionLong; lon++) {
                        printf(" ");
                    }
                     printf("|\n");
                }

            }
        }
        printf("|_______________|_______________________________________________________|_________________________________________|");
    }
    if (cantidadFacturas>0){
        printf("\n\nIngresa el folio que quieres usar-> ");
        scanf(" %s",&folioBuscado);
        for (k=0; k<=cantidadFacturas; k++){
            if (strcmpi(A->facturas[k].folio, folioBuscado)==0){
                    printf("\nFolio encontrado\n");
                    encontrado=k;
                    k=22;
            }
            else if (k==cantidadFacturas){
                printf("\nFolio no encontrado\n");
            }
        }
    }
    else{
        printf("\n\nNo hay facturas registradas\n");
    }
    system("pause");
    return encontrado;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ENVIAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int enviar(struct Usuario *A, int cantidadFacturas, int k){
    int Enviar;
    if (cantidadFacturas>0){
        if (A->facturas[k].enviado==0 || A->facturas[k].enviado==2){
            do{
                printf("\n%cQuieres enviar la factura? \n1)Si \n2)No ", 168);
                fflush(stdin);
                scanf("%d",&Enviar);
                if (Enviar!=1 && Enviar!=2){
                    printf("Opci%cn no v%clida\n", 162, 160);
                }
                if (Enviar==1){
                  system("cls");
                  printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t   _______________\n");
                  printf("\t\t\t\t\t\t\t  |               |\n");
                  printf("\t\t\t\t\t\t\t  |               |\n");
                  printf("\t\t\t\t\t\t\t  |               |\n");
                  printf("\t\t\t\t\t\t\t/_|_______________|_\\\n");
                  printf("\t\t\t\t\t\t\t| ====           #  |\n");
                  printf("\t\t\t\t\t\t\t| ====              |\n");
                  printf("\t\t\t\t\t\t\t|___________________|\n");

                  Sleep(500);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t   _______________\n");
                  printf("\t\t\t\t\t\t\t  |               |\n");
                  printf("\t\t\t\t\t\t\t  |               |\n");
                  printf("\t\t\t\t\t\t\t/_|_______________|_\\\n");
                  printf("\t\t\t\t\t\t\t| ====           #  |\n");
                  printf("\t\t\t\t\t\t\t| ====              |\n");
                  printf("\t\t\t\t\t\t\t|___________________|\n");

                  Sleep(50);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t   _______________\n");
                  printf("\t\t\t\t\t\t\t  |               |\n");
                  printf("\t\t\t\t\t\t\t/_|_______________|_\\\n");
                  printf("\t\t\t\t\t\t\t| ====           #  |\n");
                  printf("\t\t\t\t\t\t\t| ====              |\n");
                  printf("\t\t\t\t\t\t\t|___________________|\n");

                  Sleep(50);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t   _______________\n");
                  printf("\t\t\t\t\t\t\t/_|_______________|_\\\n");
                  printf("\t\t\t\t\t\t\t| ====           #  |\n");
                  printf("\t\t\t\t\t\t\t| ====              |\n");
                  printf("\t\t\t\t\t\t\t|___________________|\n");

                  Sleep(50);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t  _________________\n");
                  printf("\t\t\t\t\t\t\t/___________________\\\n");
                  printf("\t\t\t\t\t\t\t| ====           #  |\n");
                  printf("\t\t\t\t\t\t\t| ====              |\n");
                  printf("\t\t\t\t\t\t\t|___________________|\n");

                  Sleep(500);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t ___________________\n");
                  printf("\t\t\t\t\t\t\t| ====           #  |\n");
                  printf("\t\t\t\t\t\t\t| ====              |\n");
                  printf("\t\t\t\t\t\t\t|___________________|\n");

                  Sleep(200);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t ___________\n");
                  printf("\t\t\t\t\t\t\t| ==     #  |\n");
                  printf("\t\t\t\t\t\t\t|___________|\n");

                  Sleep(200);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t ____\n");
                  printf("\t\t\t\t\t\t\t|____|\n");
                  printf("\t\t\t\t\t\t\t\n");

                  Sleep(200);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t          ____________\n");
                  printf("\t\t\t\t\t\t\t ____   /   \\_______   \\\n");
                  printf("\t\t\t\t\t\t\t|____|  |   |      V   |\n");
                  printf("\t\t\t\t\t\t\t        |___|__________|\n");

                  Sleep(200);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t          ____________\n");
                  printf("\t\t\t\t\t\t\t   ____ /   \\_______   \\\n");
                  printf("\t\t\t\t\t\t\t  |____||   |      V   |\n");
                  printf("\t\t\t\t\t\t\t        |___|__________|\n");

                  Sleep(100);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t          ____________\n");
                  printf("\t\t\t\t\t\t\t      __/_  \\_______   \\\n");
                  printf("\t\t\t\t\t\t\t     |____| |      V   |\n");
                  printf("\t\t\t\t\t\t\t        |___|__________|\n");

                  Sleep(100);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t          ____________\n");
                  printf("\t\t\t\t\t\t\t        / __\\_______   \\\n");
                  printf("\t\t\t\t\t\t\t        ||__|      V   |\n");
                  printf("\t\t\t\t\t\t\t        |___|__________|\n");

                  Sleep(100);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t          ____________\n");
                  printf("\t\t\t\t\t\t\t        /   \\_______   \\\n");
                  printf("\t\t\t\t\t\t\t        |  ||      V   |\n");
                  printf("\t\t\t\t\t\t\t        |___|__________|\n");

                  Sleep(100);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t          ____________\n");
                  printf("\t\t\t\t\t\t\t        /   \\_______   \\\n");
                  printf("\t\t\t\t\t\t\t        |   |      V   |\n");
                  printf("\t\t\t\t\t\t\t        |___|__________|\n");

                  Sleep(100);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t               />\n");
                  printf("\t\t\t\t\t\t\t          ____/_______\n");
                  printf("\t\t\t\t\t\t\t        /   \\/         \\\n");
                  printf("\t\t\t\t\t\t\t        |   |          |\n");
                  printf("\t\t\t\t\t\t\t        |___|__________|\n");

                  Sleep(100);
                  system("cls"); printf("\n\n\n\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t             |>\n");
                  printf("\t\t\t\t\t\t\t          ___|________\n");
                  printf("\t\t\t\t\t\t\t        /   \\|         \\\n");
                  printf("\t\t\t\t\t\t\t        |   |          |\n");
                  printf("\t\t\t\t\t\t\t        |___|__________|\n");
                  printf("\t\t\t\t\t\t\t\n");
                  printf("\t\t\t\t\t\t\t  Factura enviada exitosamente.\n\n\n\n\n\n\n");
                  Beep(494,250);
                  Beep(740,250);
                }
            }while(Enviar!=1 && Enviar!=2);
        }
        else{
            printf("\n\nLa factura ya fue enviada.\n\n");
            system("pause");
        }
    }
    else{
        printf("No hay facturas registradas.\n");
    }
    return Enviar;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ELIMINAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int eliminar(struct Usuario *A, int cantidadFacturas, int k){
    int eliminar=0, cantidadProductos=0, cantidadProductos2=0, j;
    if (cantidadFacturas>0){
        printf("\n\n%cEst%c seguro de que quiere eliminar la factura?\nEsta acci%cn no se puede revertir. \n1)Si\nOtra tecla)No \n-> ", 168, 160, 162);
        scanf("%d", &eliminar);
        if (eliminar==1){
            if (A->facturas[k].enviado!=1){
                for (j=0; j<5; j++){
                    if (A->facturas[cantidadFacturas-1].MASPRODUCTOS[j].clave !=0){
                        cantidadProductos++;
                    }
                    if (A->facturas[k].MASPRODUCTOS[j].clave !=0){
                        cantidadProductos2++;
                    }
                }
                if (cantidadProductos<cantidadProductos2){
                    cantidadProductos=cantidadProductos2;
                }
                for (j=0; j<cantidadProductos; j++){
                    A->facturas[k].MASPRODUCTOS[j].clave=A->facturas[cantidadFacturas-1].MASPRODUCTOS[j].clave;
                    strcpy(A->facturas[k].MASPRODUCTOS[j].nombreDescripcion, A->facturas[cantidadFacturas-1].MASPRODUCTOS[j].nombreDescripcion);
                    A->facturas[k].MASPRODUCTOS[j].cantidad=A->facturas[cantidadFacturas-1].MASPRODUCTOS[j].cantidad;
                    A->facturas[k].MASPRODUCTOS[j].precioUnitario=A->facturas[cantidadFacturas-1].MASPRODUCTOS[j].precioUnitario;
                    A->facturas[k].MASPRODUCTOS[j].importe=A->facturas[cantidadFacturas-1].MASPRODUCTOS[j].importe;
                    A->facturas[k].subtotal=A->facturas[cantidadFacturas-1].subtotal;
                    A->facturas[k].IVA=A->facturas[cantidadFacturas-1].IVA;
                    A->facturas[k].total=A->facturas[cantidadFacturas-1].total;
                }
                //Emisor
                strcpy(A->facturas[k].nombreEmisor, A->facturas[cantidadFacturas-1].nombreEmisor);
                strcpy(A->facturas[k].RFCEmisor, A->facturas[cantidadFacturas-1].RFCEmisor);
                strcpy(A->facturas[k].domEmisor.calle, A->facturas[cantidadFacturas-1].domEmisor.calle);
                strcpy(A->facturas[k].domEmisor.ciudad, A->facturas[cantidadFacturas-1].domEmisor.ciudad);
                strcpy(A->facturas[k].domEmisor.colonia, A->facturas[cantidadFacturas-1].domEmisor.colonia);
                strcpy(A->facturas[k].domEmisor.estado, A->facturas[cantidadFacturas-1].domEmisor.estado);
                strcpy(A->facturas[k].domEmisor.pais, A->facturas[cantidadFacturas-1].domEmisor.pais);
                strcpy(A->facturas[k].emisorFiscales, A->facturas[cantidadFacturas-1].emisorFiscales);
                A->facturas[k].domEmisor.numero = A->facturas[cantidadFacturas-1].domEmisor.numero;
                A->facturas[k].domEmisor.codigoPostal = A->facturas[cantidadFacturas-1].domEmisor.codigoPostal;

                //Receptor
                strcpy(A->facturas[k].nombreReceptor, A->facturas[cantidadFacturas-1].nombreReceptor);
                strcpy(A->facturas[k].RFCReceptor, A->facturas[cantidadFacturas-1].RFCReceptor);
                strcpy(A->facturas[k].domReceptor.calle, A->facturas[cantidadFacturas-1].domReceptor.calle);
                strcpy(A->facturas[k].domReceptor.ciudad, A->facturas[cantidadFacturas-1].domReceptor.ciudad);
                strcpy(A->facturas[k].domReceptor.colonia, A->facturas[cantidadFacturas-1].domReceptor.colonia);
                strcpy(A->facturas[k].domReceptor.estado, A->facturas[cantidadFacturas-1].domReceptor.estado);
                strcpy(A->facturas[k].domReceptor.pais, A->facturas[cantidadFacturas-1].domReceptor.pais);
                strcpy(A->facturas[k].receptorFiscales, A->facturas[cantidadFacturas-1].receptorFiscales);
                A->facturas[k].domReceptor.numero = A->facturas[cantidadFacturas-1].domReceptor.numero;
                A->facturas[k].domReceptor.codigoPostal = A->facturas[cantidadFacturas-1].domReceptor.codigoPostal;

                strcpy(A->facturas[k].folio, A->facturas[cantidadFacturas-1].folio);
                A->facturas[k].enviado=A->facturas[cantidadFacturas-1].enviado;
                strcpy(A->facturas[k].hora, A->facturas[cantidadFacturas-1].hora);
                strcpy(A->facturas[k].firma, A->facturas[cantidadFacturas-1].firma);

                cantidadFacturas=cantidadFacturas-2;
                cantidadFacturas++;
                printf("\n\nSe ha eliminado la factura.\n");
            }
            else{
                printf("\n\nNo se puede eliminar la factura porque ya fue enviada.\n");
            }
        }
        else if (eliminar !=1){
            printf("\n\nNo se ha eliminado.\n");
        }
    }
    else{
        printf("\n\nNo hay facturas registradas.\n");
    }
    return cantidadFacturas;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~HORA ACTUAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int tiempo(struct Usuario *A, int a){
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%H:%M:%S",tlocal);
    strcpy(A->facturas[a].hora, output);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INICIO MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {

  system ("COLOR 3F");

  int MenuPrincipal, repetir, entrar=0, cantidadFacturas=0, k, enviado;
  char folioBuscado[15], folioChar[15]={'0','0','0','0','-','2','0','2','1'};
  int folioInt1=0,folioInt2=0,folioInt3=0,folioInt4=0;

  char usuario[LONGITUD + 1]; //Variable temporal para guardar el usuario ingresado
  char clave[LONGCLAVE + 1]; //Variable temporal para guardar la clave ingresada

  int intento = 0, ingresa = 0, i= 0, j = 0, CopiarAnt;
  char caracter;

  struct Usuario USUARIOS[NumUsers];

  //Asignaci�n de datos del primer usuario
  strcpy(USUARIOS[0].usuario, USUARIO);
  strcpy(USUARIOS[0].clave, CLAVE);
  strcpy(USUARIOS[0].qr, QR);
  USUARIOS[0].NumFacturas = 0;

  //Asignaci�n de datos del segundo usuario
  strcpy(USUARIOS[1].usuario, USUARIO2);
  strcpy(USUARIOS[1].clave, CLAVE2);
  strcpy(USUARIOS[1].qr, QR2);
  USUARIOS[1].NumFacturas = 0;

  //Asignaci�n de datos del tercer usuario
  strcpy(USUARIOS[2].usuario, USUARIO3);
  strcpy(USUARIOS[2].clave, CLAVE3);
  strcpy(USUARIOS[2].qr, QR3);
  USUARIOS[2].NumFacturas = 0;


  do{
    system ("COLOR b0");
        //Inicio del programa
    repetir = 0;
    system("cls");
    entrar=0;

    printf("\t\t\t\t\t\t       Los SAT-anes\n\n");

printf("\t\t\t\t\t\t\n");
printf("\t\t\t\t\t\t *                       *\n");
printf("\t\t\t\t\t\t **                     **     \n");
printf("\t\t\t\t\t\t ***                   ***  \n");
printf("\t\t\t\t\t\t ****                 ****        \n");
printf("\t\t\t\t\t\t *************************         \n");
printf("\t\t\t\t\t\t *************************       \n");
printf("\t\t\t\t\t\t *************************     \n");
printf("\t\t\t\t\t\t *************************    \n");
printf("\t\t\t\t\t\t***************************   \n");
printf("\t\t\t\t\t\t***************************   \n");
printf("\t\t\t\t\t\t***************************   \n");
printf("\t\t\t\t\t\t***************************   \n");
printf("\t\t\t\t\t\t *************************    \n");
printf("\t\t\t\t\t\t  ***********************     \n");
printf("\t\t\t\t\t\t    *******************       \n");
printf("\t\t\t\t\t\t      ***************         \n");
printf("\t\t\t\t\t\t          *******             \n");






		printf("\n\n\n\t\t\t\t1)Iniciar Sesion \n\n\t\t\t\t2)Salir\n\n\t\t\t\t->");
		scanf("%d",&entrar);
		if (entrar==1){
            do {
                ingresa = 0;
                i = 0;
                system("cls");
                printf("\t\t\t\t\t\t---------------------\n");
                printf("\t\t\t\t\t\t|\t\t    |");
                printf("\n\t\t\t\t\t\t| INICIO DE SESION  |");
                printf("\n\t\t\t\t\t\t|                   |\n");
                printf("\t\t\t\t\t\t---------------------\n");
                printf("\n\t\t\t\tUSUARIO: ");
                fflush(stdin);
                gets(usuario);
                printf("\n\t\t\t\tCLAVE: ");
                while (caracter = getch()) {

                    if (caracter == TECLA_ENTER) {
                        clave[i] = '\0';
                        break;

                    } else if (caracter == TECLA_BACKSPACE) {
                        if (i > 0) {
                            i--;
                            printf("\b \b");
                        }

                    } else {
                        if (i < LONGCLAVE) {
                            printf("*");
                            clave[i] = caracter;
                            i++;
                        }
                    }
                }

                //Comprobaci�n del usuario en la base de datos

                for(j=0; j<= 2; j++){

                  if (strcmp(usuario, USUARIOS[j].usuario) == 0 && strcmp(clave, USUARIOS[j].clave) == 0){
                      ingresa = 1;
                      break;
                  }

                }

                if(ingresa!=1) {
                    Beep(300,500); // 523 hertz (C5) for 500 milliseconds
                    printf("\n\tUsuario y/o clave son incorrectos.\n\tPresione enter para continuar.\n");
                    intento++;
                    getchar();
                    system("CLS");
                }

            } while (intento < MAX_INTENTOS && ingresa == 0);
            intento = 0;
            //Usuario encontrado
            if (ingresa == 1){
                printf("\n\nAcceso otorgado.\n");
                system("pause");
                for(i=0; i<=1; i++){
                    system("cls");
                    printf("\n\n\t\t\t\t\t\t\t %cHola %s! \\(^o^\\)", 173,usuario);
                    sleep(1);
                    system("cls");
                    printf("\n\n\t\t\t\t\t\t\t %cHola %s! ~(^u^~)", 173,usuario);
                    sleep(1);

                }
                CopiarAnt = 0;
                sleep(1);
            }
            do{
                if (ingresa == 1) {
                    system("cls");

                    system("COLOR FD");
                    system("cls");
                    printf("\t\t\t\t    ---------------------------------------------------------------------\n");
                    printf("\t\t\t\t    |\t\t\t\t");
                    printf("\t\t\t\t        |\n\t\t\t\t    |\t Bienvenido al Sistema de Facturaci%cn Electr%cnica los SAT-anes  |\n",162, 162);//�
                    printf("\t\t\t\t    |\t\t\t\t                             \t\t|\n");
                    printf("\t\t\t\t    ---------------------------------------------------------------------\n");
                    printf("\n\n\t\t\t\tTienda de equipos y suministros para impresi%cn, fotograf%ca y audiovisuales\n\n", 162, 161);

                        printf("\t\t\t\t\t\t           %cSonr%ce! :)\n\n", 173, 161);
                        sleep(3);
                        Beep(523,500); // 523 hertz (C5) for 500 milliseconds

                        printf("\t\t\t\t\t\t\t------------------\n");
                        printf("\t\t\t\t\t\t\t| ||||\t      -- |\n\t\t\t\t\t\t\t|    ______\t |\n\t\t\t\t\t\t\t|   | \\__/ |\t |\n\t\t\t\t\t\t\t|   | |__| |     |\n\t\t\t\t\t\t\t|   | /\t \\ |\t |\n\t\t\t\t\t\t\t|   --------\t |\n");
                        printf("\t\t\t\t\t\t\t------------------");
                        printf("\n\n\t\t\t\t\t\t\t    Foto tomada");
                        sleep(1);


                    printf("\n1)Crear Factura\n");
                    printf("\n2)Mostrar Factura\n");
                    printf("\n3)Enviar Factura\n");
                    printf("\n4)Eliminar Factura\n");
                    printf("\n5)Salir del sistema\n");
                    fflush(stdin);
                    scanf("%d",&MenuPrincipal);

                    switch(MenuPrincipal){
                    case 1:

                        if (folioInt1<9){
                            folioInt1++;
                            }
                        else if (folioInt2<9){
                            folioInt1=0;
                            folioInt2++;
                            }
                            else if (folioInt3<9){
                                folioInt1=0;
                                folioInt2=0;
                                folioInt3++;
                                }
                                else if (folioInt4<9){
                                    folioInt1=0;
                                    folioInt2=0;
                                    folioInt3=0;
                                    folioInt4++;
                                    }
                        folioChar[0]=folioInt4+'0'; //Se le suma el caracter 0 para convertirlo de entero a caracter
                        folioChar[1]=folioInt3+'0'; //Se le suma el caracter 0 para convertirlo de entero a caracter
                        folioChar[2]=folioInt2+'0'; //Se le suma el caracter 0 para convertirlo de entero a caracter
                        folioChar[3]=folioInt1+'0'; //Se le suma el caracter 0 para convertirlo de entero a caracter

                        strcpy(USUARIOS[0].facturas[cantidadFacturas].folio, folioChar);
                        crear(&(USUARIOS[0]), cantidadFacturas, PRODUCTOS, CopiarAnt);
                        tiempo(&(USUARIOS[0]), cantidadFacturas);
                        cantidadFacturas++;
                        CopiarAnt = 1;
                        printf("\n\n-----Datos registrados exitosamente-----.\n");
                        system("pause");
                        mostrar(USUARIOS[0], cantidadFacturas-1);
                        USUARIOS[0].facturas[cantidadFacturas-1].enviado=enviar(&(USUARIOS[0]), cantidadFacturas, cantidadFacturas-1);
                        system("pause");
                    break;

                    case 2:
                        system("pause");
                        system("cls");
                        k=buscar(&(USUARIOS[0]), cantidadFacturas, MenuPrincipal);
                        if (k!=26){
                            mostrar(USUARIOS[0], k);
                            system("pause");
                        }
                    break;

                    case 3:
                        system("pause");
                        system("cls");
                        k=buscar(&(USUARIOS[0]), cantidadFacturas, MenuPrincipal);
                        if (k!=26){
                            mostrar(USUARIOS[0], k);
                            system("pause");
                            USUARIOS[0].facturas[k].enviado=enviar(USUARIOS, cantidadFacturas, k);
                        }
                        sleep(1);

                    break;

                    case 4:
                        system("pause");
                        system("cls");
                        k=buscar(&(USUARIOS[0]), cantidadFacturas, MenuPrincipal);
                        if (k!=26){
                            mostrar(USUARIOS[0], k);
                            system("pause");
                            cantidadFacturas=eliminar(&(USUARIOS[0]), cantidadFacturas, k);
                        }
                        sleep(1);

                    break;

                    case 5:

                        printf("Cerrando sesion...");
                        sleep(1);

                    break;

                    default:

                        Beep(300,500); // 523 hertz (C5) for 500 milliseconds
                        printf("\t\t\t\t\t\tOpci%cn no v%clida\n", 162, 160);
                        fflush( stdin );
                        printf("\n\n");
                        sleep(1);

                    break;
                }
            } else {
                printf("\n\n\tHa sobrepasado el numero m%cximo de intentos permitidos\n", 160);
                sleep(1);
                repetir = 0;
            }
            }while(MenuPrincipal!=5 && ingresa==1);
        } else if (entrar==2) {
            system("cls");
            printf("\n\n\nGracias por utilizar el Sistema de Facturaci%cn Electr%cnica de los SAT-anes\n\n\n",162, 162);//�

system("COLOR F4");
int a, b, line = 12;
   for (a = line/2; a <= line; a = a+2) { //Para la parte superior del corazon
      for (b = 1; b < line-a; b = b+2) //crear espacio antes de la primera prominencia
         printf("  ");
      for (b = 1; b <= a; b++) //imprimir la primera prominencia
        printf(" *");
      for (b = 1; b <= line-a; b++) //crear espacio antes de la segunda prominencia
         printf("  ");
      for (b = 1; b <= a-1; b++) //imprimir la segunda prominencia
         printf(" *");
      printf("\n");
   }
   for (a = line; a >= 0; a--) { //la base del corazon es un triangulo invertido
      for (b = a; b < line; b++) //generar espacio antes del triangulo
         printf("  ");
      for (b = 1; b <= ((a * 2) - 1); b++) //imprimir el triangulo
         printf(" *");
      printf("\n");
   }

   //Cancioncita de Mario Bros para el salir definitivo

   Beep (330,100);Sleep(100);
   Beep (330,100);Sleep(300);
   Beep (330,100);Sleep(300);
   Beep (262,100);Sleep(100);
   Beep (330,100);Sleep(300);
   Beep (392,100);Sleep(700);
   Beep (196,100);Sleep(700);
   Beep (262,300);Sleep(300);
   Beep (196,300);Sleep(300);
   Beep (164,300);Sleep(300);
   Beep (220,300);Sleep(100);
   Beep (246,100);Sleep(300);
   Beep (233,200);
   Beep (220,100);Sleep(300);
   Beep (196,100);Sleep(150);
   Beep (330,100);Sleep(150);
   Beep (392,100);Sleep(150);
   Beep (440,100);Sleep(300);
   Beep (349,100);Sleep(100);
   Beep (392,100);Sleep(300);
   Beep (330,100);Sleep(300);
   Beep (262,100);Sleep(100);
   Beep (294,100);Sleep(100);
   Beep (247,100);Sleep(500);
   Beep (262,300);Sleep(300);
   Beep (196,300);Sleep(300);
   Beep (164,300);Sleep(300);
   Beep (220,300);Sleep(100);
   Beep (246,100);Sleep(300);
   Beep (233,200);
   Beep (220,100);Sleep(300);
   Beep (196,100);Sleep(150);
   Beep (330,100);Sleep(150);
   Beep (392,100);Sleep(150);
   Beep (440,100);Sleep(300);
   Beep (349,100);Sleep(100);
   Beep (392,100);Sleep(300);
   Beep (330,100);Sleep(300);
   Beep (262,100);Sleep(100);
   Beep (294,100);Sleep(100);
   Beep (247,100);Sleep(900);
   Beep (392,100);Sleep(100);
   Beep (370,100);Sleep(100);
   Beep (349,100);Sleep(100);
   Beep (311,100);Sleep(300);
   Beep (330,100);Sleep(300);
   Beep (207,100);Sleep(100);
   Beep (220,100);Sleep(100);
   Beep (262,100);Sleep(300);
   Beep (220,100);Sleep(100);
   Beep (262,100);Sleep(100);
   Beep (294,100);Sleep(500);
   Beep (392,100);Sleep(100);
   Beep (370,100);Sleep(100);
   Beep (349,100);Sleep(100);
   Beep (311,100);Sleep(300);
   Beep (330,100);Sleep(300);
   Beep (523,100);Sleep(300);
   Beep (523,100);Sleep(100);
   Beep (523,100);Sleep(1100);
   Beep (392,100);Sleep(100);
   Beep (370,100);Sleep(100);
   Beep (349,100);Sleep(100);
   Beep (311,100);Sleep(300);
   Beep (330,100);Sleep(300);
   Beep (207,100);Sleep(100);
   Beep (220,100);Sleep(100);
   Beep (262,100);Sleep(300);
   Beep (220,100);Sleep(100);
   Beep (262,100);Sleep(100);
   Beep (294,100);Sleep(500);
   Beep (311,300);Sleep(300);
   Beep (296,300);Sleep(300);
   Beep (262,300);Sleep(1300);
   Beep (262,100);Sleep(100);
   Beep (262,100);Sleep(300);
   Beep (262,100);Sleep(300);
   Beep (262,100);Sleep(100);
   Beep (294,100);Sleep(300);
   Beep (330,200);Sleep(50);
   Beep (262,200);Sleep(50);
   Beep (220,200);Sleep(50);
   Beep (196,100);Sleep(700);
   Beep (262,100);Sleep(100);
   Beep (262,100);Sleep(300);
   Beep (262,100);Sleep(300);
   Beep (262,100);Sleep(100);
   Beep (294,100);Sleep(100);
   Beep (330,100);Sleep(700);
   Beep (440,100);Sleep(300);
   Beep (392,100);Sleep(500);
   Beep (262,100);Sleep(100);
   Beep (262,100);Sleep(300);
   Beep (262,100);Sleep(300);
   Beep (262,100);Sleep(100);
   Beep (294,100);Sleep(300);
   Beep (330,200);Sleep(50);
   Beep (262,200);Sleep(50);
   Beep (220,200);Sleep(50);
   Beep (196,100);Sleep(700);
   /*Intro*/
   Beep (330,100);Sleep(100);
   Beep (330,100);Sleep(300);
   Beep (330,100);Sleep(300);
   Beep (262,100);Sleep(100);
   Beep (330,100);Sleep(300);
   Beep (392,100);Sleep(700);
   Beep (196,100);Sleep(700);
   Beep (196,100);Sleep(125);
   Beep (262,100);Sleep(125);
   Beep (330,100);Sleep(125);
   Beep (392,100);Sleep(125);
   Beep (523,100);Sleep(125);
   Beep (660,100);Sleep(125);
   Beep (784,100);Sleep(575);
   Beep (660,100);Sleep(575);
   Beep (207,100);Sleep(125);
   Beep (262,100);Sleep(125);
   Beep (311,100);Sleep(125);
   Beep (415,100);Sleep(125);
   Beep (523,100);Sleep(125);
   Beep (622,100);Sleep(125);
   Beep (830,100);Sleep(575);
   Beep (622,100);Sleep(575);
   Beep (233,100);Sleep(125);
   Beep (294,100);Sleep(125);
   Beep (349,100);Sleep(125);
   Beep (466,100);Sleep(125);
   Beep (587,100);Sleep(125);
   Beep (698,100);Sleep(125);
   Beep (932,100);Sleep(575);
   Beep (932,100);Sleep(125);
   Beep (932,100);Sleep(125);
   Beep (932,100);Sleep(125);
   Beep (1046,675);



            printf("\n\n............Presiona cualquier tecla para salir.........");
            sleep(1);
            repetir = 1;
            } else{
                printf("Opci%cn no v%clida\n", 162, 160);
                sleep(1);
                repetir = 0;
                Beep(300,500); // 523 hertz (C5) for 500 milliseconds
                fflush( stdin );
            }
    } while (repetir==0);

	return 0;
}
