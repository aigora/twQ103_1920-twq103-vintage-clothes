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
	char nombre[30];
	char apellido1[50];
	char apellido2[50];
	char contrasena[15];
};

int main (){
	struct TPrenda catalogo[5000];
	struct TUsuario usuarios[1000];
	
	char username1[15], contrasena1[15], username2[15];
	int opcion, nPrendas = 0, nUsuarios = 0, i, longContrasena, comprobar = 0;
	char genero1;
	
	// APERTURA DEL CATALOGO
	FILE * fentrada;
	fentrada = fopen("catalogo.txt", "r");
	if (fentrada == NULL) {
		printf("Error en la apertura del fichero\n");
		return 0;
	}
			
	while (fscanf(fentrada, "%s %s %s %c %c %f %d", catalogo[nPrendas].tipoPrenda, catalogo[nPrendas].descripcion, 
		catalogo[nPrendas].color, &catalogo[nPrendas].talla, &catalogo[nPrendas].genero, &catalogo[nPrendas].precio, &catalogo[nPrendas].udDisponibles) != EOF) {
		nPrendas++;
	} 
	fclose(fentrada);
	
	
	//APERTURA DE LOS USUARIOS
	FILE * pregistro;
	pregistro = fopen("usuarios.txt", "r");
	if (pregistro == NULL) {
		printf("Error en la apertura del fichero\n");
		return 0;
	}
			
	while (fscanf(pregistro, "%s %s %s %s %s", usuarios[nUsuarios].username, usuarios[nUsuarios].nombre, usuarios[nUsuarios].apellido1, usuarios[nUsuarios].apellido2, usuarios[nUsuarios].contrasena ) != EOF) {
		//printf("%s\t %s\t %s\t %s\t %s\n", usuarios[nUsuarios].username, usuarios[nUsuarios].nombre, usuarios[nUsuarios].apellido1, usuarios[nUsuarios].apellido2, usuarios[nUsuarios].contrasena);
		nUsuarios++;
	} 
	//printf("%d\n", nUsuarios);
	fclose(pregistro);
	
	//INICIO DEL PROGRAMA
	printf("Usted esta en vintage clothes\n");
	while (1) {
		
		//MENU DE OPCIONES
		do {
			printf("\n");
			printf("Seleccione la opcion que desee realizar\n");
			printf("\n");
			printf(" Pulse 1---> si quiere registrarse\n Pulse 2---> si ya esta registrado y desea iniciar sesion\n Pulse 3---> si quiere acceder a nuestro catalogo\n pulse 4---> si quiere salir\n");
			printf("\n");
			scanf("%d",&opcion);
		}  while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 );
		
		
		//OPCIONES
		switch(opcion){
    	case 1:
		    //REGISTRO DE NUEVO USUARIO
		    do {
		    	//COMPROBAR SI EL USUARIO EXISTE
		    	printf("Introduzca un nombre de usuario\n");
				scanf("%s", username2);
				for (i = 0; i < nUsuarios; i++) {
					if (strcmp(usuarios[i].username, username2) == 0) {
						printf("El nombre de usuario ya esta cogido, por favor escoja otro nombre de usuario\n");
						break;
					}
				}
			} while (strcmp(usuarios[i].username, username2) == 0);
			
			if (strcmp(usuarios[i].username, username2) != 0) {
				    //nUsuarios++;
					strcpy(usuarios[nUsuarios].username, username2);
			}
            fflush(stdin);
			printf("Introduzca su nombre\n");
			gets(usuarios[nUsuarios].nombre);	
			printf("Introduzca sus 2 apellidos\n");
			scanf("%s %s", usuarios[nUsuarios].apellido1, usuarios[nUsuarios].apellido2);
			fflush(stdin);
			do{
				//COMPROBAR SI LA COTRASEÑA ES MAYOR DE 8 CARACTERES
				printf("Introduzca una contrasena\n");
				gets(usuarios[nUsuarios].contrasena);
				longContrasena = strlen (usuarios[nUsuarios].contrasena);
				if (longContrasena < 8){
				    printf("Su contrasena tiene que tener 8 caracteres o mas\n");
				}	
			}while (longContrasena < 8);
			
			printf("Usted se ha registrado correctamente\n");
			//printf("%d\n", nUsuarios);
			
		break;
    	    
    	case 2:
    		//INICIO DE SESION DEL USUARIO
    		do {
    			comprobar = 0;
    			printf("\n");
    			printf("Introduzca su nombre de usuario\n");
				scanf("%s", username1);
				fflush(stdin);
				printf("Introduzca su contrasena\n");
				scanf("%s",contrasena1);
				fflush(stdin);
				printf("\n");
				for (i = 0; i <= nUsuarios; i++) {
					if (strcmp(usuarios[i].username, username1) == 0 && strcmp(usuarios[i].contrasena, contrasena1) == 0) {
						printf("Usuario y contrasena correcto, usted ha iniciado sesion correctamente...\n");
						comprobar = 1;
						break;
					}	
				}
				if (comprobar == 0) {
						printf("Usuario o contrasena incorrecto, porfavor vuelva intentarlo...\n");
					}
			} while (strcmp(usuarios[i].username, username1) != 0 || strcmp(usuarios[i].contrasena, contrasena1) != 0);
    		
			
    	break;
    	    
    	case 3:
    		//ENSEÑAR EL CATALOGO
    		printf("\n");
		    printf("Esta usted en el catalogo\n");
		    
			//printf("%d", nPrendas);	
			do {
				fflush(stdin);
				printf("\n");
				printf("Introduzca si quiere ver ropa de hombre (H) o mujer (M)\n");
				scanf("%c", &genero1);
				printf("\n");
				
				if (genero1 == 'H' || genero1 == 'M') {
					printf("TIPO DE PRENDA\t  DESCRIPCION\t  COLOR\t  TALLA\t  PRECIO      UNIDADES DISPONIBLES\n");
					printf("\n");
					for (i = 0; i < nPrendas; i++) {
						if (catalogo[i].genero == genero1) {
							printf("%s\t %s\t %s\t %c\t %.2f\t %d\n", catalogo[i].tipoPrenda, catalogo[i].descripcion, catalogo[i].color, catalogo[i].talla, catalogo[i].precio, catalogo[i].udDisponibles);
						}
					}
				}
			} while (genero1 != 'M' && genero1 != 'H');	
			
    	break; 
    	    
    	case 4:
    		//SALIR DEL PROGAMA
    		printf("Hasta pronto...\n");
    		fflush(stdin);
    		printf("\n");
    		/*for (i= 0; i <= nUsuarios; i++) {
    			printf("%s %s %s %s %s\n", usuarios[i].username, usuarios[i].nombre, usuarios[i].apellido1, usuarios[i].apellido2, usuarios[i].contrasena);
			}*/
    		
    		//REESCRIBIR EL FICHERO USUARIOS
    		FILE * pfregistro;
    		pfregistro = fopen("usuarios.txt", "w"); 
    		
    		for (i= 0; i <= nUsuarios; i++) {
    			fprintf(pfregistro, "%s %s %s %s %s\n", usuarios[i].username, usuarios[i].nombre, usuarios[i].apellido1, usuarios[i].apellido2, usuarios[i].contrasena);
			}
    		fclose(pfregistro);
    		
    		fflush(stdin);
    		
    		//REESCRIBIR EL FICHERO CATALOGO
    		FILE * pfcatalogo;
    		pfcatalogo = fopen("catalogo.txt", "w"); 
    		for (i = 0; i < nPrendas; i++) {
    			fprintf(pfcatalogo, "%s %s %s %c %c %f %d\n", catalogo[i].tipoPrenda, catalogo[i].descripcion, catalogo[i].color, catalogo[i].talla, catalogo[i].genero, catalogo[i].precio, catalogo[i].udDisponibles);
			}
    		fclose(pfcatalogo);
    		return 0;
    		
    	break;
    		
    	default: 
    	    printf("Introduzca un numero correcto");
    	break;
		}
    }
    
	return 0;
}
