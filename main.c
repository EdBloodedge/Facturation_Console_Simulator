#include <stdio.h>
#include <string.h> /* gets, strcmp */
#include <stdlib.h> /* system */

#define USUARIO "Usuario1"
#define CLAVE "contra1"
#define USUARIO2 "Jaimito"
#define CLAVE2 "tangamandapio"

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define NumUsers 5 //Número de usuarios
#define LONGITUD 20 //Longitud usuario
#define LONGCLAVE 15 //Longitud clave
#define LimiteFact 20 //Cantidad maxima de facturas por usuario
#define MAX_INTENTOS 3
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INICIALIZACIÓN DE ESTRUCTURAS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Domicilio
struct domicilio{

  char calle[20], colonia[20], ciudad[20], estado[20], pais[20];
  int numero, codigoPostal;

};

//Facturas
struct factura{

  char logo[20][10], descripcion[30], nombreEmisor[30], RFCEmisor[11], regimenEmisor[20], nombreReceptor[30], RFCReceptor[11];
  int clave, cantidad;
  struct domicilio domEmisor, domReceptor;


};

//Usuario.
struct Usuario{
  char usuario[LONGITUD+1], clave[LONGCLAVE+1], nombre[50], puesto[20];
  struct factura facturas[LimiteFact];
  int cantFacturas;
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CREAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int crear(struct Usuario *A, int a){

  int copiar = 0;

  system("CLS");
  if(a!=0){

    printf("%cDesea usar los datos de emisor de la factura anterior?\n1.-S%c\nOtra tecla.- No\n", 168, 161);
    scanf("d", &copiar);
  }

  printf("Ingrese los siguientes datos.\n");

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

    system("CLS");
    printf("-EMISOR\nNombre de la empresa: ");
    fflush(stdin);
    gets(A->facturas[a].nombreEmisor);
    printf("RFC: ");
    fflush(stdin);
    gets(A->facturas[a].RFCEmisor);
    printf("Domicilio\n-Calle: ");
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
    printf("R%cgimen fiscal: ", 130);
    fflush(stdin);
    gets(A->facturas[a].regimenEmisor);

}

  system("CLS");
  printf("\n\n-RECEPTOR\nNombre de la empresa: ");
  fflush(stdin);
  gets(A->facturas[a].nombreReceptor);
  printf("RFC: ");
  fflush(stdin);
  gets(A->facturas[a].RFCReceptor);
  printf("Domicilio\n-Calle: ");
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
  printf("\n\n-DATOS DEL PRODUCTO\nClave: ");
  fflush(stdin);
  scanf("%d", &(A->facturas[a].clave));
  printf("Cantidad: ");
  fflush(stdin);
  scanf("%d", &(A->facturas[a].cantidad));

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MOSTRAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ENVIAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ELIMINAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INICIO MAIN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {

  system ("COLOR 3F");

  int MenuPrincipal;
  int repetir;
  int entrar=0;

  char usuario[LONGITUD + 1]; //Variable temporal para guardar el usuario ingresado
  char clave[LONGCLAVE + 1]; //Variable temporal para guardar la clave ingresada

  int intento = 0;
  int ingresa = 0;
  char caracter;
  int i= 0, j = 0,SalirDefinifivo;

  struct Usuario USUARIOS[NumUsers];

  //Asignación de datos del primer usuario
  strcpy(USUARIOS[0].usuario, USUARIO);
  strcpy(USUARIOS[0].clave, CLAVE);
  strcpy(USUARIOS[1].usuario, USUARIO2);
  strcpy(USUARIOS[1].clave, CLAVE2);
  USUARIOS[0].cantFacturas = 0;


    do{
        //Inicio del programa
        repetir = 0;
        system("cls");
        entrar=0;
		printf("\n\n\t\t\t\t1)Iniciar Sesion \n\t\t\t\t2)Salir\n\t\t\t\t->");
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

                  if (strcmp(usuario, USUARIOS[j].usuario) == 0 && strcmp(clave, USUARIOS[j].clave) == 0){
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
                        printf("\n\n\t\t\t\t\t\t\t ¡HOLA! (/^o^)/");
                        sleep(1);
                        system("cls");
                        printf("\t\t\t\t     -------------------------------------------------------\n");
                        printf("\t\t\t\t     |\t\t\t\t");
                        printf("\t\t\t   |\n\t\t\t\t     |\t Bienvenido al Sistema de Facturaci%cn Electr%cnica  |\n",162, 162);//ó
                        printf("\t\t\t\t     |\t\t\t\t                           |\n");
                        printf("\t\t\t\t     -------------------------------------------------------\n");
                        sleep(1);
                    }

                    printf("\n1)Crear Factura\n");
                    printf("\n2)Mostrar Factura\n");
                    printf("\n3)Enviar Factura\n");
                    printf("\n4)Eliminar Factura\n");
                    printf("\n5)Salir del sistema\n");
                    scanf("%d",&MenuPrincipal);

                    switch(MenuPrincipal){
                    case 1:

                        crear(&(USUARIOS[j]), USUARIOS[j].cantFacturas);
                        (USUARIOS[j].cantFacturas)++;
                        sleep(1);

                    break;

                    case 2:

                        //mostrar();
                        sleep(1);

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
