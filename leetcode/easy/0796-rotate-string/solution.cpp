class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size()){
        return false;
        }
        for(int i=0;i<n;i++){
            if(s==goal){
                return true;
            }
            char temp=s[0];
            for(int i=1;i<n;i++){
                s[i-1]=s[i];
            }
            s[n-1]=temp;
            }
            return false;
    }
};