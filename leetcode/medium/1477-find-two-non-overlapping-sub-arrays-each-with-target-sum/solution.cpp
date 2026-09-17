class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        int ans = INT_MAX;

        // best[i] = shortest subarray with target sum
        // that ends at or before index i
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {

                int length = right - left + 1;

                // Combine with a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, length + best[left - 1]);
                }

                // This is the shortest target subarray
                // ending at/before right
                minLength = min(minLength, length);
            }

            best[right] = minLength;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};