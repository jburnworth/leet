#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (auto str: strs) {
            auto sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            //cout << "String: " << str << " and sorted: " << sortedStr << endl;
            anagramMap[sortedStr].push_back(str);
        }

        //cout << "Print this god forsaken map" << endl;

        vector<vector<string>> groups;
        for (auto mappedPair: anagramMap) {
            vector<string> anagrams;
            for (auto str: mappedPair.second) {
                //cout << str << " ";
                anagrams.push_back(str);
            }
            //cout << endl;
            groups.push_back(anagrams);
        }
        return groups;
    }
};

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution* sol = new Solution();
    auto gA = sol->groupAnagrams(strs);

    for (auto group: gA) {
        for (auto str: group) {
            cout << str << " ";
        }
        cout << endl;
    }
}