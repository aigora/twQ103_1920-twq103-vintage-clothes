#include <stdio.h>
int main (){
	int opcion;
	char username[15], contrasena[15], nombre[30], apellidos[50];
	printf("Usted esta en el menu de opciones\n");
	printf("Seleccione la opcion que desee realizar\n");
	printf(" Pulse 1-> si quiere registrarse\n Pulse 2-> si ya esta registrado y desea iniciar sesion\n Pulse 3-> si quiere acceder a nuestro catalogo\n");
    scanf("%d",&opcion);
    switch(opcion){
    	case 1:
		    printf("Introduzca un nombre de usuario\n");
            scanf("%s", username);
			printf("Introduzca su nombre\n");
			gets(nombre);	
			printf("Introduzca sus apellidos\n");
			gets(apellidos);
			printf("Introduzca una contrasena\n");
			gets(contrasena);
    	    break;
    	case 2:
    		printf("Introduzca su nombre de usuario\n");
            scanf("%s", username);
			printf("Introduzca su contrasena\n");
			scanf("%s",contrasena);
    	 break;
    	case 3:printf("Esta usted en el catalogo");
    	break; 
    	default: 
    	    printf("Introduzca un numero correcto");
    	    break;
	}
}
