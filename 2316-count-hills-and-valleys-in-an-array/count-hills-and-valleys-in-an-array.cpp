class Solution {
public:
    int countHillValley(vector<int>& num) {
        int n=num.size();
        vector<int>v;
        v.push_back(num[0]);
        for(int i=1;i<n;i++){
            if(num[i]!=num[i-1]){
                v.push_back(num[i]);
            }
        }
        int cnt=0;
        for(int i=1;i<v.size()-1;i++){
            if(v[i]>v[i-1]&&v[i]>v[i+1]) cnt++;
            else if(v[i]<v[i+1]&&v[i]<v[i-1]) cnt++;
        }
        return cnt;

    }
};