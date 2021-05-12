#include "base.hpp"
#include "consts.hpp"

void solve() {
  /* wt.ten
    H W H"S H"T
  */
  int H,W;cin>>H>>W;VS S(H);times(H,i0){cin>>S[i0];}VS T(H);times(H,i0){cin>>T[i0];}

  upto(-30, 30, a) upto(-30, 30, b) times(4, d) {
    bool ok = true;
    times(H, i) times(W, j) if(T[i][j] == '#') {
      int ii, jj;
      if(d % 2 == 0) {
        ii = i + a; jj = j + b;
      } else if(d % 2 == 1) {
        ii = j + b; jj = -(i + a);
      }
      if(d / 2 == 1) {
        ii = -ii; jj = -jj;
      }
      if(0 <= ii < H && 0 <= jj < W && S[ii][jj] == '.') {
        ;
      } else {
        ok = false;
        break;
      }
    }
    if(ok) {
      cout << dict::Yes ln;
      return;
    }
  }

  cout << dict::No ln;
}
