#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//BASE DE ALUMNOS DE 1P PARA LAS CALIFICACIONES DE LOS ALUMONS-PROYECTO FINAL DE PROGRAMACION ESTRUCTURADA 
  
int main (){
	
// DECLARACIONES DE LAS VARIABLES QUE SE UTILIZARAN EN EL PROGRAMA PARA LA BASE DE DATOS 
	float PROMEDIO; //VARIABLE PARA SACAR EL PROMEDIO DE LAS NOTAS DE LOS ALUMNOS REGISTRADOS EN LA BASE DE DATOS
	char opcion; // ESTA ES LA OPCION QUE SE GUARDARA PARA SABER QUE DESEA HACER EL USUARIO 
	int i, j, a=1;//ESTAS VARIABLES ESTAN GUARDADAS DE ESTA MANERA PARA USARLAS EN CICLOS DURANTE EL PROGRAMA 
	int opcion2; //VARIABLE QUE SE USA PARA ELEGIR EN EL MENU DE LA OPCION NUMERO 5
	char EDITAR[20]; //VARIABLE PARA MODIFICAR LOS DATOS DEL ALUMNADO
	char ENCONTRAR[25];  //VARIABLE PARA BUSCAR LOS DATOSS EN EL ARCHIVO TXT
	char BAJAa[20]; //VARIABLE PARA ELIMINAR UN ALUMNO 
	char MODIFICAR[25];
	char NombreEditado[25];
	char ApellidoEditado[25];
    FILE *archivo;
    archivo= fopen("Base de alumnado del 1P.txt","a+"); 
    fprintf(archivo,"HOJA DE REGISTROS: ");
    fclose(archivo);//Cierra y guarda el archivo

	//estructura para el arreglo para el registro de los alumaos junto con sus calificaciones
	struct alumnos
	{ //estructura de arreglo que sirve para guardar los datos de los alumnos.
	    char NOMBRE[50];
		char APELLIDO[50];
		////char ApellidoMaterno[50];
		float calificacion;
	};
	struct alumnos alumno[100]; 

	while (opcion !=9)
	{
		printf ("1. Registrar alumno\n2. Buscar alumno\n3. Modificar nota\n4. Promedio de notas\n5. Editar alumno\n6. Salir\n7. Limpiar pantalla\n8. Limpiar regristro\n");
		printf("\nElige una opci%cn: ", 162);
		scanf("%s", &opcion);
		 
		 switch (opcion){
		 	case '1':// CASO PARA AGREGAR A UN ALUMNO A LA BASE DE DATOS 
		 	archivo= fopen("Base de alumnado del 1P.txt","a");
			printf("\nA continuaci%cn ingrese los datos.\n", 162);
			printf("Nombre(s): ");
			fgets(alumno[a].NOMBRE,100,stdin);
			fgets(alumno[a].NOMBRE,100,stdin);
			printf("Apellido(s): ");
			fgets(alumno[a].APELLIDO,100,stdin);
			printf("Calificaci%cn: ", 162);
			scanf("%f", &alumno[a].calificacion);
			printf("\nRegistrado con %cxito.\n\n", 130);
		    fprintf(archivo,"\n\nEl nombre: %sApellidos: %sCalificaci%cn: %f\n\n\n",alumno[a].NOMBRE,alumno[a].APELLIDO,162,alumno[a].calificacion);
			fclose(archivo);
			a++;
			break;
		
	
		case '2'://OPCION DE BUSCAR EL ALUMNO YA REGISTRADIO EN LA BASE DE DATOS 
            printf("\nIngrese el alumno a buscar: ");
            fgets(ENCONTRAR,100,stdin);
            fgets(ENCONTRAR,100,stdin);
			for(i=0;i<=25;i++){
				if(strcasecmp(ENCONTRAR,alumno[i].NOMBRE)==0 && alumno[i].calificacion >=70){
                    printf("\nNombre(s): %sApellido(s): %sCalificaci%cn: %f\nLa calificaci%cn es aprobatoria\n\n",alumno[i].NOMBRE,alumno[i].APELLIDO,162,alumno[i].calificacion,162);
					}
            
		else if(strcasecmp(ENCONTRAR,alumno[i].NOMBRE)==0 && alumno[i].calificacion <=69){  
			
		    printf("\nNombre: %sApellido: %sCalificaci%cn: %.2f\nLa calificaci%cn es reprobatoria\n",alumno[i].NOMBRE,alumno[i].APELLIDO,162,alumno[i].calificacion,162);
		    printf("\n");
		    }
		    
            }
		break;
	
	
		case '3'://MODIFICAR LA CALIFICACION DE UN ALUMNO YA REGISTRADO
		    archivo= fopen("Base de alumnado del 1P.txt","a");
			printf("\nIngrese el nombre del estudiante que quiere modificar su nota: ");
            fgets(EDITAR,100,stdin);
            fgets(EDITAR,100,stdin);
			for (i=0;i<=25;i++)
			{
				if (strcmp(EDITAR, alumno[i].NOMBRE) == 0)
					{
					printf("%s%s\n", alumno[i].NOMBRE, alumno[i].APELLIDO);
					printf("Ingrese la nueva nota: ");
					scanf ("%f", &alumno[i].calificacion);
					printf("\nCalificaci%cn actualizada\n\n", 162);
					fprintf(archivo,"\nAlumno Modificado : %s %s \n Calificacion Actual: %f\n",alumno[i].NOMBRE, alumno[i].APELLIDO,alumno[i].calificacion);
					fclose(archivo);
					break;
				    }
			} 
		break;
	
		case '4'://OPCION PARA SACAR EL PROMEDIO GENERAL DEL GRUPO 
			archivo= fopen("Base de alumnado del 1P.txt","a");
		    PROMEDIO=0;
			for (j=1;j<a;j++)
			{
			 PROMEDIO= PROMEDIO + alumno[j].calificacion;
			}
			PROMEDIO=PROMEDIO/(j-1);
	      	printf("\nEl promedio es: %.2f\n\n", PROMEDIO);

	    	fprintf(archivo,"\nLa media: %.2f\n", PROMEDIO);
		    fclose(archivo);
		break;
		
		case '5'://EDITAR EL NOMBRE Y EL APELLIDO DEL ALUMNO Y ELIMINAR EL ALUMNO
			printf("\n%cQu%c desea editar del alumno?\n1. Editar nombre\n2. Eliminar alumno\n3. Regresar\n\nElige una opci%cn: ", 168, 130, 162);
			scanf("%d", &opcion2);
			
			if (opcion2 == 1){
				archivo= fopen("Base de alumnado del 1P.txt","a");
				printf("\nElige el alumno que quieras editar su nombre: ");
				fgets(MODIFICAR,100,stdin);
				fgets(MODIFICAR,100,stdin);
				for (i=0;i<=25;i++){
                    if (strcmp(MODIFICAR, alumno[i].NOMBRE) == 0)
					{
                        printf("\n--Editando nombre--\n", 162);
                        printf("Escribe el nuevo nombre de: %s",alumno[i].NOMBRE);
                        printf("Escribe el nuevo apellido: %s",alumno[i].APELLIDO);
                        printf("\n-Nuevo Nombre:");
                        fgets(NombreEditado,100,stdin);
                        printf("\n-Nuevo Apellido:");
                        fgets(ApellidoEditado,100,stdin);
                        strcpy(alumno[i].NOMBRE,NombreEditado);
                        strcpy(alumno[i].APELLIDO,ApellidoEditado);
                        printf("\nNuevo nombre del alumno: %sApellidos: %sCalificacion: %f\n\n", alumno[i].NOMBRE, alumno[i].APELLIDO,alumno[i].calificacion);
                        fprintf(archivo,"\nNombre del Alumno Modificado : %sApellido: %sCalificacion: %f\n",alumno[i].NOMBRE, alumno[i].APELLIDO,alumno[i].calificacion);
                        fclose(archivo);
					    break;
                    }
                }
			}
			if(opcion2 == 2){
			    archivo= fopen("Base de alumnado del 1P.txt","a");
			 	printf("\nElige el alumno que quieres eliminar: ");
				fgets(BAJAa,100,stdin);
				fgets(BAJAa,100,stdin);
				for (i=0;i<=25;i++){
                    if (strcmp(BAJAa, alumno[i].NOMBRE) == 0){
                        printf("\n--Nombre eliminado--\n", 162);
                        printf("\nNombre del alumno: %sApellidos: %sCalificacion: %f\n\n", alumno[i].NOMBRE, alumno[i].APELLIDO,alumno[i].calificacion);
                        fprintf(archivo,"\nAlumno eliminado : %sApellido: %sCalificacion: %f\n",alumno[i].NOMBRE, alumno[i].APELLIDO,alumno[i].calificacion);
                        //bzero(alumno[i].nombre,i);
                        break; 
                    }
                }
		    }   fclose(archivo);
		 
			
			if (opcion2 ==3){
				printf("\n"); //FUNCION DE REGRESAR AL MENU
				
		    }
		break;
		
		case '6'://opcion para salir 
		return 0;
		break;
		
		
		case '7'://opcion de limpiar la pantalla 
		system("cls");
		break;
		
		case '8'://eliminar la base de datos
	    remove("Base de alumnado del 1P.txt")==-1;//elimina el archivo que ya no es util 
		printf("\n El archivo se a eliminado con exito\n\n");	
		break;
	    }
	}
	getchar();
	getchar();
	fclose(archivo);
	return 0;
}