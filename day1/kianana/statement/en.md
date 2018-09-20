{{ self.title() }}

{{ s('description') }}

There is a huge park in C Empire, which has $n$ shops inside the park. Between these $n$ shops, there are $n-1$ biconnected ways, such that each pair of shops can reach each other. All shops sells only candies. In shop $i$, the most expensive candy is $n_i$ dollar. $a_{i,j}$ types of candies are sold at a price of $j$ $0\le j \le n_i$ dollars at shop $i$, so there are $\sum_{j=0}^{n_i} a_{i,j}$ different types of candies sold in shop $i$.

Access Globe and temporaryDO want to have $m$ picnics in this park. In the $k$th picnic, they will enter the park at shop $s_k$ and decide to have a picnic at shop $t_k$. They will go from $s_k$ to $t_k$ through the shortest path, and buy exactly one candy at each passing shop $i$. After they go to $t_k$, as spending more money will bring more happiness, they will get $x_k^v$ happiness if they spend $v$ dollars. 

We say if two ways to buy candies are different, if and only if there exists a shop such that they buy different types of candy in these two ways. Access Globe wants to know the summation of happiness among all different ways in each picnic. And in order to reduce the amount of output, you only have to output the summation of happiness modulo $998,244,353$.

{{ s('input format') }}

{{ self.input_file() }}

The first line contains $T$, the number of test cases. Then for each test case:

The first line contains $n$ and $m$, the number of shops and picnics.

For the following $n$ lines, the $i$th line contains $n_i+1$ numbers $n_i,a_{i,1},...,a{i,n_i}$.

For the following $n-1$ lines, each line contains $x$ and $y$, denotes one biconnected way between $x$ and $y$.

For the following $m$ lines, the $k$th line contains $s_k$, $t_k$ and $x_k$, denotes one picnic.

{{ s('output format') }}

{{ self.output_file() }}

For each picnic, output the the summation of happiness among all different ways modulo $998,244,353$ in one line.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

Between 14'o clock to 17'o clock,two hands concide three times. At **about** 14:11,15:16 and 16:22.