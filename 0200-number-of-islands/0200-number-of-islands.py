class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        visited = [[False]*cols for _ in range(rows)]
        islands = 0
        def dfs(r, c):
            #base cases
            if r<0 or r>=rows or c<0 or c>=cols: return
            if visited[r][c] or grid[r][c] == "0": return

            visited[r][c] = True
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == "1" and not visited[i][j]:
                    dfs(i,j)
                    islands+=1
        
        return islands
        