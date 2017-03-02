class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> lookup;

    string abbreviation(const string& word) {
        return word.front() + to_string(word.length()) + word.back();
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& word : dictionary) {
            const string abbr = abbreviation(word);
            lookup[abbr].insert(word);
        }
    } 

    bool isUnique(string word) {
        const string abbr = abbreviation(word);
        return lookup[abbr].empty() || (lookup[abbr].count(word) == lookup[abbr].size());
    }
};

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");