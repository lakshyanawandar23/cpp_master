class Solution {
    public int sumFourDivisors(int[] num) {
        int n=num.length,ans=0;
        for(int i=0;i<n;i++){
            int sum=1,cnt=2;
            for(int j=2;j<=(num[i]/2);j++){
                if(cnt>4) break;
                if(num[i]%j==0){
                    cnt++;
                    sum+=j;
                }
            }
            if(cnt==4){
                sum+=num[i];
                ans+=sum;
            }
        }
        return ans;
    }

}