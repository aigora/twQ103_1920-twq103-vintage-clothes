#include <stdio.h>
#include <string.h>

struct TPrenda {
	char tipoPrenda[100];
	char descripcion[200];
	char color[50];
	char talla;
	char genero;
	float precio;
	int udDisponibles;
};

struct TUsuario {
	char username[15];
	char contrasena[15];
	char nombre[30];
	char apellido1[50];
	char apellido2[50];
};

int main (){
	struct TPrenda catalogo[700];
	struct TUsuario usuarios[500];
	
	char username1[15], contrasena1[15];
	int opcion, nPrendas = 0, nUsuarios = 0, i;
	char genero1;
	
	printf("Usted esta en vintage clothes\n");
	while (1) {
		do {
			printf("\n");
			printf("Seleccione la opcion que desee realizar\n");
			printf("\n");
			printf(" Pulse 1-> si quiere registrarse\n Pulse 2-> si ya esta registrado y desea iniciar sesion\n Pulse 3-> si quiere acceder a nuestro catalogo\n pulse 4-> si quiere salir\n");
			scanf("%d",&opcion);
		}  while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 );
	
	
    
    switch(opcion){
    	case 1:
		    printf("Introduzca un nombre de usuario\n");
            scanf("%s", usuarios[nUsuarios].username);
            fflush(stdin);
			printf("Introduzca su nombre\n");
			gets(usuarios[nUsuarios].nombre);	
			printf("Introduzca sus apellidos\n");
			scanf("%s %s", usuarios[nUsuarios].apellido1, usuarios[nUsuarios].apellido2);
			fflush(stdin);
			printf("Introduzca una contrasena\n");
			gets(usuarios[nUsuarios].contrasena);
			nUsuarios++;
			
			FILE*pfichero;
			pfichero = fopen("usuarios.txt", "a");
			
			if (pfichero == NULL) {
			    printf("Error en la creacion del fichero\n");
				return 0;
			}
				
    	    break;
    	    
    	case 2:
    		printf("Introduzca su nombre de usuario\n");
            scanf("%s", username1);
            fflush(stdin);
			printf("Introduzca su contrasena\n");
			scanf("%s",contrasena1);
			fflush(stdin);
    	    break;
    	    
    	case 3:
    		printf("\n");
		    printf("Esta usted en el catalogo\n");
		    FILE * fentrada;
		    fentrada = fopen("catalogo.txt", "r");
		    if (fentrada == NULL) {
			    printf("Error en la apertura del fichero\n");
				return 0;
			}
			
			while (fscanf(fentrada, "%s %s %s %c %c %.2f %d", catalogo[nPrendas].tipoPrenda, catalogo[nPrendas].descripcion, 
			catalogo[nPrendas].color, &catalogo[nPrendas].talla, &catalogo[nPrendas].genero, &catalogo[nPrendas].precio, &catalogo[nPrendas].udDisponibles) != EOF) {
				//printf("%s\t %s\t %s\t %c\t %c\t %f\t %d\n", catalogo[nPrendas].tipoPrenda, catalogo[nPrendas].descripcion, catalogo[nPrendas].color, catalogo[nPrendas].talla, catalogo[nPrendas].genero, catalogo[nPrendas].precio, catalogo[nPrendas].udDisponibles);
				nPrendas++;
	        } 
			fclose(fentrada);
				
			do {
				fflush(stdin);
				printf("\n");
				printf("Introduzca si quiere ver ropa de hombre (H) o mujer (M)\n");
				scanf("%c", &genero1);
				printf("\n");
				
				if (genero1 == 'H' || genero1 == 'M') {
					for (i = 0; i < nPrendas; i++) {
						if (catalogo[i].genero == genero1) {
							printf("%s\t %s\t %s\t %c\t %.2f\t %d\n", catalogo[i].tipoPrenda, catalogo[i].descripcion, catalogo[i].color, catalogo[i].talla, catalogo[i].precio, catalogo[i].udDisponibles);
						}
					}
				}
			} while (genero1 != 'M' && genero1 != 'H');	
			
    	    break; 
    	    
    	case 4:
    		printf("Hasta pronto.\n");
    		break;
    		
    	default: 
    	    printf("Introduzca un numero correcto");
    	    break;
	}
    }
	return 0;
}
