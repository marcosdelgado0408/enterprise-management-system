/**
* @file funcionario.cpp
* @brief implementação dos metodos da classe Funcionario
* @author Marcos V A Delgado Junior
* @since 26/04/2019
* @date 07/05/2019
*/

#include <iostream>
#include "classes.h"

double Funcionario::getSalario(){ return salario; }
void Funcionario::setSalario(double num) {this->salario = num; }

string Funcionario::getNome(){ return nome; }
void Funcionario::setNome(string nome1) {this->nome = nome1; }

string Funcionario::getData_admissao(){ return data_admissao; }
void Funcionario::setData_admissao(string data1) {this->data_admissao = data1; }


ostream &operator<<(ostream &os, Funcionario &funcionario){
    os << "...................................................." << endl;
    os << "Nome: "<<funcionario.getNome() << "  ";
    os << "Data de admissão: " << funcionario.getData_admissao() << "  ";
    os << "Salario: " << funcionario.getSalario() << endl;
    os << "...................................................." << endl;
    os << endl;

    return os;
}