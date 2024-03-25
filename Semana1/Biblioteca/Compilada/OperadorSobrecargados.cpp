/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OperadorSobrecargados.cpp
 * Author: cueva.r
 * 
 * Created on 20 de marzo de 2024, 11:12 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "OperadorSobrecargados.h"
#include "Estructuras.h"

using namespace std;


void operator *=( StAlumno*arralu, StRegistroDeMatricula &reg){
    int nuevo=1;
    
    for(int i=0;arralu[i].semestre!=0;i++){
        if(arralu[i].codigo==reg.codigodelAlumno &&
                arralu[i].semestre==reg.semestreDelAlumno){
            for(int j=0;j<arralu[i].numeroDeCursos;j++){
                if(strcmp(arralu[i].cursos[j],reg.codigoDelCurso)==0){
                    nuevo=0;
                    break;
                }
            }
            if(nuevo){
                arralu[i].cursos[arralu[i].numeroDeCursos]=
                        new char[strlen(reg.codigoDelCurso)+1];
                        
                strcpy(arralu[i].cursos[arralu[i].numeroDeCursos],
                        reg.codigoDelCurso);        
                arralu[i].numeroDeCursos++;
            }
            break;
        }

    }
}




void operator *=( StCurso*arrcur,
         StRegistroDeMatricula &reg){
    int i,nuevo=1;
    
    for(i=0;strcmp(arrcur[i].codigoDelCurso,"XXXXXX")!=0;i++){
        if(strcmp(arrcur[i].codigoDelCurso,reg.codigoDelCurso)==0){
            for(int j=0;j<arrcur[i].numeroDeAlumnos;j++){
                if(arrcur[i].alumnos[j]%10000==reg.codigodelAlumno &&
                        arrcur[i].alumnos[j]/10000==reg.semestreDelAlumno){
                    nuevo=0;
                    break;
                }
            }
            if(nuevo){
                arrcur[i].alumnos[arrcur[i].numeroDeAlumnos]=
                        reg.semestreDelAlumno*10000+reg.codigodelAlumno;
                arrcur[i].numeroDeAlumnos++;
            }
            break;
        }
    }
}



void operator +=(struct StAlumno *arralu, StAlumno &alu){
    int i;
    for(i=0;arralu[i].semestre!=0;i++);
    arralu[i]=alu;    
    arralu[i+1].semestre = 0;
}

/*
INF263   20231,8320
MEC289   20231,2000
INF263     20212,5400
*/
bool operator >>(ifstream &arch, StRegistroDeMatricula &mat){
    char car;
    arch >> mat.codigoDelCurso;
    if(arch.eof()) return false;
    arch >> mat.semestreDelAlumno >> car >> mat.codigodelAlumno;
    return true;
    
}




/*
20211,1260   GORDILLO/CASTRO/RONAL          G2
20211,1397   ZEVALLOS/PRADO/RICARDO   S   50   G2
20211,2598   MORI/ZAVALETA/LUZ-LOURDES   S   20   G1
20211,2887   CABRERA/AGUERO/JESSICA   S   50   G2
*/
bool operator >>(ifstream &arch, StAlumno &alu){
    char car;
    
    arch >> alu.semestre;
    if(arch.eof()) return false;
    arch >> car >> alu.codigo >> alu.nombre >> car;
    if(car=='G')
        strcpy(alu.modalidad,"PRESENCIAL");
    if(car=='V'){
        strcpy(alu.modalidad,"VIRTUAL");
        arch >> car;
    }
    if(car=='S'){
        strcpy(alu.modalidad,"SEMIPRESENCIAL");
        arch >> alu.porcentaje >> car;
    }
    arch >> alu.escala;
    alu.numeroDeCursos = 0;
    alu.costoTotal = 0;
    return true;
}


void operator<<(ofstream&arch,const  StAlumno &alu){
    int i;
    arch<<left<<setw(15)<<"SEMESTRE"<<setw(15)<<"CODIGO"<<
            setw(50)<<"NOMBRE"<<setw(35)<<"MODALIDAD"<<"ESCALA"<<endl;
    arch<<left<<setw(15)<<alu.semestre<<setw(15)<<alu.codigo<<
            setw(50)<<alu.nombre<<setw(20)<<alu.modalidad;
    if(alu.modalidad[0]=='S'){
        arch<<" CON "<<alu.porcentaje<<"%";
    }
    else
        arch<<setw(8)<<" ";
    arch<<right<<setw(10)<<alu.escala<<endl;
    arch<<"Codigos de cursos matriculados:"<<endl;
    for(i=0;i<alu.numeroDeCursos;i++){
        arch<<setw(15)<<" "<<alu.cursos[i]<<endl;
    }
    arch<<setw(2)<<" "<<left<<setw(25)<<"Numero de Cursos: "<<right<<
            setw(10)<<alu.numeroDeCursos<<endl;
    arch<<setw(2)<<" "<<left<<setw(25)<<"Costo total: "<<right<<
            setw(10)<<alu.costoTotal<<endl;
    
}

void operator<<(ofstream&arch,const  StCurso &curso){
    int i;
    arch<<left<<setw(20)<<"CODIGO"<<setw(30)<<"NOMBRE"<<"CREDITOS"<<endl;
    arch<<left<<setw(20)<<curso.codigoDelCurso<<setw(25)<<
            curso.nombreDelCurso<<right<<fixed<<setprecision(2)<<setw(5)<<
            curso.creditos<<endl;
    arch<<left<<setw(15)<<"PROFESOR:"<<curso.nombreDelProfesor<<" "<<"["
            <<curso.codigoDelProfesor<<"]"<<endl;
    arch<<"Alumnos matriculados:"<<endl;
    arch<<left<<setw(15)<<"semestre"<<"Codigo"<<endl;
    for(i=0;i<curso.numeroDeAlumnos;i++){
        arch<<left<<setw(2)<<" "<<setw(13)<<curso.alumnos[i]/10000<<
                curso.alumnos[i]%10000<<endl;
    }
    arch<<setw(2)<<" "<<left<<setw(25)<<"Numero de alumnos: "<<right<<
            setw(10)<<curso.numeroDeAlumnos<<endl;
    arch<<setw(2)<<" "<<left<<setw(25)<<"Total ingresado: "<<right<<
            setw(10)<<curso.ingresos<<endl;
    
}



/*
INF263   Algoritmia   3.75   35030611   INGA_FLORES_CESAR_ADOLFO
MEC270   Procesos_De_Manufactura   4   83265244   PAIRAZAMAN_ALAMO_MOISES_MIGUEL
*/

bool operator >>(ifstream &arch,StCurso &cur){
    arch >> cur.codigoDelCurso;
    if(arch.eof()) return false;
    arch >> cur.nombreDelCurso >> cur.creditos >> cur.codigoDelProfesor >>
        cur.nombreDelProfesor;
    cur.numeroDeAlumnos = 0;
    cur.ingresos = 0;
    return true;
}

void operator +=(StCurso *arrcur, StCurso &cur){
    int i;
    for(i=0;strcmp(arrcur[i].codigoDelCurso,"XXXXXX")!=0;i++);
    arrcur[i] = cur;
    strcpy(arrcur[i+1].codigoDelCurso,"XXXXXX");
}




