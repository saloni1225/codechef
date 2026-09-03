class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;

        for (int x : nums1) {
            if (x % 2 != 0) {
                smallestOdd = min(smallestOdd, x);
            }
        }
        if (smallestOdd == INT_MAX)
            return true;

        for (int x : nums1) {
            if (x % 2 == 0 && x <= smallestOdd) {
                return false;
            }
        }

        return true;
    }
};