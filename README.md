*This project has been created as part of the 42 curriculum by osousa-d.*

[Versão em português 🇧🇷](docs/README-ptbr.md)

![](docs/img.png)

# push_swap

## Description

The **push_swap** project is an algorithmic challenge whose goal is to sort a stack of integers using a restricted set of operations, while minimizing the total number of moves.

The program receives a list of integers as arguments, stores them in **stack A**, and must sort them in ascending order using only the allowed operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.) and an auxiliary **stack B**.

In simple terms, we have two stacks (**A** and **B**). We place random, unsorted **numbers** into **stack A**, and the goal is to end with these numbers sorted in **ascending order**, from the **smallest (top of the stack)** to the **largest (bottom of the stack)** in **stack A**. **Stack B** is used as auxiliary support during the process.

We can sort these numbers using a restricted set of moves, which are:

### Push
Takes the first number (top) from one stack and places it on top of the other stack.  
`pa` pushes from **stack B** to **stack A**, and `pb` pushes from **stack A** to **stack B**.

### Swap
Takes the first two numbers (top) of a stack and swaps their positions.  
`sa` (stack A), `sb` (stack B), and `ss` (stack A and B).

### Rotate
Takes the first number (top) of a stack and moves it to the last position (bottom) of the same stack.  
`ra` (stack A), `rb` (stack B), and `rr` (stack A and B).

### Reverse Rotate
Takes the last number (bottom) of a stack and moves it to the first position (top) of the same stack.  
`rra` (stack A), `rrb` (stack B), and `rrr` (stack A and B).


### Implementation Details
This implementation uses:
- A **linked list** to represent the stacks:
  - `t_stack` containing `size` and `top`
  - `t_node` containing `value`, `index`, and `next`
- **Radix sort** for medium and large input sizes.
	- I gave an explanation for Radix:  [Explaining the radix](docs/radix_explained.md)

- A **mini_sort** strategy for small stacks (2 to 5 elements), ensuring optimal or near-optimal move counts
	- Minisort is another sorting method, but it's used for specific cases where we check if **Stack A** has a size between `5` and `2`, because Radix sort isn't the most efficient method for small numbers; it would make many unnecessary moves. So, minisort is only used in these specific cases.

---

### Compilation

At the root of the project, run:

```bash
make
```

## Instructions ##

After compiling the project, you must execute the **push_swap** file with the arguments:

```bash
./push_swap "<number>"
```
The project accepts two types of arguments:

```bash
./push_swap "3 2 -1 51 2"
```
or

```bash
./push_swap 3 -2 1 +51 2
```
(without quotation marks)

The arguments are not passed randomly; the following inputs are not allowed:

- Only the program name;
- Empty strings or strings containing only spaces;
- Arguments that are not numbers;
- A sign without a number;
- int overflow / underflow (2147483647 and -2147483648);
- Duplicate numbers;
- Arguments with numbers attached to text;
- Malformed zero values (++0, --0, 0-0);

---

After running the program with the arguments, it will print the moves required to sort the numbers.

```bash
./push_swap 3 -2 1 +51 2
ra
pb
pb
ra
pa
pa
```

## Scoring Rules ##

The project is evaluated according to the number of operations required to sort the stacks:

- 100 numbers in under 1100 operations and 500 numbers in under 8500 operations

- 100 numbers in under 700 operations and 500 numbers in under 11500 operations

- 100 numbers in under 1300 operations and 500 numbers in under 5500 operations

---

How to Properly Validate the Project

To validate the project in the best way, use the Push Swap Visualizer:

👉 https://push-swap42-visualizer.vercel.app/

Step-by-step:

- 1. Open the visualizer and generate the amount of numbers you want to test.

- 2. Copy the generated numbers.

- 3. Run your push_swap program with those numbers as arguments.

- 4. Your program will output the list of operations used to sort the stack.

- 5. Copy the operations from the terminal (CTRL + Shift + C).

- 6. Paste them into the "Instructions" tab of the visualizer.

- 7. Go to the "Simulation" page and press Play to visualize the sorting process.

This allows you to clearly verify:

- If the stack is correctly sorted

- The total number of operations used

- The behavior of your algorithm step by step
---

## Resources ##

I used ChatGPT (https://chatgpt.com/) to help me understand radix sort, organize the project (deciding the next steps), and translate the `README` into English.

The website to visually see how the sorting works: 
https://push-swap42-visualizer.vercel.app/
