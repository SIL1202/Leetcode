class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> vec;
    int i = 0;
    int j = 0;
    int dx, dy;
    dx = 1;
    dy = 0;

    for (int x = 0; x < row * col; x++) {
      vec.push_back(matrix[i][j]);
      matrix[i][j] = -101;
      if (i + dy > row - 1 || j + dx > col - 1 || i + dy < 0 || j + dx < 0 ||
          matrix[i + dy][j + dx] == -101) {
        int temp = dx;
        dx = -dy;
        dy = temp;
      }
      i += dy;
      j += dx;
    }
    return vec;
  }
};
