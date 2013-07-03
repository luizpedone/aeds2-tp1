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

#ifndef TP1_3D_Ponto3D_h
#define TP1_3D_Ponto3D_h

class Ponto3D {

private:
    // Coordenada X do Ponto3D.
    double x_;
    // Coordenada Y do Ponto3D.
    double y_;
    // Coordenada Z do Ponto3D.
    double z_;

public:
    // Cria um ponto com coordenadas (0.0, 0.0, 0.0).
    Ponto3D();
    
    // Cria um ponto com coordenadas (x, y, z).
    Ponto3D(double x, double y, double z);
    
    // Cria um ponto com as mesmas coordenadas de p.
    Ponto3D(Ponto3D& p);
    
    // Retorna a coordenada x do ponto.
    double& x();
    
    // Retorna a coordenada y do ponto.
    double& y();
    
    // Retorna a coordenada z do ponto.
    double& z();
    
    // Faz com que as coordenadas do ponto corrente sejam igual as de p.
    void operator=(Ponto3D& p);
    
    // Translada o ponto em qualquer dos eixos.
    void Transladar(double dx, double dy, double dz);
    
    // Muda a escala do ponto em qualquer dos eixos.
    void MudarEscala(double fx, double fy, double fz);
    
    // Rotaciona o ponto 'ang' radianos em torno do eixo 'e'.
    // Os valores válidos para 'e' são 'X', 'Y', ou 'Z'.
    void Rotacionar(char e, double ang);
};

#endif