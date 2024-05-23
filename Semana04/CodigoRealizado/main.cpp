/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 10 de abril de 2024, 10:26 AM
 */
#include "PunterosGenericos.h"
#include "FuncionesMemoria.h"
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    void *alumnoveces;
    int *alumnos_cod;
    cargarAlumnos(alumnos_cod,"alumnos.csv");
    cargacursos(alumnos_cod,alumnoveces,"Historiadenotas.csv");
    ImprimeAlumno(alumnoveces);
    
    return 0;
}

