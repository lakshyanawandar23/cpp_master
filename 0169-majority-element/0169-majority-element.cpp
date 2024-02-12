class Solution {
public:
    int majorityElement(vector<int>& num) {
        int cnt=1,ele=num[0];
        for(int i=1;i<num.size();i++){
            if(ele==num[i]){
                cnt++;
            }
            else {
                cnt--;
                if(cnt==0){
                    ele=num[i];
                    cnt=1;
                          }
            }
        }
            return ele;
    }
};