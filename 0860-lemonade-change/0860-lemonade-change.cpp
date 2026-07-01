class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int five=0;
        int ten=0;
        int twenty=0;
        int i=0;
        while(i<n){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(five&&ten){
                    five--;
                    ten--;
                    twenty++;
                }
                else if(five>=3){
                    five-=3;
                    twenty++;
                }
                else{
                    return false;
                }
            }
            i++;
        }
        return true;
        
    }
};