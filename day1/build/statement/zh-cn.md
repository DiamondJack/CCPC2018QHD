{{ self.title() }}

{{ s('description') }}

In preparation for a possible war in the future, Country T has built $n$ communication stations, numbered from $1$ to $n$, with the No. $1$ station located in the capital, and the No. $n$ station located nearest to the troops stationed in the front-line. There **may be one or more bidirectional** communication lines between any two communication stations, thus forming a communication network with $m$ communication lines. Communication stations, directly or indirectly connected by communication lines can communicate with each other. If a communication line is destroyed, it can no longer transmit information. The whole communication network is paralyzed, if the No. $1$ station and the No. $n$ station can no longer communicate with each other.

With the increasing tension in international relations, the top leader of Country T thought it probable that conflicts with the neighboring country would happen in the near future. So he decided to strengthen the communication network. Considering the limited military expenditure, the leader asked you, the most intelligent team, to plan a best scheme.

We believe that the existing communication network is too easy to be destroyed. The enemy can destroy any communication line with little efforts at zero cost. So we should reasonably raise the security level of some lines.

The engineering team has assessed all communication lines. For a communication line numbered $i$, $cost_i$ is required for each level increased, and the possible highest level is $max_i$ for various reasons. After reinforcement, the cost for the enemy to destroy the line will be equal to its security level.

Let’s imagine the worst case in the future, in which the structure of the reinforced communication network is known by the enemy. The cost for destroying a communication station is enormous compared to destroying a communication line, so the enemy will not try to destroy the communication station. Instead, they will try to pay the lowest cost to destroy some of the communication lines to paralyze the communication network.

Given the limited total amount of reinforcement cost $F$, you are asked to determine the security level of each line to be reinforced according to the data provided by the engineering team, so that the cost is highest for the enemy to make the communications network paralyzed.

{{ s('input format') }}

{{ self.input_file() }}

The first line contains three integers: $n$, $m$, and $F$, standing for the number of communication stations, the number of communication lines and the limit amount of reinforcement cost ($1 \leq n \leq 1000, 0 \leq m \leq 10000, 1 \leq F \leq 10^{18} $).

For the following $m$ lines, each contains four integers, $u_i$, $v_i$, $max_i$ and $cost_i$, which means there is a line between station $u_i$ and $v_i$ with the possible highest security level $max_i$ and it costs $cost_i$ for every security level increased ($1 \leq u_i, v_i \leq n, 0 \leq max_i \leq 1000, 0 \leq cost_i \leq 10^6, u_i \neq v_i$).

{{ s('output format') }}

{{ self.output_file() }}

Output an integer indicating the minimum cost to paralyze the communication network for the best reinforcement scheme.

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

For line $(1,2)$ and $(5,6)$, increase the security level to 2; For line $(2,3)$, $(2,4)$, $(3,5)$ and $(4,5)$, increase the security level to 1. This is the best scheme with the total reinforcement cost as $8$, less than $10$. It will cost the enemy $2$ at least to paralyze the communication network. For example, the enemy can pay 2 to destroy $(1,2)$. The enemy cannot parayze the communication network only at cost $1$, because they cannot destroy line $(1,2)$ or $(5,6)$. If they destroy line $(2,3)$ or $(3,5)$, the path $1-2-4-5-6$ enables communication; if they destroy line $(2,4)$ or $(4,5)$, the path $1-2-3-5-6$ enables communication.

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

For line $(1,2)$ and $(5,6)$, increase the security level to 5 at zero cost. For line $(2,3)$, $(2,4)$, $(3,5)$ and $(4,5)$, increase the security level to $2$. It can be proved that this is the best scheme with the total reinforcement cost as $8$. It will cost the enemy $4$ to paralyze the communication network by destroying line $(2,3)$ and $(2,4)$.
