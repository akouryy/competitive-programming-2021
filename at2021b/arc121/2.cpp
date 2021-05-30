#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    // N N(A 'C)
  */
  int N;cin>>N;VI A(N*2);VC C(N*2);times(N*2,i0){cin>>A[i0]>>C[i0];}

  dd N; A; C;

  VPII R, G, B;
  times(N*2, i) {
    if(C[i] == 'R') R.PB({A[i], i});
    if(C[i] == 'G') G.PB({A[i], i});
    if(C[i] == 'B') B.PB({A[i], i});
  }

  dd R; G; B;

  if(size(R) % 2 == 0 && size(G) % 2 == 0 && size(B) % 2 == 0) {
    cout << 0 ln;
    return;
  }
  if(size(R) % 2 == 0) {
    swap(R, B);
  } else if(size(G) % 2 == 0) {
    swap(G, B);
  }

  sort(iter(R));
  sort(iter(G));
  sort(iter(B));

  int ans1 = LLONG_MAX / 2;

  times(size(R), i) {
    auto it1 = rightmost_le(iter(G), R[i]);
    if(it1 != end(G)) amin(ans1, R[i].first - it1->first);

    auto it2 = leftmost_ge(iter(G), R[i]);
    if(it2 != end(G)) amin(ans1, it2->first - R[i].first);
  }

  int ans2 = LLONG_MAX / 2;
  {
    VPII rbs;
    times(size(R), i) {
      auto it1 = rightmost_le(iter(B), R[i]);
      // dd R[i]; distance(begin(B), it1);
      if(it1 != end(B)) rbs.PB({R[i].first - it1->first, it1->second});

      auto it2 = leftmost_ge(iter(B), R[i]);
      // dd R[i]; distance(begin(B), it2);
      if(it2 != end(B)) rbs.PB({it2->first - R[i].first, it2->second});
    }

    VPII gbs;
    times(size(G), i) {
      auto it1 = rightmost_le(iter(B), G[i]);
      // dd G[i]; distance(begin(B), it1);
      if(it1 != end(B)) gbs.PB({G[i].first - it1->first, it1->second});

      auto it2 = leftmost_ge(iter(B), G[i]);
      // dd G[i]; distance(begin(B), it2);
      if(it2 != end(B)) gbs.PB({it2->first - G[i].first, it2->second});
    }

    sort(iter(rbs));
    sort(iter(gbs));

    dd rbs; gbs;

    times(size(rbs), i) {
      int jj = -1;
      times(size(gbs), j) {
        if(rbs[i].second != gbs[j].second) {
          amin(ans2, rbs[i].first + gbs[j].first);
          jj = j;
          break;
        }
      }
      if(jj == 0) break;
    }
  }

  dd ans1; ans2;

  cout << min(ans1, ans2) ln;
}
