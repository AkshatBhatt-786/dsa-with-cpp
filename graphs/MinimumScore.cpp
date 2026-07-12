// 2492. Minimum Score of a Path Between Two Cities
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

// The score of a path between two cities is defined as the minimum distance of a road in this path.

// Return the minimum possible score of a path between cities 1 and n.

// Note:

// A path is a sequence of roads between two cities.
// It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
// The test cases are generated such that there is at least one path between 1 and n.

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n+1);
        for (const auto& road : roads) {
            int a = road[0], b = road[1], distance = road[2];
            graph[a].emplace_back(b, distance);
            graph[b].emplace_back(a, distance);
        }
        
        vector<bool> visited(n + 1, false);
        int min_score = INT_MAX;
        vector<int> stack;
        stack.reserve(n);
        stack.push_back(1);
        visited[1] = true;

        while (!stack.empty()) {
            int city = stack.back();
            stack.pop_back();
            for (const auto& [next_city, distance] : graph[city]) {
                min_score = min(min_score, distance);
                if (!visited[next_city]) {
                    visited[next_city] = true;
                    stack.push_back(next_city);
                }
            }
        }

        return min_score;
    }
};