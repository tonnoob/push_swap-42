*This project has been created as part of the 42 curriculum by osousa-d.*

# push_swap

## Description

The **push_swap** project is an algorithmic challenge whose goal is to sort a stack of integers using a restricted set of operations, while minimizing the total number of moves.

The program receives a list of integers as arguments, stores them in **stack A**, and must sort them in ascending order using only the allowed operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.) and an auxiliary **stack B**.

Simplificando, temos 2 stack (**A** e **B**), colocamos **números** (pilhas) aleatórios e desordenados na **A** e temos que finalizar com esses números ordenados do **menor (topo da stack)** para o **maior (base da stack)** na **A**, temos a **stack B** para nos auxiliar.

Podemos ordenar esses números com movimentos restritos, sendo eles:

Push: Pega o primeiro número (topo) de uma stack e joga no topo da outra stack;
`pa` (stack A) joga para a stack B e `pb` (stack b) joga para a stack A;

Swap: Pega os primeiros (topo) 2 números de uma stack e troca eles de lugar;
`sa` (stack A), `sb` (stack B) e `ss` (stack A e B);

Rotate: Pega o primeiro (topo) número de uma stack e coloca ele por último (base) da mesma stack;
`ra`(stack A), `rb` (stack B) e rr (stack A e B);

Rotate Reverse: Pega o último (base) número de uma stack e coloca colo primeiro (topo) da mesma stack;
`rra`(stack A), `rrb` (stack B) e `rrr` (stack A e B);

This implementation uses:
- A **linked list** to represent stacks
	- t_stack com size e top;
	- t_node com value, index e next;
- **Radix sort** for medium and large input sizes
- A **mini_sort** strategy for small stacks (2 to 5 elements), ensuring optimal or near-optimal move counts

---

### Compilation

At the root of the project, run:

```bash
make

## Instructions
