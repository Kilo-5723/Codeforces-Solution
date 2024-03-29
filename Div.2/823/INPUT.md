# Codeforces Round #823 (Div. 2)

- Problem C:
  - 单调栈

# Problem A

Solved at 00:02 (+)

题意：

有 $n$ 个行星在 $100$ 个轨道上，每次可以用 $1$ 的代价删除一颗行星或者 $c$ 的代价删除一个轨道上的所有行星，求删除所有行星的最小代价。

题解：

对每个轨道分开考虑，看这个轨道上的行星是一个一个删划算还是花 $c$ 的代价一起删了划算。

# Problem B

Solved at 00:07 (+)

题意：

数轴上有 $n$ 个人，第 $i$ 个人会在 $t_i$ 时刻从 $x_i$ 出发，找一个集会点使得所有人到齐的时间最短。

题解：

首先考虑 $t_i=0$ 的时候怎么做，显然集会点取 $(x_{\max}+x_{\min})/{2}$ 最优。考虑 $t_i>0$，此时相当于同时考虑两个分别在 $x_i+t_i$ 和 $x_i-t_i$ 的人，因为当集会点 $>x_i$ 时，这个人等价于从 $x_i-t_i$ 出发，集会点 $<x_i$ 时等价于从 $x_i+t_i$ 出发。最终答案是 $(\max(x_i+t_i)+\min(x_i-t_i))/2$

# Problem C

Solved at 00:14 (+)

题意：

有一串数字字符串，允许删除任何一位 $d$ 后把 $\min(d+1,9)$ 插入字符串的任意位置，求任意次这样操作后字典序最小的字符串。

题解：

如果某一位 $d_i$ 后面有比它小的字符 $d_j$，那么把 $[i,j)$ 区间的字符全部删除可以让字符串的字典序更小，否则删除该字符会让字符串的字典序变大。可以用单调栈维护，这样操作后会剩下一个递增的字符串。

接下来考虑插入的位置，显然对于 $d$，插入到前面所有字符 $\le d$，后面所有字符 $\ge d$ 的位置会使字典序最小。

# Problem D

Solved at 00:32 (+)

题意：

给两串长度为 $n$ 的字符串 $s$ 和 $t$，允许交换 $s$ 的前缀和 $t$ 的相同长度的后缀，求任意次操作后能否使 $s=t$。

题解：

将 $t$ 反转为 $t'$，发现每次操作相当于将 $s$ 和 $t'$ 相同长度的前缀反转后交换，可以发现这样的操作不能使 $s$ 和 $t'$ 同一列上的两个字符被分到不同列去。考虑先交换长度为 $k$ 再交换长度为 $k-1$ 的前缀，这样相当于将第一列插入到第 $k$ 列，从而允许对列的任意排列。考虑交换长度为 $1$ 的前缀可以使第一列的字符上下交换，结合对列的任意交换即可允许对任意列的上下交换。

因此，题目相当于给出 $n$ 个无序字符对，求这些字符能否排列出两串相同的字符串。除了 $n=2k+1$ 时的中间一列，其他所有位置都需要两个相同的无序字符对，而 $n=2k+1$ 时中间一列需要一对相同的字符对。也就是说，如果 $n=2k$，则需要所有种类的字符对都出现偶数次。如果 $n=2k+1$，则需要除了一对相同的字符对出现奇数次，其他字符对都出现偶数次。


# Problem E

Unsolved

# Problem F

Unsolved