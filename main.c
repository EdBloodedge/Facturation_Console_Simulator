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
  system ("COLOR 3F");

  //Estructura de usuario.
  struct Usuario{
    char usuario[LONGITUD+1], clave[LONGCLAVE+1], nombre[50], puesto[20];
  }USUARIOS[5]; //Arreglo de usuarios

  //Asignación de datos del primer usuario
  strcpy(USUARIOS[0].usuario, USUARIO);
  strcpy(USUARIOS[0].clave, CLAVE);

  char usuario[LONGITUD + 1]; //Variable temporal para guardar el usuario ingresado
  char clave[LONGCLAVE + 1]; //Variable temporal para guardar la clave ingresada
	int intento = 0;
	int ingresa = 0;
	char caracter;
	int i= 0, j = 0;

  //Inicio del programa
	do {
		i = 0;
		system("cls");
		printf("\n\t\t\tINICIO DE SESION\n");
		printf("\t\t\t---------------\n");
		printf("\n\tUSUARIO: ");
		gets(usuario);
		printf("\tCLAVE: ");
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
			printf("\n\tUsuario y/o clave son incorrectos\n");
			intento++;
			getchar();
		}

	} while (intento < MAX_INTENTOS && ingresa == 0);

  //Usuario encontrado
	if (ingresa == 1) {
		printf("\n\n\tBienvenido al Sistema\n");

        printf("\n1)Salir del sistema\n");
        scanf("%d",&MenuPrincipal);

        switch(MenuPrincipal){
        case 1:

            printf(".........Saliendo del sistema..........\n");

        break;

        }

	} else {
		printf("\n\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
	}



	return 0;
}
