class Solution {
public:
    int minRotations(string s) {
        int current = 0;
        int ans = 0;
        for(char c : s){
            int digit = c - '0';
            int diff = abs(digit - current);
            ans += min(diff , 10 - diff);
            current = digit;
        }
        return ans;
    }
};