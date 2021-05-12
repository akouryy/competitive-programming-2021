#include "base.hpp"
//#include "consts.hpp"

signed received[200000], pending[200000], A[200000], B[200000], T[200000], X[200000], degrees[200000];
vec<signed> edges_temp[200000], edges_act[200000];

void solve() {
  /* wt.ten
    N M M(A- B-) Q Q(T X-)
  */
  signed N,M,Q;scanf("%d%d",&N,&M);
  times(M,i0){scanf("%d%d",&A[i0],&B[i0]);--A[i0];--B[i0];}
  scanf("%d",&Q);
  times(Q,i0){scanf("%d%d",&T[i0],&X[i0]);--X[i0];}

  times(M, i) {
    edges_temp[A[i]].PB(B[i]);
    // edges[B[i]].PB(A[i]);
  }
  times(N, i) {
    signed d = degrees[i] = size(edges_temp[i]);
    edges_act[i].reserve(d);
  }
  times(N, i) for(signed j : edges_temp[i]) {
    if(degrees[i] < degrees[j]) {
      edges_act[i].PB(j);
    } else {
      edges_act[j].PB(i);
    }
  }

  // dd edges_act;

  times(Q, i) {
    if(T[i] == 1) {
      ++pending[X[i]];
      for(signed j : edges_act[X[i]]) ++received[j];
    } else {
      signed ans = received[X[i]];
      for(signed j : edges_act[X[i]]) ans += pending[j];
      printf("%d\n", ans);
      received[X[i]] -= ans;
    }
    // dd pending; received;
  }
}
