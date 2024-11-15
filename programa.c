#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nombre[50];
    char carrera[50];
    int numeroMaterias;
    struct {
        char nombreMateria[50];
        char paralelo[10];
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

void registrarProfesor(Profesor *profesor) {
	printf("Ingrese el nombre del profesor: ");
	scanf(" %[^\n]", profesor->nombre);
	printf("Ingrese la carrera del profesor: ");
	scanf(" %[^\n]", profesor->carrera);

	do{
		printf("Ingrese el número de materias dictando(RECUERDE ELEGIR DE 2 a 3 Materias) : ");
		scanf("%d", &profesor->numeroMaterias);
	}while(profesor -> numeroMaterias < 2 || profesor -> numeroMaterias > 3);

	for(int i = 0; i < profesor -> numeroMaterias; i++){
		printf("Ingrese el nombre de la materia %d: ", i + 1)
		scanf(" %[^\n]", profesor->materias[i].nombreMateria);
		printf("Ingrese el paralelo de la materia %d: ", i+1);
		scanf(" %[^\n]", profesor->materias[i].paralelo);
	}
}

void registrarEstudiante(Estudiante *estudiante){
	printf("Nombre del estudiante: ");
	scanf(" %[^\n]", estudiante->nombre);
	printf("Nombre de la carrera: ");
	scanf("%[^\n]", estudiante->carrera);
	printf("Nivel del estudiante: ");
	sacnf("%d", &estudiante->nivel);

	do{
		printf("Ingrese el numero de materias a tomar (DE 3 A 7): ");
		scanf("%d", &estudiante->numeroMaterias);
	}while(estudiante->numeroMaterias < 3 || estudiante->numeroMaterias > 7);

	for(int i = 0; i < estudiante->numeroMaterias; i++){
		printf("Nombre de la materia %d: ", i + 1);
		scanf("%[^\n]", estudiante->materias[i].nombreMateria);
		printf("Ingrese los credito de la materia %d: ", i + 1);
		scanf("%d", &estudiante->materias[i].creditos);
	}
}

void mostrarLaInformacion(int cantidadProfesores, Profesor *profesores, Estudiante *estudiantes, int numeroEstudiantes){
	printf("\n-----------INFORMACION CONSEGUIDA---------------\n");

	for(int i = 0; i < cantidadProfesores; i++){
		printf("\nPROFESOR %d:\n", i + 1);
		printf("NOMBRE: %s\n", profesores[i].nombre);
		printf("CARRERA: %s\n", profesores[i].carrera);
		printf("MATERIAS A DICTAR:\n");
		for(int j = 0; j<profesores[i].numeroMaterias; j++){
			printf("MATERIA %d: %s (PARALELO :%s)\n", j + 1, profesores[i].materias[j].nombreMateria,profesores[i].materias[j].paralelo);

		}

	}

	for(int i = 0; i < numerosEstudiantes; i++){
		printf("\nPROFESOR %d:\n", i + 1);
		printf("NOMBRE: %s\n", estudiantes[i].nombre);
		printf("CARRERA: %s\n", estudiantes[i].nombre);
		printf("NIVEL: %d\n", profesores[i].nivel);
		printf("MATERIAS APROPIADAS:\n");
		for(int j = 0; j < estudiantes[i].numeroMaterias; j++) {
			printf("MATERIA %d: %s (CREDITOS : %d)\n", j+1,estudiantes[i].materias[j].nombreMateria, estudiante[i].materias[j].creditos);
		}
	}
}

int main(int argc, char *argv[]){
	if(argc < 3){
		printf(
	}
}