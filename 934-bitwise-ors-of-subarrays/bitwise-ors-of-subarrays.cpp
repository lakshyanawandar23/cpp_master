class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>s;
        set<int>t;
        for(auto it:arr){
            set<int>p;
            p.insert(it);
            for(auto i:t){
                int x=i|it;
                p.insert(x);
            }
            t.clear();
            t.insert(p.begin(),p.end());

            s.insert(t.begin(),t.end());

        }
      //  for(auto it:s) cout<<(it)<<endl;
        return s.size();
    }
};