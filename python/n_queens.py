"""

The n-queens puzzle is the problem of placing n queens on 
an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the 
n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the
n-queens' placement, where 'Q' and '.' both indicate a queen
and an empty space, respectively.

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

"""

def solveNQueens(n):
  ans = []
  cols = [False] * n
  diag1 = [False] * (2 * n - 1)
  diag2 = [False] * (2 * n - 1)

  def dfs(i, board):
    if i == n:
      ans.append(board)
      return
    
    for j in range(n):
      if cols[j] or diag1[i + j] or diag2[j - i + n - 1]:
        continue
      cols[j] = True
      diag1[i + j] = True
      diag2[j - i + n - 1] = True
      dfs(i + 1, board + ['.' * j + 'Q' + '.' * (n - j - 1)])
      cols[j] = False
      diag1[i + j] = False
      diag2[j - i + n - 1] = False

  dfs(0, [])
  return ans
  
if __name__ == "__main__":
  print(solveNQueens(4))