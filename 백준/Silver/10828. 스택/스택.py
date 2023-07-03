import sys
n = int(sys.stdin.readline())

stack = list()

for i in range(n):
   command = sys.stdin.readline().split()
   
   # push
   if len(command) > 1:
      num = int(command[1])
      stack.append(num)

   elif command[0] == "top":
      print(stack[-1] if len(stack) else -1)

   elif command[0] == "size":
      print(len(stack))

   elif command[0] == "empty":
      print(0 if len(stack) else 1)

   elif command[0] == "pop":
      if len(stack):
         print(stack[-1])
         del stack[-1]
      else:
         print(-1)