{{ self.title() }}

{{ s('description') }}

There is a huge park with $n$ shops inside and all these shops are connected by $n-1$ paths. All the shops sell only candies. In shop $i$, the most expensive candy is $n_i$ dollar. $a_{i,j}$ types of candies are sold at a price of $j$ ($0\le j \le n_i$) dollars at shop $i$, so there are $\sum_{j=0}^{n_i} a_{i,j}$ different types of candies sold in shop $i$.

Access Globe and temporaryDO want to have $m$ picnics in this park. In the $k$-th picnic, they will start from shop $s_k$ and go to shop $t_k$ to have the picnic. They will go through the shortest path from shop $s_k$ to shop $t_k$ and buy exactly one candy at each passing shop $i$. When they arrive at shop $t_k$, as spending more money will bring more happiness, they will get $x_k^v$ happiness if they spend $v$ dollars. 

We say two ways to buy candies are different, if and only if there exists a shop such that they buy different types of candy in these two ways. Access Globe wants to know the summation of happiness of all different ways in each picnic. And in order to reduce the amount of output, you only have to output the summation of happiness modulo $998,244,353$.

{{ s('input format') }}

{{ self.input_file() }}

The first line contains $T$ ($T\le 100$), the number of test cases. Then for each test case:

The first line contains $n$ and $m$ ($n\le 10^5, m\le 5\times 10^4$), the number of shops and picnics. There are no more than $3$ test cases in which $n,m\ge 10^3$.

For the following $n$ lines, the $i$-th line contains $n_i+2$ numbers $n_i, a_{i,0}, a_{i,1}, ..., a_{i,n_i}$ ($n_i\le 5, 0\le a_{i,j}< 998,244,353, a_{i,n_i}\ne 0​$).

For the following $n-1$ lines, each line contains $x$ and $y$, denoting one path connecting shop $x$ and $y$.

For the following $m$ lines, the $k$-th line contains $s_k$, $t_k$ and $x_k$ for one picnic.

{{ s('output format') }}

{{ self.output_file() }}

For each picnic, output the summation of happiness of all different ways modulo $998,244,353$ in one line.

{{ s('sample', 1) }}

{{ self.sample_text() }}
