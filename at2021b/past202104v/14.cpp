#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N H N(A B)
  */
  int N,H;cin>>N>>H;VI A(N),B(N);times(N,i0){cin>>A[i0]>>B[i0];}

  VPII AB(N); times(N, i) AB[i] = {A[i], B[i]};
  sort(iter(AB));
  reverse(iter(AB));

  if(1) { // 全探索
    int ans = 0, hmax;
    times(1 << N, k) {
      int temp = 0, h = H;

      VI aa, bb;
      times(N, i) if((k >> i) & 1) {
        aa.PB(A[i]);
        bb.PB(B[i]);
      };
      int nn = size(aa);
      VB used(nn);
      times(nn, x) {
        int aasum = 0;
        times(nn, i) if(!used[i]) aasum += aa[i];

        int bestScore = LLONG_MAX, bestIndex = -1;
        times(nn, i) if(!used[i]) {
          if(amin(bestScore, bb[i] * (aasum - aa[i]))) {
            bestIndex = i;
          }
        }
        used[bestIndex] = true;
        temp += aa[bestIndex] * h; h -= bb[bestIndex];
        // dd bestIndex;
      }
      // dd k; temp;
      if(amax(ans, temp)) hmax = k;
    }
    dd ans; hmax;
    return;
  }

  VI dp(H + 1, LLONG_MIN / 2), dq;
  dp[H] = 0;

  times(N, i) {
    dq = dp;
    int a, b; tie(a, b) = AB[i];
    upto(1, H, h) {
      amax(dp[max(0LL, h - b)], dq[h] + a * h);
    }
    dd dp;
  }

  cout << *max_element(iter(dp)) ln;
}
