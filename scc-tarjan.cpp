#include <bits/stdc++.h>

#define mem( a , b ) memset( a , b , sizeof( a ) )
#define Debug( x ) cout<< #x <<" : " << x <<"\n"

using namespace std;

int _I(){ int x; scanf("%d",&x); return x; }

bool onstack[ 100001 ];
bool vis[ 100001 ];
int order[ 100001 ];
int link[ 100001 ];
vector< int > g[ 100001 ] , Scc[ 100001 ];
stack< int > st;
int od = 1;
int Sc = 1;

void tarjan_scc( int u )
{
        order[ u ] = od;
        link[ u ] = od;
        od++;
        st.push( u );
        onstack[ u ] = 1;
        int sz = g[ u ].size();
        vis[ u ] = 1;
        for( int i = 0 ; i < sz ; i++ )
        {
                int x = g[ u ][ i ];
                if( !vis[ x ] )
                {
                        tarjan_scc( x );
                        link[ u ] = min( link[ u ] , link[ x ] );
                }
                else if( onstack[ x ] )
                {
                        link[ u ] = min( link[ u ], order[ x ] );
                }
        }
        if( order[ u ] == link[ u ] )
        {
                int x;
                while( u != st.top() )
                {
                        x = st.top();
                        Scc[ Sc ].push_back( x );
                        onstack[ x ] = 0;
                        st.pop();
                }
                x = st.top();
                Scc[ Sc ].push_back( x );
                onstack[ x ] = 0;
                st.pop();
                Sc++;
        }
}
void solve()
{
        while( st.size() ) st.pop();
        od = Sc = 1;
        for( int i = 0 ; i <= 100001 ; i++ ){
                g[ i ].clear();
                Scc[ i ].clear();
                vis[ i ] = 0;
        }

        int n = _I();
        int m = _I();

        for( int i = 0 ; i < m ; i++ )
        {
                int u = _I();
                int v = _I();
                g[ u ].push_back( v );
        }

        for( int i = 1 ; i <= n ; i++ )
        {
                if( !vis[ i ] )
                {
                        tarjan_scc( i );
                }
        }
        cout<<Sc<<"\n";

}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        int t = _I();
        while( t-- )
        {
                solve();
        }
}
