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
#define NDEBUG
#define debug false
#endif
#include<algorithm>
#include<bitset>
#include<functional>
#include<iomanip>
#include<iostream>
#include<limits>
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
#define int LL
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
using VWI=vec<vvec<int>>;using WI=vvec<int>;using VI=vec<int>;using WB=vvec<bool>;using VPII=vec<pair<int, int>>;using VB=vec<bool>;
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
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T>Rdebug1(' ',set<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)TL<TN T>Rdebug1('\n',vvec<T>)
TL<TN T>Rdebug1('\n',vec<set<T>>)TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)TL<TN T>Rdebug1('\n',set<vec<T>>)
TL<TN T>Rdebug1('\n',set<set<T>>)TL<TN T,TN S>Rdebug1('\n',set<map<T,S>>)
#line 6001 "base.hpp"//1
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1 "consts.hpp"//1
int di4[]={-1,0,1,0},dj4[]={0,1,0,-1},di8[]={-1,-1,0,1,1,1,0,-1},dj8[]={0,1,1,1,0,-1,-1,-1,-1},
di_knight[]={-2,-1,1,2,2,1,-1,-2},dj_knight[]={1,2,2,1,-1,-2,-2,-1};namespace dict{
[[maybe_unused]]CX char
YES[]="YES",Yes[]="Yes",yes[]="yes",NO[]="NO",No[]="No",no[]="no",WIN[]="WIN",Win[]="Win",win[]="win",
LOSE[]="LOSE",Lose[]="Lose",lose[]="lose",OK[]="OK",ok[]="ok",NG[]="NG",ng[]="ng",NA[]="NA",na[]="na",
AC[]="AC",ac[]="ac",WA[]="WA",wa[]="wa",FIRST[]="FIRST",First[]="First",first[]="first",
SECOND[]="SECOND",Second[]="Second",second[]="second",
POSSIBLE[]="POSSIBLE",Possible[]="Possible",possible[]="possible",
IMPOSSIBLE[]="IMPOSSIBLE",Impossible[]="Impossible",impossible[]="impossible",
PRIME[]="PRIME",Prime[]="Prime",prime[]="prime",
NOT_PRIME[]="NOT PRIME",Not_Prime[]="Not Prime",not_prime[]="not prime",
UNBOUNDED[]="UNBOUNDED",Unbounded[]="Unbounded",unbounded[]="unbounded",
ALICE[]="ALICE",Alice[]="Alice",alice[]="alice",BOB[]="BOB",Bob[]="Bob",bob[]="bob",
BROWN[]="BROWN",Brown[]="Brown",brown[]="brown",SAME[]="SAME",Same[]="Same",same[]="same",
DIFFERENT[]="DIFFERENT",Different[]="Different",different[]="different",
TAKAHASHI[]="TAKAHASHI",Takahashi[]="Takahashi",takahashi[]="takahashi",AOKI[]="AOKI",Aoki[]="Aoki",aoki[]="aoki";}
#line 2001 "1.cpp"//

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
  {if(debug)cerr<<"cnt: "<<(cnt)ln;}
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
