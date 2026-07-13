struct Node{
    Node* links[10];
    bool flag;
    Node(){
        for(int i=0;i<10;i++){
            links[i] = nullptr;
        }
        flag = false;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
    bool containsKey(char ch){
        return (links[ch-'0']!=NULL);
    }
    void put(char ch , Node * node){
        links[ch-'0'] = node;
    }
    Node * get(char ch){
        return links[ch-'0'];
    }
};
class Trie{
private:
    Node * root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string & s){
        Node * node = root;
        for(char ch : s){
            if(!node->containsKey(ch)){
                node->put(ch , new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    int count(string & s){
        Node * node = root;
        int cnt = 0;
        for(char ch : s){
            if(!node->containsKey(ch)){
                break;
            }
            node = node->get(ch);
            cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi = 0;
        Trie t;
        for(int i = 0 ; i<arr1.size() ; i++){
            string s = to_string(arr1[i]);
            t.insert(s);
        }
        for(int i=0;i<arr2.size();i++){
            string s = to_string(arr2[i]);
            int cnt = t.count(s);
            maxi = max(maxi , cnt);
        }
        return maxi;
    }
};