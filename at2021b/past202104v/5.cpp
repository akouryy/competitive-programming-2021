#include "base.hpp"
#include "consts.hpp"

void solve() {
  /* wt.ten
    N "S
  */
  int N;string S;cin>>N>>S;

  deque<int> q;

  #define EMPTY_ERROR if(q.empty()) { cout << dict::ERROR ln; }

  times(N, i) {
    char c = S[i];
    dd c; q;
    if(c == 'L') {
      q.push_front(i + 1);
    } else if(c == 'R') {
      q.PB(i + 1);
    } else if('A' <= c && c <= 'C') {
      EMPTY_ERROR else {
        dd q.front();
        int x = q.front(); q.pop_front();
        if(c == 'A') {
          dd x;
          cout << x ln;
        } else {
          EMPTY_ERROR else {
            dd q.front();
            int y = q.front(); q.pop_front();
            if(c == 'B') {
              dd y;
              cout << y ln;
            } else {
              EMPTY_ERROR else {
                dd q.front();
                cout << q.front() ln; q.pop_front();
              }
              q.push_front(y);
            }
          }
          q.push_front(x);
        }
      }
    } else if('D' <= c && c <= 'F') {
      EMPTY_ERROR else {
        dd q.back();
        int x = q.back(); q.pop_back();
        if(c == 'D') {
          dd x;
          cout << x ln;
        } else {
          EMPTY_ERROR else {
            dd q.back();
            int y = q.back(); q.pop_back();
            if(c == 'E') {
              dd y;
              cout << y ln;
            } else {
              EMPTY_ERROR else {
                dd q.back();
                cout << q.back() ln; q.pop_back();
              }
              q.push_back(y);
            }
          }
          q.push_back(x);
        }
      }
    }
  }
}
