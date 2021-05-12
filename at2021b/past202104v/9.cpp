#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    H W HWA
  */
  int H,W;cin>>H>>W;WI A(H,VI(W));times(H,i0){times(W,i1){cin>>A[i0][i1];}}

  VWI dp(H, WI(W, VI(H + W)));

  times(H, i) times(W, j) times(H + W, k) {
    dp[i][j][k] = max({
      i > 0 ? dp[i-1][j][k] : 0,
      j > 0 ? dp[i][j-1][k] : 0,
      k > 0 ? A[i][j] : 0,
      i > 0 && k > 0 ? dp[i-1][j][k-1] + A[i][j] : 0,
      j > 0 && k > 0 ? dp[i][j-1][k-1] + A[i][j] : 0,
    });
  }

  upto(1, H+W-1, k) cout << dp[H-1][W-1][k] ln;
}
