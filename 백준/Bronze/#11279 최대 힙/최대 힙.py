import sys
input = sys.stdin.readline

class MaxHeap:
    heap = list()

    def __init__(self, max_size: int) -> object:
        self.heap = [0 for i in range(max_size + 1)]
        self.hsize = 0
        self.ROOT_NODE = 1
        self.heap[0] = sys.maxsize

    def parent(self, node: int) -> int:
        return node // 2
    
    def left_child(self, node: int) -> int:
        return node * 2
    
    def right_child(self, node: int) -> int:
        return (node * 2) + 1
    
    def switch(self, node1: int, node2: int) -> None:
        self.heap[node1], self.heap[node2] = (self.heap[node2], self.heap[node1])

    def is_leaf(self, node: int) -> bool:
        return True if ((node >= (self.hsize // 2) + 1) and node <= self.hsize + 1) else False
    
    def heapify(self, node: int) -> None:
        # leaf node가 아닐 때
        if not self.is_leaf(node):
            # 현재 노드의 값이 자식 노드들의 값 중 하나보다 작다면, 둘 중 더 큰 자식 노드와 위치 바꾸기
            if self.heap[node] < self.heap[self.left_child(node)] or self.heap[node] < self.heap[self.right_child(node)]: 
                if self.heap[self.left_child(node)] > self.heap[self.right_child(node)]: 
                    self.switch(node, self.left_child(node))
                    self.heapify(self.left_child(node))
                else:
                    self.switch(node, self.right_child(node))
                    self.heapify(self.right_child(node))


    def heappush(self, x: int) -> None:
        # 트리의 맨 끝에 요소 추가하기
        self.hsize += 1
        self.heap[self.hsize] = x

        # 추가된 노드의 값보다 더 큰 부모가 없을 때까지 부모랑 위치 바꾸기
        current_node = self.hsize
        while self.heap[current_node] > self.heap[self.parent(current_node)]:
            self.switch(current_node, self.parent(current_node))
            current_node = self.parent(current_node)

    def heappop(self) -> int:
        if self.hsize == 0:
            return 0
        
        pop_val = self.heap[1]
        self.heap[self.ROOT_NODE] = self.heap[self.hsize]
        self.hsize -= 1
        self.heapify(node=self.ROOT_NODE)
          
        return pop_val


if __name__ == "__main__":
    n = int(input())

    heap = MaxHeap(max_size=100000)

    for i in range(n):
        command = int(input())
    
        # heap push
        if command > 0:
            heap.heappush(x=command)

        else:
            pop_val = heap.heappop()
            print(pop_val)

