#include "base.hpp"
#include "consts.hpp"

void solve() {
  /* wt.ten
    H W R- C- H"S
  */
  int H,W,R,C;cin>>H>>W>>R>>C;--R;--C;VS S(H);times(H,i0){cin>>S[i0];}

  dd S;

  WB visited(H, VB(W));
  visited[R][C] = true;
  VPII next = {{R,C}};

  while(!next.empty()) {
    int i, j; tie(i, j) = next.back(); next.pop_back();
    times(4, d) {
      int ii = i + di4[d], jj = j + dj4[d];
      if(0 <= ii < H && 0 <= jj < W) {
        dd i; j; d; ii; jj; visited[ii][jj]; S[ii][jj]; "v<^>"[d];
        if(!visited[ii][jj] && (S[ii][jj] == '.' || S[ii][jj] == "v<^>"[d])) {
          visited[ii][jj] = true;
          next.PB({ ii, jj });
        }
      }
    }
  }

  times(H, i) {
    times(W, j) {
      if(S[i][j] == '#') cout << '#';
      else if(visited[i][j]) cout << 'o';
      else cout << 'x';
    }
    cout ln;
  }
}
