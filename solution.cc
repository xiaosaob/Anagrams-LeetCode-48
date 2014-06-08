// Given an array of strings, return all groups of strings that are anagrams.

// Note: All inputs will be in lower-case.

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<int> > myMap;
        for(int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            myMap[tmp].push_back(i);
        }
        vector<string> res;
        unordered_map<string, vector<int> >::iterator it = myMap.begin();
        while(it != myMap.end()) {
            if(it->second.size() > 1) {
                for(int i = 0; i < it->second.size(); ++i)
                    res.push_back(strs[(it->second)[i]]);
            }
            ++it;
        }
        return res;
    }
};
