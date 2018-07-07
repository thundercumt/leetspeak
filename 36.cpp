#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector< vector<char> >& board) {
    char row[10][10] = {0}, col[10][10] = {0}, box[10][10] = {0};
    char c;
    for (int i=0; i<9; ++i) {
      for (int j=0; j<9; ++j) {
        c = board[i][j];
        if (c == '.') continue;
        c = c-'0';
        if (row[i][c]) return false;
        row[i][c] = 1;
        if (col[j][c]) return false;
        col[j][c] = 1;
        if (box[i/3 * 3 + j/3][c]) return false;
        box[i/3 * 3 + j/3][c] = 1;
      }
    }
    return true;
  }
};


#ifdef DEBUG

int main() {
  
}

#endif
