{{ self.title() }}

## Description

Kblack loves flags. He has $n$ flags in a row, placing from left to right. The left $x$-th is numbered $x$, whose color is $c[x]$. We use the numbers ranged from $[1,m]$ to describe the flags' colors.

Kblack wants to calculate$$\sum_{1\leq i< j\leq n \bigwedge c[j]=c[i]} \left( j-i\right) ^2$$

Can you help him?

## Input

{{ self.input_file() }}

You should generate the input data in your program.

We have a private variable $x$ in the generation, which equals to $seed$ initially. When you call for a random number ranged from $[l,r]$, the generation transforms $x$ into $\left(50268147x+6082187\right)\ mod\ 100000007$. And then, it returns $x\ mod\ \left(r-l+1 \right)+l$.

The first line contains a single integer $T$ referring to the number of test cases.

For each test case, there is a single line containing 3 integers $n,m,seed$.

Then, you need to generate the $n$ flags' colors one by one.

For $i=1\dots n$, generate a random number in the range of $\left[1,m \right]$.

'Init' in the file "init"(pseudocode) could help you generate $c[]$.

$\left(1\leq T\leq {{ tools.hn(prob.args['T']) }} \right)$

$\left(1\leq n\leq {{ tools.hn(prob.args['n']) }} \right)$

$\left(1\leq m\leq {{ tools.hn(prob.args['m']) }} \right)$

$\left(0\leq seed<100000007 \right)$

## Output

{{ self.output_file() }}

For each test case, output one line with a single integer denoting the answer.

{{ self.sample_text() }}

## Hint

The flags in the first case: $1,2,3$.

The flags in the second case: $2,2,1,2$.
