#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(593);

char query(int i)
{
    cout << "? " << i+1 << endl;
    char c;
    cin >> c;
    return c;
}

void quicksort(vector<int> &a,vector<int> &ord)
{
    if(a.size() == 0)
        return ;
    int mid = rnd()%a.size();
    while(query(a[mid]) != '=')
        ;
    vector<int> l,r;
    for(int i = 0;i < a.size();++i)
    {
        if(i == mid)
            continue;
        if(query(a[i]) == '<')
        {
            l.push_back(a[i]);
        }
        else
        {
            r.push_back(a[i]);
        }
        query(a[mid]);
    }
    vector<int> l_ord;
    vector<int> r_ord;
    quicksort(l,l_ord);
    quicksort(r,r_ord);
    for(int i = 0;i < l_ord.size();++i)
    {
        ord.push_back(l_ord[i]);
    }
    ord.push_back(a[mid]);
    for(int i = 0;i < r_ord.size();++i)
    {
        ord.push_back(r_ord[i]);
    }
    return ;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        vector<int> ord;
        for(int i = 0;i < n;++i)
        {
            a.push_back(i);
        }
        quicksort(a,ord);
        cout << "! ";
        vector<int> ans(n);
        for(int i = 0;i < n;++i)
        {
            ans[ord[i]] = i;
        }
        for(int i = 0;i < n;++i)
        {
            cout << ans[i]+1 << ' ';
        }
        cout << endl;
    }
}
