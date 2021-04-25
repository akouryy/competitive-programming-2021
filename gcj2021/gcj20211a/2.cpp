///// AC1-WA2 (7/35)


#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
  // MM(PN)
  /* <foxy.memo-area> */
  int M;cin>>M;VI P(M);VI N(M);times(M,Ri_0){cin>>P[Ri_0];cin>>N[Ri_0];}
  /* </foxy.memo-area> */

  VI primes;
  times(M, i) times(N[i], j) primes.PB(P[i]);

  if(size(primes) <= 10) {
    int ans = 0;

    times(1 << size(primes), h) {
      int sum = 0, prod = 1;
      times(size(primes), i) {
        if((h >> i) & 1) {
          sum += primes[i];
        } else {
          prod = min(4991ll, prod * primes[i]);
        }
      }
      if(sum == prod) amax(ans, sum);
    }

    cout << ans ln;
  }

  /*
  int ans = 0;

  times(M, i) {
    int a = 0, pw = 1;
    while(a <= N[i] && pw <= P[M-1] * N[M-1]) {
      ++a;
      pw *= P[i];
    }
    dd a;
    ans += a;
  }

  cout << ans ln;
  */
}
