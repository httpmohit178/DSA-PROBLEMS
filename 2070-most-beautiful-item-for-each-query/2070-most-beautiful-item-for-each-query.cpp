class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        sort(items.begin(), items.end());

        int n = items.size();

        // Prefix maximum beauty
        for (int i = 1; i < n; i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<int> ans;

        for (int q : queries) {

            int l = 0, r = n - 1;
            int idx = -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (items[mid][0] <= q) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (idx == -1)
                ans.push_back(0);
            else
                ans.push_back(items[idx][1]);
        }

        return ans;
    }
};