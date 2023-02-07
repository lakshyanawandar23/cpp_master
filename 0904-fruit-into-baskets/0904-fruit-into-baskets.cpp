class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int>m;
        int ans=0,j=0;
        for(int i=0;i<f.size();i++){
            if(m.find(f[i])==m.end()){
                while(m.size()==2&&m[f[j]]>0){
                    m[f[j]]--;
                    if(m[f[j]]==0){
                        m.erase(f[j]);
                    }
                    j++;
                }
            }
            m[f[i]]++;
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};