///// WA; use 1.rb instead


#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
  // NN(X)
  /* <foxy.memo-area> */
  int N;cin>>N;VI X(N);times(N,Ri_0){cin>>X[Ri_0];}
  /* </foxy.memo-area> */

  int ans = 0, old = X[0];
  uptil(1, N, i) {
    int l = X[i], r = X[i] + 1; // [l, r)
    while(r <= old + 1) {
      l *= 10; r *= 10;
      ++ans;
    }
    old = max(l, old + 1);

    dd ans; old;
  }

  cout << ans ln;

  /*
  int ans = 0, d = 0, v = 0;
  uptil(1, N, i) {
    int x = X[i], di = 0;
    while(X[i - 1] > x) {
      x *= 10;
      ++di;
    }
    d += di;
    if(X[i - 1] < x) {
      v = d >= 3 ? N : power(10, d) - 1;
    } else {
      if(d >= 3) {
        v = N;
      } else {
        times(di, j) v *= 10;
      }
      --v;
      if(v < 0) {
        ++d;
        v = d >= 3 ? N : power(10, d) - 1;
      }
    }
    ans += d;
    dd i; X[i]; x; di; d; v;
  }

  cout << ans ln;
  */
}
