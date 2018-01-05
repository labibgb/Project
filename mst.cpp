#include <bits/stdc++.h>
#define mem(a , b ) memset( a , b , sizeof( a ) )
#define Debug( x ) cout<< #x <<" : " << x <<"\n"
using namespace std;
int _I(){ int x; scanf("%d",&x); return x; }
struct node{
        int u , v, w;
        node(){}
        node( int x , int y , int z )
        {
                u = x;
                v = y;
                w = z;
        }
        bool operator <( const node &R )
        {
              return w < R.w;
        }
};
int pr[ 100001 ];
vector< node > e;
int dsu( int u )
{
        if( u == pr[ u ] ) return u;
        return pr[ u ] = dsu( pr[ u ] );
}
int mst( int n )
{
        for( int i = 1 ; i <= n ; i++ ) pr[ i ] = i;
        int sz = e.size();
        int s = 0;
        int c = 0;
        sort( e.begin() , e.end() );
        for( int i = 0 ; i < sz ; i++ )
        {
                node x = e[ i ];
                int u = dsu( x.u );
                int v = dsu( x.v );
                if( u != v )
                {
                        pr[ u ] = v;
                        s += x.w;
                        c++;
                        if( c == n-1 ) break;
                }
        }
        return s;
}
void solve()
{
        e.clear();
        int n = _I();
        int m = _I();
        int sm = 0;
        for( int i = 0 ; i < m ; i++ ){
                int u = _I();
                int v = _I();
                int w = _I();
                sm += w;
                e.push_back( node( u + 1 , v + 1 , w ) );
        }
        printf("%d\n",sm - mst( n ) );
}
int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        int t = _I();
        //getchar();
        //makedigi();
        while( t-- ){
                solve();
        }
        return 0;
}
