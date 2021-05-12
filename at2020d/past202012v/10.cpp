#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    "S X-
  */
  string S;int X;cin>>S>>X;--X;

  int N = size(S);

  VI step(N);
  times(N, i) {
    int before = i == 0 ? 0 : step[i - 1];
    step[i] = S[i] <= '9' ? before * (S[i] - '0' + 1) : before + 1;
    amin(step[i], X + 1);
  }
  dd step;

  downto(N - 1, 1, i) {
    dd i; X; S[i]; step[i - 1];
    if(S[i] <= '9') {
      X %= step[i - 1];
    } else {
      if(X == step[i - 1]) {
        cout << S[i] ln;
        return;
      }
    }
  }

  dd 0; X; S[0];
  assert(X == 0 && S[0] > '9');
  cout << S[0] ln;
}
