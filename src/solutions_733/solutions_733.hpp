#pragma once

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    int old_color = image[sr][sc];
    solve(image, sr, sc, old_color, color);
    return image;
  }

 private:
  void solve(vector<vector<int>> &image, int x, int y, int old_color,
             int color) {
    if (old_color == color || image[x][y] == color) return;

    image[x][y] = color;

    if (x + 1 < static_cast<int>(image.size()) &&
        image[x + 1][y] == old_color) {
      solve(image, x + 1, y, old_color, color);
    }

    if (x - 1 >= 0 && image[x - 1][y] == old_color) {
      solve(image, x - 1, y, old_color, color);
    }

    if (y + 1 < static_cast<int>(image[0].size()) &&
        image[x][y + 1] == old_color) {
      solve(image, x, y + 1, old_color, color);
    }

    if (y - 1 >= 0 && image[x][y - 1] == old_color) {
      solve(image, x, y - 1, old_color, color);
    }
  }
};
