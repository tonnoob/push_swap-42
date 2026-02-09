# Explaining Radix Sort

Radix is ​​a bitwise sorting method where we perform operations based on the `0` and `1` of the binary representation of numbers.

Before sorting, we assign an `index` to each value. We go through the numbers and see where that value should be on the stack. We indicate this by placing the index (how many numbers are smaller than it) as if it were a label, so if one of the numbers received the index `0`, it means that it is the smallest number. In this way, we stop looking at the values ​​themselves.

Imagine that one of the numbers that was entered is the number `5278105` (it's a huge number), in binary it would look like this:
```bash
00000000 01010000 10001001 10011001
```

That's precisely why we "label" each number/stack. Let's take that same giant number we just used as an example. Let's say we input 100 numbers, all out of order. The program takes these numbers, sees that the number 5278105 we entered should be sorted in the 81st position of those 100 numbers we entered, so we label it with the index 81, which in binary is 01010001. That is, there are 80 numbers smaller than it.

After labeling all the numbers with their respective indexes, we start to ignore the actual value of the number, because now we know what position it should be in (index). We will base the sorting on the binary index.

Through the indexes we perform **bitwise** sorting, where the system looks at the number as binary, for example:
```bash
0 = 00000000
1 = 00000001
2 = 00000010
3 = 00000011
4 = 00000100
5 = 00000101
...
```
Why is this important? We check which is the largest index. If it's a sorting with `100` numbers, the largest index is `99` because we also have `zero` as an index, `99 = 01100011`, meaning we count how many bits are needed to represent the largest index. In the binary of `99`, it's in the 6th position (counting from right to left and based on the index starting with 0). So, we'll have **Radix** check bit by bit of each index, starting with the least significant bit (the rightmost bit in the binary).

Let's create an example:

Imagine we have many numbers (so the program doesn't call minisort), the numbers are out of order, and we're only looking at their binary index. **Radix** will make several passes through the binary numbers until we find the largest binary number (because it always has a `1` in the last position we need to check).

What "0th Radix" means in this table I created: It means which bit of the binary it's checking. So, if it's the "1st Radix," it's looking at the second bit from right to left, "2" the third, and so on.

If the bit is `0`, it moves the number to **Stack B** (pb), if it's `1`, it moves it to the last position (rotaciona) of **Stack A** (ra), then returns all the bits from **B** to **A** with (pa) and we check the next bit.

(I highlighted with "()" which bit the Radix is ​​comparing)
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

The elements become partially sorted bit by bit, maintaining the order of the previous bits; eventually, all would be sorted. The checks would continue until the number of bits needed to represent the highest index is reached. In the example table, the highest binary is `97 = 0(1)100001`, and it only has `1` up to the `6th` position (remembering that the index starts at 0).

---
But that's basically it. Understanding what **Radix** does isn't complicated; the implementation itself is more difficult, due to handling the indexes and everything else.
