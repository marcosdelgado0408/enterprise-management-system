/**
* @file empresa.cpp
* @brief implementação dos metodos da classe Empresa
* @author Marcos V A Delgado Junior
* @since 26/04/2019
* @date 07/05/2019
*/

#include <iostream>
#include <vector>
#include "classes.h"
#include <ctime>

Empresa::Empresa(){
    this->nome = "";
    this->cnpj = "";
}

Empresa::Empresa(string nome, string cnpj){
    this->nome = nome;
    this->cnpj = cnpj;
}

string Empresa::getNome(){ return nome; }
void Empresa::setNome(string nome1){ nome = nome1; }

string Empresa::getCnpj(){ return cnpj; }
void Empresa::setCnpj(string cnpj1) { cnpj = cnpj1; }

vector<Funcionario> Empresa::getLista_funcionarios(){
    return lista_funcionarios;
}

int Empresa::novo_funcionario(){

    Funcionario pessoa;
    
    string nome;
    string data;
    double salario;
    string ano;
    string mes;
    string dia;

    cout << "Digite nome do funcionario: ";
    cin >> nome;
    cout << endl;


    //mensagem de erro se ja existe funcionario
    for (int i = 0; i < lista_funcionarios.size(); i++){
        while (nome == lista_funcionarios[i].getNome()){
            cout << "o Funcionario " << lista_funcionarios[i].getNome() << " ja existe na empresa " << getNome() << endl;
            return -1;
        }
    }

    cout << "----Data de Admissão----" << endl << endl;

    cout << "Digite o ano de admissão do funcionario: ";
    cin >> ano;
    cout << endl;

    cout << "Digite o mês de admissão do funcionario: ";
    cin >> mes;
    cout << endl;

    cout << "Digite o dia de admissão do funcionario: ";
    cin >> dia;
    cout << endl;

    cout << "--------------------------" << endl;

    cout << "Digite o salario do funcionario em reais: ";
    cin >> salario;
    cout << endl;

    data.append(ano);
    data.append("-");
    data.append(mes);
    data.append("-");
    data.append(dia);

    pessoa.setNome(nome);
    pessoa.setData_admissao(data);
    pessoa.setSalario(salario);

    lista_funcionarios.push_back(pessoa);
}

void Empresa::aumento_funcionarios(){

    char op;

    cout << "Deseja dar aumento a todos os funcionarios da empresa?(s/n): ";
    cin >> op;
    cout << endl;

    if (op == 'S' or op == 's'){

        double porcentagem;

        cout << "Digite quantos porcento gostaria de dar o aumento: ";
        cin >> porcentagem;
        cout << endl;

        for (int i = 0; i < lista_funcionarios.size(); i++){
            cout << "=================================================================================================" << endl;
            double salario_anterior;
            salario_anterior = lista_funcionarios[i].getSalario();
            cout << "->Salario anterior do funcionario "
                 << "<" << lista_funcionarios[i].getNome() << ">"
                 << ": R$" << salario_anterior << endl
                 << endl;
            double aumento;
            aumento = salario_anterior * (porcentagem / 100);
            cout << "->Aumento do salario do funcionario "
                 << "<" << lista_funcionarios[i].getNome() << ">"
                 << " em " << aumento << " reais" << endl
                 << endl;
            lista_funcionarios[i].setSalario(salario_anterior + aumento);
            cout << "->Novo salario do funcionario "
                 << "<" << lista_funcionarios[i].getNome() << ">"
                 << " : R$" << lista_funcionarios[i].getSalario() << endl
                 << endl;
            cout << "=================================================================================================" << endl;
        }

        cout << "Salarios atualizados com sucesso!!!" << endl;
    }
}

string currentDateTime(){ //função para retornar data e hora atual do computador
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void Empresa::mostrar_funcionarios_inexperientes(){

//colocando cada data ta variavel em uma variavel separada
    string data_local;
    string ano_string;
    string mes_string;
    string dia_string;

    int i, j;

    data_local = currentDateTime();

    for (i = 0; i < 4; i++){
        ano_string.push_back(data_local[i]);
    }

    for (i = 5; i < 7; i++){
        mes_string.push_back(data_local[i]);
    }

    for (i = 8; i < 10; i++){
        dia_string.push_back(data_local[i]);
    }

    int ano = stoi(ano_string);

    int mes = stoi(mes_string);

    int dia = stoi(dia_string);

    //-------------------------------------------

    for (i = 0; i < this->getLista_funcionarios().size(); i++){ // cada iteração será para cada funcionario
        string data_admissao = this->getLista_funcionarios()[i].getData_admissao();
        string ano_string_funcionario;
        string mes_string_funcionario;
        string dia_string_funcionario;

        for (j = 0; j < 4; j++){
            ano_string_funcionario.push_back(data_admissao[j]);
        }

        for (j = 5; j < 7; j++){
            mes_string_funcionario.push_back(data_admissao[j]);
        }

        for (j = 8; j < 10; j++){
            dia_string_funcionario.push_back(data_admissao[j]);
        }

        int ano_funcionario = stoi(ano_string_funcionario);

        int mes_funcionario = stoi(mes_string_funcionario);

        int dia_funcionario = stoi(dia_string_funcionario);

        if (mes_funcionario >= mes - 3 and ano_funcionario >= ano){
            cout << "Nome do funcionario: " << this->getLista_funcionarios()[i].getNome() << "  ";
            cout << "data admissao: " << this->getLista_funcionarios()[i].getData_admissao() << "  ";
            cout << "Salario: " << this->getLista_funcionarios()[i].getSalario() << endl;
        }
        else{
            continue;
        }
    }
}

ostream &operator<<(ostream &os,vector<Funcionario> &funcionario){
    for(int i=0;i<funcionario.size();i++){
        os << funcionario[i];
    }
    os << endl;
    
    return os;
}

ostream &operator<<(ostream &os, Empresa empresa){
    os << empresa.getNome() << "," << empresa.getCnpj();
    return os;
}

void Empresa::mostrar_funcionarios(){
    int i;
    for(i=0;i<lista_funcionarios.size();i++){
        cout << ".............................................................." << endl;
        cout << " Funcionario " << i+1 << ": " << this->lista_funcionarios[i].getNome() << "  ";
        cout << "Data de admissão: " << this->lista_funcionarios[i].getData_admissao() << "  ";
        cout << "Salario: " << this->lista_funcionarios[i].getSalario() << " reais"<< endl;
        cout << ".............................................................." << endl << endl;   
    }
}

void Empresa::media_funcionarios(){
    double salario_total;
    double media;
    for(int i;i<this->getLista_funcionarios().size();i++){
        salario_total += this->getLista_funcionarios()[i].getSalario();
    }
        cout << "Soma dos salarios da empresa: " <<  salario_total << endl;

        cout << "Media: " << salario_total/ this->getLista_funcionarios().size() << endl;
}