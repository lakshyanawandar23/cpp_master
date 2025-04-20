class Solution {
public:
    int numRabbits(vector<int>& v) {
        int n=v.size();
        unordered_map<int,int>mp;
        for(auto it:v){
            mp[it]++;
        }
        int cnt=0;
        for(auto it:mp){
            cout<<(it.second)/(it.first+1)<<endl;
            cnt+=(ceil((double)it.second/(it.first+1))*(it.first+1));
        }
        return cnt;
    }
};