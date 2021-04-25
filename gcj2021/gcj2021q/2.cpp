///// AC


#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

#define INF (1LL << 60)

void solve(int gcj_case_id) {
  // XY"T"
  /* <foxy.memo-area> */
  int X;int Y;string T;cin>>X;cin>>Y;cin>>T;
  /* </foxy.memo-area> */

  int C = 0, J = 1;

  VI dp(2);

  times(size(T), i) {
    VI dq = dp;
    dp[C] = T[i] == 'J' ? INF : (i == 0 ? 0 : min(dq[C], Y + dq[J]));
    dp[J] = T[i] == 'C' ? INF : (i == 0 ? 0 : min(dq[J], X + dq[C]));
  }

  cout << min(dp[C], dp[J]) ln;
}
