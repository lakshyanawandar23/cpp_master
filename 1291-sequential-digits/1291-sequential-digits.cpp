class Solution {
public:
    vector<int> sequentialDigits(int l, int h) {
        vector<int>v;
        for(int i=1;i<=9;i++){
            string ans;
            ans+=(i+'0');
            for(int j=i+1;j<=9;j++){
                ans+=(j+'0');
                if(stoi(ans)>=l&&stoi(ans)<=h){
                    v.push_back(stoi(ans));
                }
                else if(stoi(ans)>h) {
                    break;
                }
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};