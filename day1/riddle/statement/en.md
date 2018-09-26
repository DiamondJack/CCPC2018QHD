{{ self.title() }}

{{ s('description') }}

Kiana wants to give you a riddle. She gives you a piece of paper with $n$ numbers on it. Any two numbers are considered different although they may have the same value.

Some numbers on the paper represent the weight of some toys, while the others represent the weight of some giftbags which containing those toys. It is **NOT** required that each toy should be put into a giftbag, but each giftbag whose weight written on the paper should contain at least one toy. The weight of a giftbag is the total weight of toys it contains. Two toys or two giftbags are considered different if their weights are represented by different numbers.

The riddle is how many different ways Kiana can get these numbers on the paper. Two ways are considered different if one of the numbers represents different kinds of weight (In one way it represents the weight of a toy but in the other way it represents the weight of a giftbag) or one of the giftbags contains different toys.

{{ s('input format') }}

{{ self.input_file() }}

There are several test cases in the data. The first line contains one integer $T(\leq5)$, the number of cases. Then for each test case:

The first line contains one integer $n$ denoting how many numbers are written on the paper. It is guaranteed that $n$ is no more than $15$.

The second line contains $n$ integers, which represent the numbers Kiana wirte on the paper. It is guaranteed that each of the numbers is no more than $2000$.

{{ s('output format') }}

{{ self.output_file() }}

For each test case, output one integer denoting how many different ways Kiana can get these numbers.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

In the first test case, there are $7$ different ways to get these numbers:

①All three numbers represent the weight of toys, which means there are no giftbags.

②The first number represents the weight of a giftbag containing a toy whose weight is represented by the second number. The third number represents the weight of a toy not in a giftbag.

③The first number represents the weight of a giftbag containing a toy whose weight is represented by the third number. The second number represents the weight of a toy not in a giftbag.

④The second number represents the weight of a giftbag containing a toy whose weight is represented by the first number. The third number represents the weight of a toy not in a giftbag.

⑤The second number represents the weight of a giftbag containing a toy whose weight is represented by the third number. The first number represents the weight of a toy not in a giftbag.

⑥The third number represents the weight of a giftbag containing a toy whose weight is represented by the first number. The second number represents the weight of a toy not in a giftbag.

⑦The third number represents the weight of a giftbag containing a toy whose weight is represented by the second number. The first number represents the weight of a toy not in a giftbag.

Notice that ② and ③ are different ways although they both mean one giftbag containing only one toy with weight $1$. But the toy in the giftbag in two ways are considered to be different because their weights are represented by different numbers.
