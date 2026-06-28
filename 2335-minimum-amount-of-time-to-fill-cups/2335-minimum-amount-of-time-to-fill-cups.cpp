class Solution {
public:
    int fillCups(vector<int>& amount) {
        int time = 0;
        priority_queue<int> pq;

        for (int x : amount) {
            if (x > 0)
                pq.push(x);
        }

        while (!pq.empty()) {
            int first = pq.top();
            pq.pop();

            if (!pq.empty()) {
                int second = pq.top();
                pq.pop();

                first--;
                second--;

                if (first > 0) pq.push(first);
                if (second > 0) pq.push(second);
            } else {
                first--;
                if (first > 0) pq.push(first);
            }

            time++;
        }

        return time;
    }
};