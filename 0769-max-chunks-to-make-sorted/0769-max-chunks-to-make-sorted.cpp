class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0,maxi=-1;
        for(int i=0;i<arr.size();i++){
            maxi=max(arr[i],maxi);
            if(maxi==i){
            cnt++;
            maxi=-1;
            }
        }
        return cnt;
    }
};