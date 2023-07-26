/* O objetivo principal do código é armazenar dados essenciais de cliente 
para uma empresa ou entidade que seja necessário possuir um banco de dados
e um software para manipulação mais fácil dos dados*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_TELEFONE 15

typedef struct {
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
    int idade;
    char endereco[MAX_NOME];
} Contato;

//parte do codigo para exibir informações cadastradas

void exibirRegistros(FILE *arquivo) {
    Contato contato;
    
    rewind(arquivo);
    printf("------ Registros ------\n");
    
    while (fread(&contato, sizeof(Contato), 1, arquivo) == 1) {
        printf("Nome: %s\n", contato.nome);
        printf("Email: %s\n", contato.email);
        printf("Telefone: %s\n", contato.telefone);
        printf("Idade: %d\n", contato.idade);
        printf("Endereco: %s\n", contato.endereco);
        printf("------------------------\n");
    }
}

// inserir informações 

void inserirRegistro(FILE *arquivo) {
    Contato contato;
    
    printf("------ Inserir Registro ------\n");
    printf("Nome: ");
    setbuf(stdin, NULL);
    gets(contato.nome);
    printf("Email: ");
    setbuf(stdin, NULL);
    gets(contato.email);
    printf("Telefone: ");
    setbuf(stdin, NULL);
    gets(contato.telefone);
    printf("Idade: ");
    scanf("%d", &contato.idade);
    printf("Endereco: ");
    setbuf(stdin, NULL);
    gets(contato.endereco);
    
    fwrite(&contato, sizeof(Contato), 1, arquivo);
    printf("Registro inserido com sucesso!\n");
}

//alterar informações cadastradas

void alterarRegistro(FILE *arquivo) {
    Contato contato;
    char nome[MAX_NOME];
    int encontrado = 0;
    
    printf("----- Alterar Registro -----\n");
    printf("Nome do contato que deseja alterar: ");
    setbuf(stdin, NULL);
    gets(nome);
    
    rewind(arquivo);
    
    while (fread(&contato, sizeof(Contato), 1, arquivo) == 1) {
        if (strcmp(nome, contato.nome) == 0) {
            printf("Novo Email: ");
            setbuf(stdin, NULL);
  			gets(contato.email);
            printf("Novo Telefone: ");
            setbuf(stdin, NULL);
 			gets(contato.telefone);
            printf("Nova Idade: ");
            scanf("%d", &contato.idade);
            printf("Novo Endereco: ");
            setbuf(stdin, NULL);
    		gets(contato.endereco);
            
            fseek(arquivo, -sizeof(Contato), SEEK_CUR);
            fwrite(&contato, sizeof(Contato), 1, arquivo);
            
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado)
        printf("Registro alterado com sucesso!\n");
    else
        printf("o registro informado nao foi encontrado.\n");
}

// apaga registro

void removerRegistro(FILE *arquivo) {
    Contato contato;
    FILE *temp;
    char nome[MAX_NOME];
    int encontrado = 0;
    
    printf("----- Remover Registro -----\n");
    printf("Nome do contato que deseja remover: ");
    setbuf(stdin, NULL);
    gets(nome);
    
    temp = fopen("temp.txt", "wb");
    rewind(arquivo);
    
    while (fread(&contato, sizeof(Contato), 1, arquivo) == 1) {
        if (strcmp(nome, contato.nome) != 0)
            fwrite(&contato, sizeof(Contato), 1, temp);
        else
            encontrado = 1;
    }
    
    fclose(arquivo);
    fclose(temp);
    
    remove("contatos.txt");
    rename("temp.txt", "contatos.txt");
    
    if (encontrado)
        printf("Registro removido com sucesso!\n");
    else
        printf("Registro nao encontrado.\n");
}

int main() {
    FILE *arquivo;
    int opcao;
    
    arquivo = fopen("contatos.txt", "ab+");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    do {
        printf("\n------ Menu ------\n");
        printf("1. Exibir registros\n");
        printf("2. Inserir registro\n");
        printf("3. Alterar registro\n");
        printf("4. Remover registro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                exibirRegistros(arquivo);
                break;
            case 2:
                inserirRegistro(arquivo);
                break;
            case 3:
                alterarRegistro(arquivo);
                break;
            case 4:
                removerRegistro(arquivo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);
    
    fclose(arquivo);
    
    return 0;
}

