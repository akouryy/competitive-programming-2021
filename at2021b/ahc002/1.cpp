///// 4302876 pts


#include "base.hpp"
#include "consts.hpp"
#include "util.hpp"

#define TIME_OK(lim_sec) (static_cast<double>(clock() - ProgramStartTime) / CLOCKS_PER_SEC < lim_sec)

clock_t ProgramStartTime;

VWI important_dir = {
  {{2}, {3}, {3}, {3}, {3}, {3}},
  {{1}, {1}, {2}, {1}, {1}, {0}},
  {{2}, {3}, {3}, {0}, {3}, {3}},
  {{1}, {1}, {2}, {1}, {1}, {0}},
  {{2}, {3}, {3}, {0}, {3}, {3}},
  {{1}, {1}, {1}, {1}, {1}, {0}},
  // {{2},   {3}, {3},   {3}, {3}},
  // {{2}, {2,3}, {3}, {0,3}, {0}},
  // {{2},   {2},  {},   {0}, {0}},
  // {{2}, {1,2}, {1}, {0,1}, {0}},
  // {{1},   {1}, {1},   {1}, {0}}
};

constexpr int IMPORTANT_WEIGHT = 5;
constexpr int UNIMPORTANT_WEIGHT = 1;
constexpr int P_WEIGHT_GETA = 10;
constexpr int SAME_DIR_WEIGHT = 30;
constexpr int LOG_RESET = 20;
constexpr int N_RETRY = 13;

int SI, SJ;
WI T(50, VI(50));
WI P(50, VI(50));
WI same_with(50, VI(50, -1));

bool can_go(int i, int j, const WB& visited) {
  if(!rab::is_in(i, 0ll, 50ll) || !rab::is_in(j, 0ll, 50ll) || visited[i][j]) return false;
  int d = same_with[i][j];
  return d < 0 || !visited[i + di4[d]][j + dj4[d]];
}

// returns {log, point, rest retry count}
tuple<VI, int, int> go_rand(int i, int j, WB& visited, VI& log) {
  // if(!can_go(i, j, visited)) return {log, INT_MIN, 0};
  assert(can_go(i, j, visited));

  visited[i][j] = true;

  // VI okdir;
  VPII okdir;
  times(4, d) {
    int ii = i + di4[d], jj = j + dj4[d];
    if(can_go(ii, jj, visited)) {
      // const VI& importants = important_dir[
      //   i / ((49 + size(important_dir)) / size(important_dir))
      // ][
      //   j / ((49 + size(important_dir[0])) / size(important_dir[0]))
      // ];
      // okdir.PB(d);
      // okdir.PB({d, find(iter(importants), d) != end(importants) ? IMPORTANT_WEIGHT : UNIMPORTANT_WEIGHT});
      okdir.PB({d, P[ii][jj] + P_WEIGHT_GETA});
      // okdir.PB({d, P[ii][jj] + P_WEIGHT_GETA + SAME_DIR_WEIGHT * (!log.empty() && log.back() == d)});
    }
  }

  if(okdir.empty()) {
    visited[i][j] = false;
    return {log, P[i][j], N_RETRY};
  }

  int original_okdir_size = size(okdir);

  VI lBest; int pBest = -1, rest_retry_parent;
  while(!okdir.empty()) {
    // int di = rand() % size(okdir);
    int di = 0;
    { // ランダムに選択
      int weightSum = 0;
      for(const auto& d : okdir) weightSum += d.second;
      int rnd = rand() % weightSum;
      times(size(okdir), x) {
        rnd -= okdir[x].second;
        if(rnd < 0) { di = x; break; }
      }
    }

    const int d = okdir[di].first;
    // const int d = okdir[di];
    // VI temp_log;
    // bool reset = size(log) == LOG_RESET;
    // if(reset) {
    //   swap(log, temp_log);
    // } else {
      log.PB(d);
    // }
    VI l; int p; int rest_retry;
    tie(l, p, rest_retry) = go_rand(i + di4[d], j + dj4[d], visited, log);
    // if(reset) {
    //   log = temp_log;
    //   copy(iter(l), back_inserter(temp_log));
    //   l = move(temp_log);
    // } else {
      log.pop_back();
    // }
    if(amax(pBest, p)) {
      lBest = move(l);
      rest_retry_parent = rest_retry - (original_okdir_size > 1);
    }
    if(rest_retry <= 0) break;
    okdir.erase(begin(okdir) + di);
  }

  { // 後処理
    visited[i][j] = false;
    return {lBest, pBest + P[i][j], rest_retry_parent};
  }
}

void peephole(VI& log) {
  WB visited(50, VB(50));
  {
    int i = SI, j = SJ;
    visited[i][j] = true;
    for(int d : log) {
      i += di4[d]; j += dj4[d];
      visited[i][j] = true;
    }
  }
  int i = SI, j = SJ;
  for(int h = 0; h < size(log) - 1; ++h) {
    int d = log[h];
    int ii = i + di4[d], jj = j + dj4[d];

    {
      int pi = i + di4[(d + 1) & 3], pj = j + dj4[(d + 1) & 3],
        pii = ii + di4[(d + 1) & 3], pjj = jj + dj4[(d + 1) & 3];

      if(can_go(pi, pj, visited) && same_with[pi][pj] != d && can_go(pii, pjj, visited)) {
        visited[pi][pj] = visited[pii][pjj] = true;
        log.insert(begin(log) + h, {(d + 1) & 3});
        log.insert(begin(log) + h + 2, {(d + 3) & 3});
        --h;
        continue;
      }
    }
    {
      int pi = i + di4[(d + 3) & 3], pj = j + dj4[(d + 3) & 3],
        pii = ii + di4[(d + 3) & 3], pjj = jj + dj4[(d + 3) & 3];

      if(can_go(pi, pj, visited) && same_with[pi][pj] != d && can_go(pii, pjj, visited)) {
        visited[pi][pj] = visited[pii][pjj] = true;
        log.insert(begin(log) + h, {(d + 3) & 3});
        log.insert(begin(log) + h + 2, {(d + 1) & 3});
        --h;
        continue;
      }
    }
    int dd = log[h + 1];
    if((d ^ dd) & 1) {
      int //iii = ii + di4[dd], jjj = jj + dj4[dd],
          pi = i + di4[dd], pj = j + dj4[dd];
      if(can_go(pi, pj, visited) && P[ii][jj] < P[pi][pj]) {
        // visited[ii][jj] = false;
        visited[pi][pj] = true;
        swap(log[h], log[h + 1]);
        --h; // h = max(-1LL, h - 2);
        continue;
      }
    }
    i = ii; j = jj;
  }
  // dd visited;
}

void solve() {
// I J 50(50(T)) 50(50(P))
/* <foxy.memo-area> */
cin>>SI;cin>>SJ;times(50,Ri_0){times(50,Ri_1){cin>>T[
Ri_0][Ri_1];}}times(50,Ri_0){times(50,Ri_1){cin>>P[Ri_0][Ri_1];}
}
/* </foxy.memo-area> */

  ProgramStartTime = clock();
  srand(time(0));

  times(50, i) times(50, j) times(4, d) {
    int ii = i + di4[d], jj = j + dj4[d];
    if(rab::is_in(ii, 0ll, 50ll) && rab::is_in(jj, 0ll, 50ll) && T[i][j] == T[ii][jj]) {
      same_with[i][j] = d;
    }
  }
  // dd same_with;

  WB visitedArg(50, VB(50));
  VI logArg;
  VI logBest; int pBest = -1; int cnt = 0;
  while(TIME_OK(1.9)) {
    times(10, o) {
      VI log; int p; bool temp0; tie(log, p, temp0) = go_rand(SI, SJ, visitedArg, logArg);
      if(amax(pBest, p)) {
        logBest = move(log);
        // if(cnt > 100)
        //   dd cnt; p;
      }
      ++cnt;
    }
  }
  dd cnt;

  for(int d : logBest) {
    cerr << "URDL"[d];
  }
  cerr ln;

  peephole(logBest);
  peephole(logBest);

  for(int d : logBest) {
    cout << "URDL"[d];
  }
  cout ln;
}
