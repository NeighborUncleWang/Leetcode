class Solution:
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        colors = {}
        #use deque as a queue in python
        q = collections.deque()
        for idx in range(len(graph)):
            if idx not in colors:
                colors[idx] = True
                q.append(idx)
                while q:
                    cur = q.popleft()
                    for neighbor in graph[cur]:
                        if neighbor not in colors:
                            q.append(neighbor)
                            colors[neighbor] = not colors[cur]
                        elif colors[neighbor] == colors[cur]:
                            return False
        return True
