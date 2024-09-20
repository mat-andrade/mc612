
s = []
soma = 0
print("{", end="")
for i in range(1000):
    soma += i * i
    print(soma % 10, end = ', ')
print("}")
