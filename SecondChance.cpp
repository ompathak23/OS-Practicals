#include <bits/stdc++.h>

using namespace std;

int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;

void getData(){
    cout<<"Enter length of page reference sequence:";
    cin>>n;
    cout<<"Enter the page reference sequence:";
    for (i = 0; i < n; i++) cin>>in[i];
    cout<<"Enter no of frames:";
    cin>>nf;
}

void initialize(){
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++) p[i] = 9999;
}

int isHit(int data){
    hit = 0;
    for (j = 0; j < nf; j++){
        if (p[j] == data){
            hit = 1;
            break;
        }
    }
    return hit;
}

int getHitIndex(int data){
    int hitind;
    for (k = 0; k < nf; k++){
        if (p[k] == data){
            hitind = k;
            break;
        }
    }
    return hitind;
}

void dispPages(){
    for (k = 0; k < nf; k++)
        if (p[k] != 9999) cout<<" "<<p[k];
}

void dispPgFaultCnt(){
    cout<<"\nTotal no of page faults: "<<pgfaultcnt;
}

int main()
{
    getData();

    int usedbit[50];
    int victimptr = 0;
    initialize();

    for (i = 0; i < nf; i++) usedbit[i] = 0;

    for (i = 0; i < n; i++){

        cout<<"\nFor "<<in[i]<<": ";
        if (isHit(in[i])){
            cout<<"No page fault!";
            int hitindex = getHitIndex(in[i]);
            if (usedbit[hitindex] == 0) usedbit[hitindex] = 1;
        }
        else{
            pgfaultcnt++;

            if (usedbit[victimptr] == 1){
                do{
                usedbit[victimptr] = 0;
                victimptr++;
                if (victimptr == nf) victimptr = 0;
                } while (usedbit[victimptr] != 0);
            }

            if (usedbit[victimptr] == 0){
                p[victimptr] = in[i];
                usedbit[victimptr] = 1;
                victimptr++;
            }

            dispPages();
        }

        if (victimptr == nf) victimptr = 0;
    }

    dispPgFaultCnt();
}
