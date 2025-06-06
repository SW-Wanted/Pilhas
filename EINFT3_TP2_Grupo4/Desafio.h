typedef struct no Lista;
typedef struct pilha Pilha;

Pilha * InicializarPilha();
void Push(Pilha ** p, int valor);
int Pop(Pilha ** p);
void Popn(Pilha ** p, int n);
void ImprimirPilha(Pilha * p);
void SubstituirElemento(Pilha ** p, int valorAtual, int valorNovo);
int ObterValorMinimo(Pilha * p);
int ObterValorMaximo(Pilha * p);
void EliminarPilha(Pilha ** p);
