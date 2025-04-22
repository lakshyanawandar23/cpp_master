class Solution {
public:
void first(vector<int>&num,int&t,int&a){
    int l=0,h=num.size()-1;
    while(l<=h){
        int m=(l+h)/2;
        if(num[m]==t){
            a=m;
            h=m-1;
        }
        else if(num[m]>t) h=m-1;
        else l=m+1;
    }
    return ;
}
void second(vector<int>&num,int&t,int&b){
    int l=0,h=num.size()-1;
    while(l<=h){
        int m=(l+h)/2;
        if(num[m]==t){
            b=m;
            l=m+1;
        }
        else if(num[m]>t) h=m-1;
        else l=m+1;
    }
    return ;
}
    vector<int> searchRange(vector<int>& num, int t) {
        int n=num.size();
        int a=-1,b=-1;
        first(num,t,a);
        second(num,t,b);
        return {a,b};
    }
};