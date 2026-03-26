```cpp
/*
Problem: Meeting Rooms II
Problem Number: 253
Difficulty: Medium
Topic: arrays
Date: 2026-03-26

Approach:
Sort all start times and end times separately, then sweep through starts in ascending order.
Maintain a pointer to the earliest ending meeting; if the next meeting starts before that end, we need a new room, otherwise we reuse a room by advancing the end pointer.
The maximum number of simultaneous ongoing meetings during this sweep is the minimum number of rooms required.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        const int n = (int)intervals.size();
        if (n == 0) return 0;

        std::vector<int> starts;
        std::vector<int> ends;
        starts.reserve(n);
        ends.reserve(n);

        for (const auto& it : intervals) {
            starts.push_back(it[0]);
            ends.push_back(it[1]);
        }

        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());

        int rooms = 0, maxRooms = 0;
        int e = 0; // pointer for earliest ending meeting

        for (int s = 0; s < n; ++s) {
            // If the next meeting starts before the earliest one ends, need a new room.
            if (starts[s] < ends[e]) {
                ++rooms;
                if (rooms > maxRooms) maxRooms = rooms;
            } else {
                // Reuse a room: the meeting at ends[e] has finished.
                ++e;
                // rooms stays the same because one ended and one started.
            }
        }

        return maxRooms;
    }
};
```