#include <bits/stdc++.h>
#define mem(a , b ) memset( a , b , sizeof( a ) )
#define pb( a ) push_back( a )
#define Debug( x ) cout<< #x <<" : " << x <<"\n"
using namespace std;
int _I(){ int x; scanf("%d",&x); return x; }
struct node{
        int r , c;
        node(){}
        node( int  x , int y )
        {
                r = x;
                c = y;
        }
        bool operator <( const node &R )
        {
                return r < R.r;
        }
};
int dis[ 100001 ];
int low[ 100001 ];
int parent[ 100001 ];
bool ap[ 100001 ];
vector< int > g[ 100001 ];
int Time = 0;
void dfs( int u )
{
        dis[ u ] = low[ u ] = ++Time;
        int chld = 0;
        int sz = g[ u ].size();
        for( int i = 0 ; i < sz ; i++ )
        {
                int v = g[ u ][ i ];
                if( v == parent[ u ] ) continue;
                else if( dis[ v ] )
                {
                        low[ u ] = min( low[ u ] , dis[ v ] );
                }
                else if( !dis[ v ] ){
                        parent[ u ] = v;
                        dfs( v );
                        low[ u ] = min( low[ u ] , low[ v ] );
                        if( dis[ u ] <= low[ v ] && u != 1 ) ap[ u ] = 1;
                        chld++;
                }
                if( chld > 1 && u == 1 )
                {
                       // Debug( chld );
                        ap[ u ] = 1;
                }
        }
}
void solve()
{
        int n;
        int m;
        while( scanf("%d %d",&n, &m ) ==2 ){
                if( !n && !m ) return;
                for( int i = 0; i <= 100000 ; i++ )
                {
                        g[ i ].clear();
                        dis[ i ] = 0;
                        ap[ i ] = 0;
                }
                Time = 0;
                for( int i = 0 ; i < m ; i++ )
                {
                        int u = _I();
                        int v = _I();
                        g[ u ].pb( v );
                        g[ v ].pb( u );
                }
                for( int i = 1 ; i <= n ; i++ )
                {
                        if( !dis[ i ] )
                        {
                                dfs( i );
                        }
                }
                int ans = 0;
                for( int i = 1; i <= n ; i++ )
                {
                        ans += ap[ i ];
                }
                printf("%d\n",ans);
        }
}
int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        //int t = _I();
        //getchar();
        //makedigi();
        //while( t-- ){
                solve();
        //}
        return 0;
}
