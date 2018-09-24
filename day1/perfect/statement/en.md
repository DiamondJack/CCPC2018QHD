{{ self.title() }}

{{ s('description') }}

Given a positive integer $k$, we define a **rooted** tree to be $k$-perfect, if and only if it met both conditions below:

* Each node is either a leaf node or has exactly $k$ direct offsprings.
* All leaf nodes have the same distance to the root, or say, all leaf nodes are of the same depth.

Now you are given an **unrooted** tree, and you should answer these questions:

* Is it possible to assign it a root, such that the tree becomes $k$-perfect for some positive integer $k$?
* If possible, what is the minimal possible $k$?

{{ s('input format') }}

{{ self.input_file() }}

Each input file contains multiple testcases.

The first line contains a single positive integer $T$, indicating following are $T$ testcases.

For each testcase, its first line contains a positive integer $n$, describing the number of tree nodes in this testcase; next $n-1$ lines each contains two space-separated integers, where a pair $u,v$ means there exists an edge between node $u$ and $v$ on the tree.

It is guaranteed each input is a valid unrooted tree, and the nodes are numbered with consecutive integers from $1$ to $n$.

The sum of $n$ in each input file will not exceed $10^6$.

{{ s('output format') }}

{{ self.output_file() }}

For each testcase, output a single integer in a line:

* If the answer to the first question is "No", output $-1$.
* Otherwise, output the minimal possible $k$.

{{ s('sample', 1) }}

{{ self.sample_text() }}
