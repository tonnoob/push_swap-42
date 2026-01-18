*This project has been created as part of the 42 curriculum by osousa-d.*

# push_swap

## Description

The **push_swap** project is an algorithmic challenge whose goal is to sort a stack of integers using a restricted set of operations, while minimizing the total number of moves.

The program receives a list of integers as arguments, stores them in **stack A**, and must sort them in ascending order using only the allowed operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.) and an auxiliary **stack B**.

This implementation uses:
- A **linked list** to represent stacks
- **Radix sort** for medium and large input sizes
- A **mini_sort** strategy for small stacks (2 to 5 elements), ensuring optimal or near-optimal move counts

---

## Instructions

### Compilation

At the root of the project, run:

```bash
make
