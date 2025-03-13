func exist(board [][]byte, word string) bool {
    m, n := len(board), len(board[0])

    visit := make([][]bool, m)
    for i := range board {
        visit[i] = make([]bool, n)
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if board[i][j] == word[0] {
                if slove(i, j, m, n, 0, board, visit, word) {
                    return true
                }
            }
        }
    }

    return false
}

func isSafe(i, j, m, n int, visit [][]bool) bool {
    if i < 0 || i >= m || j < 0 || j >= n || visit[i][j] {
        return false
    }

    return true
}

func slove(i, j, m, n, curr int, board [][]byte, visit [][]bool, word string) bool {
    if curr == len(word) {
        return true
    }

    if !isSafe(i, j, m, n, visit) {
        return false
    }

    if board[i][j] != word[curr] {
        return false
    }

    visit[i][j] = true

    if slove(i + 1, j, m, n, curr + 1, board, visit, word) || 
      slove(i - 1, j, m, n, curr + 1, board, visit, word) ||
      slove(i, j + 1, m, n, curr + 1, board, visit, word) ||
     slove(i, j - 1, m, n, curr + 1, board, visit, word) {
        visit[i][j] = false
        return true
     }
    visit[i][j] = false
    return false
}