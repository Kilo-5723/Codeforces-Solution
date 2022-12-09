fact = [1]
for i in range(1, 5983):
    fact.append(fact[-1]*i)
print(fact[-1])
