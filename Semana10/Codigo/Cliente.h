/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: cueva.r
 *
 * Created on 22 de mayo de 2024, 10:15 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>

using namespace std;
class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetNombre(char*);
    void GetNombre(char* cad)const;
    
private:
    int dni;
    char categoria;
    char *nombre;
};
ifstream &operator >> (ifstream &arch,Cliente &cli);
#endif /* CLIENTE_H */

