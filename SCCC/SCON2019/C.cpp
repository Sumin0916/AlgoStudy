#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> vt[200002];
queue<pair<int, double> > q;

double h[200002];
int v[200002];

int main()
{
    int n, m;
    int a, b;

    int qf;
    double qs;

    int i, j;



    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%lf", &h[i]);
    for(i=1; i<n; i++)
    {
         scanf("%d %d", &a, &b);
         vt[a].push_back(b);
         vt[b].push_back(a);
    }

    int vt_s;

    //번째, 필요높이
    vt_s=vt[m].size();
    v[m]=1;
    for(i=0; i<vt_s; i++)
    {
        if(h[vt[m][i]]>=h[m])
        {
            printf("1");
            return 0;
        }
        else q.push({vt[m][i], h[m]+(h[m]-h[vt[m][i]])});
    }

    while(!q.empty())
    {
        qf=q.front().first;
        qs=q.front().second;
        q.pop();
        v[qf]=1;
        vt_s=vt[qf].size();

        for(i=0; i<vt_s; i++)
        {
            if(v[vt[qf][i]]==0)
            {
                if(h[vt[qf][i]]>=qs)
                {
                    printf("1");
                    return 0;
                }
                else q.push({vt[qf][i], qs+(qs-h[vt[qf][i]])});
            }
        }
    }
    printf("0");

    return 0;
}