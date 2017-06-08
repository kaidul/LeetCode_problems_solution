class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kindSet;
        for(int candy: candies) {
            kindSet.insert(candy);
        }
        return (kindSet.size() >= candies.size() / 2) ? candies.size() / 2 : kindSet.size();
    }
};