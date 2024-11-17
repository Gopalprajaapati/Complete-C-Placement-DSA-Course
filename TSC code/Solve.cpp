#include<bits/stdc++.h>
using namespace std;

int k, r, m, res = 0;
vector<string> words;

void solve(int i, vector<int>& lan, int cnt, const vector<string>& qw) {
  if (i == (int)qw.size()) {
    res = max(res, cnt);
    return;
  }
  if (cnt + (int)(qw.size() - i) <= res) return;

  for (int j = 0; j < r; j++) {
    if (lan[j] == 0) {
      lan[j] = qw[i].size();
      solve(i + 1, lan, cnt + 1, qw);
      lan[j] = 0;
      break;
    } else if (lan[j] + 1 + (int)qw[i].size() <= m) {
      lan[j] += 1 + qw[i].size();
      solve(i + 1, lan, cnt + 1, qw);
      lan[j] -= 1 + qw[i].size();
    }
  }
  solve(i + 1, lan, cnt, qw);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  words.resize(k);
  for (auto& s : words) cin >> s;
  cin >> r >> m;

  vector<string> qw;
  for (auto& s : words) if ((int)s.size() <= m) qw.push_back(s);

  sort(qw.begin(), qw.end(), [&](const string& a, const string& b) -> bool {
    if (a.size() != b.size()) return a.size() > b.size();
    return a < b;
  });

  vector<int> lan(r, 0);
  solve(0, lan, 0, qw);
  cout << res;
}