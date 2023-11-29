struct descritor_arvore{
	//int tamanho;
	struct nodo_AVL *raiz;
};

struct nodo_AVL{
	struct equipment_label item;
	int altura;
	//struct nodo_AVL *pai;
	struct nodo_AVL *esquerdo;
	struct nodo_AVL *direito;	
};

void inOrder(struct nodo_AVL *arvore);
void preOrder(struct nodo_AVL *arvore);
void postOrder(struct nodo_AVL *arvore);

struct nodo_AVL* criaNodo(struct equipment_label item);
struct descritor_arvore* inicializa(void);
struct nodo_AVL* inserir(struct nodo_AVL* nodo_AVL, struct nodo_AVL* novoNodo);

struct nodo_AVL* rotacaoEsquerda(struct nodo_AVL* nodo_AVLDesbalanceado);
struct nodo_AVL* rotacaoDireita(struct nodo_AVL* nodo_AVLDesbalanceado);
void atualizarAltura(struct nodo_AVL* nodo_AVL);
int fatorBalanceamento(struct nodo_AVL* nodo_AVL);
int altura(struct nodo_AVL* nodo_AVL);

struct nodo_AVL* encontrarMinimo(struct nodo_AVL* nodo);
struct nodo_AVL* remover(struct nodo_AVL* nodo, char name[]);