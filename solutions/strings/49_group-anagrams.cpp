```cpp
/*
Problem: Group Anagrams
Problem Number: 49
Difficulty: Medium
Topic: strings
Date: 2026-03-15

Approach:
Use a hash map from a canonical signature to the list of strings sharing it. For each word, compute a 26-count frequency vector (for lowercase letters) and encode it into a compact string key; anagrams have identical frequency signatures. Append each word to its group's vector and return all groups from the map.

Time Complexity: O(N * L) where N is number of strings and L is average string length
Space Complexity: O(N * L) for storing output plus O(N) keys overhead
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <array>

class Solution {
    // Encode counts into a unique key with separators to avoid ambiguity.
    // Example: "#1#0#2#0...#0"
    static std::string makeKey(const std::string& s) {
        std::array<int, 26> cnt{};
        for (char c : s) ++cnt[c - 'a'];

        std::string key;
        key.reserve(26 * 3); // small optimization; actual may grow for larger counts
        for (int i = 0; i < 26; ++i) {
            key.push_back('#');
            int x = cnt[i];
            // append integer x
            if (x == 0) {
                key.push_back('0');
            } else {
                char buf[12];
                int n = 0;
                while (x > 0) {
                    buf[n++] = char('0' + (x % 10));
                    x /= 10;
                }
                while (n--) key.push_back(buf[n]);
            }
        }
        return key;
    }

public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        mp.reserve(strs.size());

        for (const auto& s : strs) {
            mp[makeKey(s)].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        res.reserve(mp.size());
        for (auto& kv : mp) res.push_back(std::move(kv.second));
        return res;
    }
};
```