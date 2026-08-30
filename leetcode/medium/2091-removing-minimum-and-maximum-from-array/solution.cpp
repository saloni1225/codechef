class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = INT_MAX;
        int mx = INT_MIN;

        int minIndex = 0;
        int maxIndex = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < mn) {
                mn = nums[i];
                minIndex = i;
            }

            if(nums[i] > mx) {
                mx = nums[i];
                maxIndex = i;
            }
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Both from left
        int option1 = right + 1;

        // Both from right
        int option2 = n - left;

        // One from each side
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};