# Codeforces Round #823 (Div. 2)

- Problem C:
  - 单调栈

# Problem A

Solved at 00:02 (+)

题意：

有 <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> 个行星在 <img src="svgs/68399e6e2d2d99a90a9e8395f7dc1f11.svg?invert_in_darkmode" align=middle width=24.657628049999992pt height=21.18721440000001pt/> 个轨道上，每次可以用 <img src="svgs/034d0a6be0424bffe9a6e7ac9236c0f5.svg?invert_in_darkmode" align=middle width=8.219209349999991pt height=21.18721440000001pt/> 的代价删除一颗行星或者 <img src="svgs/3e18a4a28fdee1744e5e3f79d13b9ff6.svg?invert_in_darkmode" align=middle width=7.11380504999999pt height=14.15524440000002pt/> 的代价删除一个轨道上的所有行星，求删除所有行星的最小代价。

题解：

对每个轨道分开考虑，看这个轨道上的行星是一个一个删划算还是花 <img src="svgs/3e18a4a28fdee1744e5e3f79d13b9ff6.svg?invert_in_darkmode" align=middle width=7.11380504999999pt height=14.15524440000002pt/> 的代价一起删了划算。

# Problem B

Solved at 00:07 (+)

题意：

数轴上有 <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> 个人，第 <img src="svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663225699999989pt height=21.68300969999999pt/> 个人会在 <img src="svgs/02ab12d0013b89c8edc7f0f2662fa7a9.svg?invert_in_darkmode" align=middle width=10.58699729999999pt height=20.221802699999984pt/> 时刻从 <img src="svgs/9fc20fb1d3825674c6a279cb0d5ca636.svg?invert_in_darkmode" align=middle width=14.045887349999989pt height=14.15524440000002pt/> 出发，找一个集会点使得所有人到齐的时间最短。

题解：

首先考虑 <img src="svgs/cd6a4d765e36c6190ced5ea9761a4aca.svg?invert_in_darkmode" align=middle width=41.54573444999998pt height=21.18721440000001pt/> 的时候怎么做，显然集会点取 <img src="svgs/2fd135689d18742f41d36e4f5beb495e.svg?invert_in_darkmode" align=middle width=115.78789034999998pt height=24.65753399999998pt/> 最优。考虑 <img src="svgs/72e9f155b6a061052f22a029ebe464f4.svg?invert_in_darkmode" align=middle width=41.54573444999998pt height=21.18721440000001pt/>，此时相当于同时考虑两个分别在 <img src="svgs/20df09847376445bb41109d3563a0630.svg?invert_in_darkmode" align=middle width=45.54597299999998pt height=20.221802699999984pt/> 和 <img src="svgs/874f9680ec016e705e0ad45967dab0a8.svg?invert_in_darkmode" align=middle width=45.54597299999998pt height=20.221802699999984pt/> 的人，因为当集会点 <img src="svgs/731d9d9632b6117463fb084b73b69eb2.svg?invert_in_darkmode" align=middle width=31.39741934999999pt height=17.723762100000005pt/> 时，这个人等价于从 <img src="svgs/874f9680ec016e705e0ad45967dab0a8.svg?invert_in_darkmode" align=middle width=45.54597299999998pt height=20.221802699999984pt/> 出发，集会点 <img src="svgs/e64c6608a66c23c5f34b55517c0050ca.svg?invert_in_darkmode" align=middle width=31.39741934999999pt height=17.723762100000005pt/> 时等价于从 <img src="svgs/20df09847376445bb41109d3563a0630.svg?invert_in_darkmode" align=middle width=45.54597299999998pt height=20.221802699999984pt/> 出发。最终答案是 <img src="svgs/4c5772453f3a747cfb80a6da703dcc47.svg?invert_in_darkmode" align=middle width=225.61270710000002pt height=24.65753399999998pt/>

# Problem C

Solved at 00:14 (+)

题意：

有一串数字字符串，允许删除任何一位 <img src="svgs/2103f85b8b1477f430fc407cad462224.svg?invert_in_darkmode" align=middle width=8.55596444999999pt height=22.831056599999986pt/> 后把 <img src="svgs/2f3cc634bd2db028278710b6b03a454a.svg?invert_in_darkmode" align=middle width=92.57423339999998pt height=24.65753399999998pt/> 插入字符串的任意位置，求任意次这样操作后字典序最小的字符串。

题解：

如果某一位 <img src="svgs/672a7aeac9254219b9609330a12e55e5.svg?invert_in_darkmode" align=middle width=13.206862349999989pt height=22.831056599999986pt/> 后面有比它小的字符 <img src="svgs/892e9ab8feb7697ce350e3ba1bd9842f.svg?invert_in_darkmode" align=middle width=14.66047274999999pt height=22.831056599999986pt/>，那么把 <img src="svgs/5c1c66599513caef522a14b956862740.svg?invert_in_darkmode" align=middle width=31.63846784999999pt height=24.65753399999998pt/> 区间的字符全部删除可以让字符串的字典序更小，否则删除该字符会让字符串的字典序变大。可以用单调栈维护，这样操作后会剩下一个递增的字符串。

接下来考虑插入的位置，显然对于 <img src="svgs/2103f85b8b1477f430fc407cad462224.svg?invert_in_darkmode" align=middle width=8.55596444999999pt height=22.831056599999986pt/>，插入到前面所有字符 <img src="svgs/6e8ef4f579337753c42d4eaf4dc8f35d.svg?invert_in_darkmode" align=middle width=25.90749644999999pt height=22.831056599999986pt/>，后面所有字符 <img src="svgs/78fd3331075458c9661202455a80b3a7.svg?invert_in_darkmode" align=middle width=25.90749644999999pt height=22.831056599999986pt/> 的位置会使字典序最小。

# Problem D

Solved at 00:32 (+)

题意：

给两串长度为 <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> 的字符串 <img src="svgs/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode" align=middle width=7.7054801999999905pt height=14.15524440000002pt/> 和 <img src="svgs/4f4f4e395762a3af4575de74c019ebb5.svg?invert_in_darkmode" align=middle width=5.936097749999991pt height=20.221802699999984pt/>，允许交换 <img src="svgs/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode" align=middle width=7.7054801999999905pt height=14.15524440000002pt/> 的前缀和 <img src="svgs/4f4f4e395762a3af4575de74c019ebb5.svg?invert_in_darkmode" align=middle width=5.936097749999991pt height=20.221802699999984pt/> 的相同长度的后缀，求任意次操作后能否使 <img src="svgs/1327ee3255e3557f570b285d55d6f5b8.svg?invert_in_darkmode" align=middle width=35.55920774999999pt height=20.221802699999984pt/>。

题解：

将 <img src="svgs/4f4f4e395762a3af4575de74c019ebb5.svg?invert_in_darkmode" align=middle width=5.936097749999991pt height=20.221802699999984pt/> 反转为 <img src="svgs/3017b5535fbc7d4cce65784dfe8fb22b.svg?invert_in_darkmode" align=middle width=9.726058649999992pt height=24.7161288pt/>，发现每次操作相当于将 <img src="svgs/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode" align=middle width=7.7054801999999905pt height=14.15524440000002pt/> 和 <img src="svgs/4f4f4e395762a3af4575de74c019ebb5.svg?invert_in_darkmode" align=middle width=5.936097749999991pt height=20.221802699999984pt/> 相同长度的前缀反转后交换，可以发现这样的操作不能使 <img src="svgs/6f9bad7347b91ceebebd3ad7e6f6f2d1.svg?invert_in_darkmode" align=middle width=7.7054801999999905pt height=14.15524440000002pt/> 和 <img src="svgs/3017b5535fbc7d4cce65784dfe8fb22b.svg?invert_in_darkmode" align=middle width=9.726058649999992pt height=24.7161288pt/> 同一列上的两个字符被分到不同列去。考虑先交换长度为 <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/> 再交换长度为 <img src="svgs/aa9d1dc08f682f546eeee2869762ff90.svg?invert_in_darkmode" align=middle width=37.38576269999999pt height=22.831056599999986pt/> 的前缀，这样相当于将第一列插入到第 <img src="svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/> 列，从而允许对列的任意排列。考虑交换长度为 <img src="svgs/034d0a6be0424bffe9a6e7ac9236c0f5.svg?invert_in_darkmode" align=middle width=8.219209349999991pt height=21.18721440000001pt/> 的前缀可以使第一列的字符上下交换，结合对列的任意交换即可允许对任意列的上下交换。

因此，题目相当于给出 <img src="svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> 个无序字符对，求这些字符能否排列出两串相同的字符串。除了 <img src="svgs/0fb3b20a857f33d782efc896af779e07.svg?invert_in_darkmode" align=middle width=77.38947974999998pt height=22.831056599999986pt/> 时的中间一列，其他所有位置都需要两个相同的无序字符对，而 <img src="svgs/0fb3b20a857f33d782efc896af779e07.svg?invert_in_darkmode" align=middle width=77.38947974999998pt height=22.831056599999986pt/> 时中间一列需要一对相同的字符对。也就是说，如果 <img src="svgs/5d8c0068642471e99c42369c0ec04232.svg?invert_in_darkmode" align=middle width=49.079084999999985pt height=22.831056599999986pt/>，则需要所有种类的字符对都出现偶数次。如果 <img src="svgs/0fb3b20a857f33d782efc896af779e07.svg?invert_in_darkmode" align=middle width=77.38947974999998pt height=22.831056599999986pt/>，则需要除了一对相同的字符对出现奇数次，其他字符对都出现偶数次。


# Problem E

Unsolved

# Problem F

Unsolved