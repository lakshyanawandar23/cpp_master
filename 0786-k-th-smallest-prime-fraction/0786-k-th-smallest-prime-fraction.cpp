class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,pair<int,int>>>v;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                float ans=arr[i]/(arr[j]*1.0);
               // cout<<ans<<endl;
                v.push_back({(float)(ans),{i,j}});
            }
        }
        sort(v.begin(),v.end());
        return  {arr[v[k-1].second.first],arr[v[k-1].second.second]} ;
    }
};