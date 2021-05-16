#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N NA
  */
  int N;cin>>N;VI A(N);times(N,i0){cin>>A[i0];}


  int ans = 0, mx = LLONG_MAX, second_max = LLONG_MAX;
  times(N-1, i) {
    int k = abs(A[i] - A[i+1]);
    ans += k;
    if(mx < k) {
      if(second_max < mx)
        second_max = mx;
      mx = k;
    } else if(second_max < k) {
      second_max = k;
    }
  }

  uptil(1, N, i) {
    amax(second_max, abs(A[0] - A[i]) - abs(A[i-1] - A[i]));
  }

  uptil(0, N-1, i) {
    amax(second_max, abs(A[N-1] - A[i]) - abs(A[i+1] - A[i]));
  }

  cout << ans - max(0ll, second_max*2) ln;
}
