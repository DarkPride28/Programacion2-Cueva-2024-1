/* 
 * File:   PedidoEspecial.cpp
 * Author: cueva.r
 * 
 * Created on 5 de junio de 2024, 11:20 AM
 */

#include "PedidoEspecial.h"

PedidoEspecial::PedidoEspecial() {
    descuento = 0;
}

PedidoEspecial::PedidoEspecial(const PedidoEspecial& orig) {
}

PedidoEspecial::~PedidoEspecial() {
}

void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}

void PedidoEspecial::lee(int cod, ifstream&arch){
    
    arch.get();
    arch >> descuento;
    Pedidos::lee(cod,arch);
  
}

void PedidoEspecial::imprime(ofstream& arch,double a,double b){
    Pedidos::imprime(arch,descuento,0);
    arch << "Descuento: " << descuento << endl;

}