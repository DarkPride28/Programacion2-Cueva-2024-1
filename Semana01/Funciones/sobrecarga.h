/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.h
 * Author: cueva.r
 *
 * Created on 19 de marzo de 2024, 11:39 AM
 */
#include <iostream>

#include "estructura.h"

using namespace std;
#ifndef SOBRECARGA_H
#define SOBRECARGA_H
    void operator << (ostream &out, const tregistro &a );
    void operator ++ (tregistro&a);
    void operator ++ (tregistro&a,int b);
#endif /* SOBRECARGA_H */
