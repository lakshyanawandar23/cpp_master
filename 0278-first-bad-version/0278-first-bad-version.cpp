// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution { // T.C. O(log(n)) A.S. O(1)
public:
    int firstBadVersion(int n) {
        long lo=1,hi=n,mid;
        while(hi>lo){
            mid=(hi+lo)/2;
            if(isBadVersion(mid)==false){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return lo;
    }
};
