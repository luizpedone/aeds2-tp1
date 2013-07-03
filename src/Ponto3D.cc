//  UNIVERSIDADE FEDERAL DE MINAS GERAIS
//  INSTITUTO DE CIENCIAS EXATAS
//  DEPARTAMENTO DE CIENCIA DA COMPUTACAO
//
//  Algoritmos e Estruturas de Dados II
//  Trabalho Pratico I
//  Aluno: Luiz Felipe Matos Pedone
//  Matricula: 2008023421
//
//  Arquivo: main.cc
//  * Descricao: Conteudo principal do programa.
//  * Criado em 06/10/2011.
//

#include <iostream>
#include <math.h>
#include "Ponto3D.h"

using namespace std;

Ponto3D::Ponto3D(){
    this -> x_ = 0.0;
    this -> y_ = 0.0;
    this -> z_ = 0.0;
}

Ponto3D::Ponto3D(double x, double y, double z){
    this -> x_ = x;
    this -> y_ = y;
    this -> z_ = z;
}

Ponto3D::Ponto3D(Ponto3D &p){
    this -> x_ = p.x_;
    this -> y_ = p.y_;
    this -> z_ = p.z_;
}

double& Ponto3D::x(){
    return x_;
}

double& Ponto3D::y(){
    return y_;
}

double& Ponto3D::z(){
    return z_;
}

void Ponto3D::operator=(Ponto3D& p){
    this -> x_ = p.x_;
    this -> y_ = p.y_;
    this -> z_ = p.z_;
}

void Ponto3D::Transladar(double dx, double dy, double dz){
    this -> x_ = x_ + dx;
    this -> y_ = y_ + dy;
    this -> z_ = z_ + dz;
}

void Ponto3D::MudarEscala(double fx, double fy, double fz){
    this -> x_ = x_ * fx;
    this -> y_ = y_ * fy;
    this -> z_ = z_ * fz;
}

void Ponto3D::Rotacionar(char e, double arg){
    double aux[3];
    if(e == 'X'){
        aux[1] = y_*cos(arg)+z_*(sin(arg));
        aux[2] = y_*(-sin(arg))+z_*cos(arg);
        this -> y_ = aux[1];
        this -> z_ = aux[2];
    }
    if(e == 'Y'){
        aux[0] = x_*cos(arg)+z_*(-sin(arg));
        aux[2] = x_*sin(arg)+z_*(cos(arg));
        this -> x_ = aux[0];
        this -> z_ = aux[1];
    }
    if(e == 'Z'){
        aux[0] = x_*cos(arg)+y_*(-sin(arg));
        aux[1] = x_*(sin(arg))+y_*cos(arg);

        this->x_ = aux[0];
        this->y_ = aux[1];
    }
}
