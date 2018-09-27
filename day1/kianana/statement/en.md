{{ self.title() }}

{{ s('description') }}

Recently Kiana loves a new game KIANANA. This is a supperzzle game and Kiana wants to introduce it to you.

In KIANANA, the game area is an $n\times m$ matrix with a candy in each grid. There are at most six different colors of candy. The players can make some operations to remove the candies and get scores. If there are three or more candies with the same color adjoining in a row or column, then they will be removed from the game area. When some candies are removed, more candies will fall down from the top of the game area.

The players in this game can swap two adjoining candies (The matrix is considered to be 4-connected). After the swap, if there is no candies that can be removed, then this operation is failed and these two candies would not be really swapped.

If four candies with the same color are adjoining in a row after a swap and then be removed, a vertical striped candy will be generated with the same color as those removed ones at the leftmost of the four grids. If four candies with the same color are adjoining in a column after a swap and then be removed, a horizontal striped candy will be generated with the same color as those removed ones at the bottom of the four grids. Vertical striped candies and horizontal striped candies can be regarded as normal ones, but when a vertical striped candy is removed, all candies stay in the same column in the game area will be removed, and when a horizontal striped candy is removed, all candies stay in the same row will be removed. After swapping with a chocolate candy, a striped candy will be removed, too.

If five or more candies with the same color are adjoining in a row after a swap and then be removed, a chocolate candy will be generated at the leftmost of those grids. If five or more candies with the same color are adjoining in a column after a swap and then be removed, a chocolate candy will be generated at the bottom of those grids. Chocolate candies have no color. If you swap a chocolate candy with a non-chocolate candy, all candies in the game area with the same color as the non-chocolate candy will be removed, together with the swapped chocolate candy. If you swap two chocolate candies, all candies in the game area will be removed. If a chocolate candy is not removed by swapping, no other candies will be removed.

Notice that only a swap that causes multiple candies of the same color to be adjoining in a row or column will generate a vertical striped candy, a horizontal striped candy or a chocolate candy. Removes caused by a vertical striped candy, a horizontal striped candy or a chocolate candy, or removes after candies fall down will not generate special candies.

After a successful swap, firstly all candies that should be removed are removed from the game area. Every vertical striped candy, horizontal striped candy or chocolate candy will give $3$ scores to the player when being removed. Every other candy will give $1$ score to the player when being removed. After removing those candies, the remaining above candies will fall down to fill the empty grids, and some candies will come into the game area from the top side.

It is possible that after falling down there are three or more candies with the same color adjoining in a row or column, which means they should be removed from the game area. After all empty grids are filled in the area, remove those candies, and the scores given by each candy is doubled for this kind of remove. Then candies fall down again, and if again some candies should be removed, just repeat the steps above (Notice that when candies fall down for the second time, scores given by removed candies will be doubled again, that means four times of the initial score, and so on). If no more candies can be removed after falling down, scores given by removed candies will return to the initial value and the player can make the next swap.

Now Kiana wants you to help her playing this game. Before making a swap, Kiana will consider the following operations in order:

1) If there are two chocolate candies adjoining in the game area, Kiana will swap them. 

2) If there is a chocolate candy in the game area, Kiana will exchange it with an adjoining candy whose color appears the most times in the game area.

3) If a candy can be swapped to remove a vertical striped candy or horizontal striped candy directly (That means, after the swap this candy will stay with a vertical striped candy or horizontal striped candy in the same row or column with three or more candies with the same color adjoining), Kiana will do so.

4) If two candies can be swapped to make five candies with the same color adjoining in a row or column, Kiana will do so.

5) If two candies can be swapped to make four candies with the same color adjoining in a row or column, Kiana will do so.

6) If two candies can be swapped to make three candies with the same color adjoining in a row or column, Kiana will do so.

When considering these operations, if there are more than one candy satisfying the conditions, Kiana will choose the lowest one (or two). If there are still mutiple choices, Kiana will choose the leftmost one (or two).

If none of the above operations is possible, or no more candies fall down in the game area, then the game is over immediately.

Now you are given a $k\times m$ matrix($k\geq n$) with candies. The bottom $n\times m$ grids represent the game area. Upper candies can fall down into the game area after some candies are removed. Kiana wants you to tell her how many scores she will get finally according to the given operation order.

{{ s('input format') }}

{{ self.input_file() }}

There are several test cases in the data. the first line contains one integer $T$($T\leq10$), the number of cases. Then for each test case:

The first line contains three integers $k,n,m$ whose meaning is given in the above statement. It is guaranteed that $n,m$ are no more than $10$ and $k$ is no more than $30$.

For the next $k$ lines, the $i$-th line contains a string with length $m$, each letter representing a candy given in the game. Candies with the same color are represented by the same letter. It is guaranteed that each letter is between '$A$'~'$F$'.

It is also guaranteed that there will not be three or more candies with the same color adjoining in a row or column initially in the game area. Notice that there is no vertical striped candies, horizontal striped candies or chocolate candies initially.

{{ s('output format') }}

{{ self.output_file() }}

For each test case, output one integer that the final scores Kiana will get in the game.

{{ s('sample', 1) }}

{{ self.sample_text() }}
