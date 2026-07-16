class Solution {
public:
  int histogram(vector<int>& h) {
    stack<int> st;
    int n = h.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            int height = h[st.top()];
            st.pop();

            int prev = st.empty() ? -1 : st.top();
            int next = i;

            ans = max(ans, height * (next - prev - 1));
        }
        st.push(i);
    }

    while (!st.empty()) {
        int height = h[st.top()];
        st.pop();

        int prev = st.empty() ? -1 : st.top();
        int next = n;

        ans = max(ans, height * (next - prev - 1));
    }

    return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>temp(m,0);
        int maxarea=INT_MIN;
        for(int  i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    temp[j]+=(matrix[i][j]-'0');
                }else{
                    temp[j]=0;
                }
            }
            int ans=histogram(temp);
            maxarea=max(maxarea,ans);
        }
        return maxarea;
    }
};