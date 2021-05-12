#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N M K Q N(P T)
  */
  int N,M,K,Q;cin>>N>>M>>K>>Q;VI P(N),T(N);times(N,i0){cin>>P[i0]>>T[i0];}

  VI C, D;
  times(N, i) {
    (T[i] ? D : C).PB(P[i]);
  }
  sort(iter(P)); //reverse(iter(P));
  sort(iter(C)); //reverse(iter(C));
  sort(iter(D)); //reverse(iter(D));

  int sc = size(C), sd=size(D);

  VI SP(N + 1), SC(sc+1), SD(sd+1);
  times(N, i) SP[i+1] = SP[i] + P[i];
  times(sc, i) SC[i+1] = SC[i] + C[i];
  times(sd, i) SD[i+1] = SD[i] + D[i];

  dd P; SP; C;SC; D; SD;

  int ans = LLONG_MAX;
  upto(0, (M + K - 1) / K, b) {
    int temp = b * Q;
    int cc = max(0LL, M - b * K);
    if(sc < cc) continue;
    if(cc == 0) {
      temp += SP[M];
      dd b; cc; temp;
    } else {
      int th = C[cc - 1];
      int dd = distance(begin(D), leftmost_gt(iter(D), th /*, greater<int>()*/));
      if(cc + dd > M) {
        temp += SC[cc] + SD[M - cc];
        dd b; cc; dd; SC[cc]; SD[M-cc]; temp;
      } else {
        temp += SP[M];
        dd b; cc; dd; SP[M]; temp;
      }
    }
    amin(ans, temp);
  }

  cout << ans ln;
}
