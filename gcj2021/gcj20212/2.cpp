#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"
#include "prime.hpp"

void solve(int gcj_case_id) {
  /* wt.ten
    N
  */
  signed N;cin>>N;

  vec<signed> dp(N + 1, INT_MIN/2);
  dp[N] = 0;
  downto(N, 1, j) if(dp[j] >= 0) {
    for(signed k = 1; k * k <= j; ++k) if(j % k == 0) {
      if(k >= (j == N ? 3 : 2))     amax(dp[j / k - 1], dp[j] + 1);
      if(j / k >= (j == N ? 3 : 2)) amax(dp[k - 1], dp[j] + 1);
    }
  }
  cout << dp[0] ln;

  /*
  WI dp(N + 1);
  dd dp[0];
  upto(1, N, i) dp[i] = VI(N / i + 1, LLONG_MIN/2);
  dp[1][N] = 0;

  upto(1, N, i) {
    if(!(i&255)) cerr<<i ln;
    times(N / i + 1, j) {
      upto(2, j, k) if(j % k == 0) {
        amax(dp[i * k][j / k - 1], dp[i][j] + 1);
      }
    }
    // dd dp;
  }

  // dd dp;

  int ans = 0;
  upto(1, N, i) amax(ans, dp[i][0]);
  cout << ans ln;
  */

  /*
  int ans = 0, before = 1;
  while(N > before * 2) {
    ++ans;
    HII k = prime_factor(N / before);
    dd N / before; k;

    if(ans == 1) { // 初回
      if(k.count(2)) {
        // dd k.count(2)&&k[2]; k.count(3)&&k[3]; *begin(k);
        if(k.count(3)) {
          before = 3;
        } else if(k[2] >= 2) {
          before = 4;
        } else {
          auto it = begin(k);
          ++it;
          before = it->first;
        }
      } else {
        dd *begin(k);
        before = begin(k)->first;
      }
    } else {
      before *= begin(k)->first;
    }
    N -= before;

    dd ans; before; N;
  }
  cout << ans ln;
  */

}
