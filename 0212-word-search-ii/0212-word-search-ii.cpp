class Solution {
public:
    vector<string>result;

    vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    int n,m;
    // Node struct For Trie
    struct trieNode{
        bool endofword;
        string word;
        trieNode*children[26];
    };

    // getTrieNode
    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        newNode->endofword=false;
        newNode->word="";
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }

    void insert(trieNode*root,string &word){
        trieNode*crawler=root;
        // check for each character of words 
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();

            }
            crawler=crawler->children[idx];
        }
        crawler->endofword=true;
        crawler->word=word;
    }
    void findWords(vector<vector<char>>&board,int i,int j,trieNode*root){
        if(i<0||j<0||i>=n||j>=m){
            return;
        }
        if(board[i][j]=='$'|| root->children[board[i][j]-'a']==NULL){
            return;
        }
        root=root->children[board[i][j]-'a'];
        if(root->endofword==true){
            result.push_back(root->word);
            root->endofword=false;
        }  
        char temp=board[i][j];
        board[i][j]='$'; // marking visiting

        // dfs left, right ,up ,down 
        for(vector<int>&dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            findWords(board,new_i,new_j,root);
        }
        board[i][j]=temp; // marking unvisiting now



    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size(); // row
        m=board[0].size(); //column

        // create root 
        trieNode*root=getNode();
        // insert words in the trie

        for(string &s:words){
            insert(root,s);
        }
        // traverse in the grid and find all the words in trie if present
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    findWords(board,i,j,root);
                }

            }
        }
        return result;
        
    }
};