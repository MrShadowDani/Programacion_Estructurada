#include <iostream>
#include <cstring> // Para usar strcpy

union Dato {
    int i;
    float f;
    char str[20];
};

int main() {
    union Dato dato;

    dato.i = 10;
    std::cout << "dato.i: " << dato.i << std::endl;

    dato.f = 220.5;
    std::cout << "dato.f: " << dato.f << std::endl;

    // Uso seguro de strcpy para evitar desbordamiento de memoria
    strncpy(dato.str, "C programming", sizeof(dato.str) - 1);
    dato.str[sizeof(dato.str) - 1] = '\0'; // Asegurar que la cadena esté terminada correctamente
    std::cout << "dato.str: " << dato.str << std::endl;

    return 0;
}