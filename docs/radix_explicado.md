# Explicando o Radix

Radix é um método de ordenação baseado em **bitwise**, aonde fazemos operações baseadas em `0` e `1` da representação binária dos números.

Antes de fazer a ordenação, colocamos um `index` em cada valor. Passamos pelos números e vemos onde esse valor deveria estar na pilha. Indicamos colocando o index (quantos números é menor que ele) como se fosse uma etiqueta, então se um dos números recebeu o index `0` significa que ele é o menor número, desta maneira paramos de olhar para os valores em si.

Imagine que um dos números que foi inserido é o número `5278105` (é um número gigante), em binários ele ficaria assim:
```bash
00000000 01010000 10001001 10011001
```

Justamente por esse motivo que "etiquetamos" cada número/pilha da stack, vamos pegar esse mesmo número gigante que acabamos de usar de exemplo, digamos que inserimos `100` números, todos desordenados, o programa pega esses números vê que o número `5278105` que inserimos era pra estar ordenado na `81ª` posição daqueles `100` números que colocamos, logo etiquetamos ele com o index `81` que em binário é `01010001`, ou seja tem `80` números menores que ele.

Após etiquetar todos os números com seus respectivos index, passamos a ignorar o valor real do número, afinal, agora sabemos qual posição ele deveria estar (index), vamos nos basear no `index` em binário, pra fazer toda a ordenação.

Através dos indexes fazemos o **bitwise**, cuja o sistema olha pro número como binário, exemplo:
```bash
0 = 00000000
1 = 00000001
2 = 00000010
3 = 00000011
4 = 00000100
5 = 00000101
...
```
Por que isso é importante, verificamos qual é o maior index, se for uma ordenação com `100` números, o maior index é o `99` pois temos o `zero` como index também, `99 = 01100011`, ou seja contamos quantos bits são necessários para representar o maior index. No binário de `99` ele fica na 6ª posição (contando da direita pra esquerda e baseando-se que o index começa com 0), então vamos fazer o **Radix** verificar bit a bit de cada index começando pelo bit menos significativo (mais a direita do binário).
Vou montar um exemplo:

Imagine que temos muitos números (assim o programa não chama o minisort), os números estão desordenados e estamos olhando só pro index deles em binário. O **Radix** vai fazer varias passagens entre os binários até o maior binário (pois ele tem o sempre o `1` na ultima casa que temos que verificar).

O que "0º Radix" significa nessa tabela que criei: Significa qual bit do binário ele está fazendo a verificação, então se for o "1º Radix", ta olhando pro segundo bit da direita pra esquerda, "2" o terceiro e por ai vai.

Se o bit for `0` ele joga o número pra **Stack B** (pb), se for `1` ele joga pra última posição (rotaciona) da **Stack A** (ra), depos devolve todos da **B** pra **A** com (pa) e verificamos o bit a seguir.

(destaquei com "()" qual bit o Radix está comparando)
| 0º Radix | 1º Radix | 2º Radix | 3º Radix |
|----------|----------|----------|----------| 
| 02 = 0000001(0) | 02 = 000000(1)0 | 32 = 00100(0)00 | 32 = 00100(0)00
| 32 = 0010000(0) | 32 = 001000(0)0 | 85 = 01010(1)01 | 97 = 01100(0)01
| 51 = 0011001(1) | 42 = 001010(1)0 | 13 = 00001(1)01 | 02 = 00000(0)10
| 85 = 0101010(1) | 51 = 001100(1)1 | 61 = 00111(1)01 | 42 = 00101(0)10
| 13 = 0000110(1) | 85 = 010101(0)1 | 21 = 00010(1)01 | 51 = 00110(0)11
| 42 = 0010101(0) | 13 = 000011(0)1 | 97 = 01100(0)01 | 85 = 01010(1)01
| 61 = 0011110(1) | 61 = 001111(0)1 | 69 = 01000(1)01 | 13 = 00001(1)01
| 21 = 0001010(1) | 21 = 000101(0)1 | 02 = 00000(0)10 | 61 = 00111(1)01
| 97 = 0110000(1) | 97 = 011000(0)1 | 42 = 00101(0)10 | 21 = 00010(1)01
| 69 = 0100010(1) | 69 = 010001(0)1 | 51 = 00110(0)11 | 69 = 01000(1)01

Os elementos vão ficando parcialmente ordenados a cada bit, mantendo a ordenação dos bits anteriores, no fim todos estariam ordenados. As verificações iriam até o número de bits necessários para representar o maior index, nessa tabela do exemplo o maior binário é o `97 = 0(1)100001`, e ele tem `1` somente até a `6ª` casa (lembrando que o index começa em 0).

Mas é basicamente isso, o entendimento do que o **Radix** faz não é complicado, dificil é mais a implementação em si, devido a tratar os index e tudo mais. 
