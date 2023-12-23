class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse=0;
        long long temp=x;
        while(x>0){
            int cc=x%10;
            x=x/10;
            reverse=reverse*10+cc;
        }
        if(reverse == temp){
            return true;
        }
        return false;
        
    }
};

