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
#define NumUsers 5 //Número de usuarios
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

};
//Facturas
struct factura{

  char logo[20][10], descripcion[30], nombreEmisor[30], RFCEmisor[11], regimenEmisor[20], nombreReceptor[30], RFCReceptor[11];
  char personasMorales[20], Asalariado[30], ActividadesEmpresariales[20];
  int Honorarios, ArrendamientoDeInmuebles, IncorporacionFiscal;
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
  int longi1 = 0;
  int longi2 = 0;
  int longitud1;
  int longitud2;

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
    gets(A->facturas[a].RFCReceptor);
    longitud1 = strlen(A->facturas[a].RFCReceptor);//Mide la longitud de la cadena
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
  char enye = 168;

  if(longitud1 == 12){
  printf("\n-PERSONAS MORALES\n\n");
  printf("%cQue tipo de personas morales son? (R%cgimen General/ Sin Fines De Lucro): ",enye, 130);
  fflush(stdin);
  gets(A->facturas[a].personasMorales);
  }

  if(longitud1 == 13){
  printf("\n-PERSONAS FISCALES\n\n");
  printf("%cQui%cn es la persona Asalariada? ",enye, 130);
  fflush(stdin);
  gets(A->facturas[a].Asalariado);

  printf("%cCu%cles son los honorarios? ",enye, 160);
  fflush(stdin);
  scanf("%i",&A->facturas[a].Honorarios);

  printf("%cCu%cl es el arrendamiento de inmuebles? ",enye, 160);
  fflush(stdin);
  scanf("%i",&A->facturas[a].ArrendamientoDeInmuebles);

  printf("%cCu%cl es la Incorporacion Fiscal? ",enye, 160);
  fflush(stdin);
  scanf("%i",&A->facturas[a].IncorporacionFiscal);

  printf("%cCu%cles son las Actividades Empresariales? ",enye, 160);
  fflush(stdin);
  gets(A->facturas[a].ActividadesEmpresariales);
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
  printf("-------DATOS DEL PRODUCTO------\n\nClave: ");
  fflush(stdin);
  scanf("%d", &(A->facturas[a].clave));
  printf("Cantidad: ");
  fflush(stdin);
  scanf("%d", &(A->facturas[a].cantidad));

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MOSTRAR FACTURA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



int mostrar(struct Usuario *A, int a){
//~~~~~~~~~~~~~~~~~~~~~~~~~~EMISOR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n\n----------EMISOR----------\n\nNombre de la empresa: %s\n", A->facturas[a].nombreEmisor);
    printf("RFC: %s\n", A->facturas[a].RFCEmisor);
    printf("Domicilio\n-Calle: %s\n", A->facturas[a].domReceptor.calle);
    printf("-N%cmero: %d\n", 163, A->facturas[a].domEmisor.numero);
    printf("-Colonia: %s\n", A->facturas[a].domEmisor.colonia);
    printf("-C%cdigo postal: %d\n", 162, A->facturas[a].domEmisor.codigoPostal);
    printf("-Ciudad: %s\n", A->facturas[a].domEmisor.ciudad);
    printf("-Estado o provincia: %s\n", A->facturas[a].domEmisor.estado);
    printf("-Pa%cs: %s\n", 161, A->facturas[a].domEmisor.pais);


//~~~~~~~~~~~~~~~~~~~~~~REGIMEN FISCAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n\n-R%cGIMEN FISCAL\n",144);
    printf("\nLa persona moral es:  %s ", A->facturas[a].personasMorales);
    printf("\nla persona Asalariada es:  %s ", A->facturas[a].Asalariado);
    printf("\nEl honorario es de:  %i ", A->facturas[a].Honorarios);
    printf("\nEl arrendimento de inmuebles es de:  %i ", A->facturas[a].ArrendamientoDeInmuebles);
    printf("\nLa incorporacion fiscal es de: %i", A->facturas[a].IncorporacionFiscal);
    printf("\nLas actividades empresariales son:  %s ", A->facturas[a].ActividadesEmpresariales);

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


//~~~~~~~~~~~~~~~~~~~~~~~~~~PRODUCTO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("\n\n\n--------DATOS DEL PRODUCTO---------\n\nClave: %d\n", A->facturas[a].clave);
    printf("Cantidad: %d\n", A->facturas[a].cantidad);
}

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
  strcpy(USUARIOS[2].usuario, USUARIO3);
  strcpy(USUARIOS[2].clave, CLAVE3);

  USUARIOS[0].cantFacturas = 0;


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
                        printf("\n\n\t\t\t\t\t\t\t %cHOLA! (/^o^)/", 173);
                        sleep(1);
                        system("cls");
                        printf("\t\t\t\t    ---------------------------------------------------------------------\n");
                        printf("\t\t\t\t    |\t\t\t\t");
                        printf("\t\t\t\t        |\n\t\t\t\t    |\t Bienvenido al Sistema de Facturaci%cn Electr%cnica los SAT-anes  |\n",162, 162);//ó
                        printf("\t\t\t\t    |\t\t\t\t                             \t\t|\n");
                        printf("\t\t\t\t     --------------------------------------------------------------------\n");
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

                      crear(&(USUARIOS[j]), USUARIOS[j].cantFacturas);
                      //(USUARIOS[j].cantFacturas)++;
                      printf("\n\n-----Datos registrados exitosamente-----.\n");
                        system("pause");

                    break;

                    case 2:

                      mostrar(&(USUARIOS[j]), USUARIOS[j].cantFacturas);
                      system("pause");

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
