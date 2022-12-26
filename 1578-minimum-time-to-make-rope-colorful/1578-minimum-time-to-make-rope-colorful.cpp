class Solution { // T.C. O(n)  and A.S. O(n)
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<int> stk;
        
        int ans=0;
        if(colors.length()==0){
            return ans;
        }
        
        
        
        for(int i=0;i<colors.size();i++){
            bool flag=true;
            while(stk.empty()==false && colors[stk.top()]==colors[i]){
                if(neededTime[stk.top()]>neededTime[i]){
                    ans+=neededTime[i];
                    flag=false;
                    break;
                }
                else{
                    ans+=neededTime[stk.top()];
                    stk.pop();
                }
            }
            if(flag)stk.push(i);
        }
        
        return ans;
        
    }
};
