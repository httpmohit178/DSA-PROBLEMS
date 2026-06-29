class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // Push only the head of each list
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            ListNode* node = curr.second;
            tail->next = node;
            tail = tail->next;

            // Push the next node of the extracted node
            if (node->next) {
                pq.push({node->next->val, node->next});
            }
        }

        return dummy->next;
    }
};