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
#include <fstream>
#include <math.h>
#include <iomanip>
#include "Ponto3D.h"
#include "Ponto3D.cc"

double grauspararad(double graus){
    return graus*(M_PI/180);
}

using namespace std;

int main ()
{
    int size = 0;   // Variavel que recebe o nœmero de pontos a serem recolhidos
    char value;     // Variavel que recebe o tipo de operacao a ser executada
    char eixo;      // Variavel para armazenar o eixo a ser utilizado na funcaoo rotacionar(eixo, valor);
    double graus;   // Variavel que armazena o grau a ser rotacionado
    double tmp[3];  // Variavel tempor‡ria para armazenar os pontos lidos no arquivo antes de serem inseridos no TAD Ponto3D

    ifstream leArquivo;                 // Variavel para a leitura do arquivo.
    leArquivo.open("entrada.txt");
    ofstream gravaArquivo;              // Variavel para a gravacao do arquivo.
    gravaArquivo.open("saida.txt");

    if(size == 0){
        leArquivo >> size;
        gravaArquivo << size << endl;
    }

    Ponto3D* vetor = new Ponto3D [size]; //Vetor do tipo Ponto3D onde todos os pontos do arquivo serao armazenados.
    /*
        Inicio da leitura dos Pontos
        As coordenadas sao recebidas do arquivo, armazenadas na variavel temporaria tmp[3] e em seguida armazenadas no Ponto3D vetor;
    */
    for(int i=0; i<size; i++){
        for(int j=0; j<3; j++){
            leArquivo >> tmp[j]; // Armazena coordenadas na variavel temporaria
        }
        Ponto3D aux (tmp[0],tmp[1],tmp[2]); // Cria um Ponto3D auxiliar
        vetor[i] = aux;                     // Insere o Ponto3D na posicao i do vetor
    }
    // Fim da leitura dos pontos.

    // Inicio da leitura das operacoes a serem executadas.
    while (leArquivo.good()){
        leArquivo >> value;     // Le o tipo de operacao a ser executada.

        // Operacao Transladar
        if(value == 'T'){
            leArquivo >> tmp[0];
            leArquivo >> tmp[1];
            leArquivo >> tmp[2];
            for(int j=0; j<size; j++){
                Ponto3D translada = vetor[j];
                translada.Transladar(tmp[0], tmp[1], tmp[2]);
                vetor[j] = translada;
            }
        }

        // Operacao Mudanca de Escala
        if(value == 'E'){
            leArquivo >> tmp[0];
            leArquivo >> tmp[1];
            leArquivo >> tmp[2];
            for(int j=0; j<size; j++){
                Ponto3D escala = vetor[j];
                escala.MudarEscala(tmp[0], tmp[1], tmp[2]);
                vetor[j] = escala;
            }
        }

        //Operacao Rotacionar Ponto
        if(value == 'R'){
            leArquivo >> eixo;
            leArquivo >> graus;
            for(int j=0; j<size; j++){
                Ponto3D rot = vetor[j];
                rot.Rotacionar(eixo, grauspararad(graus));
                vetor[j] = rot;
            }
        }
    }
    //Fim da execucao das operacoes sobre os pontos.

    // Inicio da gravacao dos resultados no arquivo de saida.
    for(int i=0; i<size;i++){
        gravaArquivo << fixed << setprecision(3) << vetor[i].x()<< " ";
        gravaArquivo << fixed << setprecision(3) << vetor[i].y() << " ";
        gravaArquivo << fixed << setprecision(3) << vetor[i].z() << endl;
    }
    //  Fim da gravacao do arquivo.

    leArquivo.close(); // Fecha o arquivo de leitura.
    gravaArquivo.close(); // Fecha o arquivo de gravacao.
    cout << "Programa executado com sucesso!" << endl;
    return 0;
}