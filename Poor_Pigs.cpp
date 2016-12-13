class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return buckets == 1 ? 0 : (int) ceil( log(buckets) / log(minutesToTest/minutesToDie + 1) );
    }
};