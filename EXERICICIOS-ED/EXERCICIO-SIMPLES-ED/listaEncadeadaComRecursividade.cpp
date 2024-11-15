#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA DE UM NÓ
struct Node {
    int data;
    struct Node* next;
};

// FUNÇÃO USADA PARA CRIAR UM NOVO NÓ
struct Node* novoNo(int valor) {
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    novo->data = valor;
    novo->next = NULL;
    return novo;
}

// FUNÇÃO PARA INSERIR NO INÍCIO DA LISTA
void inserirInicio(struct Node** head, int valor) {
    struct Node* novo = novoNo(valor);
    novo->next = *head;  // APONTA PARA O NÓ ATUAL (SE HOUVER)
    *head = novo;        // ATUALIZA O PONTEIRO PARA A CABEÇA PARA O NOVO NÓ
}

// FUNÇÃO RECURSIVA PARA EXCLUIR UM NÓ DA LISTA
struct Node* excluirRecursivo(struct Node* head, int valor) {
    if (head == NULL) { // BASE: LISTA VAZIA OU CHEGOU NO FINAL
        printf("Valor %d não encontrado.\n", valor);
        return NULL;
    }
    if (head->data == valor) { // NÓ ENCONTRADO
        struct Node* temp = head->next; // ARMAZENA O PRÓXIMO NÓ
        free(head); // LIBERA O NÓ ATUAL
        printf("Valor %d excluído.\n", valor);
        return temp; // RETORNA O PRÓXIMO NÓ COMO A NOVA CABEÇA
    }
    head->next = excluirRecursivo(head->next, valor); // CHAMADA RECURSIVA
    return head;
}

// FUNÇÃO RECURSIVA PARA ALTERAR O VALOR DE UM NÓ
void alterarRecursivo(struct Node* head, int antigo, int novo) {
    if (head == NULL) { // BASE: CHEGOU NO FINAL DA LISTA
        printf("Valor %d não encontrado.\n", antigo);
        return;
    }
    if (head->data == antigo) { // NÓ ENCONTRADO
        head->data = novo;
        printf("Valor %d alterado para %d.\n", antigo, novo);
        return;
    }
    alterarRecursivo(head->next, antigo, novo); // CHAMADA RECURSIVA
}

// FUNÇÃO RECURSIVA PARA IMPRIMIR A LISTA
void imprimirListaRecursiva(struct Node* head) {
    if (head == NULL) { // BASE: CHEGOU NO FINAL DA LISTA
        printf("CHEGAMOS NO NULL\n");
        return;
    }
    printf("%d -> ", head->data); // IMPRIME O NÓ ATUAL
    imprimirListaRecursiva(head->next); // CHAMADA RECURSIVA
}

int main() {
    struct Node* head = NULL; // LISTA INICIADA COMO VAZIA

    inserirInicio(&head, 20);  // 20
    inserirInicio(&head, 10);  // 10 -> 20

    printf("Lista após inserções:\n");
    imprimirListaRecursiva(head);

    alterarRecursivo(head, 20, 100);

    head = excluirRecursivo(head, 10); // EXCLUI O VALOR 10

    printf("Lista final:\n");
    imprimirListaRecursiva(head);

    return 0;
}
