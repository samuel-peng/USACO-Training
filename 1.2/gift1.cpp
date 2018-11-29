/*
 ID: samuelp1
 PROB: gift1
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
ifstream fin ("gift1.in");
ofstream fout ("gift1.out");
int main(int argc, const char * argv[]) {
    int NP;
    fin >> NP;
    map<string, int> P;
    string name, PName[NP];
    for (int i = 0; i < NP; i++) {
        fin >> PName[i];
        P[PName[i]] = 0;
    }
    int amount, number;
    int avg, left;
    for (int i = 0; i < NP; i++) {
        fin >> name >> amount >> number;
        if (amount == 0) avg = 0;
        else avg = amount / number;
        if (number == 0) left = amount;
        else left = amount - number * avg;
        P[name] = P[name] - amount + left;
        for (int i = 0; i < number; i++) {
            fin >> name;
            P[name] += avg;
        }
    }
    
    for (int i = 0; i < NP; i++) {
        fout << PName[i] << " " << P[PName[i]] << endl;
    }
    return 0;
}
