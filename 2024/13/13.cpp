#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbg(x) //cerr<<#x<<" = "<<x<<"\n";
#define llong long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define vvi vector<vector<int> >
#define pb push_back
#define pii pair<int, int>
#define f first
#define s second

const unsigned llong CORR = 10000000000000;

/**
 * Xa*a + Xb*b = Xt
 * Ya*a + Yb*b = Yt
*/


llong   Xa, Ya,
        Xb, Yb,
        Xt, Yt;

double divToDouble(llong x, llong y){
    return (double) x / (double) y;
}

int main(){_

    llong ansSuprema = 0;

    int t;
    cin>>t;

    while(t--){
        llong a = -1, b = -1;

        llong ans = 0;

        cin>>Xa>>Ya;
        cin>>Xb>>Yb;
        cin>>Xt>>Yt;

        Xt += CORR;
        Yt += CORR;

        llong C = Xa*Yb - Ya*Xb;
        llong R = Xa*Yt - Ya*Xt;

        if(C != 0){
            // S.P.D.

            double aux; 
            
            aux = divToDouble(R, C);
            if(aux == trunc(aux)){
                b = aux;
            }

            aux = divToDouble(Xt - Xb*b, Xa);
            if(aux == trunc(aux)){
                a = aux;
            }

            if(a != -1 && b != -1){
                ans = 3*a + b;
            } 
        }
        else if(R == 0){
            // S.P.I.
            // escolher o menor 'a' possivel
            // b = (Xt - Xa*a)/Xt

            double aux;
            
            a = 0;
            while(Xt - Xa*a > 0){
                aux = divToDouble(Xt - Xa*a, Xt);
            
                if(aux == trunc(aux)){
                    b = aux;
                    break;
                }
            
                a++;
            } 

            if(a != -1 && b != -1){
                ans = 3*a + b;
            }
        }
        // else eh S.I.

        ansSuprema += ans;
    }

    cout<<ansSuprema<<"\n";

    return 0;
}