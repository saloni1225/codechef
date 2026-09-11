class Solution {
  public:
    bool isBinary(string& s) {
    for(int i=0;i<s.length();i++){
        if(s[i]=='0' || s[i]=='1'){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
        
    }
};