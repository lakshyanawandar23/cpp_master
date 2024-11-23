class Solution {
public:
    long long countFairPairs(vector<int>& num, int lower, int upper) {
        sort(num.begin(),num.end());
        long long int cnt=0;
        for(int i=0;i<num.size();i++){
            auto it1=lower_bound(num.begin()+i+1,num.end(),(lower-num[i]))-num.begin();
           auto it2=upper_bound(num.begin()+i+1,num.end(),(upper-num[i]))-num.begin();
            it2--;
            cout<<it1<<" "<<it2<<endl;
            if(it1<=it2){
                cnt+=(it2-it1+1);
            }
        }
        return cnt;
    }
};