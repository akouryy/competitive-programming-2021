/// 12209116pts

#define INT_IS_SIGNED
#include "base.hpp"
//#include "consts.hpp"

constexpr int N_ALIGN = 128;

#define PT(i, j) ((i) << 7 | (j))
#define I(p) ((p) >> 7)
#define J(p) ((p) & N_ALIGN - 1)

// inputs
int N, S;
VS C;
string Cflat;

VI isecs; // intersections
HII isec_indices;
// int dists[N_ALIGN][N_ALIGN]; // 交差点自体のマスは距離に含まない
WI dists; // 交差点自体のマスは距離に含まない
WI dist_nexts;
VI isecs_to_use;
string ans;

// set isecs
void calc_isecs() {
  int cnt = 0;
  times(N, i) times(N, j) {
    const int p = PT(i, j);
    if(p == S || (
      Cflat[p] > '0' &&
      ((i > 0 && Cflat[p - N_ALIGN] > '0') || (i < N-1 && Cflat[p + N_ALIGN] > '0')) &&
      ((j > 0 && Cflat[p - 1]       > '0') || (j < N-1 && Cflat[p + 1]       > '0'))
    )) {
      // dd make_pair(i, j);
      isecs.PB(p);
      isec_indices[p] = cnt;
      ++cnt;
    }
  }
}

void calc_dists() {
  int nIsecs = size(isecs);
  dists = WI(nIsecs, VI(nIsecs));
  times(nIsecs, a) times(nIsecs, b) if(a != b) dists[a][b] = INT_MAX / 5;
  dist_nexts = WI(nIsecs, VI(nIsecs, -1));

  times(2, d) {
    times(N, i) {
      int dist = 0;
      int old_a = -1;
      times(N, j) {
        const int p = d == 0 ? PT(i, j) : PT(j, i);
        if(Cflat[p] > '0') {
          if(isec_indices.count(p) > 0) {
            const int a = isec_indices[p];
            if(old_a >= 0) {
              dists[a][old_a] = dists[old_a][a] = dist;
              dist_nexts[a][old_a] = old_a;
              dist_nexts[old_a][a] = a;
            }
            old_a = a;
            dist = 0;
          } else {
            dist += Cflat[p] - '0';
          }
        } else {
          old_a = -1;
        }
      }
    }
  }
  times(nIsecs, a) {
    int middle = Cflat[isecs[a]] - '0';
    times(nIsecs, b) times(nIsecs, c) {
      if(amin(dists[b][c], dists[b][a] + middle + dists[a][c])) {
        dist_nexts[b][c] = dist_nexts[b][a];
      }
    }
  }
}

VI farthest_insertion() {
  int nIsecs_to_use = size(isecs_to_use);
  VB used(nIsecs_to_use);
  used[0] = true;
  VI path = {0};
  path.reserve(nIsecs_to_use);

  uptil(1, nIsecs_to_use, nPath) {
    int cv = INT_MIN, c;
    times(nIsecs_to_use, cc) if(!used[cc]) {
      int bv = INT_MAX;
      times(nIsecs_to_use, bb) if(used[bb]) {
        amin(bv, dists[bb][cc]);
      }
      if(amax(cv, bv)) { c = cc; }
    }
    used[c] = true;
    // dd c;

    int abv = INT_MAX, aPath;
    times(nPath, aaPath) {
      int aa = path[aaPath], bb = path[(aaPath + 1) % nPath];
      if(amin(abv, dists[c][aa] + dists[c][bb] - dists[aa][bb])) { aPath = aaPath; }
    }
    path.insert(path.begin() + aPath + 1, c);
  }
  return path;
}

string cycle_to_ans(VI cycle) {
  rotate(cycle.begin(), find(iter(cycle), isec_indices[S]), cycle.end());
  if(debug) {
    for(auto a : cycle) cerr << a << "=" << I(isecs[a]) << "," << J(isecs[a]) sp;
    cerr ln;
  }

  string ret;
  int nCycle = size(cycle);
  times(nCycle, aCycle) {
    int a = cycle[aCycle], b = cycle[(aCycle + 1) % nCycle],
        c = a;
    do {
      int d = dist_nexts[c][b];
      // dd a; b; c; d;
      int pc = isecs[c], pd = isecs[d];
      dd pc; pd;
      char dir = I(pc) == I(pd) ? J(pc) < J(pd) ? 'R' : 'L' :
                                  I(pc) < I(pd) ? 'D' : 'U';
      ret.append(string(
        abs(I(pc) - I(pd)) + abs(J(pc) - J(pd)),
        dir
      ));
      // dd string(abs(I(pc) - I(pd)) + abs(J(pc) - J(pd)),dir);
      c = d;
    } while (b != c);
  }

  return ret;
}

// use isecs_to_use
void calc_ans() {
  VI cycle = farthest_insertion();
  ans = cycle_to_ans(cycle);
}

void solve() {
  srand(4835);

  /* wt.ten: NIJ N@"C */
  int si,sj;cin>>N>>si>>sj;C.resize(N);times(N,i0){cin>>C[i0];}
  S = PT(si, sj);
  times(N, i) {
    Cflat.append(C[i]);
    Cflat.append(string(N_ALIGN - N, '#'));
  }
  // dd Cflat;

  calc_isecs();
  calc_dists();

  isecs_to_use = isecs;
  calc_ans();

  cout << ans ln;
}
