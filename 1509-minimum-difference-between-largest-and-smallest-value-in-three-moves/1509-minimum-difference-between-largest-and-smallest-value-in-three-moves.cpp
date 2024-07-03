class Solution {
public:
    int minDifference(vector<int>& num) {
        sort(num.begin(),num.end());
        if(num.size()<=3) return 0;
        int a=num[0],b=num[3],c=num[num.size()-4],d=num[num.size()-1],e=num[2],f=num[num.size()-2];
        return min({(d-b),(c-a),(f-e),(num[num.size()-3]-num[1])});
    }
};