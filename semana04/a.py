def calculate_probability(n, a, b):

    dp = []
    for i in range(n + 1):
        dp.append([0] * (6 * n + 1))

    dp[0][0] = 1

    for i in range(1, n + 1):
        for j in range(i, 6 * i + 1):
            for k in range(1, 7):
                if j - k >= 0:
                    dp[i][j] += dp[i - 1][j - k]

    possibilities = 0
    for i in range(a, b + 1):
        possibilities += dp[n][i]
    total = 6 ** n

    probability = possibilities / total

    return probability

def main():
    n, a, b = map(int, input().split())
    print(f"{round(calculate_probability(n, a, b), 6):.6f}")

main()
