#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>

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
        file << id << "," << name << "," << balance << "\n";
        file.close();
        file_in_use = false;
    }

    
    void static debit_account (string file_name, int id, float amount)
    {
        mutex mutex;
        fstream file; 
        ofstream temp;
        int counter = 1;
        string line, aux, id_file, name_file, balance_file;
        mutex.lock();
        file.open(file_name);
        temp.open("temp.txt", ios::out);
        while (getline(file, line, '\n'))
        {
            if (counter == id)
                break;
            line.push_back('\n');
            temp << line;
            counter++;
        }

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ',' and line[i] != '\n')
                aux.push_back(line[i]);
            if (line[i] == ',')
            {
                if (id_file.empty())
                {
                    id_file = aux;
                    aux.clear();
                    continue;
                }
                if (name_file.empty())
                {
                    name_file = aux;
                    aux.clear();
                    continue;
                }
                if (balance_file.empty())
                {
                    balance_file = aux;
                    aux.clear();
                    continue;
                }
            }
        }

        temp << id_file << "," << name_file << "," << stof(balance_file) - amount << "," << endl;

        while (getline(file, line))
        {
            line.push_back('\n');
            temp << line;
        }
        
        temp.close();
        file.close();

        remove(file_name.c_str());
        rename("temp.txt", file_name.c_str());
        mutex.unlock();
    }
 
    void static deposit_account (string file_name, int id, float amount)
    {
        mutex mutex;
        fstream file; 
        ofstream temp;
        int counter = 1;
        string line, aux, id_file, name_file, balance_file;

        mutex.lock();
        file.open(file_name);
        temp.open("temp.txt", ios::out);
        while (getline(file, line, '\n'))
        {
            if (counter == id)
                break;
            line.push_back('\n');
            temp << line;
            counter++;
        }

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ',' and line[i] != '\n')
                aux.push_back(line[i]);
            if (line[i] == ',')
            {
                if (id_file.empty())
                {
                    id_file = aux;
                    aux.clear();
                    continue;
                }
                if (name_file.empty())
                {
                    name_file = aux;
                    aux.clear();
                    continue;
                }
                if (balance_file.empty())
                {
                    balance_file = aux;
                    aux.clear();
                    continue;
                }
            }
        }

        temp << id_file << "," << name_file << "," << stof(balance_file) + amount << "," << endl;

        while (getline(file, line))
        {
            line.push_back('\n');
            temp << line;
        }
        
        temp.close();
        file.close();

        remove(file_name.c_str());
        rename("temp.txt", file_name.c_str());
        mutex.unlock(); 
    }

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
            cout << last_line[i];
            if (last_line[i] != '\n' or last_line[i] != ',')
                id.push_back(last_line[i]);
        }

        return 1;
    }
};

int main()
{
    fstream clients_file;
    const string FILE_NAME = "clients.txt";

    Client client("asd", FILE_NAME);

    thread thread1(client.deposit_account, FILE_NAME, 3, 300);
    thread thread2(client.debit_account, FILE_NAME, 3, 300);
    thread1.join();
    thread2.join();

    return 0;
}