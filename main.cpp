#include <iostream>
#include <pthread.h>
#include <fstream>
#include "headers.cpp"

using namespace std;

int main ()
{
    ofstream clients_file ("clients_file.txt");
    if (!clients_file)
    {
        cout << "ERRO na criacao do arquivo de clients_txt" << endl;
    }
    clients_file.close();  
    
    // client t3ste = create_new_client(1, "jose carlos", 000.00);
    // add_new_client(t3ste, clients_file);
    
    return 0;
}