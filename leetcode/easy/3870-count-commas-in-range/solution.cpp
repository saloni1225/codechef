class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        long long start = 1000;  // First number that has a comma

        while (start <= n) {
            long long end = start * 1000 - 1;

            // Number of commas for numbers in this range
            long long commas = start / 1000;

            // Only go up to n
            long long last = min((long long)n, end);

            // Count numbers in this range
            long long count = last - start + 1;

            ans += count * commas;

            start *= 1000;
        }

        return ans;
    }
};