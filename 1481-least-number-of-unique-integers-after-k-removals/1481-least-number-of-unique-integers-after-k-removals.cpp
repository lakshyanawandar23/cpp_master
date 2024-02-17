class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto it:arr){
            m[it]++;
        }
        for(auto it:m){
            q.push(it.second);
        }
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            if(k>=p){
                k-=p;
            }
            else {
                return q.size()+1;
            }
        }
        return 0;
    }
};