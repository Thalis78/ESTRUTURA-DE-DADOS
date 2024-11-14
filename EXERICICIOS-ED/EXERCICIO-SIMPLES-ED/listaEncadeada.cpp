#include <stdio.h>
#include <stdlib.h>

// ESTRUTURA DE UM NÓ;
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
// FUNÇÃO PARA I-NSERIR NO INICIO DA LISTA
void inserirInicio(struct Node** head, int valor) {
    struct Node* novo = novoNo(valor);
    novo->next = *head;  // APONTA PARA O NÓ ATUAL(SE HOUVER)
    *head = novo;  //ATIALIZA O PONTEIRO PARA A CABEÇA PARA O NOVO NÓ.
}
// FUNÇÃO PARA EXCLUIR UM NÓ DA LISTA
void excluir(struct Node** head, int valor) {
    if (*head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    //SE O NÓ A SER EXCLUÍDO É O PRIMEIRO
    if (temp != NULL && temp->data == valor) {
        *head = temp->next;// A CABEÇA DA LISTA É ATUALIZADA PARA O PRÓXIMO NÓ
        free(temp); // LIBERA A MEMÓRIA
        printf("Valor %d excluído.\n", valor);
        return;
    }
    //PROXIMO O NÓ A SER EXCLUIDO
    while (temp != NULL && temp->data != valor) {
        prev = temp;
        temp = temp->next;
    }
    //SE O VALOR NÃO FOI ENCONTRADO
    if (temp == NULL) {
        printf("Valor %d não encontrado.\n", valor);
        return;
    }
    // DESCONCETA O NÓ DA LISTA E LIBERA A MEMÓRIA
    prev->next = temp->next;
    free(temp);
    printf("Valor %d excluído.\n", valor);
}
// FUNÇÃO PARA ALTERAR O VALOR DE UM NÓ
void alterar(struct Node* head, int antigo, int novo) {
    struct Node* temp = head;
    // PERCORRE A LISTA ATÉ ENCONTRAR O VALOR ANTIGO;
    while (temp != NULL && temp->data != antigo) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Valor %d não encontrado.\n", antigo);
    } else {
        temp->data = novo;  // ALTERA O VALOR DO NÓ
        printf("Valor %d alterado para %d.\n", antigo, novo);
    }
}

void imprimirLista(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("CHEGAMOS NO NULL\n");
}

int main() {
    struct Node* head = NULL;  //LISTA INICIADA COM VAZIO

    inserirInicio(&head, 20);   // 10
    inserirInicio(&head, 20);   // 20 -> 10


    printf("Lista após inserções:\n");
    imprimirLista(head);

    alterar(head, 20, 100);

    excluir(&head, NULL);

    printf("Lista final:\n");
    imprimirLista(head);

    return 0;
}
