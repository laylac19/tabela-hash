#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Definição do tamanho da tabela hash (preferencialmente um número primo)
#define TABLE_SIZE 13

// Estrutura para um nó da lista encadeada
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Estrutura da tabela hash
typedef struct tabelaHash {
    Node* array[TABLE_SIZE];
} tabelaHash;

// Função para inicializar a tabela hash
void criarTabela(tabelaHash* hash);

// Função para inserir um elemento na tabela hash
void inserir(tabelaHash* hash, int key);

// Função para buscar um elemento na tabela hash
Node* buscar(tabelaHash* hash, int key);

// Função para remover um elemento da tabela hash
void remover(tabelaHash* hash, int key);

// Função para imprimir a tabela hash
void imprimir(tabelaHash* hash);

#endif // HASH_TABLE_H

