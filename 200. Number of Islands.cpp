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
};
