#include <boost/algorithm/string/replace.hpp>
#include "base.hpp"
//#include "consts.hpp"

void solve() {
  /* wt.ten
    N "S
  */
  int N;string S;cin>>N>>S;

  string T = "";

  for(char c : S) {
    boost::algorithm::replace_all(T, string(1, c), "");
    T.PB(c);
  }

  cout << T ln;
}
