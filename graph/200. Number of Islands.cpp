class Solution {
private:
  int dirction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
  int numIslands(vector<vector<char>> &grid) {
    int islands = 0;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c] == '1') {
          dfs(grid, r, c);
          islands++;
        }
      }
    }

    return islands;
  }

  void dfs(vector<vector<char>> &grid, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
        grid[r][c] == '0') {
      return;
    }

    grid[r][c] = '0';
    for (int i = 0; i < 4; i++) {
      dfs(grid, r + dirction[i][0], c + dirction[i][1]);
    }
  }

  /* void bfs(vector<vector<char>> &grid, int r, int c) {
    queue<pair<int, int>> q;
    grid[r][c] = '0';
    q.push({r, c});

    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      int row = node.first, col = node.second;

      for (int i = 0; i < 4; i++) {
        int nr = row + dirction[i][0];
        int nc = col + dirction[i][1];
        if (nr >= 0 && nc >= 0 && nr < grid.size() && grid[0].size() &&
            grid[nr][nc] == '1') {
          q.push({nr, nc});
          grid[nr][nc] = '0';
        }
      }
    }
  } */
};
