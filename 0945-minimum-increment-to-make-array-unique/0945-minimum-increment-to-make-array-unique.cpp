class Solution {
public:
    int minIncrementForUnique(vector<int>& num) {
        int n=num.size(),cnt=0;
        sort(num.begin(),num.end());
        set<int>s;
        s.insert(num[0]);
        auto it=s.begin();
      //  auto val=*(it);
        for(int i=1;i<n;i++){
            auto val=*(it);
          //  cout<<val<<endl;
            if(num[i]==num[i-1]){
                cnt+=abs(val-num[i])+1;
                s.insert(val+1);
            }
            else if(s.find(num[i])!=s.end()){
                cnt+=abs(val-num[i])+1;
                s.insert(val+1);
            }
           else {
               s.insert(num[i]);
           }
            it++;
        }
        return  cnt;
    }
};