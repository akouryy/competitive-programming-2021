///// AC


// #define GCJ_CASE
#include <fstream>
#include "base.hpp"
//#include "consts.hpp"

#if debug
  #define cerr DBGFILE
#endif

void solve(/*int gcj_case_id*/) {
// TNBP
/* <foxy.memo-area> */
int T;int N;int B;int P;cin>>T;cin>>N;cin>>B;cin>>P;
/* </foxy.memo-area> */

  #if debug
    ofstream DBGFILE("3.dbg");
  #endif

  times(T, gcj_case_id) {
    VI nums(N);

    times(N * B, i) {
      int D; cin >> D;
      int ans;
      #define SEARCH(cond) { ans = 0; while(ans < N && !(nums[ans] cond)) ++ans; }
      int nRest = 0;
      times(N, j) nRest += !nums[j];

      if(D == 9 || D >= nRest + 8) {
        SEARCH(< B);
      } else if(D == 8 || D >= nRest + 5 /*&& rand() % 2*/) {
        SEARCH(< B - 1);
        if(ans == N) {
          SEARCH(< B);
        }
      } else {
        SEARCH(< B - 2);
        if(ans == N) {
          SEARCH(< B - 1);
          if(ans == N) {
            SEARCH(< B);
          }
        }
      }
      ++nums[ans];
      // dd nums; ans;
      cout << ans + 1 << endl;
    }
  }

  int score; cin >> score;
}
