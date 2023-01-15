# Educational Codeforces Round 141 (Rated for Div. 2) Problem A

Constructive Problem.

## Problem Statement

Rearrange an array $a$ $(a_i>0)$ in an order that none of the elements is equal to the sum of all elements before it.

## Observation

If we rearrange the elements arbitarily, then we can find out that after several elements, the sum of previous elements will be very big, and the latter elements will be way smaller than the sum of previous elements.

Therefore, the key of the solution is about how to satisfy the condition of the first few elements.

Also, the observation gives us a hint to the solution. Can we rearrange the elements, that the sum of the previous elements will be bigger than all latter elements very soon?

The answer is yes. If we move the biggest element to the first, then the sum of previous elements will be no less than all latter elements. And if the second element is not equal to the first element, the constraint will be satisfied.

## Solution

If all elements have the same value, the solution doesn't exist. Else, move the biggest element to $a_1$ and move the smallest element to $a_2$, then the rest elements can be assigned in arbitary order.