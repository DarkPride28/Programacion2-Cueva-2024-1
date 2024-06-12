/* 
 * File:   Lista.cpp
 * Author: cueva.r
 * 
 * Created on 5 de junio de 2024, 11:28 AM
 */

#include "Lista.h"
#include "PedidoEspecial.h"
#include "PedidoUsual.h"
#include "PedidoEventual.h"

Lista::Lista() {
    lini = nullptr;
    lfin = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::inserta(ifstream&arch){
    int codigo;
    Nodo *nuevo;
    Nodo *p = lini,*rec=NULL;
    
    nuevo = new Nodo;
    
    arch >> codigo;
    if(arch.eof()) return;
    
    if(codigo<400000)
        nuevo->ped = new PedidoEspecial;
   if(codigo>=400000 and codigo<600000)
        nuevo->ped = new PedidoUsual;    
   if(codigo>=600000)
        nuevo->ped = new PedidoEventual;
    
    nuevo->ped->lee(codigo,arch);
    
    while(p){
        if(p->cmp(*nuevo)) break;
        rec=p;
        p=p->sig;
    }
    nuevo->sig = p;
    if(p!=NULL) p->ant = nuevo;
    if(rec == NULL) {
        if(p==NULL) lfin = nuevo;
        lini = nuevo;
    }
    else{   rec->sig = nuevo;
            nuevo->ant = rec;
            if(rec == lfin) lfin = nuevo;
    }    
    
   
}

void Lista::modifica(int dni, int fecha){
    Nodo*rec;
    
    rec = lfin;
    
    while(rec){
        if( rec->ped->GetDni()==dni and 
                rec->ped->GetFecha() < fecha)
            rec->ped->actualiza();
        
        rec = rec->ant;
    }
    
    
}
void Lista::muestra(ofstream& arch){
    class Nodo *p;

    p=lini;
        
    while(p)
    {   p->ped->imprime(arch,0,0);
        p=p->sig;
    }        

}