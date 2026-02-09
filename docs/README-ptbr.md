*Este projeto foi criado como parte do currículo 42 por osousa-d.*

![](img.png)

# push_swap

## Descrição

O projeto **push_swap** é um desafio algorítmico cujo objetivo é ordenar uma stack (pilha) de inteiros usando um conjunto restrito de operações, minimizando o número total de movimentos.

O programa recebe uma lista de inteiros como argumentos, armazena-os na **Stack A** e deve ordená-los em ordem crescente usando apenas as operações permitidas (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.) e uma **Stack B** auxiliar.

De forma simples, temos duas pilhas (**A** e **B**). Colocamos **números** aleatórios e não ordenados na **Stack A**, e o objetivo é terminar com esses números ordenados em **ordem crescente**, do **menor (topo da Stack)** ao **maior (base da Stack)** na **Stack A**. A **Stack B** é usada como suporte auxiliar durante o processo.

Podemos ordenar esses números usando um conjunto restrito de movimentos, que são:

### Push
Pega o primeiro número (do topo) de uma Stack e o coloca no topo da outra Stack.
`pa` empurra da **Stack B** para a **Stack A**, e `pb` empurra da **Stack A** para a **Stack B**.

### Swap
Pega os dois primeiros números (do topo) de uma Stack e troca suas posições.
`sa` (Stack A), `sb` (Stack B) e `ss` (pilhas A e B).

### Rotate
Pega o primeiro número (do topo) de uma Stack e o move para a última posição (base) da mesma Stack.
`ra` (Stack A), `rb` (Stack B) e `rr` (pilhas A e B).

### Reverse Rotate
Pega o último número (base) de uma Stack e o move para a primeira posição (topo) da mesma Stack. `rra` (Stack A), `rrb` (Stack B) e `rrr` (pilhas A e B).

---
### Detalhes da Implementação
Esta implementação utiliza:
- Uma **lista ligada** para representar as stacks:
	- `t_stack` contendo `size` e `top`
	- `t_node` contendo `value`, `index` e `next`
- **Radix** para a ordenação de tamanhos de entrada médios e grandes.
	- Eu fiz uma explicação sobre o radix: [Explicando o radix](radix_explicado.md)
- A ordenação **mini_sort** para pilhas pequenas (2 a 5 elementos), garantindo contagens de movimentos ideais ou quase ideais.
	- O minisort é outro método de ordenação, só que é feito para casos específicos, cujos verificamos se a **Stack A** tem o tamanho entre `5` e `2`, pois o Radix não é o método mais êficaz pra números pequenos, ele faria muitos movimentos desnecessários. Então só nesses casos específicos o minisort é chamado.

---
### Compilação

Na raiz do projeto, execute:

```bash
make
```

## Instruções ##

Após compilar o projeto, você deve executar o arquivo **push_swap** com os seguintes argumentos:

```bash
./push_swap "<números>"
```
O projeto aceita dois tipos de argumentos:

```bash
./push_swap "3 2 -1 51 2"
```
ou

```bash
./push_swap 3 -2 1 +51 2
```
(sem aspas)

Os argumentos não são passados ​​aleatoriamente; as seguintes entradas não são permitidas:

- Apenas o nome do programa;
- Cadeias vazias ou cadeias contendo apenas espaços;
- Argumentos que não sejam números;
- Um sinal sem um número;
- Overflow/underflow de int (2147483647 e -2147483648);
- Números duplicados;
- Argumentos com números anexados a texto;
- Valores zero malformados (++0, --0, 0-0);

---
Após executar o programa com os argumentos, ele imprimirá os movimentos necessários para ordenar os números.

```bash
./push_swap 3 -2 1 +51 2
ra
pb
pb
ra
pa
pa
```

## Critérios de Avaliação ##

O projeto é avaliado de acordo com o número de operações necessárias para ordenar as pilhas:

- 100 números em menos de 1100 operações e 500 números em menos de 8500 operações

- 100 números em menos de 700 operações e 500 números em menos de 11500 operações

- 100 números em menos de 1300 operações e 500 números em menos de 5500 operações

Baseado no resultado das operações fui pontuado de acordo com a régua.

---
Como validar o projeto corretamente

Para validar o projeto da melhor forma, utilize o Push Swap Visualizer:

👉 https://push-swap42-visualizer.vercel.app/

Passo a passo:

- 1. Abra o visualizador e gere a quantidade de números que deseja testar.
- 2. Copie os números gerados.
- 3. Execute seu programa push_swap com esses números como argumentos.
- 4. Seu programa exibirá a lista de operações usadas para ordenar a pilha.
- 5. Copie as operações do terminal (CTRL + Shift + C).
- 6. Cole-as na aba "Instructions" do visualizador.
- 7. Vá para a página "Simulation" e clique em "Play" para visualizar o processo de ordenação.

Isso permite verificar claramente:
- Se a pilha está ordenada corretamente
- O número total de operações usadas
- O comportamento do seu algoritmo passo a passo
---

## Recursos ##

Utilizei o ChatGPT (https://chatgpt.com/) para me ajudar a entender o radix sort, organizar o projeto (definindo os próximos passos) e traduzir o arquivo `README` para o inglês.

O site para visualizar como a ordenação funciona:
https://push-swap42-visualizer.vercel.app/
