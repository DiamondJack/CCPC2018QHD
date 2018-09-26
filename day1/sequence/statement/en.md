{{ self.title() }}

## {{ _('Description') }}

Yazid has a sequence $A$ of length $n$, and now he wants to fill in a plus or multiplier between every two numbers to get an expression. Obviously, he has a total of $2^{n-1}$ different filling schemes. For each scheme, we specify its score as the value of the resulting expression.

The score of a sequence is the sum of all the filling scheme scores modulo $998,244,353$.

Yazid wants to know the score of the sequence. What's more, Yazid will make modification for several times, every time changing a number in the sequence, and you will need to tell him the score of the new sequence after each modification.

## {{ _('Input Format') }}

{{ self.input_file() }}

The $1$st line contains one integer $n$.

The $2$nd line contains $n$ space-seperated integers $A_1,\dots,A_n$.

The $3$rd line contains one integer $Q$.

In the next $Q$ lines, each line contains two space-seperated integers $i,b$, representing a modification that changes $A_i$ to $b$.

$1\leq i\leq n\leq 2\times 10^5$

$0\leq Q\leq 2\times 10^5$

$0\leq A_{i},b < 998,244,353$

## {{ _('Output Format') }}

{{ self.output_file() }}

Output $n+1$ lines, $1$ integer per line. The $i$-th line is the score of the sequence after the $(i-1)$-th modification. In particular, the $1$st line is the score of the initial sequence.

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{{ self.title_sample_description() }}

The expressions for the $4$ schemes of the initial sequence are: $1+2+3=6$, $1+2\times 3=7$, $1\times 2+3=5$, $1\times 2\times 3 =6$. So the sequence score is $6+7+5+6=24$.

After the $1$st modification, the new sequence is $4,2,3$.

After the $2$nd modification, the new sequence is $4,1,3$.

{% do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_text() }}
