from collections import deque, defaultdict

# Initialize graph
graph = defaultdict(list)
edges = int(input("Enter the number of edges: "))

print("Enter the edges (source destination):") 
for _ in range(edges):
    u, v = input().split() 
    graph[u].append(v)

# BFS function with proper indentation
def bfs(graph, start):
    visited = [] 
    queue = deque()

    visited.append(start) 
    queue.append(start)
    
    while queue:
        node = queue.popleft() 
        print(node, end=" ")
        
        for neighbour in graph[node]:
            if neighbour not in visited: 
                visited.append(neighbour) 
                queue.append(neighbour)

# Get starting node and run traversal
start = input("\nEnter the starting node: ") 
print("BFS Traversal:")
bfs(graph, start)

# Fixed the smart quotes error at the end
print("\n Imteyaz Alam - 2400971640030")
