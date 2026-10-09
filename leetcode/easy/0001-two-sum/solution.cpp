class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int req=target-nums[i];
            if(mp.find(req)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[req]);
                break;
            }
            else{
                mp[nums[i]]=i;
            }

        }
        return ans;
    }
};