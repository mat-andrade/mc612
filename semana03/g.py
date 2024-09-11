while True:
    try:
        n = int(input())
        ant = 0
        atual = 0
        for i in range(1, n):
            if i % 2 == 0:
                atual = 2 * ant - 1
            else:
                atual = 2 * ant + 1
            ant = atual
        print(atual)
    except:
        break
