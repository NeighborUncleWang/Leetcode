class Solution:
    def hasPath(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
        q = collections.deque([start])
        directions = [[-1, 0], [0, -1], [1, 0], [0, 1]]
        m, n = len(maze), len(maze[0])
        visited = [[False] * n for a in range(m)]
        # 千万不要写成下面这样，否则会visited[0][0]会修改整个第0列
        # https://stackoverflow.com/questions/13157961/2d-array-of-zeros
        # visited = [[False] * n] * m
        visited[start[0]][start[1]] = True
        while q:
            cur = q.popleft()
            for direction in directions:
                i, j = cur[0], cur[1]
                while i >= 0 and i < m and j >= 0 and j < n and maze[i][j] == 0:
                    i += direction[0]
                    j += direction[1]
                i -= direction[0]
                j -= direction[1]
                if [i, j] == destination:
                    return True
                elif visited[i][j] == False:
                    q.append([i, j])
                    visited[i][j] = True
        return False
