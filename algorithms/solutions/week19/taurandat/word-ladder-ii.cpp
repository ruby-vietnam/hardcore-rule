#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {
        vector<vector<string>> answers;
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return answers;
        }

        // 1. Construct a graph
        map<string, vector<pair<string, int>>> costsAdjacent;
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }
        for(auto &u: wordList) {
            for(auto &v: wordList) {
                if(u != v && isAdjacent(u, v)) {
                    costsAdjacent[u].push_back(make_pair(v, 1));
                }
            }
        }

        // 2. Find the shortest path from beginWord to endWord
        map<string, int> dist;
        map<string, string> p;
        for(auto& w: wordList) {
            dist[w] = INT_MAX;
        }   dist[beginWord] = 0;

        priority_queue <pair<int, string>> q;
        q.push(make_pair(0, beginWord));
        while (!q.empty()) {
            string v = q.top().second;
            int cur_d = -q.top().first;

            q.pop();
            if (cur_d > dist[v]) {
                continue;
            }

            for (auto& edge: costsAdjacent[v]) {
                string to = edge.first;
                int len = edge.second;
                if (dist[v] + len < dist[to]) {
                    dist[to] = dist[v] + len;
                    p[to] = v;
                    q.push(make_pair(-dist[to], to));
                }
            }
        }

        // 3. Generate all paths with given length from beginWord to endWord
        int targetLength = dist[endWord];

        /* DFS-based search */
        answers = dfsFind(costsAdjacent, wordList, beginWord, endWord, targetLength);

        /* BFS-based search */
        // answers = bfsFind(costsAdjacent, beginWord, endWord, targetLength);

        return answers;
    }

private:
    bool isAdjacent(string a, string b){
        if (a.size() != b.size()) {
            return false;
        }

        int count = 0;
        for(int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                count = count + 1;
            }
            if (count > 1) {
                return false;
            }
        }

        return (count == 1);
    }

    void dfsUtils(map<string, vector<pair<string, int>>>& costs,
                  string currentSource,
                  string target,
                  set<string> visited,
                  int maxLength,
                  int currentLength,
                  vector<vector<string>>& paths,
                  vector<string> currentPath) {
        visited.insert(currentSource);
        currentPath.push_back(currentSource);

        if (currentSource == target && currentLength == maxLength) {
            paths.push_back(currentPath);
        } else if (currentLength < maxLength) {
            for(auto& edge: costs[currentSource]) {
                string newSource = edge.first;
                int weight = edge.second;
                if (visited.find(newSource) == visited.end() ) {
                    dfsUtils(costs, newSource, target, visited, maxLength, currentLength+weight, paths, currentPath);
                }
            }
        }

        currentPath.clear();
        currentLength = 0;
        visited.erase(currentSource);
    }

    vector<vector<string>> dfsFind(map<string, vector<pair<string, int>>>& costs,
                                    vector<string> wordList,
                                    string source,
                                    string target,
                                    int maxLength) {
        vector<string> currentPath;
        set<string> visited;

        vector<vector<string>> paths;
        dfsUtils(costs, source, target, visited, maxLength, 0, paths, currentPath);

        return paths;
    }

    vector<vector<string>> bfsFind(map<string, vector<pair<string, int>>>& costs,
                                   string source,
                                   string target,
                                   int targetLength) {
        vector<vector<string>> answers;

        queue<vector<string>> q;
        vector<string> path;
        path.push_back(source);

        q.push(path);
        while (!q.empty()) {
            path = q.front();

            q.pop();
            string lastNode = path[path.size() - 1];

            if (lastNode == target && path.size() == targetLength + 1) {
                answers.push_back(path);
            }

            for (auto& e: costs[lastNode]) {
                string newNode = e.first;
                if (find(path.begin(), path.end(), newNode) == path.end()) {
                    vector<string> newpath(path);
                    newpath.push_back(newNode);
                    q.push(newpath);
                }
            }
        }

        return answers;
    }
};
