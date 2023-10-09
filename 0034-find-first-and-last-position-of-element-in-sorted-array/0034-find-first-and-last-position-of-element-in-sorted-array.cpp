class Solution {
public:
    int find(vector<int>&num,int &t){
   int l=0,h=num.size()-1,ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(num[m]==t){
                ans=m;
                l=m+1;
            }
            else if(num[m]>t){
                h=m-1;
            }
            else {
                l=m+1;
            }
        }
        return ans;
    }
    int solve(vector<int>&num,int &t){
   int l=0,h=num.size()-1,ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(num[m]==t){
                ans=m;
                h=m-1;
            }
            else if(num[m]>t){
                h=m-1;
            }
            else {
                l=m+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& num, int t) {
        vector<int>v;
       int f=solve(num,t);
       int l=find(num,t);
        if(l==-1|f==-1)  return {-1,-1};
        return {f,l};
    }
};