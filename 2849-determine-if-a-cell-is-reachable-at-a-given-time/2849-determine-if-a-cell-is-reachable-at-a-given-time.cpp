class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(fx-sx);
        int y=abs(sy-fy);
        if(fx==sx&&fy==sy&&t==1) return false;
        return max(x,y)<=t;
    }
};