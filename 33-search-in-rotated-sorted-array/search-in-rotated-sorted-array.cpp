class Solution {
public:
    int search(vector<int>& num, int t) {
        int l=0,h=num.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(num[mid]==t) return mid;
            if(num[l]<=num[mid]){
                if(num[l]<=t&&num[mid]>=t)
                h=mid-1;
                else l=mid+1;
            }
            else {
                if(num[mid]<t&&num[h]>=t) l=mid+1;
                else h=mid-1;
            }
        }
        return -1;
    }
};