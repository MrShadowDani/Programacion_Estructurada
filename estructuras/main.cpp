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
    Estudiante estudiante1{};
    strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 9.5;

    // b. Instanciación de estructuras
    imprimirEstudiante(estudiante1);

    // c. Instanciación con el operador malloc
    auto estudiante2 = static_cast<Estudiante*>(malloc(sizeof(Estudiante)));
    strcpy(estudiante2->nombre, "Ana");
    estudiante2->edad = 22;
    estudiante2->promedio = 9.8;
    imprimirEstudiante(*estudiante2);

    // d. Punteros y estructuras
    auto punteroEst = &estudiante1;
    imprimirEstudiante(*punteroEst);

    // e. Organización de la programación
    // Creación de una lista de estudiantes usando un array
    const int MAX_ESTUDIANTES = 10;
    Estudiante listaEstudiantes[MAX_ESTUDIANTES];
    int cantidadEstudiantes = 0;

    // Función para añadir un estudiante a la lista
    auto agregarEstudiante = [&](const char* nombre, int edad, float promedio) {
        if (cantidadEstudiantes < MAX_ESTUDIANTES) {
            strcpy(listaEstudiantes[cantidadEstudiantes].nombre, nombre);
            listaEstudiantes[cantidadEstudiantes].edad = edad;
            listaEstudiantes[cantidadEstudiantes].promedio = promedio;
            cantidadEstudiantes++;
        } else {
            std::cout << "La lista de estudiantes está llena." << std::endl;
        }
    };

    // Función para ver los estudiantes en la lista
    auto verEstudiantes = [&]() {
        std::cout << "Lista de Estudiantes:" << std::endl;
        for (int i = 0; i < cantidadEstudiantes; ++i) {
            imprimirEstudiante(listaEstudiantes[i]);
        }
    };

    // Función para eliminar un estudiante de la lista
    auto eliminarEstudiante = [&](int indice) {
        if (indice >= 0 && indice < cantidadEstudiantes) {
            for (int i = indice; i < cantidadEstudiantes - 1; ++i) {
                listaEstudiantes[i] = listaEstudiantes[i + 1];
            }
            cantidadEstudiantes--;
        } else {
            std::cout << "Índice inválido." << std::endl;
        }
    };

    // Uso de las funciones para manejar la lista de estudiantes
    agregarEstudiante("Pedro", 21, 8.7);
    agregarEstudiante("María", 19, 9.1);
    verEstudiantes();

    eliminarEstudiante(1);
    verEstudiantes();

    // Liberar memoria reservada con malloc
    free(estudiante2);

    return 0;
}