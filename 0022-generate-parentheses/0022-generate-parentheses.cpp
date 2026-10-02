class Solution {
public:
    void parent(int n,int left,int right,vector<string>&ans,string &temp){
        if(left==n && right==n){
            ans.push_back(temp);
        }
        if(left<n){
            temp.push_back('(');
            parent(n,left+1,right,ans,temp);
            temp.pop_back();
        }
         if(left>right){
            temp.push_back(')');
            parent(n,left,right+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        parent(n,0,0,ans,temp);
        return ans;
        
    }
};