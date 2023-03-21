#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream f1("../exemplu1.in");
ifstream f2("../exemplu2.in");
ifstream f3("../exemplu3.in");

int matrice[1001][1001], stfin[1001], nrstfin, nrlitere;
char alfabet[101];

void initializare() {
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            matrice[i][j] = -1;
}

void citire1() {
    int nrstari, nrfunctii, stare1, stare2, k = -1, cnt = -1, ok;
    char cuv;

    f3 >> nrstari >> nrfunctii >> nrstfin >> nrlitere;
    for (int i = 0; i < nrfunctii; i++) {
        f3 >> stare1 >> cuv >> stare2;
        matrice[stare1][int(cuv)] = stare2;
        ok = 0;
        for (int j = 0; j <= cnt; j++) {
            if (alfabet[j] == cuv)
                ok = 1;
        }
        if (ok == 0)alfabet[++cnt] = char(cuv);
    }
    for (int i = 0; i < nrstfin; i++) {
        f3 >> stfin[++k];
    }
}

void stergelitera(char v[]) {
    for (int i = 0; i < strlen(v); i++)
        v[i] = v[i + 1];
}

int main() {
    initializare();
    citire1();
    char cuvant[100001];

    cin >> cuvant;
    cin.get();
    int stare, ok = 1, k = 0, okk;
    int drum[10001];
    stare = 0;
    drum[0] = 0;

    while (ok == 1 && strlen(cuvant) != 0) {
        if (matrice[stare][(int) cuvant[0]] == -1)
            ok = 0;
        else {
            stare = matrice[stare][(int) cuvant[0]];
            stergelitera(cuvant);
            drum[++k] = stare;
        }
    }
    int posibilcuvvid = 0;
        for(int i = 0; i < nrstfin; i++)
        {
            if( stfin[i] == 0)posibilcuvvid = 1;
        }

    if( cuvant[0] == '-' && ::strlen(cuvant) == 1)
    {
        if(posibilcuvvid == 1)cout<< "acceptat\n" << 0 << "->" <<0;
        else cout << "neacceptat";
    }
    else{
        if (ok == 0)
            cout << "neacceptat";
        else {
            okk = 0;
            for(int i = 0; i <nrstfin; i++)
                if(stare == stfin[i]) okk = 1;

            if(okk == 0)
                cout << "neacceptat";
            else
            {
                cout << "acceptat" << endl;
                cout << drum[0];
                for (int i = 1; i < k; i++)
                    cout << "->" << drum[i];}

        }
    }
    return 0;
}
