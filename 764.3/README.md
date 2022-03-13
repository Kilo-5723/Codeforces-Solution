# Codeforces Round #764 (Div. 3)

- Problem A:
  - Solved. 00:03 (+)

- Problem B:
  - Solved. 00:08 (+)

- Problem C:
  - Solved. 00:16 (+)

- Problem D:
  - Solved. 00:26 (+)

- Problem E:
  - Solved. 01:10 (+2)

- Problem F:
  - Solved. 01:30 (+)

- Problem G:
  - Solved. 01:30 (+)
  - 位运算
  - 并查集

# Problem A

题意：

给出序列 <img src="svgs/b0ac02d8b6d2a12a2b4188c8739b974f.svg?invert_in_darkmode" align=middle width=34.07551124999999pt height=24.65753399999998pt/>，每次操作可以选一些位置 <img src="svgs/c11fe0cea175e1b787b3403c763dc9b0.svg?invert_in_darkmode" align=middle width=21.00464354999999pt height=21.18721440000001pt/>，求让整个序列相同需要的最少操作次数。

题解：

显然每次选不等于最大值的位置 <img src="svgs/c11fe0cea175e1b787b3403c763dc9b0.svg?invert_in_darkmode" align=middle width=21.00464354999999pt height=21.18721440000001pt/>，操作次数即为序列的 <img src="svgs/e01602ac7abb93919b7f0f623d7a0026.svg?invert_in_darkmode" align=middle width=134.71664744999998pt height=24.65753399999998pt/>。



# Problem G

题意：

求边权位运算或 (OR) 和最小的生成树。

题解：

题目要求所有选中边权的位或和最小。假设已经知道了答案为 ans，那么答案对应的生成树中可选的边的边权 w 一定满足 w OR ans = ans，也就是 w 的二进制中所有 1 位在 ans 中也为 1。

因此，可以从大到小逐步确定 ans 每一位的值。例如，一共确定 8 位，前三位已经确定为 101，那么如果第五位为 0，可选的边权 w 就满足 w OR 10101111 = 10101111。如果原图中满足该条件的边可以形成一颗生成树，也就是使图连通，那么 ans 的第四位就为 0，否则就为 1。

本题需要位运算加速边权是否满足条件，同时需要并查集判断联通性。