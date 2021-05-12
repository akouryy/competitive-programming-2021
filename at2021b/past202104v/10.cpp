#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N C N(X Y)
  */
  int N,C;cin>>N>>C;VI X(N),Y(N);times(N,i0){cin>>X[i0]>>Y[i0];}

  LD ans = 0, sum = 0;

  times(N, i) sum += X[i];

  LD p = sum / N;

  times(N, i) ans += (p - X[i]) * (p - X[i]) + (C - Y[i]) * (C - Y[i]);
  
  cout << ans ln;
}
