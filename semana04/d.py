n, k = map(int, input().split())

p = 0

for i in range(1, n + 1):
    acc = 1
    while i * acc < k:
        acc *= 2
    p += 1/(n * acc)


print(p)
