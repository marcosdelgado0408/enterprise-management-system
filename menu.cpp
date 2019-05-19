/**
* @file menu.cpp
* @brief implementação da função menu()
* @author Marcos V A Delgado Junior
* @since 26/04/2019
* @date 07/05/2019
*/

#include "classes.h"

int menu(){
    
    Empresa empresa;
    
    char op1;
    while(op1 != '0'){
        cout << endl<< endl;
        cout << "#                             =====MENU=====                          #" << endl << endl;
        cout << "#  Criar uma empresa -> Digite 1                                      #" << endl << endl;
        cout << "#  Adicionar funcionario -> Digite 2                                  #" << endl << endl;
        cout << "#  Listar os dados de todos os funcionarios da empresa -> Digite 3    #" << endl << endl;
        cout << "#  Dar aumento a todos os funcinarios da empresa -> Digite 4          #" << endl << endl;
        cout << "#  Listar dados de funcionarios em periodo de experiencia -> digite 5 #" << endl << endl;
        cout << "#  Media de funcionarios -> Digite 6                                  #" << endl << endl;
        cout << "#  Sair -> Digite 0                                                   #" << endl << endl << endl << endl;
        cout << "Digite opção: ";
        cin >> op1;
        cout << endl;


        string nome, cnpj;
        
            switch (op1){

                case '1':
                    cout << "Digite o Nome da empresa: ";
                    getline(cin,nome);
                    getline(cin, nome);
                    cout << endl;

                    cout << "Digite o cnpj da empresa: ";
                    getline(cin,cnpj);
                    cout << endl;

                    empresa.setNome(nome);
                    empresa.setCnpj(cnpj);
                    break;

                case '2':
                    empresa.novo_funcionario();
                    break;
                case '3':
                    for(int i;i<empresa.getLista_funcionarios().size();i++){
                        cout << empresa.getLista_funcionarios()[i] << endl;
                    }
                    break;
                case '4':
                    empresa.aumento_funcionarios();
                    break;
                case '5':
                    empresa.mostrar_funcionarios_inexperientes();
                    break;

                case '6':
                    empresa.media_funcionarios();
                    break;

                case '0':
                    return 0;
               
               
                default:
                    break;
            }


    }

}