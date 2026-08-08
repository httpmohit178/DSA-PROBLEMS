class Solution {
public:
    int countSubstrings(string s) {
       // using smart apporach

       // Tc=>O(N^2);

       // consider every index as the center of pallindrome for odd pallindromes

       // consider 2 indexs with together and check for pallindromes it gives about 
       // the even length pallindrome 
       int n=s.size();
      int count=0;
       for(int i=0;i<n;i++){
        int l=i;
        int r=i;
        while(l>=0&&r<n&&s[l]==s[r]){
            count++;
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while(l>=0&&r<n&&s[l]==s[r]){
            count++;
            l--;
            r++;
        }
       }
        return count;
        
    }
};