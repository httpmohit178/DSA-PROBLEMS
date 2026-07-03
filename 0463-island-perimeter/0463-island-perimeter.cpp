class Solution {
public:
    int r, c;
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};

    bool valid(int x, int y) {
        return x >= 0 && x < r && y >= 0 && y < c;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>> q;

        // Find first land cell
        for (int i = 0; i < r; i++) {
            bool found = false;
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2;   // mark visited
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        int perimeter = 0;

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nx = x + dirx[k];
                int ny = y + diry[k];

                if (!valid(nx, ny)) {
                    perimeter++;
                }
                else if (grid[nx][ny] == 0) {
                    perimeter++;
                }
                else if (grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
                // if grid[nx][ny] == 2 (already visited land),
                // do nothing because it is still land.
            }
        }

        return perimeter;
    }
};