#include <iostream>
#include <cstring> // Para usar strcpy
#include <cstdlib> // Para usar malloc y free

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

// Función para imprimir los datos de un estudiante
void imprimirEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << ", Edad: " << estudiante.edad << ", Promedio: " << estudiante.promedio << std::endl;
}

int main() {
    // a. Constitución de una estructura
    Estudiante estudiante1;
    strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 9.5;