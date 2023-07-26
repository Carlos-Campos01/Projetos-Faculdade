/*O Programa armazena dados de um estacionamento, armazena a placa e o modelo de um carro, 
assim como o horário de entrada e saída do estacionamento, com horas e minutos. para o total de 20 carros */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 20
#define MAX_PLACA 7
#define MAX_MODELO 20

struct Carro {
    char placa[MAX_PLACA];
    char modelo[MAX_MODELO];
    int entrada_horas;
    int entrada_minutos;
    int saida_horas;
    int saida_minutos;
};

int main() {
    struct Carro estacionamento[MAX_VAGAS];
    int i;

    for (i = 0; i < MAX_VAGAS; i++) {
        printf("Carro #%d\n", i + 1);

        printf("\nInforme a placa do veiculo: ");
        scanf("%s", estacionamento[i].placa);

        printf("\nInforme o modelo do veiculo: ");
        scanf("%s", estacionamento[i].modelo);
		
		char entrada[6]; 
		printf("\nInforme o horario de entrada (horas:minutos): ");
        scanf("%s", entrada);
        sscanf(entrada, "%d:%d", &estacionamento[i].entrada_horas, &estacionamento[i].entrada_minutos);
        char saida[6]; 
        printf("\nInforme o horario de saida (horas:minutos): ");
        scanf("%s", saida);
        sscanf(saida, "%d:%d", &estacionamento[i].saida_horas, &estacionamento[i].saida_minutos);
     
        printf("\n");
    }
    
    printf("Informações dos carros estacionados:\n");
    for (i=0; i < MAX_VAGAS; i++) {
        printf("Carro #%d\n", i + 1);
        printf("Placa: %s\n", estacionamento[i].placa);
        printf("Modelo: %s\n", estacionamento[i].modelo);
        printf("Horario de entrada: %02d:%02d\n", estacionamento[i].entrada_horas, estacionamento[i].entrada_minutos);
        printf("Horario de saida: %02d:%02d\n", estacionamento[i].saida_horas, estacionamento[i].saida_minutos);
        printf("\n");
    }

    return 0;
}

