#include "base.hpp"
//#include "consts.hpp"

/* include禁止(コピペする) */
/*! http://codeforces.com/blog/entry/1256 http://codeforces.com/blog/entry/18051 */

constexpr int N = 262144; /*- たぶん2^xじゃなくても大丈夫 */
int same[N*2]; /*- 1, 2 3, 4 5 6 7, 8 9 10 11 12 13 14 15 */
int val[N*2]; /*- 1, 2 3, 4 5 6 7, 8 9 10 11 12 13 14 15 */

struct SegTree {
  map<int, int> count;
  int nPair;
  SegTree(const VI& A) {
    nPair = 0;
    times(N, i) {
      if(i < size(A)) {
        val[i + N] = A[i];
        nPair += count[A[i]]++;
      } else {
        val[i + N] = -1;
      }
      same[i] = false;
      same[i + N] = true;
    }
  }

  /** [l, r) 0-based **/
  void update(int a, int b, int v) {
    update(a, b, v, 1, 0, N);
  }

  void update(int a, int b, int v, int k, int l, int r) {
    if(r <= a || b <= l) return;
    dd a; b; v; k; l; r; a <= l && r <= b; same[k]; val[k];
    if(a <= l && r <= b) {
      if(same[k]) {
        int xx = r - l;
        dd count[val[k]]; count[v]; nPair; xx;
        nPair -= count[val[k]] * (count[val[k]] - 1) / 2;
        count[val[k]] -= xx;
        nPair += count[val[k]] * (count[val[k]] - 1) / 2;
        nPair -= count[v] * (count[v] - 1) / 2;
        count[v] += xx;
        nPair += count[v] * (count[v] - 1) / 2;
        dd count[val[k]]; count[v]; nPair;
      } else {
        update(a, b, v, k * 2, l, (l + r) / 2);
        update(a, b, v, k * 2 + 1, (l + r) / 2, r);
      }
      same[k] = true;
      val[k] = v;
    } else {
      if(same[k]) {
        same[k * 2] = same[k * 2 + 1] = true;
        val[k * 2] = val[k * 2 + 1] = val[k];
      }
      update(a, b, v, k * 2, l, (l + r) / 2);
      update(a, b, v, k * 2 + 1, (l + r) / 2, r);
      if(same[k * 2] && same[k * 2 + 1] && val[k * 2] == val[k * 2 + 1]) {
        same[k] = true;
        val[k] = val[k * 2];
      } else {
        same[k] = false;
      }
    }
  }
};

void solve() {
/* wt.ten
    N NA Q Q(L- R X)
  */
  int N,Q;cin>>N;VI A(N);times(N,i0){cin>>A[i0];}cin>>Q;VI L(Q),R(Q),X(Q);times(Q,i0){cin>>L[i0]>>R[i0]>>X[i0];
  --L[i0];}

  SegTree st(A);

  times(Q, i) {
    dd i;
    st.update(L[i], R[i], X[i]);
    cout << st.nPair ln;
  }
}
