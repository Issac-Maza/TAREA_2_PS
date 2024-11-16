#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	char nombre[50];
	char carrera[50];
	int numeroMaterias;
	struct {
		char nombreMateria[50];
		int paralelo;
	} materias[3];
} Profesor;

typedef struct {
	char nombre[50];
	char carrera[50];
	int nivel;
	int numeroMaterias;
	struct {
		char nombreMateria[50];
		int creditos;
	} materias[7];
} Estudiante;

void limpiarBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void registrarProfesor(Profesor *profesor) {

	printf("Nombre del profesor: ");
	fgets(profesor->nombre, 50, stdin);
	strtok(profesor->nombre, "\n");

	printf("Ingrese la carrera del profesor: ");
    	fgets(profesor->carrera, 50, stdin);
    	strtok(profesor->carrera, "\n");

	do{
		printf("Ingrese el número de materias dictando(RECUERDE ELEGIR DE 2 a 3 Materias) : ");
		if (scanf("%d", &profesor->numeroMaterias) != 1) {
			printf("Error: Por favor ingrese un número válido.\n");
			limpiarBuffer();
			continue;
		}
		limpiarBuffer();
	}while(profesor -> numeroMaterias < 2 || profesor -> numeroMaterias > 3);

	for(int i = 0; i < profesor -> numeroMaterias; i++){
		printf("Ingrese el nombre de la materia %d: ", i + 1);
		fgets(profesor->materias[i].nombreMateria, sizeof(profesor->materias[i].nombreMateria), stdin);
		strtok(profesor->materias[i].nombreMateria, "\n");

		printf("Ingrese el paralelo de la materia %d: ", i+1);
		scanf("%d", &profesor->materias[i].paralelo);
        	getchar();
	}
}

void registrarEstudiante(Estudiante *estudiante){

	printf("Nombre del estudiante: ");
	fgets(estudiante->nombre, 50, stdin);
	strtok(estudiante->nombre, "\n");

	printf("Nombre de la carrera: ");
	fgets(estudiante->carrera, 50, stdin);
	strtok(estudiante->carrera, "\n");

	printf("Nivel del estudiante: ");
	while (scanf("%d", &estudiante->nivel) != 1) {
		printf("Error: Por favor ingrese un número válido.\n");
		limpiarBuffer();
	}
	limpiarBuffer();

	do{
		printf("Ingrese el numero de materias a tomar (DE 3 A 7): ");

		if (scanf("%d", &estudiante->numeroMaterias) != 1) {
			printf("Error: Por favor ingrese un número válido.\n");
			limpiarBuffer();
			continue;
		}
		limpiarBuffer();
	}while(estudiante->numeroMaterias < 3 || estudiante->numeroMaterias > 7);

	for(int i = 0; i < estudiante->numeroMaterias; i++){

		printf("Nombre de la materia %d: ", i + 1);
		fgets(estudiante->materias[i].nombreMateria, sizeof(estudiante->materias[i].nombreMateria), stdin);
		strtok(estudiante->materias[i].nombreMateria, "\n");

		printf("Ingrese los credito de la materia %d: ", i + 1);
		while (scanf("%d", &estudiante->materias[i].creditos) != 1) {
			printf("Error: Por favor ingrese un número válido.\n");
			limpiarBuffer();
		}
		limpiarBuffer();
	}
}

void mostrarLaInformacion(int cantidadProfesores, Profesor *profesores, Estudiante *estudiantes, int numeroEstudiantes){
	printf("\n-----------INFORMACION CONSEGUIDA---------------\n");

	for (int i = 0; i < cantidadProfesores; i++) {
        	printf("\nPROFESOR %d:\n", i + 1);
        	printf("NOMBRE: %s\n", profesores[i].nombre);
        	printf("CARRERA: %s\n", profesores[i].carrera);
        	printf("MATERIAS A DICTAR:\n");
		for (int j = 0; j < profesores[i].numeroMaterias; j++) {
			printf("MATERIA %d: %s (PARALELO: %d)\n", j + 1, profesores[i].materias[j].nombreMateria, profesores[i].materias[j].paralelo);
        	}
	}


	for (int i = 0; i < numeroEstudiantes; i++) {
		printf("\nESTUDIANTE %d:\n", i + 1);
		printf("NOMBRE: %s\n", estudiantes[i].nombre);
		printf("CARRERA: %s\n", estudiantes[i].carrera);
		printf("NIVEL: %d\n", estudiantes[i].nivel);
		printf("MATERIAS:\n");
		for (int j = 0; j < estudiantes[i].numeroMaterias; j++) {
			printf("MATERIA %d: %s (CREDITOS: %d)\n", j + 1, estudiantes[i].materias[j].nombreMateria, estudiantes[i].materias[j].creditos);
		}
	}

}

int main(int argc, char *argv[]){

	if(argc < 3){
		printf("Cantidad : %s <personas> <opciones (-p|-e|-a)>\n", argv[0]);
		return 1;
	}

	int cantidad = atoi(argv[1]);

	if(cantidad < 2) {
		printf("La cantidad de personas debe ser si o si ser mayor o igual a 2.\n");
		return 1;
	}

	char *opcion = argv[2];
	Profesor *profesores = NULL;
	Estudiante *estudiantes = NULL;

	if(opcion[1] == 'p'){

		profesores = malloc(cantidad * sizeof(Profesor));
		for(int i = 0; i<cantidad;i++){
			registrarProfesor(&profesores[i]);
		}
		mostrarLaInformacion(cantidad, profesores, NULL, 0);
        	free(profesores);

	}else if(opcion[1] == 'e'){

		estudiantes = malloc(cantidad * sizeof(Estudiante));
		for(int i = 0; i < cantidad; i++) {
			registrarEstudiante(&estudiantes[i]);
		}
		mostrarLaInformacion(0,NULL,estudiantes,cantidad);
		free(estudiantes);

	}else if(opcion[1] == 'a'){

		profesores = malloc(sizeof(Profesor));
		estudiantes = malloc((cantidad - 1) * sizeof(Estudiante));


		registrarProfesor(profesores);

		for(int i = 0; i < cantidad -1; i++){
			registrarEstudiante(&estudiantes[i]);
		}

		mostrarLaInformacion(1, profesores,estudiantes,cantidad -1);
		free(profesores);
		free(estudiantes);

	}else{
		printf("Opción inválida o Incorrecta. Use -p para profesor, -e para estudiante, o -a para ambos.\n");
	}

	return 0;
}
