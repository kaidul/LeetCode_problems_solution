class Logger {
    unordered_map<string, int> logMap;
public:
    /** Initialize your data structure here. */
    Logger() {
        logMap = unordered_map<string, int>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false. The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(logMap.find(message) != logMap.end()) {
            int lastPrintTime = logMap[message];
            if(timestamp < lastPrintTime + 10) {
                return false;
            }
        }
        logMap[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */