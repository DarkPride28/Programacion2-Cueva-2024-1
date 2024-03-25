/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.cpp
 * Author: cueva.r
 * 
 * Created on 19 de marzo de 2024, 11:39 AM
 */
#include <iostream>
#include <iomanip>
#include "sobrecarga.h"
#include "estructura.h"

using namespace std;

void operator << (ostream &out, const tregistro&a ){
      
    for(int i=0;i<a.n;i++)
        out << setw(4)<<a.lab[i];
    out << endl;
//    return out;
}

void operator ++ (tregistro&a){
    
    for(int i=0;i<a.n;i++)
        a.lab[i]++;
}
void operator ++ (tregistro&a,int b){
    
    for(int i=0;i<a.n;i++)
        a.lab[i]+=2;
}
