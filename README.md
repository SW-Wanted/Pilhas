# Pilhas

Este repositório apresenta a implementação de uma **pilha de inteiros** (stack) usando **listas ligadas simples** em linguagem C, com suporte a operações básicas e avançadas. O projeto foi realizado como parte da disciplina **Estrutura de Dados I** no curso de Engenharia Informática (ISPTEC, 2º Ano).

## 🎯 Objectivo

O foco deste projeto é:
- Compreender a estrutura e operação de uma **pilha dinâmica**.
- Implementar **operações clássicas** (push, pop).
- Adicionar **operações otimizadas**, como acesso a mínimo e máximo em tempo constante.
- Praticar o uso de ponteiros e manipulação dinâmica de memória.

---

## 🧱 Operações Implementadas

- `inicializarPilha()`: cria uma pilha vazia
- `push(valor)`: insere um elemento no topo
- `pop()`: remove o topo da pilha
- `pop(n)`: remove os `n` elementos do topo

- `imprimirPilha()`: imprime todos os elementos sem destruir
- `substituir(valorAntigo, novoValor)`: substitui a primeira ocorrência

- `minimo()`: retorna o menor valor da pilha em tempo **O(1)**
- `maximo()`: retorna o maior valor da pilha em tempo **O(1)**

- `destruirPilha()`: libera toda a memória alocada

---

## 📁 Estrutura de Arquivos
```bash
├── EINFT3_TP2_Grupo4/
│   ├── Desafio.c
│   ├── Desafio.h
│   └── main.c
├── 2PP_EIN3_T2_B
└── README.md
```


---

## ⚙️ Compilação e Execução

```bash
gcc Desafio.c main.c -o pilha
./pilha