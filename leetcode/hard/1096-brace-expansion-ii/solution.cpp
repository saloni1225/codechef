class Solution {
public:

    set<string> combine(set<string> &a, set<string> &b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    set<string> parse(string &s, int &i) {

        set<string> result;

        while (i < s.size() && s[i] != '}') {

            set<string> current;

            if (s[i] == '{') {
                i++;  // skip '{'

                current = parse(s, i);

                i++;  // skip '}'
            }

            else {
                current.insert(string(1, s[i]));
                i++;
            }

            if (result.empty()) {
                result = current;
            } else {
                result = combine(result, current);
            }

            // Union
            if (i < s.size() && s[i] == ',') {
                i++;
                
                set<string> next = parse(s, i);

                for (string x : next) {
                    result.insert(x);
                }
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};