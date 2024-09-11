a, b, c, d = map(int, input().split())
p = a / b
q = c / d

r = 1
p_ = 1 - p
q_ = 1 - q
pi = 1 - p
qi = 1 - q

for i in range(1, 1000000):
    r += pi * qi
    pi *= p_
    qi *= q_

print(p * r)
