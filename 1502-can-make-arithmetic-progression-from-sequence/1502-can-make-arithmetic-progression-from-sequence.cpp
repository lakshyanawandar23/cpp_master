class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff=abs(arr[0]-arr[1]);
        for(int i=2;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])!=diff){
                return false;
            }
            diff=abs(arr[i]-arr[i-1]);
        }
        return true;
    }
};