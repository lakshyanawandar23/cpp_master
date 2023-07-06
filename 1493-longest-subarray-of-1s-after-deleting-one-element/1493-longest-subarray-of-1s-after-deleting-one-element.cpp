class Solution {
public:
    int longestSubarray(vector<int>& num) {
        int n=num.size(),cnt=0,s=0,p=0,ans=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(num[i]==0){
                flag=true;
                cnt++;
                if(cnt>1){
                    s=p;
                    p=i+1;
                    cnt=1;
                    ans=max(ans,(i-s));
                }
                else{
                    p=i+1;
                    ans=max(ans,(i-s));
                }
            }
            else{
                if(cnt>0){
                ans=max(ans,(i-s));
                }
                else {
                    ans=max(ans,(i-s)+1);
                    cnt=0;
                }
            }
        }
        if(!flag) return n-1;
        return ans;
    }
};