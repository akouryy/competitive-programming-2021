///// AC


#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

bool calc(int N, int c, int i, VI& ans) {
  if(c < 0 || i == N - 1) return false;
  int lim = N - 1 - i;
  if(c <= lim) {
    ans.resize(N);
    times(N, j) ans[j] = j + 1;
  } else {
    if(!calc(N, c - lim, i + 1, ans)) return false;
    c = lim;
  }
  times((c + 1) / 2, j) swap(ans[i + j], ans[i + c - j]);
  dd N; c; i; ans;
  return true;
}

void solve(int gcj_case_id) {
  // NC
  /* <foxy.memo-area> */
  int N;int C;cin>>N;cin>>C;
  /* </foxy.memo-area> */

  VI ans;
  if(calc(N, C - N + 1, 0, ans)) {
    cout << ans ln;
  } else {
    cout << dict::IMPOSSIBLE ln;
  }
}
