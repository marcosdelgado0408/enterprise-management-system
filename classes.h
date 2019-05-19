/**
* @file classes.h
* @brief Descrição das classes Funcionario e empresa e das funcções menu() e currentDateTime()
* @author Marcos V A Delgado Junior
* @since 26/04/2019
* @date 07/05/2019
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef _classes_
#define _classes_

class Funcionario{
  private:
    double salario;
    string nome;
    string data_admissao;

  public:
    double getSalario();
    void setSalario(double num);

    string getNome();
    void setNome(string nome);

    string getData_admissao();
    void setData_admissao(string data);

    /**
     * @brief Método para sobrecarregar o operador << com o objetivo de retornar todos os dados de 1 funcionario
     * @return ostream os
    */
    friend ostream &operator<<(ostream &os, Funcionario &funcionario);
};





class Empresa{
  private:
    string nome;
    string cnpj;
    vector<Funcionario> lista_funcionarios;

  public:
    Empresa();
    Empresa(string nome, string cnpj);

    string getNome();
    void setNome(string nome1);

    string getCnpj();
    void setCnpj(string cnpj1);

    vector<Funcionario> getLista_funcionarios(); // retornar a lista de funcionarios quando necessario

    /** 
     * @brief Método para adicionar novo funcionario na lista de funcionarios da classe
     * @return 0 caso ja exista o funcionario que a pessoa está querendo adicionar
    */
    int novo_funcionario();

    /**
     *@brief Método backup caso a sobrecarga de operador não funcionasse.
    */
    void mostrar_funcionarios();

    /**
     *@brief Método dada porcentagem desejada vai adicionar um aumento no salario de todos os funcionarios.
    */
    void aumento_funcionarios();

    /**
     *@brief Método que exibe todos os dados dos funcionarios num periodo de experiência(do dia atual para 90 dias atras).
     */
    void mostrar_funcionarios_inexperientes();

    /**
     *@brief Método que exibie a media dos funcionarios da empresa
     */
    void media_funcionarios();

    /**
     *@brief sobrecarga de operador para "printar" a lista de funcionarios -> vai receber como parametro a lista de funcionarios pra poder printar
    */
    friend ostream &operator<<(ostream &os, vector<Funcionario> &funcionario);

    /**
     * @brief Sobreacarga do operador << para poder imprimir dados de uma empresa
     * @return ostream os 
     */
    friend ostream& operator<<(ostream &os,Empresa empresa);
};

/**
 *@brief Função do menu 
  */
int menu();

/**
 *@brief função para saber data e hora atual
 *@return data e hora local do computador
*/
string currentDateTime();

#endif