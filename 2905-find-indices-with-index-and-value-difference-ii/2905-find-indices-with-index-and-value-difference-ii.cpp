class Solution {
public:
    vector<int> findIndices(vector<int>& num, int index, int value) {
        int n=num.size(),mini=INT_MAX,maxi=INT_MIN;
        vector<int>s(n),l(n);
        for(int i=num.size()-1;i>=0;i--){
            if(mini>num[i]){
                mini=num[i];
                s[i]=i;
            }
            else{
                s[i]=s[i+1];
            }
            
        }
           for(int i=num.size()-1;i>=0;i--){
            if(maxi<num[i]){
                maxi=num[i];
                l[i]=i;
            }
            else{
                l[i]=l[i+1];
            }
            
        }
        vector<int>v;
        for(int i=0;i<n-index;i++){
            if(abs(num[i]-num[s[i+index]])>=value){
                v.push_back(i);
                v.push_back(s[i+index]);
                return v;
            }
               if(abs(num[i]-num[l[i+index]])>=value){
                   v.push_back(i);
                v.push_back(l[i+index]);
                   return v;
               }
               }
        return {-1,-1};
    }
};