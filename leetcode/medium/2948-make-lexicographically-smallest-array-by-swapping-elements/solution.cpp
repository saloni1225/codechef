class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> v;

        // Store {value, original index}
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort by value
        sort(v.begin(), v.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            int j = i;

            // Find one connected group
            while (j + 1 < n && v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Get original indices of this group
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(v[k].second);
            }

            // Sort original indices
            sort(indices.begin(), indices.end());

            // Values v[i...j] are already sorted
            for (int k = 0; k < indices.size(); k++) {
                ans[indices[k]] = v[i + k].first;
            }

            i = j + 1;
        }

        return ans;
    }
};