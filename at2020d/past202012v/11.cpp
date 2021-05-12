#include "base.hpp"
#include "consts.hpp"

void solve() {
  /* wt.ten
    [4]"S
  */
  VS S(4);times(4,i0){cin>>S[i0];}

  VD dp(1<<16, numeric_limits<double>::infinity());
  dp[0] = 0;

  int ans_index = 0;
  times(4, i) times(4, j) {
    if(S[i][j] == '#') ans_index += 1 << i*4+j;
  }

  uptil(1, 1<<16, b) if((b & ~ans_index) == 0) {
    times(4, ci) times(4, cj) {
      VPII ps;
      if((b >> ci*4+cj) & 1) ps.PB({ci, cj});
      times(4, d) {
        int ii = ci + di4[d], jj = cj + dj4[d];
        if(0 <= ii < 4 && 0 <= jj < 4 && (b >> ii*4+jj) & 1) {
          ps.PB({ii, jj});
        }
      }
      int n = size(ps);
      if(n) {
        LD sum = 0;
        for(auto& p : ps) {
          sum += dp[b & ~(1 << p.first*4+p.second)];
        }
        dd b; ci; cj; ps; sum; n; sum/n + 5.0/n;
        amin(dp[b], sum/n + 5.0/n);
      }
    }
  }

  dd dp;

  cout << dp[ans_index] ln;
}
