{{ self.title() }}

## Description

You are given $n$ integers $a[1]\dots a[n]$, and you can choose any two numbers from $a$. If you choose $a[i]$ and $a[j]$, you will get $a[i]-a[j]$ points.

Now, you want to maximize your score. Please calculate your maximum score and which $i,j$ you should choose in order to get the maximum score.

If there are more than one pair of $i,j$, please output the pair with minimum $i$. If there are still more than one pair, please output the one with minimum $j$.

## Input

{{ self.input_file() }}

The first line contains one integer $n$, which denotes the size of $a$.

The second line contains $n$ integers $a[i]\dots a[n]$. It is guaranteed that for each $a[i]$, its absolute value does not exceed ${{ tools.hn(prob.args['a']) }}$.

$(1\leq n\leq {{ tools.hn(prob.args['n']) }})$

## Output

{{ self.output_file() }}

One line contains three integers denoting your maximum score, $i$, and $j$.

**It is guaranteed that the maximum score does not exceed the range of signed 32-bit integer.**


{{ self.sample_text() }}
