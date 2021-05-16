#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N NA
  */
  int N;cin>>N;VI A(N);times(N,i0){cin>>A[i0];}

  HII pyon;
  ++pyon[0];
  int ans = 0, sum = 0;

  times(N, i) {
    sum += A[i] * (i % 2 ? 1 : -1);
    ans += pyon[sum]++;
  }

  cout << ans ln;
}
