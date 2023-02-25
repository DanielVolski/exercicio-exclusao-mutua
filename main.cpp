#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    fstream clients_file;
    const string FILE_NAME = "clients.txt";

    clients_file.open(FILE_NAME, ios::app);

    if (clients_file)
    {
        cout << "File opened in append mode" << endl;
        clients_file << "Teste\n"; 
    }

    clients_file.close();

    return 0;
}