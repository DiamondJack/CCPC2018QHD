{{ self.title() }}

## Description

​	For a convex polygon $P$ and a segment of positive reals $[l,r]$, we define their product, denoted by $P \circ [l,r]$ , as follows:
$$
P \circ [l,r] := \{ a \cdot p : a \in [l,r], p \in P  \}.
$$
​	It is easy to see that $P \circ [l,r]$ is also a convex polygon.

​	Yuuka has got a convex polygon $P$ with $n$ vertices, such that all vertices have positive x-coordinates and positive y-coordinates.  In addition, she also has got a set of $m$ segments of positive reals, denoted by $s_1 = [l_1,r_1],s_2=[l_2,r_2],\dotsc,s_m = [l_m,r_m]$. 

​	Surprisingly, all segments of Yuuka satisfy an interesting property: it has the form of $[x,2x]$, in other words, $r_i = 2 \cdot l_i$, for all $i$.

​	Yuuka wants to choose exactly $k$ of these $m$ segments, so that the area of the union of the convex polygons $P \circ s_{a_1}, P \circ s_{a_2},\dotsc,P \circ s_{a_k}$ are maximized, where $s_{a_1},s_{a_2},\dotsc,s_{a_k}$ are the chosen segments.

​	Can you help Yuuka to calculate the maximum area of the union?

## Input format

​	The first line contains three integers $n,m,k$, where $n$ is the number of the vertices in $P$, $m$ is the number of the segments and $k$ is the number of segment to be chosen.

​	Then $n$ lines follows,  the $i$-th line contains two integers $x_i,y_i$, denoting that the $i$-th vertex in $P$ is $(x_i,y_i)$.

​	Then $m$ lines follows, the $i$-th line contains two integers $l_i,r_i$, denoting that the $i$-th segment is $[l_i,r_i]$.

​	We guarantee that $3 \le n \le 100$, $1 \le m \le 100$, $1 \le k \le m$. 

​	The vertices of $P$ are given in counter-clockwise order, all the vertices will be distinct. It is possible for three consecutive vertices to be colinear.  

​	For all $i$ from $1$ to $n$, we have $0 < x_i,y_i \le 10^4$. For all $i$ from $1$ to $m$, we have $0 < l_i \le r_i \le 10^4$, and $r_i = 2 \cdot l_i$.

## Output format

​	One line contains the maximum area of the union.

​	Your solution will be considered as correct if either relative or absolute error is smaller than $10^{-4}$.

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{% do vars.__setitem__('sample_id', 2) -%}
{{- self.sample_text() }}


