#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N K NA
  */
  int N,K;cin>>N>>K;VI A(N);times(N,i0){cin>>A[i0];}

  VI S(N+1); times(N, i) S[i+1]=S[i]+A[i];
  
  times(N-K+1, j) {
    cout << S[j+K] - S[j] ln;
  }
}
