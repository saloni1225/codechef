class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>ans;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
            ans.push_back(tolower(s[i]));
            }
        }
        int i=0,j=ans.size()-1;
        while(i<j){
            if(ans[i] != ans[j]){
                return false;
            }
            i++;j--;
        }
        return true;
        
    }
};