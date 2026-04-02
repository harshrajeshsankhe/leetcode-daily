```cpp
/*
Problem: Top K Frequent Elements
Problem Number: 347
Difficulty: Medium
Topic: arrays
Date: 2026-04-02

Approach:
Count occurrences with a hash map, then apply Quickselect (Hoare-style partition) on the unique elements array using their frequencies as the key.
This finds the k most frequent elements in expected linear time without fully sorting; finally return any k elements from the top partition.

Time Complexity: Expected O(n) (worst-case O(n^2) due to quickselect, but mitigated with random pivot)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq.reserve(nums.size() * 2);
        freq.max_load_factor(0.7f);

        for (int x : nums) ++freq[x];

        vector<int> uniq;
        uniq.reserve(freq.size());
        for (auto &p : freq) uniq.push_back(p.first);

        // If k equals number of unique elements, return them all.
        if (k >= (int)uniq.size()) return uniq;

        // Quickselect to place top-k frequent elements in the first k positions (in any order).
        std::mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

        auto f = [&](int val) -> int { return freq[val]; };

        auto partition = [&](int l, int r, int pivotIdx) -> int {
            int pivotVal = uniq[pivotIdx];
            int pivotFreq = f(pivotVal);
            swap(uniq[pivotIdx], uniq[r]); // move pivot to end
            int store = l;
            // Partition by greater frequency first
            for (int i = l; i < r; ++i) {
                if (f(uniq[i]) > pivotFreq) {
                    swap(uniq[store++], uniq[i]);
                }
            }
            swap(uniq[store], uniq[r]); // move pivot to its final place
            return store;
        };

        int left = 0, right = (int)uniq.size() - 1;
        int target = k - 1; // we need indices [0..k-1] to be top-k

        while (left <= right) {
            uniform_int_distribution<int> dist(left, right);
            int pivotIdx = dist(rng);
            int pivotNewIdx = partition(left, right, pivotIdx);

            if (pivotNewIdx == target) break;
            if (pivotNewIdx < target) left = pivotNewIdx + 1;
            else right = pivotNewIdx - 1;
        }

        uniq.resize(k);
        return uniq;
    }
};
```