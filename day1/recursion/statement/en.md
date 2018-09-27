{{ self.title() }}

{{ s('description') }}

Let's define a recursion $f(n, m)$ as follows:

$$
\begin{aligned}
&f(0,0)=0 \\
&f(x, y) = 2\cdot f\left( \left\lceil \frac{y-x}{2} \right\rceil + \left\lceil \frac{-x-y}{2} \right\rceil \right) + [x+y\equiv 1\bmod 2]
\end{aligned}
$$

Here $\lceil x \rceil$ means **rounded up**, namely, the smallest integer $k$ which satisfies $x\le k$. 

The value of boolean formula $[...]$ is $1$, if and only if the statement `...` in it is true. Otherwise, it has value $0$.

It's not hard to see that our recursion is well-defined, that is, given $n,m$, the value of $f(n, m)$ is uniquely determined.

Here we give three examples: $f(1,0)=1$, $f(-1,1)=2$ and $f(0,1)=3$ .

Now it comes to your part: given integers $N$ and $M$, please calculate the following:

$$
\sum_{i=-N}^{N}\sum_{j=-M}^{M} f(i, j)
$$

You only need to output the answer modulo $10^9+7$ .

{{ s('input format') }}

{{ self.input_file() }}

There are multiple test cases.

The first line, an integer $T$, denotes the number of test cases.

For the following $T$ lines, each line contains two integers, separated by a space, denoting $N$ and $M$ respectively.

It's guaranteed that $T\le 1000$,  $0\le N, M\le 10^{15}$.

{{ s('output format') }}

{{ self.output_file() }}

For each test case, output an integer denoting the answer modulo $10^9+7$.

{{ s('sample', 1) }}

{{ self.sample_text() }}

