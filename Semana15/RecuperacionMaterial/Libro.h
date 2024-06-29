/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: cueva
 *
 * Created on 10 de junio de 2024, 10:37 PM
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <fstream>

using namespace std;

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetNombre(char*);
    void GetNombre(char* )const;
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void lee(ifstream&);
    void imprime(ofstream&);
private:
    char *nombre;
    int paginas;
    double peso;
};

#endif /* LIBRO_H */

