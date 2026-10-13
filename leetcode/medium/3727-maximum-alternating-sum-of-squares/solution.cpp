class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>v;
        for(int i =0;i<nums.size();i++){
            long long sq =nums[i]*nums[i];
            v.push_back(sq);
        }
        sort(v.begin(),v.end());
        long long nsum=0,psum=0;
        for(int i =0;i<v.size()/2;i++){
            nsum += 0-v[i];
        }
        for(int i =(v.size()/2);i<v.size();i++){
            psum += v[i];
        }
        return nsum + psum;
    }
};