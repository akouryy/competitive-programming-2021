#include "base.hpp"
//#include "consts.hpp"

/*! http://codeforces.com/blog/entry/1256 http://codeforces.com/blog/entry/18051 */
struct SegTree {
  static constexpr int N = 131072*2; /*- たぶん2^xじゃなくても大丈夫 */
  int node[N*2]; /*- 1, 2 3, 4 5 6 7, 8 9 10 11 12 13 14 15 */
  SegTree() { times(N*2, i) node[i] = LLONG_MIN/2 /*-単位元*/; }
  /** 0-based **/
  int get(int i) const { return node[N + i]; }

  void update(int i, int v) {
    i += N;
    node[i] = v;
    while(i >>= 1) {
      node[i] = /*-更新関数*/ max(node[i<<1], node[i<<1 | 1]);
    }
  }

  /** [l, r) 0-based **/
  int query(int l, int r) const {
    l += N; r += N;
    int a = LLONG_MIN/2 /*-単位元*/;
    while(l < r) {
      if(l & 1) a = /*-集約関数*/ max(a, node[l]);
      if(r & 1) a = /*-集約関数*/ max(node[r&-2], a);
      l = (l+1) >> 1;
      r >>= 1;
    }
    return a;
  }
};

SegTree pos_left, neg_right;

void solve() {
  dd 0;
  /* wt.ten
    N Q [N-1](L R) Q(A B-)
  */
  int N,Q;cin>>N>>Q;VI L(N-1),R(N-1);times(N-1,i0){cin>>L[i0]>>R[i0];}VI A(Q),B(Q);times(Q,i0){
  cin>>A[i0]>>B[i0];--B[i0];}

  dd 0;

  times(N-1, i) {
    dd i;
    pos_left.update(i, L[i]);
    neg_right.update(i, -R[i]);
  }
  dd 1;

  times(Q, i) {
    int a = A[i];
    int lng = -1, lok = B[i];
    while(abs(lng - lok) > 1) {
      int m = (lng + lok + 1) / 2;
      dd m; pos_left.query(m, B[i]); a; -neg_right.query(m, B[i]);
      if(pos_left.query(m, B[i]) <= a <= -neg_right.query(m, B[i])) {
        lok = m;
      } else {
        lng = m;
      }
    }
    int rng = N, rok = B[i];
    while(abs(rng - rok) > 1) {
      int m = (rng + rok) / 2;
        dd m; pos_left.query(B[i], m); a; -neg_right.query(B[i], m);
      if(pos_left.query(B[i], m) <= a <= -neg_right.query(B[i], m)) {
        rok = m;
      } else {
        rng = m;
      }
    }
    dd A[i]; lok; B[i]; rok;
    cout << rok - lok + 1 ln;
  }

}
