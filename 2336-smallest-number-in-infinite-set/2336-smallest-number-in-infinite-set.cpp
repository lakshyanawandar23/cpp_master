class SmallestInfiniteSet {
public:
    set<int>s;
    SmallestInfiniteSet() {
        for(int i=1;i<2000;i++){
            s.insert(i);
        }
    }
    
    int popSmallest() {
        auto it=s.begin();
        int u=*it;
        s.erase(it);
        return u;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */