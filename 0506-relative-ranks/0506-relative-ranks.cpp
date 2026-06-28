class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        // max heap because highest score gets rank 1
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        vector<string> arr(n);
        int count = 1;

        while (!pq.empty()) {
            string ans = "";

            if (count == 1)
                ans = "Gold Medal";
            else if (count == 2)
                ans = "Silver Medal";
            else if (count == 3)
                ans = "Bronze Medal";
            else
                ans = to_string(count);

            arr[pq.top().second] = ans; // store at original index

            pq.pop();
            count++;
        }

        return arr;
    }
};