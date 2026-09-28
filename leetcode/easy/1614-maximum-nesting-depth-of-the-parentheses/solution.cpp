class Solution {
public:
    int maxDepth(string s) {
        int par=0;
        int maxpar=0;
        for(char c: s){
            if( c == '('){
                par++;
                maxpar=max(par,maxpar);
            }
            else if(c == ')'){
                par--;
            }
        }
        return maxpar;
    }
};