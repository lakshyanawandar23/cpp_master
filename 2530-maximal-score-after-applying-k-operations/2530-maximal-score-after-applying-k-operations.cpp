class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto val:nums){
            q.push(val);
        }
        long long int cnt=0;
        while(!q.empty()&&k>0){
         auto it=q.top();
            q.pop();
            cnt+=it;
            int res;
            if(it%3!=0){
                res=(it/3)+1;
            }
            else{
                res=it/3;
            }
            //cout<<res<<endl;
            if(res>0){
            q.push(res);
        }
            k--;
        }
        return cnt;
    }
};