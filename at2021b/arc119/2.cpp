#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N "S "T
  */
  int N;string S,T;cin>>N>>S>>T;

  VI si, ti;
  times(N, i) {
    if(S[i] == '0') si.PB(i);
    if(T[i] == '0') ti.PB(i);
  }

  if(size(si) != size(ti)) {
    cout << -1 ln;
    return;
  }

  int ans = 0;
  times(size(si), j) {
    ans += si[j] != ti[j];
  }

  cout << ans ln;
}
