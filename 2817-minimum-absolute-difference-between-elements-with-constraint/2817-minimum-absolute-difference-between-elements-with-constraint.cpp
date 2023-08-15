class Solution {
public:
    int minAbsoluteDifference(vector<int>& num, int x) {
        set<int>s;
        int ans=INT_MAX;
        for(int i=x;i<num.size();i++){
            s.insert(num[i-x]);
            auto ele=s.lower_bound(num[i]);
          //  cout<<*ele<<endl;
            
            if(ele!=s.end()){
            ans=min(ans,abs(*(ele)-num[i]));
                if(ele!=s.begin()){
                    ele--;
                   ans=min(ans,abs(*(ele)-num[i]));
                }
            }
            else{
                ele--;
                   ans=min(ans,abs(*(ele)-num[i]));
            }
          //  s.insert(num[i]);
        }
        return ans;
    }
};