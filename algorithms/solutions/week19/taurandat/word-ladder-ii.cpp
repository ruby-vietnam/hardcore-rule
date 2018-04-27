#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    set<vector<string>> marked;

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {
        vector<vector<string>> answers;
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return answers;
        }

        // 1. Construct a graph
        map<string, vector<pair<string, int>>> costsAdjacent;
        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = 0; j < wordList.size(); j++) {
                if(isAdjacent(wordList[i], wordList[j])) {
                    if(wordList[i] != beginWord) {
                        costsAdjacent[wordList[j]].push_back(make_pair(wordList[i], 1));
                    }
                    if(wordList[j] != beginWord) {
                        costsAdjacent[wordList[i]].push_back(make_pair(wordList[j], 1));
                    }
                }
            }
        }

        // 2. Find the shortest path from beginWord to endWord
        map<string, int> dist;
        for(auto& w: wordList) {
            dist[w] = INT_MAX;
        }   dist[beginWord] = 0;

        for(int i = 1; i <= wordList.size(); i++){
            for(auto& v: wordList) {
                for(auto& e: costsAdjacent[v]) {
                    string source = v;
                    string target = e.first;
                    int weight = e.second;

                    if(dist[source] != INT_MAX && dist[source] + weight < dist[target]) {
                        dist[target] = dist[source] + weight;
                    }
                }
            }
        }

        // 3. Generate all paths with given length from beginWord to endWord
        int targetLength = dist[endWord];
        generate(costsAdjacent, wordList, beginWord, endWord, targetLength);

        for(auto& v: marked) {
            answers.push_back(v);
        }

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

    void generateUtils(map<string, vector<pair<string, int>>>& costs,
                        map<string, bool> visited,
                        string &currentSource,
                        string target,
                        int maxLength,
                        int currentLength,
                        vector<string> currentPath) {
        visited[currentSource] = true;
        currentPath.push_back(currentSource);

        if (currentSource == target && currentLength == maxLength) {
            if(marked.find(currentPath) == marked.end()){
                marked.insert(currentPath);
            }
        } else if (currentLength < maxLength) {
            for(auto& edge: costs[currentSource]) {
                string newSource = edge.first;
                int weight = edge.second;
                if (!visited[newSource]) {
                    generateUtils(costs, visited, newSource, target, maxLength, currentLength+weight, currentPath);
                }
            }
        }

        currentPath.clear();
        currentLength = 0;
        visited[currentSource] = false;
    }

    void generate(map<string, vector<pair<string, int>>>& costs,
                                    vector<string> wordList,
                                    string source,
                                    string target,
                                    int maxLength) {
        vector<pair<vector<string>, int>> paths;
        map<string, bool> visited;

        for(auto& v: wordList) {
            visited[v] = false;
        }

        vector<string> currentPath;

        generateUtils(costs, visited, source, target, maxLength, 0, currentPath);
    }
};
