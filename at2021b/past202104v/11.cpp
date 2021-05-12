#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N N(P U)
  */
  int N;cin>>N;VI P(N),U(N);times(N,i0){cin>>P[i0]>>U[i0];}

  VI dp(100, LLONG_MIN / 2), dq(100);
  dp[0] = 0;

  times(N, i) {
    dq = dp;
    times(100, qm) {
      amax(dp[(qm + P[i]) % 100], dq[qm] + 5 * U[i] - 4 * P[i]);
    }
    // dd dp;
  }
  dd dp;

  int ans = -1;
  times(100, qm) amax(ans, (dp[qm] - qm) / 5);
  cout << ans ln;
}
