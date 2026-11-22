class Solution {
public:
    bool checkString(string s) {
        int j=0;
        for(int i=1;i<s.size();i++){
            if(s[j]>s[i])return false;
            j++;
        }
        return true;
    }
};