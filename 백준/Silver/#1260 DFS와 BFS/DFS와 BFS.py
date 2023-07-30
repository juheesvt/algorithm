import sys

input = sys.stdin.readline



def dfs(current_node):
    global graph, dfs_visited, dfs_path

    dfs_visited[current_node] = 1
    dfs_path.append(current_node)

    for next_node in graph[current_node]:
        if not dfs_visited[next_node]:
            dfs(next_node)

def bfs(start_node):
    global graph, bfs_visited, bfs_path

    queue = list()
    queue.append(start_node)
    bfs_path.append(start_node)

    bfs_visited[start_node] = 1

    while len(queue):
        current_node = queue[0]
        del queue[0]
        
        for next_node in graph[current_node]:
            if not bfs_visited[next_node]:
                queue.append(next_node)
                bfs_path.append(next_node)
                bfs_visited[next_node] = 1




n, m, start_node = map(int, input().split())

graph = [[] for i in range(n + 1)]
dfs_visited = [ 0 for i in range(n + 1)]
bfs_visited = [ 0 for i in range(n + 1)]

dfs_path = list()
bfs_path = list()

for i in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

for i in range(n + 1):
    graph[i].sort()

dfs(start_node)
bfs(start_node)
print(*dfs_path)
print(*bfs_path)




