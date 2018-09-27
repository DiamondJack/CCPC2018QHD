{{ self.title() }}

{{ s('description') }}

Given a positive integer $k$, we define a **rooted** tree to be $k$-perfect, if and only if it meets both conditions below:

* Each node is either a leaf node or having exactly $k$ direct offsprings.
* All leaf nodes have the same distance to the root (i.e., all leaf nodes are of the same depth).

Now you are given an **unrooted** tree, and you should answer these questions:

* Is it possible to assign it a root, so that the tree becomes $k$-perfect for some positive integer $k$?
* If possible, what is the minimal $k$?

{{ s('input format') }}

{{ self.input_file() }}

Each input contains multiple test cases.

The first line contains a single positive integer $T$, indicating the number of test cases.

For each test case, its first line contains a positive integer $n$, describing the number of tree nodes. Each of the next $n-1$ lines contains two space-separated integers $u$ and $v$, which means there exists an edge between node $u$ and $v$ on the tree.

It is guaranteed each test case gives a valid unrooted tree, and the nodes are numbered with consecutive integers from $1$ to $n$.

The sum of $n$ in each input will not exceed $10^6$.

{{ s('output format') }}

{{ self.output_file() }}

For each test case, output a single integer in a line:

* If the answer to the first question is "No", output $-1$.
* Otherwise, output the minimal $k$.

{{ s('sample', 1) }}

{{ self.sample_text() }}
