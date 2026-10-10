class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }

        long long total = 0;
        for (int d : diff) total += d;

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid)
                    needed += d - mid;
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long ans = 0;

        for (int d : diff) {
            int reduced = min(d, level);
            ans += 1LL * reduced * reduced;
            k -= d - reduced;
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] >= level && level > 0) {
                ans -= 1LL * level * level;
                ans += 1LL * (level - 1) * (level - 1);
                k--;
            }
        }

        return ans;
    }
};