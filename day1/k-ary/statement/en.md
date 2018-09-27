{{ self.title() }}

{{ s('description') }}

Little Chimaki prepares a problem for you today!

She generates all $k$-ary trees that contain exactly $n$ nodes. A $k$-ary tree is a rooted tree in which each node has no more than $k$ children. Binary tree is the special case where $k=2$.

After that, she randomly picks one of them. Let us denote it by $T$. Then she calculates the size of each subtree on $T$, and sums them up. Formally, she calculates the following formula for $T$:
$$
S_T=\sum_{u\in T}size_u
$$

where $size_u$ denotes the size of the subtree which is rooted at node $u$.

Now Chimaki wants to know the expectation of $S_T$. In other words, let $T\_set$ be the set of all the $k$-ary trees Chimaki generated, please help her to calculate the value of the following formula:
$$
\frac{1}{|T\_set|}\sum_{T\in T\_set}S_T
$$
Two $k$-ary trees are different if and only if the following function returns *True*.

```
struct Node {
    Node *ch[k];    //this->ch[i] points to the k-th child of this Node
};

bool cmp(Node* T1, Node* T2)
{
    if (T1 == NULL && T2 == NULL) return False;
    if (T1 == NULL || T2 == NULL) return True;
    for (int i = 0; i < k; i++) {
        if (cmp(T1->ch[i], T2->ch[i])) return True;
    }
    return False;
}
```

{{ s('input format') }}

{{ self.input_file() }}

The input consists of multiple test cases.

The first line of the input is an integer $T$, denoting the number of the test cases. The value of $T$ is about $20$.

Each of the following $T$ lines provides two integers $n$ and $k$, denoting that Chimaki generates $k$-ary trees containing $n$ node(s).

It is guaranteed that in each test case the values of $n$ and $k$ satisfy $1\le n\le 6\times 10^4$ and $1\le k \le 10^9$. There are at most 3 test cases with $n \ge 4\times 10^4$.

{{ s('output format') }}

{{ self.output_file() }}

It is obvious that the answer is a rational number and can be denoted with $\frac{p}{q}$, where $p,q$ are relatively prime. Let $P=998244353$, and you need to find $0\le s <P$ that satisfies $p\equiv sq (\bmod P)$.

For each test case, output the value of $s$ in a single line.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

In the first test case, there are three possible $k$-ary trees:

{{ img('explanation.png', size = 1, align = 'middle', inline = False) }}

The value of $S$ of each tree is $3$. Thus the answer is $3$.
