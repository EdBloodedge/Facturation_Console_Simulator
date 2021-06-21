#include <stdio.h>
#include <string.h> /* gets, strcmp */
#include <stdlib.h> /* system */

#define USUARIO "Usuario1"
#define CLAVE "contra1"

#define USUARIO2 "Jaimito"
#define CLAVE2 "tangamandapio"

#define USUARIO3 "LosSAT-anes"
#define CLAVE3 "SAT-anes"

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define NumUsers 2 //Número de usuarios
#define LONGITUD 20 //Longitud usuario
#define LONGCLAVE 15 //Longitud clave
#define LimiteFact 20 //Cantidad maxima de facturas por usuario
#define MAX_INTENTOS 3
#define Tamanio 1 //Tamaño

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INICIALIZACIÓN DE ESTRUCTURAS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Domicilio
struct domicilio{

  char calle[20], colonia[20], ciudad[20], estado[20], pais[20];
  int numero, codigoPostal;
  int Honorarios, ArrendamientoDeInmuebles, IncorporacionFiscal;
  char personasMorales[20], Asalariado[30], ActividadesEmpresariales[20];

};



//Facturas
struct factura{

  char logo[20][10], descripcion[30], nombreEmisor[30], RFCEmisor[15], regimenEmisor[20], nombreReceptor[30], RFCReceptor[15];
  int clave, cantidad;
  char folio[15], nombreDescripcion[50];
  float precioUnitario, subtotal, IVA, total;
  struct domicilio domEmisor, domReceptor;

};

//Usuario.
struct Usuario{
  char usuario[LONGITUD+1], clave[LONGCLAVE+1], nombre[50], puesto[20];
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

{82131601, 6500.00, "Servivios de fotografia aerea"},
{82131602, 6315.00, "Cinematografia"},
{82131603, 4950.00, "Servicios de produccion de videos"},
{82131604, 3500.00, "Servicios de estudio fotografico o fotos fijas"},
{82131501, 7500.00, "Elaboracion o reproduccion de pelicula fija"},
{82131502, 6315.00, "Elaboracion o reproduccion de peliculas de cine"},
{82131503, 2572.90, "Servicios de microficha"},
{82131504, 175.90, "Separacion de colores"},
{82131505, 3750.00, "Servicio de postproduccion de peliculas"},
{82131506, 2950.00, "Servicio de fotos de graduacion"}
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CREAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int crear(struct Usuario *A, int a, struct producto *B){

  int copiar = 0;
  int longi1 = 0;
  int longi2 = 0;
  int longitud1;
  int longitud2;
  char enye = 168;
  int claveBuscada, k, salir;

  system("CLS");
  if(a!=0){

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
    strcpy(A->facturas[a].regimenEmisor, A->facturas[a-1].regimenEmisor);
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
            printf("\nEl RFC es incorrecto, vuelve a intentarlo\n");
            longi1=2;
        }

    }while (longi1 == 2);

    printf("\n\nDOMICILIO\n\n-Calle: ");
    fflush(stdin);
    gets(A->facturas[a].domEmisor.calle);
    printf("-N%cmero: ", 163);
    fflush(stdin);
    scanf("%d", &(A->facturas[a].domEmisor.numero));
    printf("-Colonia: ");
    fflush(stdin);
    gets(A->facturas[a].domEmisor.colonia);
    printf("-C%cdigo postal: ", 162);
    fflush(stdin);
    scanf("%d", &(A->facturas[a].domEmisor.codigoPostal));
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
    printf("%cQue tipo de personas morales son? (R%cgimen General/ Sin Fines De Lucro): ",enye, 130);
    fflush(stdin);
    gets(A->facturas[a].domEmisor.personasMorales);
    }

  if(longitud1 == 13){
    printf("\n-PERSONAS FISCALES\n\n");
    printf("%cQui%cn es la persona Asalariada? ",enye, 130);
    fflush(stdin);
    gets(A->facturas[a].domEmisor.Asalariado);

    printf("%cCu%cles son los honorarios? ",enye, 160);
    fflush(stdin);
    scanf("%i",&A->facturas[a].domEmisor.Honorarios);

    printf("%cCu%cl es el arrendamiento de inmuebles? ",enye, 160);
    fflush(stdin);
    scanf("%i",&A->facturas[a].domEmisor.ArrendamientoDeInmuebles);

    printf("%cCu%cl es la Incorporacion Fiscal? ",enye, 160);
    fflush(stdin);
    scanf("%i",&A->facturas[a].domEmisor.IncorporacionFiscal);

    printf("%cCu%cles son las Actividades Empresariales? ",enye, 160);
    fflush(stdin);
    gets(A->facturas[a].domEmisor.ActividadesEmpresariales);
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
        printf("\nEl RFC es incorrecto, vuelve a intentarlo\n");
        longi2=2;
    }
  }while (longi2 == 2);

  printf("\nDOMICILICO\n\n-Calle: ");
  fflush(stdin);
  gets(A->facturas[a].domReceptor.calle);
  printf("-N%cmero: ", 163);
  fflush(stdin);
  scanf("%d", &(A->facturas[a].domReceptor.numero));
  printf("-Colonia: ");
  fflush(stdin);
  gets(A->facturas[a].domReceptor.colonia);
  printf("-C%cdigo postal: ", 162);
  fflush(stdin);
  scanf("%d", &(A->facturas[a].domReceptor.codigoPostal));
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
    printf("%cQue tipo de personas morales son? (R%cgimen General/ Sin Fines De Lucro): ",enye, 130);
    fflush(stdin);
    gets(A->facturas[a].domReceptor.personasMorales);
    }

  if(longitud2 == 13){
    printf("\n-PERSONAS FISCALES\n\n");
    printf("%cQui%cn es la persona Asalariada? ",enye, 130);
    fflush(stdin);
    gets(A->facturas[a].domReceptor.Asalariado);

    printf("%cCu%cles son los honorarios? ",enye, 160);
    fflush(stdin);
    scanf("%i",&A->facturas[a].domReceptor.Honorarios);

    printf("%cCu%cl es el arrendamiento de inmuebles? ",enye, 160);
    fflush(stdin);
    scanf("%i",&A->facturas[a].domReceptor.ArrendamientoDeInmuebles);

    printf("%cCu%cl es la Incorporacion Fiscal? ",enye, 160);
    fflush(stdin);
    scanf("%i",&A->facturas[a].domReceptor.IncorporacionFiscal);

    printf("%cCu%cles son las Actividades Empresariales? ",enye, 160);
    fflush(stdin);
    gets(A->facturas[a].domReceptor.ActividadesEmpresariales);
    }

//------------------------------DATOS DE LOS PRODUCTOS Y SERVICIOS---------------------------------------------

    printf("\n\n\n\n-------------PRODUCTOS Y SERVICIOS-----------\n\n");
    printf(" CLAVES           PRODUCTOS\n\n");
    printf("45121503       C%cmaras desechables\n", 160);
    printf("45121504       C%cmaras digitales\n", 160);
    printf("45121505       C%maras cinematogr%cficas\n",160, 160);
    printf("45121506       C%cmaras de video conferencia\n",160);
    printf("45121510       C%cmaras a%creas\n",160, 130);
    printf("45121511       C%cmaras de alta velocidad\n",160);
    printf("45121520       C%cmaras de web\n",160);
    printf("45121521       C%cmaras de inspecci%cn\n",160, 162);
    printf("45121522       C%cmaras infrarrojas\n",160);
    printf("45121523       C%cmaras astron%cmicas\n",160, 162);
    printf("45121601       Flashes o iluminaci%cn para c%cmaras\n",162, 160);
    printf("45121602       Tr%cpodes para c%cmaras (Tripi%cs para c%cmara)\n",161, 160,130, 160);
    printf("45121603       Lentes para c%cmaras\n", 160);
    printf("45121604       Oclusores para c%cmaras\n",160);
    printf("45121605       Marcos de pantalla\n\n\n");

    printf(" CLAVES                SERVICIOS \n\n");
    printf("82131601       Servicios de fotograf%ca a%crea\n",161, 130);
    printf("82131602       Cinematograf%ca\n",161);
    printf("82131603       Servicios de producci%cn de v%cdeos\n",162,161);
    printf("82131604       Servicios de estudio fotogr%cfico o fotos fijas\n",160);
    printf("82131501       Elaboraci%cn o reproducci%cn de pel%ccula fija\n",162, 162, 161);
    printf("82131502       Elaboraci%cn o reproducci%cn de pel%cculas de cine\n",162, 162, 161);
    printf("82131503       Servicios de microficha\n");
    printf("82131504       Separación de colores\n");
    printf("82131505       Servicio de posproducci%cn de pel%cculas\n",162, 160);
    printf("82131506       Servicio de fotos de graduacion\n");

    do{
        salir=0;
        printf("\n\n\n%cQu%c producto(s) o servicio(s) quieres comprar?  ",168, 130);
        fflush(stdin);
        scanf("%d",&claveBuscada);
        for (k=0; k<=25; k++){
            if ((B[k].clave) == claveBuscada){
                    A->facturas[a].clave=B[k].clave;
                    strcpy(A->facturas[a].nombreDescripcion, B[k].descripcion);
                    A->facturas[a].precioUnitario=B[k].precio;
                    printf("Producto/Servicio guardado\n");
                    k=26;
                    salir=1;
            }
            else if (k==25){
                printf("Clave no existente\n");
            }
        }
    }while(salir==0);

    printf("Cantidad: ");
    fflush(stdin);
    scanf("%d", &(A->facturas[a].cantidad));
    if (A->facturas[a].cantidad>0){
        A->facturas[a].subtotal=(A->facturas[a].precioUnitario*A->facturas[a].cantidad);
    }
    A->facturas[a].IVA=(A->facturas[a].subtotal*0.16);
    A->facturas[a].total=(A->facturas[a].subtotal+A->facturas[a].IVA);



}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MOSTRAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int mostrar(struct Usuario *A, int a){
    system("CLS");
    int longitud1;
    int longitud2;
//~~~~~~~~~~~~~~~~~~~~~~~~~~EMISOR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n\n----------EMISOR----------\n\nNombre de la empresa: %s\n", A->facturas[a].nombreEmisor);
    printf("RFC: %s\n", A->facturas[a].RFCEmisor);
    printf("Domicilio\n-Calle: %s\n", A->facturas[a].domEmisor.calle);
    printf("-N%cmero: %d\n", 163, A->facturas[a].domEmisor.numero);
    printf("-Colonia: %s\n", A->facturas[a].domEmisor.colonia);
    printf("-C%cdigo postal: %d\n", 162, A->facturas[a].domEmisor.codigoPostal);
    printf("-Ciudad: %s\n", A->facturas[a].domEmisor.ciudad);
    printf("-Estado o provincia: %s\n", A->facturas[a].domEmisor.estado);
    printf("-Pa%cs: %s\n", 161, A->facturas[a].domEmisor.pais);


//~~~~~~~~~~~~~~~~~~~~~~REGIMEN FISCAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    longitud1 = strlen(A->facturas[a].RFCEmisor);
    longitud2 = strlen(A->facturas[a].RFCEmisor);
    if(longitud1 == 12){
        printf("\n-PERSONAS MORALES\n\n");
        printf("\nLa persona moral es:  %s ", A->facturas[a].domEmisor.personasMorales);
        }

    if(longitud1 == 13){
        printf("\n-PERSONAS FISCALES\n\n");
        printf("\nla persona Asalariada es:  %s ", A->facturas[a].domEmisor.Asalariado);
        printf("\nEl honorario es de:  %i ", A->facturas[a].domEmisor.Honorarios);
        printf("\nEl arrendimento de inmuebles es de:  %i ", A->facturas[a].domEmisor.ArrendamientoDeInmuebles);
        printf("\nLa incorporacion fiscal es de: %i", A->facturas[a].domEmisor.IncorporacionFiscal);
        printf("\nLas actividades empresariales son:  %s ", A->facturas[a].domEmisor.ActividadesEmpresariales);
        }
    printf("\n\n-R%cGIMEN FISCAL\n",144);


//~~~~~~~~~~~~~~~~~~~~~~~~~~RECEPTOR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n\n-----------RECEPTOR----------\n\nNombre de la empresa: %s\n", A->facturas[a].nombreReceptor);
    printf("RFC: %s\n", A->facturas[a].RFCReceptor);
    printf("\n\nDOMICILIO\n\n-Calle: %s\n", A->facturas[a].domReceptor.calle);
    printf("-N%cmero: %d\n", 163, A->facturas[a].domReceptor.numero);
    printf("-Colonia: %s\n", A->facturas[a].domReceptor.colonia);
    printf("-C%cdigo postal: %d\n", 162, A->facturas[a].domReceptor.codigoPostal);
    printf("-Ciudad: %s\n", A->facturas[a].domReceptor.ciudad);
    printf("-Estado o provincia: %s\n", A->facturas[a].domReceptor.estado);
    printf("-Pa%cs: %s\n", 161, A->facturas[a].domReceptor.pais);

    if(longitud2 == 12){
        printf("\n-PERSONAS MORALES\n\n");
        printf("\nLa persona moral es:  %s ", A->facturas[a].domReceptor.personasMorales);
        }

    if(longitud2 == 13){
        printf("\n-PERSONAS FISCALES\n\n");
        printf("\nla persona Asalariada es:  %s ", A->facturas[a].domReceptor.Asalariado);
        printf("\nEl honorario es de:  %i ", A->facturas[a].domReceptor.Honorarios);
        printf("\nEl arrendimento de inmuebles es de:  %i ", A->facturas[a].domReceptor.ArrendamientoDeInmuebles);
        printf("\nLa incorporacion fiscal es de: %i", A->facturas[a].domReceptor.IncorporacionFiscal);
        printf("\nLas actividades empresariales son:  %s ", A->facturas[a].domReceptor.ActividadesEmpresariales);
        }
    printf("\nClave: %d", A->facturas[a].clave);
    printf("\nDescripcion: %s", A->facturas[a].nombreDescripcion);
    printf("\nCantidad: %d", A->facturas[a].cantidad);
    printf("\nPrecio Unitario: %.2f", A->facturas[a].precioUnitario);
    printf("\nSubTotal: %.2f", A->facturas[a].subtotal);
    printf("\nIVA: %.2f", A->facturas[a].IVA);
    printf("\nTotal: %.2f", A->facturas[a].total);
printf("\n\n");

    printf("Su folio: %s\n", A->facturas[a].folio);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BUSCAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int buscar(struct Usuario *A, int cantidadFacturas){
    int k, encontrado=26;
    char folioBuscado[15];
    if (cantidadFacturas>0){
        printf("Ingresa el folio del que quiere consultar-> ");
        scanf(" %s",&folioBuscado);
        for (k=0; k<=cantidadFacturas; k++){
            if (strcmpi(A->facturas[k].folio, folioBuscado)==0){
                    printf("Folio encontrado\n");
                    encontrado=k;
                    k=22;
            }
            else if (k==cantidadFacturas){
                printf("Folio no encontrado\n");
            }
        }
    }
    else{
        printf("No hay facturas registradas\n");
    }
    system("pause");
    return encontrado;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ELIMINAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INICIO MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {

  system ("COLOR 3F");

  int MenuPrincipal;
  int repetir;
  int entrar=0;
  char folioBuscado[15], folioChar[15]={'0','0','0','0','-','2','0','2','1'};
  int folioInt1=0,folioInt2=0,folioInt3=0,folioInt4=0;
  int cantidadFacturas=0,k;

  char usuario[LONGITUD + 1]; //Variable temporal para guardar el usuario ingresado
  char clave[LONGCLAVE + 1]; //Variable temporal para guardar la clave ingresada

  int intento = 0;
  int ingresa = 0;
  char caracter;
  int i= 0, j = 0;

  struct Usuario USUARIOS[NumUsers];

  //Asignación de datos del primer usuario
  strcpy(USUARIOS[0].usuario, USUARIO);
  strcpy(USUARIOS[0].clave, CLAVE);
  strcpy(USUARIOS[1].usuario, USUARIO2);
  strcpy(USUARIOS[1].clave, CLAVE2);
  strcpy(USUARIOS[2].usuario, USUARIO3);
  strcpy(USUARIOS[2].clave, CLAVE3);


  do{
        //Inicio del programa
    repetir = 0;
    system("cls");
    entrar=0;

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

                //Comprobación del usuario en la base de datos

                for(j=0; j<= NumUsers; j++){

                  if (strcmp(usuario, USUARIOS[0].usuario) == 0 && strcmp(clave, USUARIOS[0].clave) == 0){
                      ingresa = 1;
                      break;
                  }

                }

                if(ingresa!=1) {
                    printf("\n\tUsuario y/o clave son incorrectos.\n\tPresione enter para continuar.\n");
                    intento++;
                    getchar();
                    system("CLS");
                }

            } while (intento < MAX_INTENTOS && ingresa == 0);
            intento = 0;
            //Usuario encontrado
            if (ingresa == 1){
                printf("\n\n\tAcceso otorgado.");
                sleep(1);
            }
            do{
                if (ingresa == 1) {
                    system("cls");
                    for(i=0; i<=1; i++){
                        system("cls");
                        printf("\n\n\t\t\t\t\t\t\t %cHOLA! (/^o^)/", 173);
                        sleep(1);
                        system("cls");
                        printf("\t\t\t\t    ---------------------------------------------------------------------\n");
                        printf("\t\t\t\t    |\t\t\t\t");
                        printf("\t\t\t\t        |\n\t\t\t\t    |\t Bienvenido al Sistema de Facturaci%cn Electr%cnica los SAT-anes  |\n",162, 162);//ó
                        printf("\t\t\t\t    |\t\t\t\t                             \t\t|\n");
                        printf("\t\t\t\t     --------------------------------------------------------------------\n");
                        printf("\n\n\t\t\t\tEquipos y Suministros para Impresi%cn, Fotografia y Audiovisuales",162);
                        sleep(1);
                    }

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
                        crear(&(USUARIOS[0]), cantidadFacturas, PRODUCTOS);
                        cantidadFacturas++;
                        printf("\n\n-----Datos registrados exitosamente-----.\n");
                        system("pause");
                        mostrar(USUARIOS, cantidadFacturas-1);
                        system("pause");
                    break;

                    case 2:

                        k=buscar(&(USUARIOS[0]), cantidadFacturas);
                        if (k!=26){
                            mostrar(USUARIOS, k);
                            system("pause");
                        }
                    break;

                    case 3:

                        //enviar();
                        sleep(1);

                    break;

                    case 4:

                        //eliminar();
                        sleep(1);

                    break;

                    case 5:

                        printf("Cerrando sesion...");
                        sleep(1);

                    break;

                    default:

                        printf("Opcion no valida\n");
                        sleep(1);

                    break;
                }
            } else {
                printf("\n\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
                sleep(1);
                repetir = 0;
            }
            }while(MenuPrincipal!=5 && ingresa==1);
        } else if (entrar==2) {
            printf("Saliendo del programa...");
            sleep(1);
            repetir = 1;
            } else{
                printf("Opcion no valida\n");
                sleep(1);
                repetir = 0;
            }
    } while (repetir==0);

	return 0;
}
