# Educational Codeforces Round 141 (Rated for Div. 2) Problem C

Greedy Algorithm.

## Problem Statement

There is a contest where each pair of players will play against each other. There are $n$ players other than you. When they play against each other, player $i$ defeats player $j$ if $i>j$.

When you play against one of the $n$ players, you need to prepare for $a_i$ time to defeat player $i$, otherwise you will be defeated by player $i$.

The overall rank is decided by the total winning rounds of each player. You want to minimize your rank, and you have $m$ time to prepare for all opponents in total, what is your minimal rank?

## Observation

If we rearrange the elements arbitarily, then we can find out that after several elements, the sum of previous elements will be very big, and the latter elements will be way smaller than the sum of previous elements.

Therefore, the key of the solution is about how to satisfy the condition of the first few elements.

Also, the observation gives us a hint to the solution. Can we rearrange the elements, that the sum of the previous elements will be bigger than all latter elements very soon?

The answer is yes. If we move the biggest element to the first, then the sum of previous elements will be no less than all latter elements. And if the second element is not equal to the first element, the constraint will be satisfied.

## Solution

If all elements have the same value, the solution doesn't exist. Else, move the biggest element to $a_1$ and move the smallest element to $a_2$, then the rest elements can be assigned in arbitary order.