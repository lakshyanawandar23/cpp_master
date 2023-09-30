class Solution {
public:
    bool find132pattern(vector<int>& num) {
        int n=num.size();
        vector<int>l(n,INT_MIN);
        vector<int>r(n,INT_MIN);
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(num[i]);
            auto it=s.find(num[i]);
            
            if(it!=s.begin()){
            //    cout<<(*it)<<endl;
                l[i]=(*s.begin());
            }
        }
        s.clear();
         for(int i=n-1;i>=0;i--){
            s.insert(num[i]);
            auto it=s.find(num[i]);
            if(it!=s.begin()){
                 it--;
                r[i]=(*it);
            }
        }
        for(int i=0;i<n;i++){
          //  cout<<l[i]<<" "<<r[i]<<endl;
            if(l[i]!=INT_MIN&&r[i]!=INT_MIN&&l[i]<r[i]){
                return true;
            }
        }
        return false;
    }
};