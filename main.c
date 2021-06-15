#include <stdio.h>
#include <string.h> /* gets, strcmp */
#include <stdlib.h> /* system */

#define USUARIO "Usuario1"
#define CLAVE "contra1"

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 20
#define LONGCLAVE 15
#define MAX_INTENTOS 3

int main() {
    int MenuPrincipal;
    system ("COLOR 3F");
	char usuario[LONGITUD + 1];
	char clave[LONGCLAVE + 1];
	int intento = 0;
	int ingresa = 0;
	char caracter;
	int i = 0;

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

		if (strcmp(usuario, USUARIO) == 0 && strcmp(clave, CLAVE) == 0) {
			ingresa = 1;

		} else {
			printf("\n\tUsuario y/o clave son incorrectos\n");
			intento++;
			getchar();
		}

	} while (intento < MAX_INTENTOS && ingresa == 0);

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
