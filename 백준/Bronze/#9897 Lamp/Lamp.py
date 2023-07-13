import sys
input = sys.stdin.readline


if __name__ == "__main__":

    l, g, r = map(int, input().split())
    lamps = [0 for i in range(l + 1)]
    
    info = dict()
    for i in range(g):
        name, first, common = input().split()
        info[name] = (int(first), int(common))
    
    order = list()
    for i in range(r):
        order.append(input().rstrip())

    for current_name in order:
        for lamp in range( info[current_name][0], l + 1, info[current_name][1]):
            lamps[lamp] = 1 - lamps[lamp]

    print(sum(lamps))


