class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) { // T.C. O(n) A.S. O(n/2) or O(n)
        sort(changed.begin(),changed.end());
        vector<int> ans;
        if(changed.size()%2){
            return ans;
        }
        map<int,int> mp;
        for(auto elem:changed){
            if(elem%2==0 && mp[elem/2]>0){
                mp[elem/2]--;
                continue;
            }
            else{
                mp[elem]++;
                ans.push_back(elem);
            }
        }
        if(ans.size()==changed.size()/2){
            return ans;
        }
        vector<int> v;
        return v;
    }
};
