{{ self.title() }}

{{ s('description') }}

Lucas Skipper is given a sequence $A$ whose length is $n$ (The sequence is $1$-indexed). Lucas will do $Q$ operations on this sequence in order. The $i$-th operation is to sort the numbers in interval $[l_i,r_i]$ in ascending order.

You are a fan of Lucas, so you want to know the sequence after all of his operations.

{{ s('input format') }}

{{ self.input_file() }}

The first line contains one integer $n$, which means the length of $A$.

The second line contains $n$ integers $A[1]\dots A[n]$, which describe the sequence.

The third line contains one integer $Q$, which means the number of operations.

The next $Q$ lines, each line contains $2$ integers $l_i,r_i$, describing the $i$-th operation.

$1\leq n\leq {{ tools.hn(prob.args['n']) }}$.

$1\leq A[i]\leq {{ tools.hn(prob.args['a']) }}$.

$1\leq Q\leq {{ tools.hn(prob.args['Q']) }}$.

$1\leq l_i\leq r_i\leq n$.

{{ s('output format') }}

{{ self.output_file() }}

One line containing $n$ integers denoting the final sequence, separated by single spaces.

{{ self.sample_text() }}
