{{ self.title() }}

## {{ _('Description') }}

Alice, Bob and Yazid are good friends.

Each of them has a **r**ed, **g**reen or **b**lue color. They can describe their own color in the format of `[name] is [color].`, such as `Yazid is green.`.

Now they made their description in some order. After that, Yazid will do the following operations:

1. Connect the $3$ sentences and get **initial string**.
2. Remove all non-alphabetic characters.
3. Change all uppercase letters to lowercase.

For example, if the initial string is `Yazid is green. Alice is red. Bob is blue.`, then after Yazid's all operation, they will be turned to `yazidisgreenaliceisredbobisblue`.

Finally, Alice and Bob will insert any lowercase letters in any position in this string and get **final string**.

You are given the final string. Your task is to find the initial string. In particular:

* If there are multiple solutions, please output the minimum one in lexical order.

* If there is no solution, please output `No solution.` instead.

## {{ _('Input Format') }}

{{ self.input_file() }}

Input data contains multiple cases. The first line contains one integer $T$, representing the number of test cases. For each case:

* One line of a string containing only lowercase letters, representing the final string.

* It is guaranteed that the length of final string won't exceed $600$.

$T\leq 500$

## {{ _('Output Format') }}

{{ self.output_file() }}

For each case:

* One line of string, representing the initial string.

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}


