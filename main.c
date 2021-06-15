#include <stdio.h>
#include <string.h> /* gets, strcmp */
#include <stdlib.h> /* system */

#define USUARIO "Usuario1"
#define CLAVE "contra1"

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define NumUsers 5 //Número de usuarios
#define LONGITUD 20 //Longitud usuario
#define LONGCLAVE 15 //Longitud clave
#define MAX_INTENTOS 3

int main() {

  int MenuPrincipal;
  int repetir;
  int entrar=0;

  char usuario[LONGITUD + 1]; //Variable temporal para guardar el usuario ingresado
  char clave[LONGCLAVE + 1]; //Variable temporal para guardar la clave ingresada

  int intento = 0;
  int ingresa = 0;
  char caracter;
  int i= 0, j = 0,SalirDefinifivo;

  system ("COLOR 3F");

  //Estructura de usuario.
  struct Usuario{
    char usuario[LONGITUD+1], clave[LONGCLAVE+1], nombre[50], puesto[20];
  }USUARIOS[5]; //Arreglo de usuarios

  //Asignación de datos del primer usuario
  strcpy(USUARIOS[0].usuario, USUARIO);
  strcpy(USUARIOS[0].clave, CLAVE);

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
                if (strcmp(usuario, USUARIOS[0].usuario) == 0 && strcmp(clave, USUARIOS[0].clave) == 0) {
                    ingresa = 1;

                } else {
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
                    printf("\n\n\t\t\t\t\tBienvenido al Sistema\n");

                    printf("\n1)Crear Factura\n");
                    printf("\n2)Mostrar Factura\n");
                    printf("\n3)Enviar Factura\n");
                    printf("\n4)Eliminar Factura\n");
                    printf("\n5)Salir del sistema\n");
                    scanf("%d",&MenuPrincipal);

                    switch(MenuPrincipal){
                    case 1:

                        printf("Crear Factura\n");
                        sleep(1);

                    break;

                    case 2:

                        printf("Mostrar Factura\n");
                        sleep(1);

                    break;

                    case 3:

                        printf("Enviar Factura\n");
                        sleep(1);

                    break;

                    case 4:

                        printf("Eliminar Factura\n");
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
