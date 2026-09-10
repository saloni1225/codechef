class Solution {
public:
    string defangIPaddr(string address) {
        int index=0;
        string result;
        for(int i=0;i<address.size();i++){
            if(address[index]=='.'){
                result+="[.]";
                index++;
            }
            else{
                result+=address[index];
                index++;
            }
        }
        return result;
    }
};