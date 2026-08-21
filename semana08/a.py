def kmp(s):
    n = len(s)
    table = [0] * n
    j = 0
    for i in range(1, n):
        while j > 0 and s[i] != s[j]:
            j = table[j - 1]
        if s[i] == s[j]:
            j += 1
            table[i] = j
    return table[-1]

def palindrome(s):
    s_reverse = s[::-1]
    s_double = s_reverse + s
    
    suffix_pos = kmp(s_double)
    
    return s + s_reverse[suffix_pos:]


def main():
    try:
        while True:
            s = str(input())
            print(palindrome(s))
    except Exception:
        return

main()
