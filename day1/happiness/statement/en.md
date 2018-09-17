{{ self.title() }}

{{ s('description') }}

There is a huge park in C Empire, which has $n$ shops inside the park. Between these $n$ shops, there are $n-1$ biconnected ways, such that each pair of shops can reach each other. All shops sells only candies. In shop $i$, the most expensive candy is $n_i$ dollar. $a_{i,j}$ types of candies are sold at a price of $j$ $0\le j \le n_i$ dollars at shop $i$, so there are $\sum_{j=0}^{n_i} a_{i,j}$ different types of candies sold in shop $i$.

Access Globe and temporaryDO want to have $m$ picnics in this park. In the $k$th picnic, they will enter the park at shop $s_k$ and decide to have a picnic at shop $t_k$. They will go from $s_k$ to $t_k$ through the shortest path, and buy exactly one candy at each passing shop $i$. After they go to $t_k$, as spending more money will bring more happiness, they will get $x_k^v$ happiness if they spend $v$ dollars. 

We say if two ways to buy candies are different, if and only if there exists a shop such that they buy different types of candy in these two ways. Access Globe wants to know the summation of happiness among all different ways in each picnic. And in order to reduce the amount of output, you only have to output the summation of happiness modulo $998,244,353$.

{{ s('input format') }}

{{ self.input_file() }}

??

{{ s('output format') }}

{{ self.output_file() }}

??

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

$n\le 10^5, m\le 5\times 10^4, T\le 100$.

No more than $3$ test cases that $n,m\ge 10^3$.