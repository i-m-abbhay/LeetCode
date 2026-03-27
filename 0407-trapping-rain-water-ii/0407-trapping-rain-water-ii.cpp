class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int totalRows = heightMap.size();
        int totalCols = heightMap[0].size();
        priority_queue<Cell> boundary;
        vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));
        int dRow[4] = {0, 0, -1, 1};
        int dCol[4] = {-1, 1, 0, 0};
        for(int i = 0;i<totalRows;i++){
            boundary.push(Cell(heightMap[i][0], i, 0));
            boundary.push(Cell(heightMap[i][totalCols-1],i,totalCols-1));
            visited[i][0] = visited[i][totalCols-1] = true;
        }
        for(int i=0;i<totalCols;i++){
            boundary.push(Cell(heightMap[0][i], 0, i));
            boundary.push(Cell(heightMap[totalRows-1][i], totalRows-1, i));
            visited[0][i]=visited[totalRows-1][i]=true;
        }
        int waterTotal = 0;
        while(!boundary.empty()){
            Cell currCell = boundary.top();
            boundary.pop();
            int minBoundaryHt = currCell.height;
            int currRow = currCell.row;
            int currCol = currCell.col;
            for(int i =0;i<4;i++){
                int neighborRow = currRow+dRow[i];
                int neighborCol = currCol+dCol[i];
                if(isValidCell(neighborRow, neighborCol, totalRows, totalCols) && !visited[neighborRow][neighborCol]){
                    if(heightMap[neighborRow][neighborCol]<minBoundaryHt){
                        waterTotal+= minBoundaryHt - heightMap[neighborRow][neighborCol];
                            }
                        boundary.push(Cell(max(minBoundaryHt, heightMap[neighborRow][neighborCol]), neighborRow, neighborCol));
                        visited[neighborRow][neighborCol] = true;
                
                }
            }
        }
        return waterTotal;
    }

private:
    class Cell {
        public:
        int height;
        int row;
        int col;
        Cell(int height, int row, int col): height(height), row(row), col(col){}

        bool operator<(const Cell& other)const {
            return height>other.height;
        }
    };
    bool isValidCell(int row, int col, int totalRows, int totalCols){
        return col<totalCols && row < totalRows && row >=0 && col >= 0;
    }
};