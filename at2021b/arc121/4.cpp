#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N NA
  */
  int N;cin>>N;VI A(N);times(N,i0){cin>>A[i0];}

  sort(iter(A));
  bool a = 1, b = 1;
  times(N, i) {
    if(A[i] < 0) a = 0;
    if(A[i] > 0) b = 0;
  }
  if(a || b) {
    cout << A[N-1] - A[0] ln;
    return;
  }

  int l = 0, r = N-1;
  int X = 0, Y = 0;
  while(A[l] < 0 && A[r] > 0) {
    amax(X, A[r] - A[l]);
    amin(Y, A[r] - A[l]);
    ++l;
    --r;
  }
  upto(l, r, i) {
    amax(X, A[i]);
    amin(Y, A[i]);
  }

  cout << X - Y ln;
}
