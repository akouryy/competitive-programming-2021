///// AC


// #define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

int ask(int i, int j, int k) {
  cout << i + 1 sp << j + 1 sp << k + 1 << endl;
  int ret;
  cin >> ret;
  return ret - 1;
}

void answer(VI a) {
  // VI raw(size(a));
  // times(size(a), i) raw[a[i]] = i + 1;
  // cout << raw << endl;
  for(auto& i : a) ++i;
  cout << a << endl;
  int res;
  cin >> res; // 1 or -1
}

void solve() {
  // TNQ
  /* <foxy.memo-area> */
  int T;int N;int Q;cin>>T;cin>>N;cin>>Q;
  /* </foxy.memo-area> */

  times(T, case_id) {
    VI seq(3);
    {
      int first = ask(0, 1, 2);
      seq[1] = first;
      seq[0] = first == 0 ? 1 : 0;
      seq[2] = first == 2 ? 1 : 2;
      dd seq;
    }
    uptil(3, N, j) {
      int lo = -1, hi = size(seq);
      while(abs(hi - lo) > 1) {
        dd lo; hi;
        int p = (lo * 2 + hi) / 3, q = (lo + hi * 2) / 3;
        if(lo == -1 && hi == 1) { p = 0; q = 1; }
        int r = ask(j, seq[p], seq[q]);
        if(r == j)           { lo = p; hi = q; }
        else if(r == seq[p]) {         hi = p; }
        else                 { lo = q; }
      }
      dd lo; hi;
      seq.insert(begin(seq) + hi, j);
      dd seq;
    }

    answer(seq);
  }
}
