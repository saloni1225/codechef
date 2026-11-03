class Solution {
public:
    int romanToInt(string s) {
        vector<char>symb={'I','V','X','L','C','D','M'};
        vector<int>val={1,5,10,50,100,500,1000};
        unordered_map<char,int>mp;
        for(int i =0;i<symb.size();i++){
            mp[symb[i]]=val[i];
        }
        int sum =0;
        int n=s.size();
        for(int i = 0;i<n-1;i++){
            if(mp[s[i]]>=mp[s[i+1]]){
                sum+=mp[s[i]];
            }
            else{
                sum-=mp[s[i]];
            }
        }

        return sum + mp[s[n-1]];
    }
};