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
        int n = wordList.size() + 1;
        vector<vector<int>> costs(n);
        for(int i = 0; i < n; i++) {
            costs[i].resize(n);
        }
        for(int i = 0; i < wordList.size(); i++) {
            if (isAdjacent(beginWord, wordList[i])) {
                costs[0].push_back(i+1);
                costs[i+1].push_back(0);
            }
        }
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i + 1; j < wordList.size(); j++) {
                if(isAdjacent(wordList[i], wordList[j])) {
                    costs[i+1].push_back(j+1);
                    costs[j+1].push_back(i+1);
                }
            }
        }

        // 2. Find the shortest path from `beginWord` to `endWord`
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        vector<vector<int>> prev(n);
        set<int> visited;

        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int nodeFrom = q.front();
            q.pop();

            for (auto& node: costs[nodeFrom]) {
                int nodeTo = node;

                if (dist[nodeFrom] + 1 < dist[nodeTo] && visited.find(nodeTo) == visited.end()) {
                    dist[nodeTo] = dist[nodeFrom] + 1;
                    prev[nodeTo].push_back(nodeFrom);
                    visited.insert(nodeTo);
                    q.push(nodeTo);
                } else if (dist[nodeFrom] + 1 == dist[nodeTo]) {
                    prev[nodeTo].push_back(nodeFrom);
                }
            }
        }

        // 3. Generate all paths with given length from `beginWord` to `endWord`
        // using precomputed `prev`
        int targetIndex = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) {
                targetIndex = i + 1;
                break;
            }
        }
        int targetLength = dist[targetIndex];
        if (targetLength == INT_MAX) {
            return answers;
        }

        /* Dijkstra trace back: MLE */
        vector<int> path;
        trace(answers, wordList, beginWord, endWord, prev, path, targetIndex);

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

    void trace(vector<vector<string>>& answers,
               vector<string> wordList,
               string beginWord,
               string endWord,
               vector<vector<int>> prev,
               vector<int> path,
               int current) {
        if (current == 0) {
            vector<string> answer;
            answer.push_back(beginWord);
            for(int i = path.size() - 1; i >= 0; i--) {
                answer.push_back(wordList[path[i]]);
            }
            answers.push_back(answer);
            path.clear();
        } else {
            path.push_back(current-1);
            for (auto v: prev[current]) {
                trace(answers, wordList, beginWord, endWord, prev, path, v);
            }
        }
    }
};
