class Solution {
    public int minTimeToVisitAllPoints(int[][] p) {
           int ans=0;
        for(int i=1;i<p.length;i++){
            int x=Math.abs(p[i][0]-p[i-1][0]);
            int y=Math.abs(p[i][1]-p[i-1][1]);
            ans+=Math.max(x,y);
        }
        return ans;
    }
}