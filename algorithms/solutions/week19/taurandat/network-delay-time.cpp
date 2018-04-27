class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int edges = times.size();

        vector<int> dist(N+1);
        for(int i = 0; i <= N; i++) {
            dist[i] = INT_MAX;
        }   dist[K] = 0;

        for(int i = 0; i <= N - 1; i++) {
            for(auto &edge: times) {
                int source = edge[0];
                int target = edge[1];
                int weight = edge[2];

                if(dist[source] != INT_MAX && dist[source] + weight < dist[target]) {
                    dist[target] = dist[source] + weight;
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