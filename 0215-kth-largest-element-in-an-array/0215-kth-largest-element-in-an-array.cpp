class Solution {
public:
    int findKthLargest(vector<int>& num, int k) {
        priority_queue<int>q;
        for(auto it:num){
            q.push(it);
        }
        int ans;
        while(k--){
        auto p=q.top();
            q.pop();
        ans=p;
        }
        return ans;
    }
};