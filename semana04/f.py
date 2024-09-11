def imbalance(n, array):
    total = 0
    for i in range(n - 1):
        max = array[i]
        min = array[i]
        for j in range(i + 1, n):
            if array[j] > max:
                max = array[j]
            if array[j] < min:
                min = array[j]
            total += max - min
    return total

def main():
    n = int(input())
    array = list(map(int, input().split()))
    print(imbalance(n, array))
main()



# for a in [i for i in range(1, 1000000)]:
#     print(f"{a}", end=' ')
