class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;//set基于hashtable实现，可以快速查找和删除
        for(int i=0;i<obstacles.size();i++) obs.insert(to_string(obstacles[i][0])+"#"+to_string(obstacles[i][1]));
        int res=0, dir=0, x=0, y=0;
        vector<vector<int>> ds={{0,1}, {1,0}, {0,-1}, {-1,0}};//四个方向移动的单位向量。
        for(int i=0;i<commands.size();i++) {
            if(commands[i]==-2) dir--;
            else if(commands[i]==-1) dir++;
            else {
                for(int j=0;j<commands[i];j++) {
                    string pos=to_string(x+ds[dir][0])+"#"+to_string(y+ds[dir][1]);
                    if(obs.find(pos)!=obs.end()) break;//用字符串将两个坐标存成一个“单元”，便于比较！
                    x+=ds[dir][0], y+=ds[dir][1];
                }
                res=max(res, x*x+y*y);
            }
            //if(dir==-1) dir=3;
            //if(dir==4) dir=0;//有更简单的写法吗？负数%4可以吗？
            dir=(dir+4)%4;//任意4的正整数倍，这样显然执行效率更高。
        }
        return res;
    }
};