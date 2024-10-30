#include <bits/stdc++.h> 
 
using namespace std; 
 
typedef long long ll; 
#define placementlelo vector<int> 
#define all(a) (a).begin(), (a).end() 
#define sz(a) ((int)((a).size())) 
 
const int INF = 1e9; 
 
map<pair<int, int>, int> dp; 
 
int f(int i, int j, int s, int r, string &x, string &y, string &y1) { 
    if (i > j) return 0; 
     
    if (dp.count({i, j})) return dp[{i, j}]; 
     
    int mini = INF; 
    for (int k = i; k <= j; k++) { 
        string substring = x.substr(i, k - i + 1); 
        if (y1.find(substring) != string::npos) { 
            mini = min(mini, r + f(k + 1, j, s, r, x, y, y1)); 
        } 
        if (y.find(substring) != string::npos) { 
            mini = min(mini, s + f(k + 1, j, s, r, x, y, y1)); 
        } 
    } 
 
    return dp[{i, j}] = mini; 
} 
 
int solve(int s, int r, string x, string y) { 
    string y1 = y; 
    reverse(all(y1)); 
    dp.clear(); // Clear the map before solving a new case 
    return f(0, sz(x) - 1, s, r, x, y, y1); 
} 
 
int main() { 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
 
    string x, y; 
    cin >> x >> y; 
    int s, r; 
    cin >> s >> r; 
    int ans = solve(s, r, x, y); 
    if (ans == INF) { 
        cout << "Impossible"; 
        return 0; 
    } 
    cout << ans; 
 
    return 0; 
}