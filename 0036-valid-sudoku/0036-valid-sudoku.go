func isValidSudoku(board [][]byte) bool {
    rows:= make([]map[byte]bool, 9)   
    cols:= make([]map[byte]bool, 9)
    boxes := make([]map[byte]bool, 9)
    for i:= 0; i<9; i++{
        rows[i] = make(map[byte]bool)
        cols[i] = make(map[byte]bool)
        boxes[i] = make(map[byte]bool)
    }

    for row:=0; row < 9; row++ {
        for col:=0; col<9 ; col++ {
            val := board[row][col]
            if val =='.'{
                continue
            }
            boxIndex := (row/3)*3 + (col/3)
            if rows[row][val] || cols[col][val] || boxes[boxIndex][val]{
                return false
            }
            rows[row][val] = true
            cols[col][val] = true
            boxes[boxIndex][val] =true
        }
    }   
    return true

}
