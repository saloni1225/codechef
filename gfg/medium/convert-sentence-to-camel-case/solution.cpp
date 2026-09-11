class Solution {
  public:
    // Function to convert the given string to Camel Case
    string convertToCamelCase(string& s) {
        // code here
        string res;
        bool captalize=false;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                captalize=true;
            }
            else if(captalize==true){
                res+=toupper(s[i]);
                captalize=false;
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};
