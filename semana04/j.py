def groups(n, cards):
    restos=[0] * (5)
    for i in range(n):
        a = cards[i] % 5
        restos[a] += 1
    
    group = 0

    group += restos[0] 
    restos[0] = 0

    x = min(restos[1], restos[4])
    group += x
    restos[1] -= x
    restos[4] -= x

    y = min(restos[2], restos[3])
    group += y
    restos[2] -= y
    restos[3] -= y

    z = min(restos[1], restos[2]//2)
    group += z
    restos[1] -= z
    restos[2] -= 2*z

    w = min(restos[1]//2, restos[3])
    group += w
    restos[1] -= 2*w
    restos[3] -= w

    g = min(restos[1]//3, restos[2])
    group += g
    restos[1] -= 3*g
    restos[2] -= g

    t = restos[1]//5
    group += t
    restos[1] -= 5*t

    return group


def main():
    n = int(input())
    cards = list(map(int, input().split()))
    print(groups(n, cards))
main()
