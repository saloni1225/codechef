class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < s.size(); i++) {

            int c = s[i] - 'a';

            if (first[c] == -1) {
                first[c] = i;
            }

            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid substring for every character
        for (int c = 0; c < 26; c++) {

            if (first[c] == -1)
                continue;

            int left = first[c];
            int right = last[c];

            bool valid = true;

            for (int i = left; i <= right; i++) {

                int current = s[i] - 'a';

                // This character appeared before our left boundary
                if (first[current] < left) {
                    valid = false;
                    break;
                }

                // We need to include all occurrences
                right = max(right, last[current]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // Select maximum number of non-overlapping intervals
        sort(intervals.begin(), intervals.end(),
             [](pair<int,int> a, pair<int,int> b) {
                 return a.second < b.second;
             });

        vector<string> answer;

        int previousEnd = -1;

        for (auto interval : intervals) {

            int left = interval.first;
            int right = interval.second;

            if (left > previousEnd) {

                answer.push_back(s.substr(left, right - left + 1));

                previousEnd = right;
            }
        }

        return answer;
    }
};