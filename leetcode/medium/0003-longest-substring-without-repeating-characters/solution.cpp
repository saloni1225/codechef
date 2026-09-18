class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //your code goes here
        int first=0,second=0,len=0;
        vector<bool>substr(256,0);
        while(second<s.size()){
            while(substr[s[second]]){
                substr[s[first]]=0;
                first++;
            }
            substr[s[second]]=1;
            len=max(len,(second-first+1));
            second++;
        }
        return len;
    }
};