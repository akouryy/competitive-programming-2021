#include "base.hpp"
#include "consts.hpp"

void solve() {
  /* wt.ten
    "S
  */
  string S;cin>>S;

  if(S.find("ooo") != string::npos) {
    cout << 'o' ln;
  } else if(S.find("xxx") != string::npos) {
    cout << 'x' ln;
  } else {
    cout << "draw" ln;
  }
}
