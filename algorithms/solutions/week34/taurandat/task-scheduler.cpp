class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> counts;

    int max_count = 0, tasks_size = tasks.size();
    for(int i = 0; i < tasks_size; i++) {
      counts[tasks[i]]++;
      max_count = max(max_count, counts[tasks[i]]);
    }

    int ans = (max_count - 1) * (n + 1);
    for(auto& element: counts) {
      if(element.second == max_count) {
        ans++;
      }
    }

    return max(tasks_size, ans);
  }
};
