/// 18687046 pts


/*
  i, j: 点の各座標
  p, q: 点
  a, b, c: 交差点ID
  x, y, z: サイクル内添字
*/

#define INT_IS_SIGNED
#line 1 "base.hpp"//1
#ifndef __clang__
#pragma GCC optimize ("O3")
#endif
void solve(
#ifdef GCJ_CASE
long long case_id
#endif
);
#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define _GLIBCXX_DEBUG
// #define _LIBCPP_DEBUG 0
#define _LIBCPP_DEBUG2 0
#else
#define NDEBUG 1
#define debug false
#endif
#include<algorithm>
#include<bitset>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<type_traits>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;
using LL=long long;
using ULL=unsigned long long;
#ifndef INT_IS_SIGNED
#define int LL
#endif
#define CS const
#define CX constexpr
#define IL inline
#define OP operator
#define RT return
#define TL template
#define TN typename
#define lambda [&]
#define rep(f,t,i,c,u)for(int Rb_=(t),i=(f);i c Rb_;u(i))
#define upto(f,t,i)rep(f,t,i,<=,++)
#define uptil(f,t,i)rep(f,t,i,<,++)
#define downto(f,t,i)rep(f,t,i,>=,--)
#define downtil(f,t,i)rep(f,t,i,>,--)
#define times(n,i)uptil(0,n,i)
#define rtimes(n,i)downto((n)-1,0,i)
#define iter(v)begin(v),end(v)
#define citer(v)cbegin(v),cend(v)
#define riter(v)rbegin(v),rend(v)
#define criter(v)crbegin(v),crend(v)
#define IF(a,b,c)((a)?(b):(c))
#if debug
#define ln <<endl
#else
#define ln <<'\n'
#endif
#define tb <<'\t'
#define sp <<' '
#line 1 "base_util.hpp"//1b
#define BINOPa(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)

#define TLA TL<TN A>
#define TLB TL<TN A,TN B>
#line 1 "mod.hpp"//1b
#ifndef MOD
#define MOD 1000000007
#endif
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error mod
#endif
#line 1 "power.hpp"//1bm
TL<TN T>IL T power(T x,int n){T r(1);for(;n;n/=2){if(n%2)r*=x;x*=x;}RT r;}IL int pow_mod(int x,int n,int m){int r=1;
for(;n;n/=2){if(n%2)r=r*x%m;x=x*x%m;}RT r;}
#line 2001 "mod.hpp"//1b
IL CX int modulo(int a,int b){a%=b;RT a&&(a>0)!=(b>0)?a+b:a;}IL CX int divide(int a,int b){RT(a-modulo(a,b))/b;}
TL<int d=MOD>struct MInt{
/*!https://ei1333.github.io/luzhiled/snippets/other/mod-int.html*/
int v;CX MInt():v(0){}explicit CX MInt(int i):v(modulo(i,d)){}MInt&OP+=(CS MInt&m){v+=m.v;if(v>=d)v-=d;RT*this;}
MInt&OP-=(CS MInt&m){v-=m.v;if(v<0)v+=d;RT*this;}MInt&OP*=(CS MInt&m){v=v*m.v%d;RT*this;}MInt&OP/=(CS MInt&m){
RT*this*=m.inv();}BINOPa(MInt,MInt,+)BINOPa(MInt,MInt,-)BINOPa(MInt,MInt,*)BINOPa(MInt,MInt,/)MInt OP-()CS{
RT MInt()-=*this;}CMPOP(MInt,==,v,m.v,m)CMPOP(MInt,!=,v,m.v,m)MInt pow(int n)CS{RT power(*this,n);}MInt inv()CS{
int a=v,b=d,x=1,y=0;while(b){swap(y,x-=a/b*y);swap(b,a%=b);}RT(MInt)x;}
friend ostream&OP<<(ostream&o,CS MInt&m){RT o<<m.v;}friend istream&OP>>(istream&i,MInt&m){i>>m.v;m.v%=d;RT i;}};
using mint=MInt<>;CX mint OP"" _m(ULL n){RT mint(n);}CX MInt<998244353>OP"" _m998244353(ULL n){RT MInt<998244353>(n);}
CX MInt<1000000007>OP"" _m1e9_7(ULL n){RT MInt<1000000007>(n);}
CX MInt<1000000009>OP"" _m1e9_9(ULL n){RT MInt<1000000009>(n);}
#line 1 "typedefs.hpp"//1b
using unit = tuple<>;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;
TL<TN T>using pq_gt=priority_queue<T,vec<T>,greater<T>>;
using VS=vec<string>;using VI=vec<int>;using HII=map<int, int>;using VZI=vec<set<int>>;using WI=vvec<int>;using VB=vec<bool>;using VPII=vec<pair<int, int>>;
#line 1 "alias.hpp"//1b
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//1b
TL<TN T>IL bool amax(T&v,CS T&a){RT v<a&&(v=a,1);}TL<TN T>IL bool amin(T&v,CS T&a){RT v>a&&(v=a,1);}
TL<TN T>IL int sizeRAB(T t){RT t.size();}
#define size sizeRAB
#define clamp clampRAB
TL<TN T>IL CX CS T&clamp(CS T&a,CS T&l,CS T&r){RT a<l?l:r<a?r:a;}TL<TN V>IL void uniq2(V&v){
v.erase(unique(iter(v)),v.end());}TL<TN V>IL void uniq(V&v){sort(iter(v));uniq2(v);}
#define leftmost_ge lower_bound
#define leftmost_gt upper_bound
TL<TN C,TN D>IL decltype(end(C()))rightmost_le(CS C&set,CS D&d){auto l=set.leftmost_gt(d);
RT l==begin(set)?end(set):--l;}TL<TN C,TN D>IL decltype(end(C()))rightmost_lt(CS C&set,CS D&d){
auto l=set.leftmost_ge(d);RT l==begin(set)?end(set):--l;}TL<TN C,TN D>IL C rightmost_le(CS C&from,CS C&to,CS D&d){
auto l=leftmost_gt(from,to,d);RT l==from?to:--l;}TL<TN C,TN D>IL C rightmost_lt(CS C&from,CS C&to,CS D&d){
auto l=leftmost_ge(from,to,d);RT l==from?to:--l;}namespace rab{TL<TN I>IL bool is_in(I x,I l,I r){RT l<=x&&x<r;}
TL<TN T>IL T fetch(CS T&d,CS vec<T>&v,int i){RT 0<=i&&i<size(v)?v[i]:d;}}
#line 1 "debug.hpp"//1b
TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS pair<T,S>&p);TL<TN T,TN U,TN V>IL ostream&OP<<(ostream&s,CS tuple<T,U,V>&p);
TL<TN T>IL ostream&OP<<(ostream&s,CS vec<T>&p);TL<TN T>IL ostream&OP<<(ostream&s,CS set<T>&p);TL<TN T,TN S>
IL ostream&OP<<(ostream&s,CS map<T,S>&p);TL<TN T>IL ostream&OP<<(ostream&s,CS vvec<T>&p);TL<TN T,TN S>
IL ostream&OP<<(ostream&s,CS vec<map<T,S>>&p);TL<TN T>IL istream&OP>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}
TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}TL<TN T,TN U,TN V>
IL ostream&OP<<(ostream&s,CS tuple<T,U,V>&p){RT s<<"("<<get<0>(p)<<","<<get<1>(p)<<","<<get<2>(p)<<")";}
#define Rdebug1(sep, ...)IL ostream& OP<<(ostream&s,CS __VA_ARGS__&v){\
int i=0;for(CS auto&e:v){i++&&s<<sep;s<<e;}RT s;}
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T>Rdebug1(' ',set<T>)TL<TN T>Rdebug1(' ',deque<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)
TL<TN T>Rdebug1('\n',vvec<T>)TL<TN T>Rdebug1('\n',vec<set<T>>)TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)
TL<TN T>Rdebug1('\n',set<vec<T>>)TL<TN T>Rdebug1('\n',set<set<T>>)TL<TN T,TN S>Rdebug1('\n',set<map<T,S>>)
#line 6001 "base.hpp"//1
#ifndef CUSTOM_MAIN
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#endif
#line 1001 "1.cpp"//
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
VZI can_see_virt, can_see_hori;
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
  can_see_hori = VZI(nIsecs);
  can_see_virt = VZI(nIsecs);
  times(nIsecs, a) {
    can_see_hori[a].insert(a);
    can_see_virt[a].insert(a);
  }

  times(2, d) {
    VZI& can_see = d == 0 ? can_see_hori : can_see_virt;

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
              can_see[a].insert(old_a);
              can_see[old_a].insert(a);
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
      if(can_see_hori[b].count(a) > 0 && can_see_hori[a].count(c) > 0) can_see_hori[b].insert(c);
      if(can_see_virt[b].count(a) > 0 && can_see_virt[a].count(c) > 0) can_see_virt[b].insert(c);
      if(amin(dists[b][c], dists[b][a] + middle + dists[a][c])) {
        dist_nexts[b][c] = dist_nexts[b][a];
      }
    }
  }
}

// 始点cycle[0]以外で、消していいやつを全削除
VI remove_unnecessary_isecs_locally(const VI& cycle) {
  VI ret = cycle;
  int nIsecs = size(isecs);
  int nCycle = size(cycle);
  VB used(nIsecs);
  for(int a : cycle) used[a] = true;

  times(nCycle - 2, o) {
    VPII candidates;
    times(nCycle, x) {
      int a = cycle[x];
      if(isecs[a] != S && used[a]) {
        int nh = 0, nv = 0;
        for(int b : can_see_hori[a]) nh += used[b];
        for(int b : can_see_virt[a]) nv += used[b];
        if(nh >= 2 && nv >= 2) {
          int xx = distance(ret.begin(), find(iter(ret), a));
          int before_a = ret[(xx + size(ret) - 1) % size(ret)],
              after_a  = ret[(xx + 1)             % size(ret)];
          int middle = Cflat[isecs[a]] - '0';
          candidates.PB({
            dists[before_a][after_a] - (dists[before_a][a] + middle + dists[a][after_a]),
            x
          });
        }
      }
    }
    if(candidates.empty()) break;
    sort(iter(candidates));
    int x_rm = candidates[0].second, //rand() % size(candidates)],
        a_rm = cycle[x_rm];
    used[a_rm] = false;
    ret.erase(find(iter(ret), a_rm));
  }
  return ret;
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
      // dd pc; pd;
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
  {if(debug)cerr<<"size(cycle): "<<(size(cycle))ln;}
  times(4, o) {
    cycle = remove_unnecessary_isecs_locally(cycle);
    {if(debug)cerr<<"cycle: "<<(cycle)ln;}
    VI next_cycle = { cycle[0] };
    int nCycle = size(cycle);
    VB used(size(isecs));
    used[cycle[0]] = true;

    times(nCycle, x) {
      int a = cycle[x], b = cycle[(x + 1) % nCycle],
          c = a;
      do {
        int d = dist_nexts[c][b];
        if(!used[d]) {
          next_cycle.PB(d);
          used[d] = true;
        }
        c = d;
      } while (b != c);
    }
    // dd next_cycle;
    cycle = move(next_cycle);
  }
  {if(debug)cerr<<"size(cycle): "<<(size(cycle))ln;}
  // dd cycle;
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
