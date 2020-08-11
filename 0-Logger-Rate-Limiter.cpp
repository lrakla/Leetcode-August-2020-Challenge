class Logger {
    unordered_map<string,int> map0_10,map10_20;
    int t; //earliest time in 0-10
public:
    Logger():t(0){
        
    }
    bool shouldPrintMessage(int timestamp,string message){
        if(timestamp >= t+10){
            map10_20 = map0_10;
            map0_10.clear();
            t = timestamp;
        }
        if(map0_10.find(message) != map0_10.end()) return false;
        int ts = map10_20[message];
        if(ts && timestamp < ts+10) return false;
        map0_10[message] = timestamp;
        return true;
    }
}