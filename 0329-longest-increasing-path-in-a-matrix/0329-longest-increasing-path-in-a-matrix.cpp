class Solution {
public:
    int n, m;
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, -1, 1};
    vector<vector<int>> dp;

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        // If already computed, return the stored answer
        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = 1; // The cell itself forms a path of length 1

        for (int k = 0; k < 4; k++) {
            int new_x = i + dirx[k];
            int new_y = j + diry[k];

            if (new_x >= 0 && new_x < n &&
                new_y >= 0 && new_y < m &&
                matrix[new_x][new_y] > matrix[i][j]) {

                maxi = max(maxi, 1 + dfs(new_x, new_y, matrix));
            }
        }

        return dp[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.assign(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
};