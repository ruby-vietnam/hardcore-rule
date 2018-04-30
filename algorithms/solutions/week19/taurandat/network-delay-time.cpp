/*
 * Link: https://leetcode.com/problems/network-delay-time/
 *
 * 51 / 51 test cases passed.
 * Status: Accepted
 * Runtime: 63 ms
 * Your runtime beats 95.74 % of cpp submissions.
 *
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> graph(N+1);
        for (auto& edge: times) {
            int source = edge[0];
            int target = edge[1];
            int weight = edge[2];

            graph[source].push_back(make_pair(target, weight));
        }

        vector<int> dist(N+1, INT_MAX);
        dist[K] = 0;

        priority_queue <pair<int, int>> q;
        q.push(make_pair(K, 0));
        while (!q.empty()) {
            int nodeFrom = q.top().first;
            int cWeight = q.top().second;

            q.pop();
            if (cWeight > dist[nodeFrom]) {
                continue;
            }

            for (auto& node: graph[nodeFrom]) {
                int nodeTo = node.first;
                int weight = node.second;

                if (dist[nodeFrom] + weight < dist[nodeTo]) {
                    dist[nodeTo] = dist[nodeFrom] + weight;
                    q.push(make_pair(nodeTo, -dist[nodeTo]));
                }
            }
        }

        int answer = 0;
        for(int i = 1; i <= N; i++) {
            if(dist[i] == INT_MAX) {
                return -1;
            } else {
                answer = max(answer, dist[i]);
            }
        }

        return answer;
    }
};
