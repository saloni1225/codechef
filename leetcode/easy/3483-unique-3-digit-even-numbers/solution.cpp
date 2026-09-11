class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;

        for (int num = 100; num <= 999; num++) {

            // Number must be even
            if (num % 2 != 0) {
                continue;
            }

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> freq(10, 0);

            // Count available digits
            for (int d : digits) {
                freq[d]++;
            }

            // Try using the three digits
            if (freq[a] > 0) {
                freq[a]--;
            } else {
                continue;
            }

            if (freq[b] > 0) {
                freq[b]--;
            } else {
                continue;
            }

            if (freq[c] > 0) {
                freq[c]--;
            } else {
                continue;
            }

            count++;
        }

        return count;
    }
};