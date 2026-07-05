class Solution {
public:
   bool dfs(int node,vector<int>&visited,vector<int>adj[],vector<int>&ans,vector<int>&path){
    visited[node]=1;
    path[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
           if( !dfs(it,visited,adj,ans,path)){
            return false;
           }
        }else if(path[it]==1){
            return false;
        }else if(ans[it]==0){
              return false;
        }
}

    path[node]=0;
    ans[node]=1;
    return true;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // kha se kha tak ja rhe edges adajcency list creation
        vector<int>adj[n];
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        // solve using dfs
        vector<int>visited(n,0);
        vector<int>ans(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj,ans,path);
            }
        }
        vector<int>safenodes;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1){
                safenodes.push_back(i);
            }
        }
       
        return safenodes;
        
    }
};