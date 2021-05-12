#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N L NA
  */
  int N,L;cin>>N>>L;VI A(N);times(N,i0){cin>>A[i0];}

  VI sa(N+1); times(N, i) sa[i+1] = sa[i] + A[i];

  int ok=0, ng=L+1;
  while(abs(ok-ng)>1){
    int m = (ok+ng) / 2;

    VI sok(N+2);
    times(N+1, i) {
      int left = distance(begin(sa), leftmost_ge(iter(sa), sa[i] - L));
      int right = distance(begin(sa), leftmost_gt(iter(sa), sa[i] - m));
      bool fok = m <= sa[i] && sa[i] <= L || sok[left] != sok[right];
      sok[i+1] = sok[i] + fok;
      if(i == N) {
        if(fok) ok = m;
        else ng = m;
      }
    }
    dd m; sa; sok;
  }

  cout << ok ln;
}
