import sys
input = sys.stdin.readline

class Queue:
    queue = list()

    def __init__(self, maxSize: int) -> object:
        self.queue = [0 for i in range(maxSize)]
        self.head = 0
        self.tail = 0
        self.qsize = 0

    def enqueue(self, x: int) -> None:
        self.queue[self.head] = x
        self.head += 1
        self.qsize += 1

    def dequeue(self) -> int:
        if self.qsize == 0:
            return -1
        else:
            val = self.queue[self.tail]
            self.tail += 1
            self.qsize -= 1
            return val

    def empty(self) -> bool:
        return 1 if self.qsize == 0 else 0

    def front(self) -> int:
        return self.queue[self.tail] if self.qsize != 0 else -1

    def back(self) -> int:
        return self.queue[self.head - 1] if self.qsize != 0 else -1

    def size(self) -> int:
        return self.qsize
    

if __name__ == "__main__":
    n = int(input())

    queue = Queue(maxSize=10000)

    for i in range(n):
        command = input().split()
    
        # push
        if len(command) > 1:
            num = int(command[1])
            queue.enqueue(x=num)

        elif command[0] == "front":
            print(queue.front())

        elif command[0] == "back":
            print(queue.back())

        elif command[0] == "size":
            print(queue.size())

        elif command[0] == "empty":
            print(queue.empty())

        elif command[0] == "pop":
            print(queue.dequeue())




    

