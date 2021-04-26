///// AC


#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

void solve(int gcj_case_id) {
// NABN(U)
/* <foxy.memo-area> */
int N;int A;int B;cin>>N;cin>>A;cin>>B;VI U(N);times(N,Ri_0){cin>>U[Ri_0];}
/* </foxy.memo-area> */

  // int oldN = N;

  // dd 0;
  {
    int g = gcd(A, B);
    if(g != 1) {
      // A /= g;
      // B /= g;
      // VI realU((N - 1) / g + 1);
      times(N, i) if(U[i]) {
        if((N - 1 - i) % g != 0) {
          cout << dict::IMPOSSIBLE ln;
          return;
        }
        // realU[i / g] = U[i];
      }
      // U = realU;
      // N = (N - 1) / g;
      // dd U;
    }
  }
  // dd 1;

  upto(N, 100000000, ans) {
    VI fib = {1};
    bool ok = true;
    upto(1, ans, i) {
      fib.PB(
        (i >= A ? fib[i - A] : 0)
      + (i >= B ? fib[i - B] : 0)
      - (ans - i < N ? U[ans - i] : 0)
      );
      if(fib.back() < 0) {
        ok = false; break;
      }
    }
    // dd ans; fib;
    if(ok) {
      dd fib;
      cout << ans + 1 ln;
      return;
    }
  }
}
