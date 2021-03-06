#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  string PlusOne(string s, int index) {
    if (s[index] != '9')
      s[index] = s[index] - '0' + 1 + '0';
    else
      s[index] = '0';
    return s;
  }
  string MinusOne(string s, int index) {
    if (s[index] != '0')
      s[index] = s[index] - '0' - 1 + '0';
    else
      s[index] = '9';
    return s;
  }
  void AddToNextState(string tt, unordered_set<string> *cache,
                      unordered_set<string> *state) {
    if (cache->find(tt) == cache->end()) {
      cache->insert(tt);
      state->insert(tt);
    }
  }
  void SwitchNewState(string t, int i, unordered_set<string> *cache,
                      unordered_set<string> *state) {
    // 前进
    string f = PlusOne(t, i);
    AddToNextState(f, cache, state);
    // 后退
    string b = MinusOne(t, i);
    AddToNextState(b, cache, state);
  }

  void OnlyAddToNextState(string tt, unordered_set<string> *cache,
                          unordered_set<string> *state) {
    if (cache->find(tt) == cache->end()) {
      state->insert(tt);
    }
  }
  void OnlySwitchNewState(string t, int i, unordered_set<string> *cache,
                          unordered_set<string> *state) {
    // 前进
    string f = PlusOne(t, i);
    OnlyAddToNextState(f, cache, state);
    // 后退
    string b = MinusOne(t, i);
    OnlyAddToNextState(b, cache, state);
  }

  int openLock(vector<string> &deadends, string target) {
    // return bfs(deadends, target);
    return DoulbleBFS(deadends, target);
  }
  int bfs(vector<string> &deadends, string target) {
    unordered_set<string> state;
    unordered_set<string> cache(deadends.begin(), deadends.end());
    if (cache.count("0000")) return -1;

    int step = 0;
    state.insert("0000");
    while (!state.empty()) {
      unordered_set<string> c;
      swap(c, state);
      for (auto it = c.begin(); it != c.end(); ++it) {
        string t = *it;
        if (t == target) return step;
        for (int i = 0; i < t.size(); ++i) {
          SwitchNewState(t, i, &cache, &state);
        }
      }
      ++step;
    }
    return -1;
  }
  void PrintSet(unordered_set<string> s) {
    for (auto t : s) {
      cout << t << " ";
    }
    cout << endl;
  }
  int DoulbleBFS(vector<string> &deadends, string target) {
    unordered_set<string> state;
    unordered_set<string> ts;
    unordered_set<string> cache(deadends.begin(), deadends.end());
    if (cache.count("0000")) return -1;

    int step = 0;
    state.insert("0000");
    ts.insert(target);
    while (!state.empty() && !ts.empty()) {
      // if (ts.size() < state.size()) swap(ts, state);
      unordered_set<string> c;
      swap(c, state);
      for (auto it = c.begin(); it != c.end(); ++it) {
        string t = *it;
        if (ts.find(t) != ts.end()) return step;
        cache.insert(t);
        for (int i = 0; i < t.size(); ++i) {
          OnlySwitchNewState(t, i, &cache, &state);
        }
      }
      if (ts.size() < state.size()) swap(ts, state);
      ++step;

      //   cout << step << endl;
      //   PrintSet(ts);
      //   PrintSet(state);
    }
    return -1;
  }
};