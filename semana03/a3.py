a, n, m = map(int, input().split())

print(((a * (1 - a ** (n))) // (1 - a)) % m)

s = a
for i in range(2, n + 1):
    a *= a
    s += a % m
print (s % m)
