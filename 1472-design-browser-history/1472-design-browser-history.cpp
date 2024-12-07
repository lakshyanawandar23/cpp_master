class BrowserHistory {
public:
    vector<string>v;
    int i;
    BrowserHistory(string homepage) {
        i=0;
        v.clear();
        v.push_back(homepage);
    }
    
    void visit(string url) {
        v.erase(v.begin()+i+1,v.end());
        v.push_back(url);
        i++;
    }
    
    string back(int steps) {
        while(steps>0&&i>0){
           steps--;
            i--;
        }
        return v[i];
    }
    
    string forward(int steps) {
        while(steps>0&&(i+1)<v.size()){
            i++;
            steps--;
        }
        return v[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */