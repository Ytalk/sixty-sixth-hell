#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#include "character.h"
#include "ctminventory.h"

struct descritor_arvore* inicializa(void){
    struct descritor_arvore *myTree;
    myTree = (struct descritor_arvore *)malloc(sizeof(struct descritor_arvore));
    //myTree->tamanho = 0;
    myTree->raiz = NULL;
    return myTree;	
}

struct nodo_AVL* criaNodo(struct equipment_label item){
	struct nodo_AVL* novonodo_AVL;
	novonodo_AVL = (struct nodo_AVL *) malloc(sizeof(struct nodo_AVL));
	
	novonodo_AVL->item = item;
	
    novonodo_AVL->altura = 1;
	novonodo_AVL->esquerdo=NULL;
	novonodo_AVL->direito=NULL;
	//novonodo_AVL->pai=NULL;	
}


void inOrder(struct nodo_AVL *arvore){
    if (arvore != NULL){
        inOrder(arvore->esquerdo);
        printf("%s (%i), ", arvore->item.name, arvore->item.equipment_action);
        inOrder(arvore->direito);
    }
}

void preOrder(struct nodo_AVL *arvore){
    if (arvore != NULL){
        printf("%s (%i), ", arvore->item.name, arvore->item.equipment_action);
        preOrder(arvore->esquerdo);
        preOrder(arvore->direito);
    }
}

void postOrder(struct nodo_AVL *arvore){
    if (arvore != NULL){
        postOrder(arvore->esquerdo);
        postOrder(arvore->direito);
        printf("%s (%i), ", arvore->item.name, arvore->item.equipment_action);
    }
}


int altura(struct nodo_AVL *nodo_AVL){
    if (nodo_AVL == NULL)
        return 0;
    return nodo_AVL->altura;
}


int fatorBalanceamento(struct nodo_AVL *nodo_AVL){
    if (nodo_AVL == NULL)
        return 0;
    return altura(nodo_AVL->esquerdo) - altura(nodo_AVL->direito);
}


void atualizarAltura(struct nodo_AVL *nodo_AVL){
    int alturaEsquerda = altura(nodo_AVL->esquerdo);
    int alturaDireita = altura(nodo_AVL->direito);
    nodo_AVL->altura = (alturaEsquerda > alturaDireita) ? alturaEsquerda + 1 : alturaDireita + 1;
}


struct nodo_AVL *rotacaoDireita(struct nodo_AVL* nodo_AVLDesbalanceado){
    struct nodo_AVL *nodo_AVLEsquerda = nodo_AVLDesbalanceado->esquerdo;
    struct nodo_AVL *subArvoreDireita = nodo_AVLEsquerda->direito;

    nodo_AVLEsquerda->direito = nodo_AVLDesbalanceado;
    nodo_AVLDesbalanceado->esquerdo = subArvoreDireita;

    atualizarAltura(nodo_AVLDesbalanceado);
    atualizarAltura(nodo_AVLEsquerda);

    return nodo_AVLEsquerda;
}

struct nodo_AVL *rotacaoEsquerda(struct nodo_AVL* nodo_AVLDesbalanceado){
    struct nodo_AVL *nodo_AVLDireita = nodo_AVLDesbalanceado->direito;
    struct nodo_AVL *subArvoreEsquerda = nodo_AVLDireita->esquerdo;

    nodo_AVLDireita->esquerdo = nodo_AVLDesbalanceado;
    nodo_AVLDesbalanceado->direito = subArvoreEsquerda;

    atualizarAltura(nodo_AVLDesbalanceado);
    atualizarAltura(nodo_AVLDireita);

    return nodo_AVLDireita;
}


struct nodo_AVL *inserir(struct nodo_AVL* raiz, struct nodo_AVL* novoNodo){
    if (raiz == NULL)
        return novoNodo;

    if (strcmp(novoNodo->item.name, raiz->item.name) < 0)
        raiz->esquerdo = inserir(raiz->esquerdo, novoNodo);
    else if (strcmp(novoNodo->item.name, raiz->item.name) > 0)
        raiz->direito = inserir(raiz->direito, novoNodo);
    else
        return raiz; //valor já existe

    atualizarAltura(raiz);

    int balanceamento = fatorBalanceamento(raiz);

    //balanceamento
    if (balanceamento > 1 && strcmp(novoNodo->item.name, raiz->esquerdo->item.name) < 0)
        return rotacaoDireita(raiz);

    if (balanceamento < -1 && strcmp(novoNodo->item.name, raiz->direito->item.name) > 0)
        return rotacaoEsquerda(raiz);

    if (balanceamento > 1 && strcmp(novoNodo->item.name, raiz->esquerdo->item.name) > 0){
        raiz->esquerdo = rotacaoEsquerda(raiz->esquerdo);
        return rotacaoDireita(raiz);
    }

    if (balanceamento < -1 && strcmp(novoNodo->item.name, raiz->direito->item.name) < 0){
        raiz->direito = rotacaoDireita(raiz->direito);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}




//sucessor
struct nodo_AVL* encontrarMinimo(struct nodo_AVL* nodo){
    struct nodo_AVL* atual = nodo;
    while (atual->esquerdo != NULL)
        atual = atual->esquerdo;
    return atual;
}


struct nodo_AVL* remover(struct nodo_AVL* nodo, char name[]){
    if (nodo == NULL){
        printf("a chave %i nao foi encontrada.\n", name);
        return nodo;
    }
    if(strcmp(name, nodo->item.name) < 0)
        nodo->esquerdo = remover(nodo->esquerdo, name);
    else if(strcmp(name, nodo->item.name) > 0)
        nodo->direito = remover(nodo->direito, name);
    else {
        //nodo encontrado
        if (nodo->esquerdo == NULL || nodo->direito == NULL){
            struct nodo_AVL* temp = nodo->esquerdo ? nodo->esquerdo : nodo->direito;

            if (temp == NULL){
                temp = nodo;
                nodo = NULL;
            } 
            else{
                *nodo = *temp;
            }
            free(temp);
        } 
        else{
            struct nodo_AVL* temp = encontrarMinimo(nodo->direito);
            strcpy(nodo->item.name, temp->item.name);
            nodo->direito = remover(nodo->direito, temp->item.name);
        }
    }

    if (nodo == NULL)
        return nodo;

    atualizarAltura(nodo);

    int balanceamento = fatorBalanceamento(nodo);

    //balanceamento
    if (balanceamento > 1 && fatorBalanceamento(nodo->esquerdo) >= 0)
        return rotacaoDireita(nodo);

    if (balanceamento > 1 && fatorBalanceamento(nodo->esquerdo) < 0){
        nodo->esquerdo = rotacaoEsquerda(nodo->esquerdo);
        return rotacaoDireita(nodo);
    }

    if (balanceamento < -1 && fatorBalanceamento(nodo->direito) <= 0)
        return rotacaoEsquerda(nodo);

    if (balanceamento < -1 && fatorBalanceamento(nodo->direito) > 0){
        nodo->direito = rotacaoDireita(nodo->direito);
        return rotacaoEsquerda(nodo);
    }

    return nodo;
}