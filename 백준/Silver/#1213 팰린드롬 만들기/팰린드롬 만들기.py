import sys

input = sys.stdin.readline

name_dict = dict()
name = list(input().rstrip())
name.sort()


for i in name:
    if i in name_dict.keys():
        name_dict[i] += 1
    else:
        name_dict[i] = 1

odd_cnt = 0 
for i, j in name_dict.items():
    if j % 2 != 0:
        odd_cnt += 1

answer = ""
if odd_cnt >= 2:
    answer = "I'm Sorry Hansoo"

else:
    left = ""
    for i in range(len(name)):
        if name[i] in name_dict and name_dict[name[i]] >= 2:
            left += name[i]
            name_dict[name[i]] -= 2

            if name_dict[name[i]] == 0:
                del name_dict[name[i]]
    
    answer += left
    for i in range(len(name)):
        if name[i] in name_dict:
            answer += name[i]
            name_dict[name[i]] -= 1

            if name_dict[name[i]] == 0:
                del name_dict[name[i]]
    answer += left[::-1]

print(answer)




