#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    bool isRunning = true;
    fstream clients_file;
    const string FILE_NAME = "clients.txt";
    int option = 0;

    clients_file.open("clients.txt", ios::app);

    do
    {
        
        #if defined(_WIN32)
            system("cls");
        #else
            system("clear");
        #endif
        cout << "Gestao de conta bancaria" << endl;
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Cadastrar novo cliente" << endl;
        cout << "2 - Creditar" << endl;
        cout << "3 - Debitar" << endl;
        cout << "4 - Sair" << endl;
        cin >> option;

        switch (option)
        {
            case 1:
                break;

            case 2:
                break;
            
            case 3:
                break;

            case 4:
                cout << "Encerrando programa." << endl;
                break;
            
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }
    } while (option > 0 and option < 4);

    clients_file.close();

    return 0;
}