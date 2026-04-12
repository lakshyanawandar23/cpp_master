class Robot {
public:
   vector<vector<int>>v;
    bool flag;
    int idx=0;
    Robot(int w, int h) {
    // move for east side
      for(int i=0;i<w;i++){
        v.push_back({i,0,1});
      }    
      //move for north
      for(int i=1;i<h;i++){
         v.push_back({w-1,i,2});
      }
      //move for west side
      for(int i=w-2;i>=0;i--){
        v.push_back({i,h-1,3});
      }
      //move for south
      for(int i=h-2;i>0;i--){
         v.push_back({0,i,4});
      }
     flag=false;
     v[0][2]=4;
    }
    
    void step(int num) {
        flag=true;
        idx=(idx+num)%v.size();
      //  return {v[idx][0],v[idx][1]};
    }
    
    vector<int> getPos() {
         return {v[idx][0],v[idx][1]};

    }
    
    string getDir() {
                if(!flag) return "East";
        int dir=v[idx][2];
        if(dir==2) return "North";
        if(dir==3) return "West";
        if(dir==4) return "South";
        return "East";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */