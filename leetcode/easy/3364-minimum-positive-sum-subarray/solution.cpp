class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int minm=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum =0;
                for(int k=i;k<=j;k++){
                    sum += nums[k];
                }
                int len=j-i+1;
                if(len>=l && len <=r && sum>0){
                    minm=min(minm,sum);
                }
            }
        }
        if(minm==INT_MAX) return -1;
        return minm;
    }
};