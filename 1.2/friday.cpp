/*
 ID: samuelp1
 PROB: friday
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("friday.in");
ofstream fout ("friday.out");
int main () {
    int n; //number of yearsN
    fin >> n;
    int D[2][12] = {{3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3}, {3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3}};
    int ans[7] = {0, 0, 0, 0, 0, 0, 0};
    bool leap;
    int ORIG = 6;
    for (int i = 0; i < n; i++) {
        if (i % 4) leap = false;
        else if (i % 100) leap = true;
        else if ((i - 100) % 400) leap = false;
        else leap = true;
        for (int j = 0; j < 12; j++) {
            ans[ORIG] ++;
            ORIG += D[leap][j];
            ORIG %= 7;
        }
    }
    //ans[ORIG] ++;
    fout << ans[6] << " " << ans[0] << " ";
    for(int i = 1; i < 5; i++) {
        fout << ans[i] << " ";
    }
    fout << ans[5] << endl;
    return 0;
}
