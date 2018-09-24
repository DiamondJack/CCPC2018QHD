{{ self.title() }}

## {{ _('Description') }}

Alice, Bob and Yazid are good friends.

Each of them has a color, **r**ed, **g**reen or **b**lue. They can describe their own color in the format of `[name] is [color].`, such as `Yazid is green.`.

Now they have made their descriptions in some order. After that, Yazid will do the following operations:

1. Connect the $3$ sentences to get the **initial string**.
2. Remove all non-alphabetic characters.
3. Change all uppercase letters to lowercase.

For example, if the initial string is `Yazid is green.Alice is red.Bob is blue.`, then after Yazid's all operations, it will be turned to `yazidisgreenaliceisredbobisblue`.

Finally, Alice and Bob will insert any lowercase letters into any positions in this string to get the **final string**.

You are given the final string. Your task is to find the initial string. In particular:

* If there are multiple solutions, please output the minimum one in lexical order.

* If there is no solution, please output `No solution.` instead.

## {{ _('Input Format') }}

{{ self.input_file() }}

The first line contains one integer $T$ ($T\leq 500$), representing the number of test cases. For each case:

* One line of a string containing only lowercase letters, representing the final string.

* It is guaranteed that the length of final string won't exceed $600$.


## {{ _('Output Format') }}

{{ self.output_file() }}

For each case:

* One line of string, representing the initial string or `No solution.`.

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}


