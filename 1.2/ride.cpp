/*
 ID: samuelp1
 PROB: ride
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin ("ride.in");
ofstream fout ("ride.out");
int main() {
    string first, second;
    int firstMod = 1, secondMod = 1;
    fin >> first >> second;
    for(int i = 0; i < first.length(); i++) {
        firstMod *= first[i] - 'A' + 1;
        firstMod %= 47;
    }
    for(int i = 0; i < second.length(); i++) {
        secondMod *= second[i] - 'A' + 1;
        secondMod %= 47;
    }
    if(firstMod == secondMod) {
        fout<<"GO"<<endl;
    } else {
        fout<<"STAY"<<endl;
    }
    return 0;
}
