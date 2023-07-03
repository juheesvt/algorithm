import sys
n = int(sys.stdin.readline())

queue = list()

for i in range(n):
   command = sys.stdin.readline().split()
   
   # push
   if len(command) > 1:
      num = int(command[1])
      queue.append(num)

   elif command[0] == "front":
      print(queue[0] if len(queue) else -1)

   elif command[0] == "back":
      print(queue[-1] if len(queue) else -1)

   elif command[0] == "size":
      print(len(queue))
   elif command[0] == "empty":
      print(0 if len(queue) else 1)

   elif command[0] == "pop":
      if len(queue):
         print(queue[0])
         del queue[0]
      else:
         print(-1)