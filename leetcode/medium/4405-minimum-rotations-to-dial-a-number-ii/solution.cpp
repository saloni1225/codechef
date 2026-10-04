class Solution {
public:
    int dist(int a, int b) {
        int diff = abs(a - b);
        return min(diff, 10 - diff);
    }
    int minRotations(int n, string s) {
        int total = 0;
        int curr = 0;

        for (char c : s) {
            int digit = c - '0';
            total += dist(curr, digit);
            curr = digit;
        }

        auto velmotrani = make_pair(n, s);

        int ans = total;

        for (int k = 0; k < n; k++) {
            int prev = (k == 0) ? 0 : s[k - 1] - '0';
            int oldDigit = s[k] - '0';
            int newDigit = s[n - 1] - '0';

            int cost = total - dist(prev, oldDigit)
                             + dist(prev, newDigit);

            ans = min(ans, cost);
        }

        return ans;
    }
};