//Range Update Range Get
template <class T, class E>
struct Segtree {
    inline T merge(const T &a, const T &b) { return min(a, b); }
    inline void act(E &a, const E &b) { a = b; }
    inline void comb(T &a, const E &b) { a = b; }
    int n;
    T et;
    E ee;
    vector<T> dat;
    vector<E> laz;
    Segtree(int n_, T et, E ee) : et(et), ee(ee) {
        n = 1;
        while (n < n_) {
            n <<= 1;
        }
        dat.resize(2 * n, et);
        laz.resize(2 * n, ee);
    }
    inline void eval(int k) {
        if (laz[k] == ee) {
            return;
        }
        comb(dat[k], laz[k]);
        if (k < n) {
            act(laz[k << 1], laz[k]);
            act(laz[k << 1 | 1], laz[k]);
        }
        laz[k] = ee;
    }
    void upd(const int &a, const int &b, const E &x, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            act(laz[k], x);
            eval(k);
            return;
        }
        upd(a, b, x, k << 1, l, (l + r) >> 1);
        upd(a, b, x, k << 1 | 1, (l + r) >> 1, r);
        dat[k] = merge(dat[k << 1], dat[k << 1 | 1]);
    }
    inline void upd(const int &a, const int &b, const E &x) {
        if (a >= b) {
            return;
        }
        upd(a, b, x, 1, 0, n);
    }
    T get(const int &a, const int &b, int k, int l, int r) {
        if (b <= l || r <= a) {
            return et;
        }
        eval(k);
        if (a <= l && r <= b) {
            return dat[k];
        }
        return merge(get(a, b, k << 1, l, (l + r) >> 1),
                     get(a, b, k << 1 | 1, (l + r) >> 1, r));
    }
    inline T get(const int &a, const int &b) {
        if (a >= b) {
            return et;
        }
        return get(a, b, 1, 0, n);
    }
    int find(const int &a, const int &b, const T &x, int k, int l, int r) {
        eval(k);
        if (b <= l || r <= a || dat[k] > x) {
            return -1;
        }
        if (k >= n) {
            return k - n;
        }
        int il = find(a, b, x, k << 1, l, (l + r) >> 1);
        if (il != -1) {
            return il;
        }
        return find(a, b, x, k << 1 | 1, (l + r) >> 1, r);
    }
    inline int find(const int &a, const int &b, const T &x) { //[a,b)における、値<=x なる最左のindexを求める
        if (a >= b) {
            return -1;
        }
        return find(a, b, x, 1, 0, n);
    }
};