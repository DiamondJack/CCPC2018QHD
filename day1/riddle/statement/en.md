{{ self.title() }}

{{ s('description') }}

Kiana wants to give you a riddle. She gives you a piece of paper with $n$ numbers on it. Each two numbers are considered to be different although they may have the same value.

Some numbers on the paper represents the weight of some toys, while the others represents the weight of some giftbags which containing those toys. It is **NOT** required that each toy should be put into a giftbag, but each giftbag whose weight written on the paper should contain at least one toy. The weight of a giftbag is the total weight of toys it contains. Two toys or two giftbags are thought to be different if their weights are presented by different numbers.

The riddle is how many different kinds of ways can Kiana get these numbers on the paper. Two ways are thought to be different if one of the numbers represents different kinds of weight( In one way it represents the weight of a toy but in the other way it represents the weight of a giftbag) or one of the giftbags contains different toys.

{{ s('input format') }}

{{ self.input_file() }}

There are several test cases in the data, the first line contains one integer $T(\leq5)$ that the number of cases. Then for each test case:

The first line contains one integer $n$ that how many numbers are written on the paper. It is guaranteed that $n$ is no more than $15$.

The second line contains $n$ integers, which represents the numbers Kiana wirte on the paper. It is guaranteed that each of the numbers is no more than $2000$.

{{ s('output format') }}

{{ self.output_file() }}

For each test case, output one integer that how many different kinds of ways can Kiana get these numbers in a single line.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

In the first test case, there are $7$ different ways to get these numbers:

①All three numbers represent the weight of toys, which means there are no giftbags.

②The first number represents the weight of a giftbag containing a toy whose weight is representing by the second number. The third number represents the weight of a toy not be put into a giftbag.

③The first number represents the weight of a giftbag containing a toy whose weight is representing by the third number. The second number represents the weight of a toy not be put into a giftbag.

④The second number represents the weight of a giftbag containing a toy whose weight is representing by the first number. The third number represents the weight of a toy not be put into a giftbag.

⑤The second number represents the weight of a giftbag containing a toy whose weight is representing by the third number. The first number represents the weight of a toy not be put into a giftbag.

⑥The third number represents the weight of a giftbag containing a toy whose weight is representing by the first number. The second number represents the weight of a toy not be put into a giftbag.

⑦The third number represents the weight of a giftbag containing a toy whose weight is representing by the second number. The first number represents the weight of a toy not be put into a giftbag.

Notice that ② and ③ are different ways although they both mean one giftbag contains only one toy with weight $1$. But the toy in the giftbag in two ways are thought to be different because their weights are presented by different numbers.