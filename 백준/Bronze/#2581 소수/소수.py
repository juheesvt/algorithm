import math

m = int(input())
n = int(input())
E = int(math.sqrt(n))


list_1=[ i for i in range(m,n+1)]

for i in range(2,n):
    if i > E:
        break

    for j in range(i*i,n+1,i):
        if j in list_1:
            list_1.remove(j)

if 1 in list_1:
    list_1.remove(1)
    
    
if len(list_1)==0:
    print(-1)

else:
    sum = 0
    for i in list_1:
        sum += i

    print(sum)
    print(list_1[0])

