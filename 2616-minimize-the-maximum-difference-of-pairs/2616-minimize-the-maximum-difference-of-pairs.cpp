class Solution {
public:
    bool solve(vector<int>&num,int mid,int &p){
        int cnt=0;
        for(int i=1;i<num.size();i++){
            if(num[i]-num[i-1]<=mid){
                cnt++;
                i++;
            }
        }
        return p<=cnt;
    }
    int minimizeMax(vector<int>& num, int p) {
        sort(num.begin(),num.end());
        int l=0,h=num[num.size()-1]-num[0];
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(num,mid,p)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};