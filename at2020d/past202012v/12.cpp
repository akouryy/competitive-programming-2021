#include "base.hpp"
//#include "consts.hpp"
#include "util_flatten.hpp"

void solve() {
  /* wt.ten
    N "S "T
  */
  int N;string S,T;cin>>N>>S>>T;

  assert(N == size(S));

  WB okp(N+1, VB(N+1)), okq(N+1, VB(N+1)), okr(N+1, VB(N+1)),
     okpq(N+1, VB(N+1)), okpqr(N+1, VB(N+1));

  upto(0, N, i) okpqr[i][i] = true;

  upto(1, N, diff) upto(0, N-diff, i) {
    int j = i + diff;
    upto(i, j, k) {
      okp[i][j] = okp[i][j] || okpqr[i][k] && S[k] == T[0] && okpqr[k+1][j];
      okq[i][j] = okq[i][j] || okpqr[i][k] && S[k] == T[1] && okpqr[k+1][j];
      okr[i][j] = okr[i][j] || okpqr[i][k] && S[k] == T[2] && okpqr[k+1][j];
    }
    upto(i, j, k) {
      if(i == 3 && j == 5) {
        // dd k; okp[i][k]; okq[k][j];
      }
      okpq[i][j] = okpq[i][j] || okp[i][k] && okq[k][j];
    }
    upto(i, j, k) {
      okpqr[i][j] = okpqr[i][j] || okpq[i][k] && okr[k][j];
      if(okpqr[i][j]) break;
    }
  }
  dd okp; okq; okr; okpq; okpqr;

  VI dp(N+1);
  upto(0, N, i) {
    upto(i, N, j) {
      amax(dp[j], dp[i] + okpqr[i][j] * (j - i) / 3);
    }
  }
  dd dp;
  cout << dp[N] ln;

  /*int ans = 0;

  bool pq = T[0] == T[1], pr = T[0] == T[2];

  if(pq && !pr) {
    reverse(iter(S));
    reverse(iter(T));
    pq = T[0] == T[1], pr = T[0] == T[2];
  }

  dd pq; pr;

  if(pq && pr) {
    for(char c : S) {
      if(c == T[0]) {
        ++ans;
      } else {
        ans = ans / 3 * 3;
      }
    }
    ans /= 3;
  } else if(!pq && !pr) {
    VI stack;
    for(char c : S) {
      if(c == T[0]) {
        stack.PB(1);
      } else {
        if(c == T[1] && !stack.empty() && stack.back() == 1) {
          stack.back() = 2;
        } else if(c == T[2] && !stack.empty() && stack.back() == 2) {
          ++ans;
          stack.pop_back();
        } else {
          stack.clear();
        }
      }
      dd stack;
    }
  } else {
    assert(!pq && pr);

    VWI Y(N / 2 + 1);
    Y[0] = {{ 0 }};
    times(N / 2, i) {
      Y[i].resize(i + 1);
    }
  }

  cout << ans ln;
  */
}
