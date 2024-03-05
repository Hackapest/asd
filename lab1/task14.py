

MY_TOWERS = ['A','B','C']


def displayTowers():
    for i in result:
        print(i)
    print(50 * "_")
    

def towers(n, source, target, middle):
    global c
    if n==1:
        print (f"move {source} to {target}")
        result[MY_TOWERS.index(target)].append(result[MY_TOWERS.index(source)].pop())
        c += 1
        displayTowers()
    else:
        towers(n - 1, source, middle, target)
        print (f"move {source} to {target}")
        result[MY_TOWERS.index(target)].append(result[MY_TOWERS.index(source)].pop())
        c += 1
        displayTowers()
        towers(n - 1, middle, target, source)


def main():
    n = 4

    global result
    global c

    c = 0

    result = [[], [], []]

    result[0] = [i + 1 for i in range(0, n)]
    result[0].reverse()

    displayTowers()

    towers(n, 'A', 'C', 'B')

    print(c)

main()