class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>max){
                max=nums[i];
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            while(nums[i]!=max){
                nums[i]+=1;
                count++;
            }
        }
        return count;
    }
};