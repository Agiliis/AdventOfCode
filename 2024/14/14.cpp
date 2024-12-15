// 1 estrela

#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<"\n";
#define llong long long
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define vvi vector<vector<int> >
#define pb push_back
#define pii pair<int, int>
#define f first
#define s second

#include <format>
#define CONS_UP         "\033[A"
#define CONS_DEL_LINE   "\033[2K"
#define CONS_CLEAR      "\033[2J"
#define CONS_RESET      "\033[f"
#define CONS_NEW_LINE   "\033["

const unsigned llong MAXN = 1e5+10, INF = LLONG_MAX;
const int wide = 101, tall = 103;

llong seconds = 0;

struct Robo{
    pii pos;
    pii vel;
};

int midWide = wide/2;
int midTall = tall/2;

int mapa[tall][wide];
vector<Robo> robos;

void limpar_tela(){
    printf(CONS_CLEAR); printf(CONS_RESET);
}

llong calc_quad(int i0, int j0){
    int safetyFac = 0;

    for(int i=i0; i<i0+midTall; i++){
        for(int j=j0; j<j0+midWide; j++){
            safetyFac += mapa[i][j];
        }
    }

    return safetyFac;
}

void print_mapa(){
    for(int i=0; i<tall; i++){
        for(int j=0; j<wide; j++){
            cout<<(mapa[i][j]>0? 'R' : '.')<<" ";
        }cout<<"\n";
    }
}

ifstream stop;

void avancar(int prog, float slp){

    for(int i=0; i<prog; i++){
        stop.open("stop");

        seconds++;

        for(auto &[pos, vel] : robos){
            mapa[pos.f][pos.s]--;

            pos.f = (pos.f + vel.f) % tall;
            if(pos.f < 0) pos.f += tall;
            pos.s = (pos.s + vel.s) % wide;
            if(pos.s < 0) pos.s += wide;

            mapa[pos.f][pos.s]++;
        }

        limpar_tela();

        print_mapa();
        dbg(seconds);

        char stopCh;
        stop>>stopCh;
        dbg(stopCh)
        if(stopCh == '1') break;

        system("sleep 0.01");

        stop.close();
    }

}

void retroceder(int prog, float slp){
    for(int i=0; i<prog; i++){
        stop.open("stop");

        seconds--;

        for(auto &[pos, vel] : robos){
            mapa[pos.f][pos.s]--;

            pos.f = (pos.f - vel.f) % tall;
            if(pos.f < 0) pos.f += tall;
            pos.s = (pos.s - vel.s) % wide;
            if(pos.s < 0) pos.s += wide;

            mapa[pos.f][pos.s]++;
        }

        limpar_tela();

        print_mapa();
        dbg(seconds);

        char stopCh;
        stop>>stopCh;
        dbg(stopCh)
        if(stopCh == '1') break;

        system("sleep 0.01");

        stop.close();
    }
}

int main(){

    ifstream input;
    input.open("proc_input.txt");

    if(!input.is_open()){
        perror("Erro ao abrir proc_input.txt");
        exit(1);
    }

    llong ans = 1;
    int n; input>>n;
    robos.resize(n);
    
    for(int i=0; i<n; i++){
        pii pos, vel;
        
        input>>pos.s>>pos.f;
        input>>vel.s>>vel.f;

        robos[i].pos = pos;
        robos[i].vel = vel;

        mapa[pos.f][pos.s]++;
    }

    input.close();

    while(1){

        llong mode, prog;
        float slp;
        
        puts("<modo (1 para avancar, 2 para retroceder)> <progresso de segundos>");
        cin>>mode>>prog;

        switch(mode){
        case 1:
            avancar(prog, slp);
            break;
        case 2:
            retroceder(prog, slp);
            break;
        }

    }

    // ans *= calc_quad(0,         0           );
    // ans *= calc_quad(midTall+1, 0           );
    // ans *= calc_quad(0,         midWide+1   );
    // ans *= calc_quad(midTall+1, midWide+1   );

    //cout<<ans<<"\n";

    return 0;
}