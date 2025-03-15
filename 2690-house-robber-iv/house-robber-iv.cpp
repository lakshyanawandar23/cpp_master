class Solution {
public:
 bool solve(vector<int>&num,int mid,int k){
    int cnt=0;
    for(int i=0;i<num.size();i++){
        if(num[i]<=mid){
            cnt++;
            i++;
        }
    }
    return cnt>=k;
 }
    int minCapability(vector<int>& num, int k) {
        int n=num.size(),ans=0;
        int l=*(min_element(num.begin(),num.end()));
        int h=*(max_element(num.begin(),num.end()));
        while(l<=h){
            int mid=(l+h)/2;
           if(solve(num,mid,k)){
            ans=mid;
            h=mid-1;
           }
           else {
            l=mid+1;
           }
        }
        return ans;
    }
};