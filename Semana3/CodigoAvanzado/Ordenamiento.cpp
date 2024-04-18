/* 
 * File:   Ordenamiento.cpp
 * Author: cueva
 * 
 * Created on 18 de abril de 2024, 10:22 AM
 */

#include "Ordenamiento.h"


void ordenar(double *datos,char***datoscad){ 
    int numDat=0;
    while(datos[numDat]!=-1)numDat++;
        qSort(datos,datoscad,0, numDat-1);
  } 
 
  void qSort(double *datos,char***datoscad, int izq, int der){
    int limite,pos;
    if(izq >= der)return; 
    pos =(izq+der)/2; 
    cambiar(datos[izq],datos[pos],datoscad[izq],datoscad[pos]);
    limite = izq; 
    for(int i=izq+1;i<=der; i++)
        if(datos[i]<datos[izq]){  
             limite++; 
             cambiar(datos[limite],datos[i],datoscad[limite],datoscad[i]);
         }
    cambiar(datos[limite],datos[izq],datoscad[limite],datoscad[izq]);
    qSort(datos,datoscad,izq,limite-1);
    qSort(datos,datoscad,limite+1,der);
  }


void cambiar(double &datoI,double &datoK,char**&datocadI,char **&datocadK ){
    int aux;
    char **auxcad;
    aux=datoI;
    datoI = datoK;
    datoK = aux;
     
    auxcad=datocadI;
    datocadI=datocadK;
    datocadK=auxcad;
     
 }