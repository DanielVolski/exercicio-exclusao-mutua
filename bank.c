#include <stdio.h>
#include <pthread.h>
#include <string.h>

typedef struct client
{
    int account_id;
    char name[60];
    float balance;
} client;

int add_new_client(client new_client, FILE *file);
void deposit_into_account(client account, FILE *file);
void debt_from_account(client account, FILE *file);

int main()
{
    FILE *clients_file = fopen("clients.txt", "a");

    if (clients_file != NULL)
        fputs("teste1\n", clients_file);
    else
        printf("Faile to open the file");

    fclose(clients_file);
    
    return 0;
}