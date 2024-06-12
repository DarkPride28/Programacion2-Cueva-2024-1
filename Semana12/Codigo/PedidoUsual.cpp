/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PedidoUsual.cpp
 * Author: cueva.r
 * 
 * Created on 5 de junio de 2024, 11:23 AM
 */

#include "PedidoUsual.h"

PedidoUsual::PedidoUsual() {
}

PedidoUsual::PedidoUsual(const PedidoUsual& orig) {
}

PedidoUsual::~PedidoUsual() {
}

void PedidoUsual::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::GetDescuento() const {
    return descuento;
}

void PedidoUsual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::GetFlete() const {
    return flete;
}

void PedidoUsual::lee(int cod, ifstream &arch ){
      arch.get();
      arch >> descuento;
      arch.get();
      arch >> flete;
      Pedidos::lee(cod,arch);
}

void PedidoUsual::actualiza(){
    flete=0;
}

void PedidoUsual::imprime(ofstream&arch,double a,double b){
    Pedidos::imprime(arch,descuento,flete);
    arch << "Descuento: " << descuento<< endl;;
    arch << "Flete : " << flete << endl;;
    
}