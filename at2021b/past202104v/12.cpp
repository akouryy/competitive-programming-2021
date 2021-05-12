#include "base.hpp"
//#include "consts.hpp"
#include "kruskal.hpp"

void solve() {
  /* wt.ten
    N M N(P Q) M(C D R)
  */
  int N,M;cin>>N>>M;VI P(N),Q(N);times(N,i0){cin>>P[i0]>>Q[i0];}VI C(M),D(M),R(M);times(M,i0){
  cin>>C[i0]>>D[i0]>>R[i0];}

  LD ans = 1e1000L;
  times(1<<M, m) {
    int nisc = 0;
    VI isc;
    times(M, i) if((m >> i) & 1) {
      ++nisc;
      isc.PB(i);
    }
    VI iscRev(M);
    times(size(isc), k) iscRev[isc[k]] = k;

    Graph<LD> g(N + nisc);
    times(N, i) times(N, j) if(i < j) {
      g.add_uedge(i, j, hypot(P[i] - P[j], Q[i] - Q[j]));
    }
    times(N, i) for(int j : isc) {
      g.add_uedge(i, N + iscRev[j], abs(R[j] - hypot(P[i] - C[j], Q[i] - D[j])));
    }
    for(int i : isc) for(int j : isc) if(i < j) {
      LD d = hypot(C[i] - C[j], D[i] - D[j]);
      g.add_uedge(
        N + iscRev[i], N + iscRev[j],
        R[i] + R[j] < d ? d - (R[i] + R[j]) :
          abs(R[i] - R[j]) < d ? 0 :
          abs(R[i] - R[j]) - d
      );
    }
    dd m; isc; iscRev;
    if(debug) for(auto e : flatten(g.edges, g.nde())) {
      dd make_tuple(e.weight, e.from, e.to);
    }
    auto kr = rab::kruskal(g);
    LD temp = 0;
    for(auto& es : kr.edges) for(auto& e : es) {
      temp += e.weight;
    }
    amin(ans, temp / 2);
  }
  
  cout << ans ln;
}
