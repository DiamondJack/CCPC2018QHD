{{ self.title() }}

## Description

​	Yuuka has got a tree of $n$ vertices. There is a value $a_i$ attached to the $i$-th vertex of the tree. Yuuka has a mysterious number $k$, and she wants to choose a non-empty connected subset of these $n$ vertices. In other words, for each pair $a,b$ of the chosen vertices, all vertices along the path between $a$ and $b$ must be chosen as well.

​	For a chosen subset of vertices $S$ , we are interested in the following characteristic of $S$, denoted by $f(S)$:
$$
f(S) := \sum_{i \in S} a_i \pmod k.
$$
​	That is, the sum of all $a_i​$'s for the vertices in $S​$ modulo $k​$. 

​	Yuuka is really concerned with counting problems, so she is interested in the following question: for each integer $i$ such that $1 \le i \le k -1$, how many distinct non-empty connected subsets $S$ satisfy $f(S) = i$?

​	You only need to output the number module $10^9 + 7$.

## Input format

​	The first line contains two integers $n,k$, where $n$ is the number of the vertices in the tree, $k$ is the mysterious number.

​	The next line contains $n$ numbers, the $i$-th number $a_i$ being the value attached to the $i$-th vertex of the tree.

​	Then $n-1$ lines follow,  the $i$-th line containing two integers $a_i,b_i$, denoting that there is an edge between vertices $a_i$ and $b_i$ in the tree.

​	We guarantee that $1 \le n \le 50000$, $2 \le k \le 500$, and for each $1 \le i \le n$, we have $0 \le a_i < k$. 

## Output format

​	For each $1 \le i \le k-1$, output a line containing the number of distinct non-empty connected subsets $S$ satisfying $f(S) = i$ module $10^9 + 7$.

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{% do vars.__setitem__('sample_id', 2) -%}
{{- self.sample_text() }}


