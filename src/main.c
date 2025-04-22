#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    double saldo = 100.00;
    printf("Você tem um saldo de %.2f\n", saldo);

    //quanto voce quer apostar?
    int tentativas = 0;
    
    printf("Quantas tentativas voce quer?\n");
    scanf("%d", &tentativas);

    srand(time(NULL));
    

    char res = 's';
    while (res == 's')
    {
        
        while (saldo < tentativas * 10)
        {
            printf("Saldo insuficiente. Tente outro valor\n");
            scanf("%d", &tentativas);
        }

        for (int i = 0; i < tentativas; i++)
        {
            saldo -= 10;        

            int numeroSecreto1 = rand() % 10;
            int numeroSecreto2 = rand() % 10;
            int numeroSecreto3 = rand() % 10;
            
            printf("Numeros sorteados: %d", numeroSecreto1);
            Sleep(2000); // espera 1000 milissegundos = 1 segundos
            printf(" %d", numeroSecreto2);
            Sleep(2000);
            printf(" %d\n", numeroSecreto3);
            Sleep(500);
            
            if (numeroSecreto1 == numeroSecreto2 && numeroSecreto2 == numeroSecreto3)
            {
                printf("\033[1;32mVoce ganhou\033[1;32m\n");
                Sleep(1000);
            } else {
                printf("\033[1;31mVoce perdeu\033[1;31m\n");
                Sleep(1000);
            }
            printf("\033[0m");
        }

        if (saldo <= 0)
        {
            printf("Seu saldo acabou");
            break;
        }

        printf("Saldo: %.2f\n", saldo);
        printf("Deseja continuar?\n");
        scanf(" %c", &res);
        if (res == 's')
        {
            printf("Quantas tentativas voce quer?\n");
            scanf("%d", &tentativas);
        } else {
            printf("O programa acabou.");
            break;
        }


    }
    return 0;
}
