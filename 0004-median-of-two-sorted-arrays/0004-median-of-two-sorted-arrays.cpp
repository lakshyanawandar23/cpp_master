class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        while(i<n&&j<m){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n){
            v.push_back(nums1[i]);
            i++;
        }
         while(j<m){
            v.push_back(nums2[j]);
            j++;
        }
        if(v.size()%2!=0){
         //   cout<<v[v.size()/2]<<endl;
            return (double)v[v.size()/2];
        }
        else{
            return (double)(v[v.size()/2]+v[(v.size()/2)-1])/2;
        }
    }
};