/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.h
 * Author: cueva
 *
 * Created on 10 de junio de 2024, 10:35 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <fstream>

using namespace std;

class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void leestante(ifstream &);
    void setCapacidad(double capacidad);
    double getCapacidad() const;
    void setId(int id);
    int getId() const;
    void setClase(char clase);
    char getClase() const;
    void imprime(ofstream &)const;
private:
    char clase;
    int id;
    double capacidad;


};

#endif /* ESTANTE_H */

