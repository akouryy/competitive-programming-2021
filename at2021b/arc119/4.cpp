#include "base.hpp"
//#include "consts.hpp"
#include "graph.hpp"
#include "kruskal.hpp"

int H,W;

void dfs(Graph<int>& tree, VB& visited, int i, int p, bool selectH) {
  dd "begin"; i; p; selectH;
  if(i<H) visited[i] = true;
  int edgesize = size(tree.edges[i]);
  times(edgesize, oo) {
    const auto& edge = tree.edges[i][oo];
    if(edge.to != p) {
      dfs(tree, visited, edge.to, i, false);
      if(i<H) {
        cout << (selectH && (oo == edgesize-1) ? "X" : "Y") sp << i+1 sp << edge.to-H+1 ln;
      } else {
        cout << "X" sp << edge.to+1 sp << i-H+1 ln;
      }
    }
  }
  dd "end"; i; p;
}

void solve() {
  /* wt.ten
    H W H"S
  */
  cin>>H>>W;VS S(H);times(H,i0){cin>>S[i0];}

  Graph<int> g(H+W);
  times(H, i) times(W, j) if(S[i][j] == 'R') {
    g.add_uedge(i, j+H, 0);
  }

  Graph<int> tree = rab::kruskal(g);
  dd tree.edges;

  int ic=0, jc=0;
  times(H, i) if(!tree.edges[i].empty()) ++ic;
  times(W, j) if(!tree.edges[j+H].empty()) ++jc;

  int ans = INT_MAX, ians;
  int v = tree.nue();
  // assert(v == ic + jc - 連結成分の数);
  upto(v - jc, ic, i) {
    dd i; (H - i) * (W - (v - i));
    if(amin(ans, (H - i) * (W - (v - i)))) ians = i;
  }

  cout << v ln;
  VB visited(H);
  times(H, i) if(!visited[i] && !tree.edges[i].empty()) {
    dfs(tree, visited, i, i, ians>v-jc);
    --ians;
  }
}
