union item{
    struct equipment_helmet helmet;
	struct equipment_superior_armor superior_armor;
	struct equipment_inferior_armor inferior_armor;
	struct equipment_boots boots;
	struct equipment_accessory accessory;
	struct equipment_weapon weapon;
};

struct descritor_arvore{
	//int tamanho;
	struct nodo_AVL *raiz;
};

struct nodo_AVL{
	union item item;
	int altura;
	//struct nodo_AVL *pai;
	struct nodo_AVL *esquerdo;
	struct nodo_AVL *direito;	
};

void inOrder(struct nodo_AVL *arvore);
void preOrder(struct nodo_AVL *arvore);
void postOrder(struct nodo_AVL *arvore);

struct nodo_AVL* criaNodo(union item item);
struct descritor_arvore* inicializa(void);
struct nodo_AVL* inserir(struct nodo_AVL* nodo_AVL, struct nodo_AVL* novoNodo);

struct nodo_AVL* rotacaoEsquerda(struct nodo_AVL* nodo_AVLDesbalanceado);
struct nodo_AVL* rotacaoDireita(struct nodo_AVL* nodo_AVLDesbalanceado);
void atualizarAltura(struct nodo_AVL* nodo_AVL);
int fatorBalanceamento(struct nodo_AVL* nodo_AVL);
int altura(struct nodo_AVL* nodo_AVL);

struct nodo_AVL* encontrarMinimo(struct nodo_AVL* nodo);
struct nodo_AVL* remover(struct nodo_AVL* nodo, char name[]);