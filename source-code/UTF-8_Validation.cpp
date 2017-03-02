class Solution {
    const int MSB = 7;
public:
    bool validUtf8(vector<int>& data) {
        int i = 0, n = (int)data.size();
        while(i < n) {
            int nbyte = 0;
            for(int k = 0; k < 4 and (data[i] & (1 << (MSB - k))); k++) {
                nbyte++;
            }
            if(nbyte == 1) {
                return false;
            }
            if(nbyte == 0) nbyte++;
            if(nbyte > 1 and (bool)(data[i] & (1 << (MSB - nbyte))) ) {
                return false;
            }
            if(i + nbyte - 1 >= n) {
                return false;
            }
            for(int k = 1; k < nbyte; k++) {
                bool on = data[i + k] & (1 << MSB);
                bool off = data[i + k] & (1 << (MSB - 1));
                if(!on or off) {
                    return false;
                }
            }
            i += nbyte; 
        }
        return true;
    }
};