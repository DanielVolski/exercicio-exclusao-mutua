#include <iostream>
#include <string>
#ifndef CLIENTS
#define CLIENTS

using namespace std;

typedef struct client
{
    int account_id;
    string name;
    float balance;
} client;
#endif

client create_new_client (int id, string name, float balance)
{
    client this_client;

    this_client.account_id = id;
    this_client.name = name;
    this_client.balance = balance;

    return this_client;
}

// int add_new_client(client new_client, FILE *file)
// {

    
// }
void deposit_into_account(client account, FILE *file);
void debt_from_account(client account, FILE *file);