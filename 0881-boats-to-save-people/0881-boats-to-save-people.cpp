class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int i=0;
        int j=people.size()-1;
        int result=0;
        sort(people.begin(),people.end());
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
                result++;
            }else{
                j--;
                result++;
            }
        }
    return result;
    }
};