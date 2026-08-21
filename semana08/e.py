# Inspired by https://cp-algorithms.com/string/suffix-array.html

def suffix_array(s):
    n = len(s)
    suffixs = []
    suffix_array = []

    for i in range(n):
        suffixs.append((s[i:], i))
    suffixs = sorted(suffixs)

    for suffix in suffixs:
        suffix_array.append(suffix[1])

    return suffix_array

def lcp_array(s, suffix_array):
    n = len(s)
    rank = [0] * n
    lcp = [0] * n

    for i in range(len(suffix_array)):
        sufix = suffix_array[i]
        rank[sufix] = i

    h = 0
    for i in range(n):
        if rank[i] > 0:
            j = suffix_array[rank[i] - 1]
            while (i + h < n) and (j + h < n) and (s[i + h] == s[j + h]):
                h += 1
            lcp[rank[i]] = h
            if h > 0:
                h -= 1

    return lcp

def substrings(s):
    n = len(s)
    suffix_ar = suffix_array(s)
    lcp = lcp_array(s, suffix_ar)
    
    total = n * (n + 1) // 2 
    lcp_sum = sum(lcp)
    
    return total - lcp_sum

def main():
    s = input()
    print(substrings(s))

main()