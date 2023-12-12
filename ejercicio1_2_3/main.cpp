#include <iostream>
#include <cstring> // Para usar strcpy

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

Estudiante copiarEstudiante(const Estudiante& est) {
    Estudiante nuevoEst{est}; // Constructor de copia para realizar la copia
    return nuevoEst;
}

Estudiante estudiante3{"Pedro", 25, 9.7}; // Inicialización directa

void imprimirEstudiante(const Estudiante& est) {
    std::cout << "Nombre: " << est.nombre << ", Edad: " << est.edad << ", Promedio: " << est.promedio << std::endl;
}

void modificarEstudiante(Estudiante& est) {
    est.edad = 30;
}

void imprimirEstudiante2(const Estudiante* est) {
    std::cout << "Nombre: " << est->nombre << ", Edad: " << est->edad << ", Promedio: " << est->promedio << std::endl;
}

int main() {
    Estudiante estudiante1{"Juan", 20, 9.5};

    imprimirEstudiante(estudiante1);

    Estudiante copiaEstudiante = copiarEstudiante(estudiante1);
    imprimirEstudiante(copiaEstudiante);

    modificarEstudiante(estudiante1);
    imprimirEstudiante(estudiante1);

    imprimirEstudiante2(&estudiante1);

    return 0;
}