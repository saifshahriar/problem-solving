#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;
int d[maxn];
int h[maxn];
int p[maxn];
vector<int> leaf_jump_gains;
vector<vector<int> > children;

bool comp_by_depth(int u,int v)
{
    return d[u] < d[v];
}

void sort_subtrees_by_depth(int v)
{
    d[v] = 0;
    if(v == 1)
        h[v] = 0;
    else
        h[v] = h[p[v]]+1;
    for(int i = 0; i < int(children[v].size()); ++i)
    {
        int u = children[v][i];
        sort_subtrees_by_depth(u);
        d[v] = max(d[v],d[u]+1);
    }
    sort(children[v].begin(),children[v].end(),comp_by_depth);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    children.resize(n+1);
    for(int i = 2; i <= n; ++i)
    {
        cin >> p[i];
        children[p[i]].push_back(i);
    }
    sort_subtrees_by_depth(1);
    for(int i = 1; i <= n; ++i)
    {
        if(children[i].size() == 0)
        {
            int jump_gain = 0;
            int v = i;
            while(v != 1)
            {
                int s = children[p[v]].size();
                if(children[p[v]][s-1] == v)
                {
                    v = p[v];
                    ++jump_gain;
                }
                else
                {
                    jump_gain = jump_gain+1-h[p[v]];
                    break;
                }
            }
            leaf_jump_gains.push_back(jump_gain);
        }
    }
    sort(leaf_jump_gains.begin(),leaf_jump_gains.end());
    int s = leaf_jump_gains.size();
    ++k; //non-returning from the last leaf is like one more jump
    int res = 2*(n-1);
    for(int i = s-1; i >= max(0,s-k); --i)
        res -= max(leaf_jump_gains[i],0);
    cout << res << '\n';
    return 0;
}
