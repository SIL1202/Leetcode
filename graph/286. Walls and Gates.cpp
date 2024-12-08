#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
  int dirctions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    int ROWS = grid.size();
    int COLS = grid[0].size();
    queue<pair<int, int>> q;

    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        if (grid[r][c] == 0) {
          q.push({r, c});
        }
      }
    }
    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nr = r + dirctions[i][0];
        int nc = c + dirctions[i][1];

        if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS ||
            grid[nr][nc] != INT_MAX)
          continue;

        grid[nr][nc] = grid[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }
};
