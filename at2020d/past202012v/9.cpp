#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N M K NH KC- M(A- B-)
  */
  int N,M,K;cin>>N>>M>>K;VI H(N);times(N,i0){cin>>H[i0];}VI C(K);times(K,i0){cin>>C[i0];--C[i0];}VI A(M),B(M);
  times(M,i0){cin>>A[i0]>>B[i0];--A[i0];--B[i0];}

  VTIII hab;
  times(M, i) {
    int ha = H[A[i]], hb = H[B[i]];
    hab.PB({ha < hb ? ha : hb, ha < hb ? A[i] : B[i], ha < hb ? B[i] : A[i]});
  };
  sort(iter(hab));

  VI ans(N, LLONG_MAX / 2);
  times(K, i) ans[C[i]] = 0;
  times(M, i) {
    int h, a, b; tie(h, a, b) = hab[i];
    dd a; b; ans[b]; ans[a] + 1;
    amin(ans[b], ans[a] + 1);
  }
  times(N, i) {
    cout << (ans[i] == LLONG_MAX / 2 ? -1 : ans[i]) ln;
  }
}
