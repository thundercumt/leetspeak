#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  void solveSudoku(vector< vector<char> >& board) {
    char row[10][10] = {0};
    char col[10][10] = {0};
    char box[10][10] = {0};
    int c;
    for (int i=0; i<9; ++i) {
      for (int j=0; j<9; ++j) {
        c = board[i][j];
        if (c=='.') continue;
        c = c - '0';
        row[i][c] = 1;
        col[j][c] = 1;
        box[i/3 * 3 + j/3][c] = 1;
      }
    }
    dfs (board, 0, 0, row, col, box);
  }

  bool dfs(vector< vector<char> > &board, int i, int j,
           char (&row)[10][10], char (&col)[10][10], char (&box)[10][10]) {
    if (i>8) return true;
    while (board[i][j] != '.') {
      if (i==8 && j==8) return true;
      ++j;
      if (j==9) { ++i; j=0; }
    }

    vector<int> cand;
    for (int k=1; k<=9; ++k) {
      if (!row[i][k] && !col[j][k] && !box[i/3*3+j/3][k]) cand.push_back(k);
    }

    if (cand.empty()) return false;
    int n = cand.size();
    bool ret = false;
    int c;
    for (int k=0; k<n; ++k) {
      c = cand[k];
      board[i][j] = c + '0';
      row[i][c] = 1;
      col[j][c] = 1;
      box[i/3*3+j/3][c] = 1;
      ret = dfs(board,  j==8 ? i+1:i, j==8 ? 0:j+1, row, col, box);
      if (ret) return true;
      board[i][j] = '.';
      row[i][c] = 0;
      col[j][c] = 0;
      box[i/3*3+j/3][c] = 0;
    }
    return false;
  }
};



#ifdef DEBUG
int main() {
  vector<char> tmp(9, 0);
  vector< vector<char> > v(9, tmp);
  cout << "fuckers!!\n";

  char c;
  for (int i=0; i<9; ++i) {
    for (int j=0; j<9; ++j) {
      cin >> c;
      v[i][j] = c;
      cout << c << ' ';
    }
    cout << '\n';
  }

  Solution s;
  s.solveSudoku(v);

  for (int i=0; i<9; ++i) {
    for (int j=0; j<9; ++j)
      cout << v[i][j] << ' ';
    cout << '\n';
  }
}

#endif
