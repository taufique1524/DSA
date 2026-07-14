class Solution {
public:
    pair<int, int> expand(int start, string &s, vector<int> &first, vector<int> &last) {
        int left = start;
        int right = last[s[start] - 'a'];
        for (int i = left; i <= right; i++) {
            int ch = s[i] - 'a';
            if (first[ch] < left)
                return {-1, -1};
            right = max(right, last[ch]);
        }
        return {left, right};
    }

    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26);
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a'])
                continue;
            auto interval = expand(i, s, first, last);
            if (interval.first != -1)
                intervals.push_back(interval);
        }
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int end = -1;

        for (auto &[l, r] : intervals) {
            if (l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};