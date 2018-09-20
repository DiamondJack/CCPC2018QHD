{{ self.title() }}

{{ s('description') }}

Kiana has $n$ toys and $m$ giftbags. Each two toys are different while all giftbags are the same. The $i$th toy has a weight $w_i$. Each giftbag can contain toys with arbitrary numbers and total weight.

Now Kiana wants to give you a riddle. Firstly Kiana writes down the weight of each toy on a piece of paper. Then she puts some toys into some giftbags( It is **NOT** required that each toy should be put into a giftbag or each giftbag should contain at least one toy). Finally Kiana weighs each giftbag and writes down the weight on the same paper.

Kiana gives the paper to you, and the riddle is how many different kinds of ways can Kiana get these numbers on the paper. Two ways are think to be different, if one of the numbers represents different kinds of weight( In one way it represents the weight of a toy and in the other way it represents the weight of a giftbag) or one of the giftbags contains different toys.

Notice that you **DO NOT** know the value of $n$, $m$ and every $w_i$, but only $n+m$ numbers on the paper. It is possible that there are two ways to get the same numbers on the paper, but $n$ or $m$ or $w_i$ in them are different( So the two ways are different).

{{ s('input format') }}

{{ self.input_file() }}

There are several test cases in the data, the first line contains one integer $T(\leq10)$ represents the number of cases. Then for each test case:

The first line contains one integer $k$, where $k=m+n$ represents the total number of toys and giftbags. It is guaranteed that $k$ is no more than $15$.

The second line contains $k$ integers, which represents the numbers Kiana wirte on the paper. It is guaranteed that each of the number is no more than $1000$.

{{ s('output format') }}

{{ self.output_file() }}

For each test case, output one integer representing how many different kinds of ways can Kiana get these numbers in a single line.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

Between 14'o clock to 17'o clock,two hands concide three times. At **about** 14:11,15:16 and 16:22.