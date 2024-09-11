str = input()

c = 0
for i in range(len(str)):
    letras = set()
    for j in range(i, len(str)):
        if str[j] in letras:
            break
        else:
            letras.add(str[j])
            c += 1

print(c)
