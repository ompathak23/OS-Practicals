#include <bits/stdc++.h>

using namespace std;

static int mark[20];
int i, j, np, nr;

int main()
{
    int alloc[10][10], request[10][10], avail[10], r[10], w[10];
    cout<<"Enter the no of processes: ";
    cin>>np;
    cout<<"Enter the no of resources: ";
    cin>>nr;

    for(i = 0; i < nr; i++)
    {
        cout<<"Total Amount of the Resource R"<<i + 1<<": ";
        cin>>r[i];
    }

    cout<<"\nEnter the request matrix:"<<endl;
    for (i = 0; i < np; i++){
        for (j = 0; j < nr; j++){
            cin>>request[i][j];
        }
    }

    cout<<"\nEnter the allocation matrix:"<<endl;
    for (i = 0; i < np; i++){
        for (j = 0; j < nr; j++){
            cin>>alloc[i][j];
        }
    }
    

    /*Available Resource calculation*/
    for (j = 0; j < nr; j++){
        avail[j] = r[j];
        for (i = 0; i < np; i++){
            avail[j] -= alloc[i][j];
        }
    }

    for (i = 0; i < np; i++){
        int count = 0;
        for (j = 0; j < nr; j++){
            if (alloc[i][j] == 0) count++;
            else break;
        }
        if (count == nr) mark[i] = 1;
    }

    for (j = 0; j < nr; j++) w[j] = avail[j];
    for (i = 0; i < np; i++){
        int canbeprocessed = 0;
        if (mark[i] != 1) {
            for (j = 0; j < nr; j++){
                if (request[i][j] <= w[j]) canbeprocessed = 1;
                else {
                    canbeprocessed = 0;
                    break;
                }
            }
            
            if (canbeprocessed){
                mark[i] = 1;
                for (j = 0; j < nr; j++) w[j] += alloc[i][j];
            }
        }
    }

    int deadlock = 0;
    for (i = 0; i < np; i++)
        if (mark[i] != 1) deadlock = 1;

    if (deadlock) cout<<"\nDeadlock detected";
    else cout<<"\nNo Deadlock possible";
}