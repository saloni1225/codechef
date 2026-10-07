class Solution {
public:

    bool isValid(string s) {
        int count = 0;

        for(char ch : s) {

            if(ch == '(') {
                count++;
            }
            else if(ch == ')') {
                count--;

                if(count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string curr = q.front();
                q.pop();

                // Check whether current string is valid
                if(isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // If we already found valid strings,
                // don't generate another level.
                if(found)
                    continue;

                // Remove one character at a time
                for(int i = 0; i < curr.size(); i++) {

                    // Only remove parentheses
                    if(curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next = curr.substr(0, i) +
                                  curr.substr(i + 1);

                    if(visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // First valid level = minimum removals
            if(found)
                break;
        }

        return ans;
    }
};