class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& num, int k) {
        deque<pair<int,int>>q;
        for(int i=0;i<k;i++){
            while(!q.empty()&&q.back().first<num[i]){
                q.pop_back();
            }
            q.push_back({num[i],i});
        }
        vector<int>ans;
        ans.push_back(q.front().first);
        int j=k;
        while(j<num.size()){
            while(!q.empty()&&abs(q.front().second-j)>=k){
                q.pop_front();
            }
            while(!q.empty()&&q.back().first<num[j]){
                q.pop_back();
            }
            q.push_back({num[j],j});
            ans.push_back(q.front().first);
            j++;
        }
        return ans;
    }
};