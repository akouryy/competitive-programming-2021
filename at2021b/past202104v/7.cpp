#include "base.hpp"
//#include "consts.hpp"
#include "graph.hpp"

void solve() {
  /* wt.ten
    N M Q M(A- B- C) QX
  */
  int N,M,Q;cin>>N>>M>>Q;VI A(M),B(M),C(M);times(M,i0){cin>>A[i0]>>B[i0]>>C[i0];--A[i0];--B[i0];}VI X(Q);
  times(Q,i0){cin>>X[i0];}

  Graph<int> g(N);
  times(M, j) g.add_uedge(A[j], B[j], C[j]);

  pq_gt<Edge<int>> pq;
  VB visited(N);
  int nVis = 1;
  visited[0] = 1;
  for(auto& e : g.edges[0]) pq.push(e);
  times(Q, i) {
    vec<Edge<int>> es;
    while(!pq.empty() && pq.top().weight <= X[i]) { es.PB(pq.top()); pq.pop(); }
    for(auto& e : es) {
      if(!visited[e.to]) {
        visited[e.to] = true;
        ++nVis;
        for(auto& ee : g.edges[e.to]) if(!visited[ee.to]) pq.push(ee);
      }
    }
    cout << nVis ln;
  }
}
