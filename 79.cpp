#include <vector>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
  bool exist(vector< vector<char> > &board, string word) {
    if (board.empty() || board[0].empty() || word.empty()) return false;

    this->m = board.size(), this->n = board[0].size();

    for (int i=0; i<this->m; ++i) {
      for (int j=0; j<this->n; ++j) {
        if (board[i][j] == word[0]) {
          //vector< vector<bool> > visited(this->m, vector<bool>(this->n, false));
          bool visited[200][200] = {0};
          if (dfs(board, visited, i, j, 0, word)) return true;
        }
      }
    }

    return false;
    
  }

private:

  bool dfs(vector< vector<char> > &board,
           bool visited[200][200],
           int i, int j, int count, const string &word) {
    //printf("trying i=%d j=%d %c\n", i, j, board[i][j]);
    if (count == word.size()-1) return true;
    visited[i][j] = true;

    if (i>0 && !visited[i-1][j] && board[i-1][j] == word[count+1] && dfs(board, visited, i-1, j, count+1, word))
      return true;
    if (j+1<n && !visited[i][j+1] && board[i][j+1] == word[count+1] && dfs(board, visited, i, j+1, count+1, word))
      return true;
    if (i+1<m && !visited[i+1][j] && board[i+1][j] == word[count+1] && dfs(board, visited, i+1, j, count+1, word))
      return true;
    if (j>0 && !visited[i][j-1] && board[i][j-1] == word[count+1] && dfs(board, visited, i, j-1, count+1, word))
      return true;

    visited[i][j] = false;
    return false;
  }

    int m, n;
};


#ifdef DEBUG

int main() {
  char a[][4] = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
  vector< vector<char> > va(sizeof(a)/sizeof(a[0]), vector<char>(sizeof(a[0]), 0));

  for (int i=0; i<va.size(); ++i)
    for (int j=0; j<va[0].size(); ++j)
      va[i][j] = a[i][j];

  Solution s;
  printf("%d\n", s.exist(va, "ABCEFSADEESE"));
}

#endif
