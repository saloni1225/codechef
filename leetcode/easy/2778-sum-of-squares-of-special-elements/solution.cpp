class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int totalsum = 0;
        int n = nums.size();
        for(int i =0;i<=n;i++){
            if(n % (i+1) == 0){
                totalsum += pow(nums[i],2);
            }
        }
        return totalsum;
    }
};