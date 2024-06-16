import sys
n = int(sys.stdin.readline())

stack = list()
for i in range(n):
   stack.append(int(sys.stdin.readline()))

cnt = 1
maxVal = stack[-1]
stack = stack[::-1]
for top in stack:
   if maxVal < top:
      cnt += 1
      maxVal = top
                
print(cnt)