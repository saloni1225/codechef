class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.empty()) return "";
       sort(strs.begin(),strs.end());
       vector<char>ans;
       string st=strs[0];
       string ed=strs[strs.size()-1];
       for(int i=0;i<min(st.size(),ed.size());i++){
        if(st[i] != ed[i])break;
            ans.push_back(st[i]);
       }
       return string(ans.begin(),ans.end());
    }
};