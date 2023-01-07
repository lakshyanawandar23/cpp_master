class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>m;
        string ans,res;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<order.size();i++){
            if(m.find(order[i])!=m.end()){
                string r;
                r.append(m[order[i]],order[i]);
                ans+=r;
                m.erase(order[i]);
            }
        }
        for(auto it:m){
            string r;
            r.append(it.second,it.first);
          ans+=r;
        }
        return ans;
    }
};