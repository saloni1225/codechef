class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty()) return "";
       sort(strs.begin(),strs.end());
       vector<char>ans;
       string firstword=strs[0];
       string endword=strs[strs.size()-1];
       for(int i=0;i<min(firstword.size(),endword.size());i++){
        if(firstword[i] != endword[i])break;
            ans.push_back(firstword[i]);
       }
       return string(ans.begin(),ans.end());
    }
};