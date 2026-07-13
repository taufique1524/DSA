struct Node{
    Node* links[2];
    int bit;
    int cnt;
    Node(){
        links[0] = links[1] = nullptr;
        bit = 0;
        cnt = 0;
    }
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }

    Node * get(int bit){
        return links[bit];
    }
    void put(int bit , Node * node){
        links[bit] = node;
    }
};
class Trie{
private:
    Node * root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node * node = root;
        for(int i=31;i>=0;i--){
            int bit = ((num>>i)&1);
            if(!node->containsKey(bit)){
                node->put(bit , new Node());
            }
            node = node->get(bit);
            node->cnt++;
        }
    }

    int findMaxi(int num){
        Node * node = root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int bit = ((num>>i)&1);
            int reqBit = 1-bit;
            if(node->containsKey(reqBit) && node->get(reqBit)->cnt>0){
                ans = (ans | 1<<i);
                node = node->get(reqBit);
            }else{
                node = node->get(bit);
            }
        }
        return ans;
    }

    void remove(int num){
        Node * node = root;
        for(int i=31 ; i>=0 ; i--){
            int bit = ((num>>i)&1);
            node = node->get(bit);
            node->cnt--;
        }
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        Trie t;
        int n = nums.size() , j = 0 , maxi = 0;
        sort(nums.begin() , nums.end());
        for(int i=0;i<n;i++){
            while(j<nums.size() && ((nums[j]-nums[i])<= min(nums[i],nums[j]))){
                t.insert(nums[j]);
                j++;
            }
            int temp = t.findMaxi(nums[i]);
            maxi = max(maxi , temp);
            t.remove(nums[i]);
        }
        return maxi;
    }
};