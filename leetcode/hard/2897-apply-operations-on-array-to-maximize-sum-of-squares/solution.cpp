#pragma GCC optimize("O3")
#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        // Fast I/O
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        const int MOD = 1'000'000'007;
        int bitCount[30] = {0};
        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }

        long long totalSumOfSquares = 0;
        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;
            for (int i = 0; i < 30; ++i) {
                if (bitCount[i] > 0) {
                    currentNum |= (1 << i);
                    bitCount[i]--;
                }
            }
            totalSumOfSquares = (totalSumOfSquares + (currentNum * currentNum) % MOD) % MOD;
        }

        return totalSumOfSquares;
    }
};