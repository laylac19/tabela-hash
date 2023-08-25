#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Defini��o do tamanho da tabela hash (preferencialmente um n�mero primo)
#define TABLE_SIZE 13

// Estrutura para um n� da lista encadeada
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Estrutura da tabela hash
typedef struct tabelaHash {
    Node* array[TABLE_SIZE];
} tabelaHash;

// Fun��o para inicializar a tabela hash
void criarTabela(tabelaHash* hash);

// Fun��o para inserir um elemento na tabela hash
void inserir(tabelaHash* hash, int key);

// Fun��o para buscar um elemento na tabela hash
Node* buscar(tabelaHash* hash, int key);

// Fun��o para remover um elemento da tabela hash
void remover(tabelaHash* hash, int key);

// Fun��o para imprimir a tabela hash
void imprimir(tabelaHash* hash);

#endif // HASH_TABLE_H

