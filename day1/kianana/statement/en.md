{{ self.title() }}

{{ s('description') }}

Recently Kiana loves a new game KIANANA. This is a supperzzle game and Kiana wants to introduce it to you.

In KIANANA, the game area is a $n\times m$ matrix with a candy in each grid. There are at most six different colors of candy. The players can make some operations to remove the candies and get scores. If there are three or more candies with the same color adjoining in a row or column, then they will be removed from the game area. When some candies are removed, the new candies will fall down from the top of the game area.

The players in this game can exchange two adjoining candies( The matrix is thought to be 4-connected). After the exchanging, if there is no candy can be removed, then this operation is failed and these two candies would not be really exchanged.

If four candies with the same color are exchanged to be adjoining in a row and then be removed, there will generate a vertical stripes candy with the same color of those removed candies at the leftmost of the four grids. If four candies with the same color are exchanged to be adjoining in a column and then be removed, there will generate a horizontal stripes candy with the same color of those removed candies at the bottom of the four grids. Vertical stripes candies and horizontal stripes candies can be regarded as normal candies, but when a vertical stripes candy is removed, all candies stay in the same column will be removed, and when a horizontal stripes candy is removed, all candies stay in the same row will be removed. After exchanging a chocolate candy, it will be removed, too.

If five or more candies with the same color are exchanged to be adjoining in a row and then be removed, there will generate a chocolate candy at the leftmost of those grids. If five or more candies with the same color are exchanged to be adjoining in a column and then be removed, there will generate a chocolate candy at the bottom of those grids. Chocolate candies have no color. If you exchange a chocolate candy with a non-chocolate candy, then all candies in the game area with the same color of the non-chocolate candy will be removed. If you exchange two chocolate candies, then all candies in the game area will be removed. If a chocolate candy is removed without being exchanging, it will not remove any other candy.

Notice that only candies exchanged to be adjoining in a row or column will generate vertical stripes candy,horizontal stripes candy or chocolate candy. Removed by vertical stripes candy,horizontal stripes candy or chocolate candy, or removed after sometime falling down will not generate special candies.

After a successful exchanging, firstly all candies which should be removed are removed from the game area. Each vertical stripes candy,horizontal stripes candy or chocolate candy will give $3$ scores to the player when be removed. Each other candy will give $1$ score to the player when be removed. After removing those candies, new candies will fall down. When falling down, each candy will go to the grid under it while it's empty, and some candies will go into the game area from the outer of the area.

It is possible that after falling down there are three or more candies with the same color adjoining in a row or column, which means they should be removed from the game area. After all empty grids is filled in the area, remove those candies, and the scores given by each candy is doubled during this removing. Then candies fall down, and if there are also some candies should be removed, just repeat the steps above( Notice that after the second times of candies falling down, the scores given by candy will be doubled again, that means, four times of the initial score, and so on). When sometime after falling down there are no three or more candies with the same color adjoining in a row or column, the scores given by each candy will return to the initial value and the player could make the next exchange.

Now Kiana wants you to help her playing this game. When making a exchange, Kiana will consider the following operations in order:

①If there are two chocolate candies adjoining in the game area, Kiana will exchanging them. 

②If there is a chocolate candy in the game area, Kiana will exchange it with a adjoining candy whose color appears the most times in the game area.

③If there is a candy can be exchanged to remove a vertical stripes candy or horizontal stripes candy directly( That means, after exchanging this candy will stay with a vertical stripes candy or horizontal stripes candy in the same row or column with three or more candies with the same color adjoining), Kiana will do so.

④If there two candies can be exchanged to make five candies with the same color adjoining in a row or column, Kiana will do so.

⑤If there two candies can be exchanged to make four candies with the same color adjoining in a row or column, Kiana will do so.

⑥If there two candies can be exchanged to make five candies with the same color adjoining in a row or column, Kiana will do so.

When considering some operation above, if there are more than one candies satisfy the condition, Kiana will choose the lowest one( or two). If there are still mutiple choices, Kiana will choose the leftmost one( or two).

If sometime when Kiana should make a exchange, but all the above operations is unavailable, or sometime there are no candies can fall down to fill the empty grid in the game area, then the game will over immediately.

Now you are given a $k\times m$ matrix($k\geq n$) with candies. The bottom $n\times m$ grids represents the game area. Other candies can fall down into the game area after some candies removed. Kiana wantes you to tell her that according to the given operations, how many scores she will get finally.

{{ s('input format') }}

{{ self.input_file() }}

There are several test cases in the data, the first line contains one integer $T(\leq10)$ that the number of cases. Then for each test case:

The first line contains three integers $k,n,m$ whose meaning is given in the statement. It is guaranteed that $n,m$ are no more than $10$ and $k$ is no more than $30$.

Then there will follow $k$ lines. The $i$th line contains a string with length $m$, each letter represents a candy given in the game. Two candies with the same color are represented by the same letter. It is guaranteed that each letter is between '$A$'~'$F$'.

It is also guaranteed that there will not be three or more candies with the same color adjoining in a row or column in the initial game area. Notice that no vertical stripes candy,horizontal stripes candy or chocolate candy is given initially.

{{ s('output format') }}

{{ self.output_file() }}

For each test case, output one integer that the final scores Kiana will get in the game.

{{ s('sample', 1) }}

{{ self.sample_text() }}