#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N M M(A- B- C-)
  */
  int N,M;cin>>N>>M;VI A(M),B(M),C(M);times(M,i0){cin>>A[i0]>>B[i0]>>C[i0];--A[i0];--B[i0];--C[i0];}

  int ans = 0;
  times(1<<N, b) {
    bool out = false;
    times(M, i) {
      if(((b >> A[i]) & 1) && ((b >> B[i]) & 1) && ((b >> C[i]) & 1)) {
        out = true; break;
      }
    }
    if(out) continue;

    VI danger;
    times(M, i) {
      if(((b >> A[i]) & 1) && ((b >> B[i]) & 1)) {
        danger.PB(C[i]);
      }
      if(((b >> A[i]) & 1) && ((b >> C[i]) & 1)) {
        danger.PB(B[i]);
      }
      if(((b >> B[i]) & 1) && ((b >> C[i]) & 1)) {
        danger.PB(A[i]);
      }
    }
    std::sort(iter(danger));
    danger.erase(unique(iter(danger)), end(danger));
    dd b; danger;
    amax(ans, size(danger));
  }

  cout << ans ln;
}
