class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnOdd = INT_MAX;

        for (int x : nums1) {
            if (x % 2)
                mnOdd = min(mnOdd, x);
        }

        for (int x : nums1) {
            if (x % 2 == 0) {
                if (mnOdd >= x)
                    return false;
            }
        }

        return true;
    }
};