import sys
input = sys.stdin.readline

n = int(input())
for i in range(n):
    words, string = input().split()
    word_dict = dict()
    for word in string:
        word_dict[word] = 1

    is_exist = True
    for word in words:
        if word in word_dict.keys():
            word_dict[word] = 0
        else:
            is_exist = False
            break
    else:
        if sum(word_dict.values()) == 0:
            print("YES")
        else:
            print("NO")

    if not is_exist:
        print("NO")