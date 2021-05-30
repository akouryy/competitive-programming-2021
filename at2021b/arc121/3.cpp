#include "base.hpp"
//#include "consts.hpp"

int N, ansSize; VI P, ans;

void query(int i) {
  // dd i;
  assert((ansSize % 2 == i % 2));
  /*if(ansSize % 2 != i % 2) {
    bool found = false;
    times(N-1, j) if(ansSize % 2 == j % 2 && P[j] > P[j+1]) {
      found = true;
      query(j, fallback_begin);
    }
    if(!found) {
      assert(fallback_begin >= 0);
      query(fallback_begin + (fallback_begin + ansSize) % 2, -1);
    }

    // int cand = N - 2 - (N + ansSize) % 2;
    // if(i < N - 3) {
    //   query(cand);
    // } else if(i == N-1 && cand == N-3) {
    //   query(cand);
    // } else {
    //   query(ansSize % 2);
    // }
  }*/
  ans.PB(i);
  ++ansSize;
  swap(P[i], P[i+1]);
  dd P; ans; ansSize;
}

void solve() {
  /* wt.ten
    T
  */
  int T;cin>>T;

  times(T, t) {
    /* wt.ten
      N NP
    */
    cin>>N;P.resize(N);times(N,i0){cin>>P[i0];}
    dd P;

    ans.clear();
    ansSize = 0;
    VI goal(N); times(N, i) goal[i] = i+1;

    while(goal != P) {
      bool found = false;
      times(N-1, j) if(ansSize % 2 == j % 2 && P[j] > P[j+1]) {
        found = true;
        query(j);
        break;
      }
      if(!found) {
        int m = 0, mj = 0;
        times(N-1, j) if(ansSize % 2 == j % 2 && amax(m, P[j])) {
          mj = j;
        }
        query(mj);
      }
    }

    // times(N, x) {
    //   int zp; times(N, i) if(P[i] == x+1) zp = i;
    //   downto(zp-1, x, i) query(i, i+2 <= N-2 ? i+2 : 0);

    //   if(1 <= x && x <= N-2) while(P[0] != 1 || P[1] != 2) query(ansSize % 2, -1);
    //   if(1 <= x && x <= N-2) while(P[x-1] != x || P[x] != x+1) query(x-1 + (x-1 + ansSize) % 2, -1);
    // }

    // while(P[0] != 1 || P[1] != 2 || N>=3 && P[2] != 3) query(ansSize % 2, -1);


    // while(P[N-1] != N || P[N-2] != N-1 || N>=3 && P[N-3] != N-2) query(N - 2 - (N + ansSize) % 2);

    // int first; times(N, i) if(P[i] == 1) first = i;
    // downto(first-1, 1, i) query(i);
    // if(first >= 1) {
    //   if(size(ans) % 2 == 1) {
    //     query(N-2);
    //   }
    //   query(0);
    // }

    // uptil(1, N-1, i) {
    //   downto(N-1, i+1, j) {
    //     if(P[j-1] > P[j]) query(j-1);
    //   }
    // }

    cout << size(ans) ln;
    times(size(ans), i) {
      cout << (i ? " " : "") << ans[i]+1;
    }
    cout ln;
  }


}
