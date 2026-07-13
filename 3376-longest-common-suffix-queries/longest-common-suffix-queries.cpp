class Solution {
public:
    struct Node {
        int child[26];
        int index;

        Node() {
            memset(child, -1, sizeof(child));
            index = -1;
        }
    };

    vector<Node> trie;

    void update(int node, vector<string>& words, int idx) {
        if (trie[node].index == -1 ||
            words[idx].size() < words[trie[node].index].size() ||
            (words[idx].size() == words[trie[node].index].size() &&
             idx < trie[node].index)) {
            trie[node].index = idx;
        }
    }

    void insert(int idx, vector<string>& words) {
        int node = 0;
        update(node, words, idx);

        const string &s = words[idx];

        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].child[c];
            update(node, words, idx);
        }
    }

    int search(string &q) {
        int node = 0;

        for (int i = q.size() - 1; i >= 0; i--) {
            int c = q[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].index;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.emplace_back(); // root

        for (int i = 0; i < wordsContainer.size(); i++)
            insert(i, wordsContainer);

        vector<int> ans;

        for (string &q : wordsQuery)
            ans.push_back(search(q));

        return ans;
    }
};