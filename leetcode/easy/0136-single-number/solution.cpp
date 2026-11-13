class Solution {
public:
    int singleNumber(vector<int>& nums) {
      //int count 0;
    unordered_map<int,int>mp;
      for(auto x:nums){
        mp[x]++;
      }
      for(auto y:mp){
        if(y.second==1){
            return y.first;
        }
      }
      return -1;
    }
};