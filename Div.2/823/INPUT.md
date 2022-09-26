# Codeforces Round #823 (Div. 2)

- Problem A:
  - NULL
- Problem B:
  - NULL
- Problem C:
  - NULL
- Problem D:
  - NULL
- Problem E:
  - NULL
- Problem F:
  - NULL

# Problem A

Solved at 00:02 (+)

题意：

有 $n$ 个行星在 $100$ 个轨道上，每次可以用 $1$ 的代价删除一颗行星或者 $c$ 的代价删除一个轨道上的所有行星，求删除所有行星的最小代价。

题解：

对每个轨道分开考虑，看这个轨道上的行星是一个一个删划算还是花 $c$ 的代价一起删了划算。

# Problem B

题意：

数轴上有 $n$ 个人，第 $i$ 个人会在 $t_i$ 时刻从 $x_i$ 出发，找一个集会点使得所有人到齐的时间最短。

题解：

首先考虑 $t_i=0$ 的时候怎么做，显然集会点取 $(x_{\max}+x_{\min})/{2}$ 最优。考虑 $t_i>0$，此时相当于同时考虑两个分别在 $x_i+t_i$ 和 $x_i-t_i$ 的人，因为当集会点 $>x_i$ 时，这个人等价于从 $x_i-t_i$ 出发，集会点 $<x_i$ 时等价于从 $x_i+t_i$ 出发。

# Problem C

题意：

xxx

题解：

xxx

# Problem D

题意：

xxx

题解：

xxx

# Problem E

题意：

xxx

题解：

xxx

# Problem F

题意：

xxx

题解：

xxx
