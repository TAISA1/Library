#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
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
constexpr ll INF = (1LL << 60) - 1LL;
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
#include "../DataStructure/SegmentTree.cpp"
#include "../Math/Modint.cpp"
#undef call_from_test
struct T {
    mint a, b;
    inline static T id() {
        return T{1, 0};
    }
    inline static T f(const T &x, const T &y) {
        return T{x.a * y.a, y.a * x.b + y.b};
    }
    inline static T g(const T &a, const T &b) {
        return b;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    Segtree<T> seg(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        seg.upd(i, T{a, b});
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            seg.upd(p, T{c, d});
        } else {
            int l, r;
            cin >> l >> r;
            T t = seg.get(l, r);
            ll x;
            cin >> x;
            cout << (t.a * x + t.b) << '\n';
        }
    }
}