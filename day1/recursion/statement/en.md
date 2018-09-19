{{ self.title() }}

{{ s('description') }}

Let's define a recursion $f(n, m)$ as follows:

$$
\begin{aligned}
&f(0,0)=0 \\
&f(x, y) = 2\cdot f\left( \left\lceil \frac{y-x}{2} \right\rceil + \left\lceil \frac{-x-y}{2} \right\rceil \right) + [x+y\equiv 1\bmod 2]
\end{aligned}
$$

Here $\lceil x \rceil$ means 'rounded up', namely, the smallest integer $k$ which satisfy $x\le k$. 

The value of boolean formula $[...]$ is $1$, if and only if the statement `...` in it is true. Otherwise it has value $0$.

It's not hard to see that our recursion is well-defined, that is, given $n,m$, the value of $f(n, m)$ is uniquely determined.

Here we give three examples: $f(1,0)=1$, $f(-1,1)=1$ and $f(0,1)=2$ .

Now it comes to your part: given integers $L,R,D,U$, please calculate the following:
$$
\sum_{i=L}^{R}\sum_{j=D}^{U} f(i, j)
$$
You only need to output answer modulo $10^9+7$ .

{{ s('input format') }}

Multiple testcases.

First line, an integer $T$, denotes the number of testcases.

Following $T$ lines, each line contains four integers, seperated by space, denotes $L,R,D,U$ respectively.

It's guaranteed that $T\le 50$, the **abosolute value** of $L,R,U,D$ doesn't exceed $10^{18}$, and $L\le R, D\le U$ .

{{ s('output format') }}

For each testcases, print a single line contains a single integer, denotes the answer after modulo $10^9+7$ .