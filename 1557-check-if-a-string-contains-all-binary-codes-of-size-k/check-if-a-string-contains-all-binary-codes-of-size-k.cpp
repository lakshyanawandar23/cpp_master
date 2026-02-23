class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        long long int ans=0;
        int i=0;
        for(int j=k-1;j<s.size();j++){
            string res=s.substr(i,k);
            i++;
            st.insert(res);
        }
        ans=pow(2,k);
        int res=st.size();
        return ans==res;
    }
};