///// AC


#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
  // NN(L)
  /* <foxy.memo-area> */
  int N;cin>>N;VI L(N);times(N,Ri_0){cin>>L[Ri_0];}
  /* </foxy.memo-area> */

  int ans = -1;

  times(N, i) {
    auto b = begin(L) + i;
    auto it = min_element(b, end(L)) + 1;
    reverse(b, it);
    ans += distance(b, it);
    dd L; ans;
  }

  cout << ans ln;
}
