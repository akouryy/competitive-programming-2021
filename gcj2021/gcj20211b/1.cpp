///// AC


#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

constexpr int DEG = (int)12e10l;

void solve(int gcj_case_id) {
// 3(A)
/* <foxy.memo-area> */
VI A(3);times(3,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  dd DEG;

  times(6, g) {
    int hi = g / 2, mi = g == 2 || g == 4 ? 0 : g == 0 || g == 5 ? 1 : 2, si = 3 - hi - mi;
    // dd hi; mi; si;

    int sec_tick = modulo(A[si] - A[hi], 360 * DEG);
    int min_tick = modulo(A[mi] - A[hi], 360 * DEG);

    times(11, base_hour) {
      int actual_min_tick = (min_tick + 360 * DEG * base_hour);
      if(actual_min_tick % 11 == 0) {
        int ns = actual_min_tick / 11;
        if(ns * 719 % (360 * DEG) == sec_tick) {
          int sec = ns / (int)1e9;
          int min = sec / 60;
          cout << min / 60 sp << min % 60 sp << sec % 60 sp << ns % (int)1e9 ln;
          return;
        }
      }
    }
  }
}
