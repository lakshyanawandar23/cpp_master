class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int len=temp.size();
        vector<int> ans(len,0);
        if(len==0){
            return ans;
        }
        stack<int> stk;
        stk.push(len-1);
        for(int i=len-2;i>=0;i--){
            while(stk.empty()==false && temp[stk.top()]<=temp[i]){
                stk.pop();
            }
            if(stk.empty()==false){
                ans[i]=stk.top()-i;
            }
            stk.push(i);
        }
        return ans;
    }
};
