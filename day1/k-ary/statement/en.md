{{ self.title() }}

{{ s('description') }}

Little Chimaki prepare a problem for you today!

She generates all $k$-ary trees that contains exactly $n$ nodes. A $k$-ary tree is a rooted tree in which each node has no more than $k$ children. Binary tree is the special case where $k=2$.

After that, she randomly pick one of them, let us denote it by $T$, then she calculate the size of each subtree on $T$, and sum them up. Formally, she calculate the following formula for $T$:
$$
S_T=\sum_{u\in T}size_u
$$

where $size_u$ denote the size of the subtree which is rooted at node $u$.

Now that Chimaki wants to know the expectation of $S_T$, or in other words, let $T\_set$ be the set of all the $k$-ary tree Chimaki generated, please help her to calculate the value of the following formula:
$$
\frac{1}{|T\_set|}\sum_{T\in T\_set}S_T
$$
Two $k$-ray tree are different if the following function returns *True*.

```c++
struct Node {
    Node *ch[k];	//this->ch[i] points to the kth child of this Node
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

The input consists of multiple testcases.

First line of the input is an integer $T$, denotes the number of the testcases. The value of $T$ is about $20$.

Each of the following $T$ lines provides two integers $n,k$, denotes that Chimaki generates $k$-ary trees contains $n$ node(s).

It is guaranteed that in each testcases the value of $n,k$ satisfies $1\le n\le 6\times 10^4, 1\le k \le 10^9$. There are at 

{{ s('output format') }}

It is obviously that the answer is a rational number and can be denote with $\frac{p}{q}$ where $p,q$ are relatively prime. Let $P=998244353$, you need to find $0\le s <P$ that satisfies $p\equiv sq (\bmod P)$.

For each testcases, output the value of $s$ in a single line.{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

In the first testcases, there are there possible $k$-ary trees:

{{img('explanation.bmp')}}

The value of $S$ of each tree is $3$, thus the answer is $3$.