class Solution { // T.C.O(n) and A. S. O(2n) not best approach

public:

    int minimumAverageDifference(vector<int>& nums) {

        int len=nums.size();

        vector<int> avg(len+1, 0);

        vector<int> arr(len+1, 0);

        if(len==1){

            return 0;

        }

        long long int sum=0;

        for(int i=0;i<len;i++){

            sum+=nums[i];

            avg[i+1]=sum/(i+1); 

        }

        sum=0;

        int cnt=1;

        for(int i=len-1;i>0;i--){

            sum+=nums[i];

            arr[i]=sum/(cnt); 

            cnt++;

        } 

        int minInd=-1;

        int avgDiff=INT_MAX;

        for(int i=0;i<len;i++){

            int avgVal=abs(avg[i+1]-arr[i+1]);

            if(avgVal<avgDiff){

                avgDiff=avgVal;

                minInd=i;

            } 

        } 

        return minInd;

    }

};
