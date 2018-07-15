#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
  map<string, int> counts;
  for(int i = 0; i < strings.size(); i++) {
    counts[strings[i]]++;
  }

  vector<int> results;
  for(int i = 0; i < queries.size(); i++) {
    results.push_back(counts[queries[i]]);
  }

  return results;
}
