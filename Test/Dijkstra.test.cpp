#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"
#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll MOD = 998244353LL;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
#define call_from_test
#include "../Graph/Dijkstra.cpp"
#undef call_from_test
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, s;
    cin >> n >> m >> s;
    Dijkstra<int> g(n);
    for (int i = 0; i < m; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        g.addedge(s, t, d);
    }
    V<int> d = g.dijkstra(s);
    for (int i = 0; i < n; i++) {
        if (d[i] == INF) {
            cout << "INF\n";
        } else {
            cout << d[i] << '\n';
        }
    }
}