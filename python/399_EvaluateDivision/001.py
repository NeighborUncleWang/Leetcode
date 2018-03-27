class Solution:
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        visited = set()
        adj_list = {}
        for equation, value in zip(equations, values):
            adj_list.setdefault(equation[0], {})[equation[1]] = value
            adj_list.setdefault(equation[1], {})[equation[0]] = 1.0 / value
        def dfs(cur, end, visited, adj_list):
            if cur == end:
                return 1.0
            visited.add(cur)
            for neighbor in adj_list[cur]:
                if neighbor not in visited:
                    res = dfs(neighbor, end, visited, adj_list)
                    if res > 0:
                        visited.remove(cur)
                        return res * adj_list[cur][neighbor]
            visited.remove(cur)
            return -1.0
        res = []
        for query in queries:
            res.append(dfs(query[0], query[1], visited, adj_list) if query[0] in adj_list else -1.0)
        return res
