#include <iostream>
#include <fstream>
#include <thread>

#if defined(_WIN32)
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif

using namespace std;

bool file_in_use = false;

class Client
{
public:
    int id;
    string name;
    float balance;

    Client(string new_name, string file_name)
    {
        id = get_last_id(file_name) + 1;
        name = new_name;
        balance = 0.0;
    }

    void register_client(string file_name)
    {
        fstream file;
        file_in_use = true;
        file.open(file_name, ios::app);
        file << endl << id << "," << name << "," << balance << ",";
        file.close();
        file_in_use = false;
    }

    void debit_account (float amount_to_debit, string file_name)
    {
        string id;
        fstream file;
        file.open(file_name);

        while (getline(file_name, id) != )
        {
            getline(file_name, client.id, ' ');
            getline(file_name, client.name, ' ');
            getline(file_name, client.balance);
        }
        
        if (client.balance >= amount_to_debit)   
        {
            client.balance -= amount_to_debit;
            cout << "Operacao realizada com sucesso!" << endl;
            cout << "Id: " << client.id << " Nome: " << client.name << endl;
            cout << "Operacao: " << client.balance << " - " << amount_to_debit << 
            " = " << client.balance - amount_to_debit << endl;
        }
        else
        {
            cout << "Saldo insuficiente!" << endl;
        }


        
    }

    void debit_account (float amount_to_debit, string file_name)
    {
        string id;
        fstream file;
        file.open(file_name);

        while (getline(file_name, id) != )
        {
            getline(file_name, client.id, ' ');
            getline(file_name, client.name, ' ');
            getline(file_name, client.balance);
        }
        
        if (client.balance >= amount_to_debit)   
        {
            client.balance -= amount_to_debit;
            cout << "Operacao realizada com sucesso!" << endl;
            cout << "Id: " << client.id << " Nome: " << client.name << endl;
            cout << "Operacao: " << client.balance << " - " << amount_to_debit << 
            " = " << client.balance - amount_to_debit << endl;
        }
        else
        {
            cout << "Saldo insuficiente!" << endl;
        }


        
    }

private: 

    Client client;
    int get_last_id(string file_name)
    {
        fstream file;
        string last_line, id;
        file.open(file_name);
        if(file.is_open()) 
        {
            file.seekg(-1,ios_base::end);
            bool keepLooping = true;
            while(keepLooping) 
            {
                char ch;
                file.get(ch);                            

                if((int)file.tellg() <= 1) 
                {             
                    file.seekg(0);                      
                    keepLooping = false;                
                }
                else if(ch == '\n')                
                    keepLooping = false;                
                else                              
                    file.seekg(-2,ios_base::cur);        
            }

            getline(file, last_line);
            file.close();
        }

        for (int i = 0; i < last_line.length(); i++)
        {
            if (last_line[i] == ' ')
                break;
            if (last_line[i] != '\n')
                id.push_back(last_line[i]);
        }

        return stoi(id);
    }
};

int main()
{
    fstream clients_file;
    const string FILE_NAME = "clients.txt";
    int option = 0;

    do
    {
        CLEAR_SCREEN();
        
        cout << "Gestao de conta bancaria" << endl;
        cout << "Escolha uma opcao:" << endl;
        cout << "1 - Cadastrar novo cliente" << endl;
        cout << "2 - Creditar" << endl;
        cout << "3 - Debitar" << endl;
        cout << "4 - Sair" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            string name = "";
            cin >> name;
            Client new_client(name, FILE_NAME);
            new_client.register_client(FILE_NAME);
        }
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
    } while ((option > 0 and option < 4));

    return 0;
}

