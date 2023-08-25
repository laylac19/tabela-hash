// Aluno: Layla Maria dos Santos Couto

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>  // Biblioteca para usar caracteres acentuados

#include "tabelaHashEnderecamentoFechado.h"

// Fun��o de hash (resto da divis�o)
int calcularBucket(int key) {
    return key % TABLE_SIZE;
}

// Fun��o para inicializar a tabela hash
void criarTabela(tabelaHash* hash) {
	int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        hash->array[i] = NULL;
    }
}

// Fun��o para inserir um elemento na tabela hash
void inserir(tabelaHash* hash, int key) {
    int index = calcularBucket(key);

    // Cria��o do novo n�
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    // Inser��o no in�cio da lista encadeada
    if (hash->array[index] == NULL) {
        hash->array[index] = newNode;
    } else {
        newNode->next = hash->array[index];
        hash->array[index] = newNode;
    }
}

// Fun��o para buscar um elemento na tabela hash
Node* buscar(tabelaHash* hash, int key) {
    int index = calcularBucket(key);
    Node* current = hash->array[index];

    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }

    return NULL; // Elemento n�o encontrado
}

// Fun��o para remover um elemento da tabela hash
void remover(tabelaHash* hash, int key) {
    int index = calcularBucket(key);
    Node* current = hash->array[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                hash->array[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Fun��o para imprimir a tabela hash
void imprimir(tabelaHash* hash) {
	int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* current = hash->array[i];
        while (current != NULL) {
            printf("%d\t", current->key);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    tabelaHash hash;
    criarTabela(&hash);

    int opcao, key;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Imprimir\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o dado para inserir: ");
                scanf("%d", &key);
                inserir(&hash, key);
                break;
            case 2:
                printf("Digite o dado para remover: ");
                scanf("%d", &key);
                remover(&hash, key);
                break;
            case 3:
                printf("Digite o dado para buscar: ");
                scanf("%d", &key);
                Node* result = buscar(&hash, key);
                if (result != NULL) {
                    printf("Dado %d encontrado na tabela.\n", key);
                } else {
                    printf("Dado %d nao encontrado na tabela.\n", key);
                }
                break;
            case 4:
                imprimir(&hash);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}


