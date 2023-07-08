import sys

class Stack:
   arr = list()
   top = -1

   def __init__(self):
      self.arr = [ 0 for i in range(10000)]
      self.top = -1
       
   def push(self, x: int) -> int:
      self.top += 1
      self.arr[self.top] = x

   def pop(self) -> int:
      if self.empty() == 1:
         return -1

      val = self.arr[self.top]
      self.top -= 1
      return val
   
   def peek(self) -> int:
      if self.empty() == 1:
         return -1
      return self.arr[self.top]

   def empty(self) -> int:
      return 1 if self.top == -1 else 0

   def size(self) -> int:
      return self.top + 1


if __name__ == "__main__":
   n = int(sys.stdin.readline())

   stack = Stack()

   for i in range(n):
      command = sys.stdin.readline().split()
      
      # push
      if len(command) > 1:
         stack.push(int(command[1]))

      elif command[0] == "top":
         print(stack.peek())

      elif command[0] == "size":
         print(stack.size())

      elif command[0] == "empty":
         print(stack.empty())

      elif command[0] == "pop":
         print(stack.pop())