class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>v;
        for(int i =0;i<nums.size();i++){
            long long sq =nums[i]*nums[i];
            v.push_back(sq);
        }
        sort(v.begin(),v.end());
        long long sum=0;;
        for(int i =0;i<v.size();i++){
            if(i<v.size()/2){
            sum += 0-v[i];
        }
            else{
            sum += v[i];
        }
        }
        return sum;
    }
};