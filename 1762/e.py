a = [1]

sum = 1
for i in range(4, 12, 2):
    print(1)
    a.append(i**(i-3)*(i-1))
    print((i-1)**(i-3))
    sum += a[-1]
print(a)
