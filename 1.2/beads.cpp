/*
 ID: samuelp1
 PROB: beads
 LANG: c++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
ifstream fin ("beads.in");
ofstream fout ("beads.out");
int charToInt(char current) {
    if (current == 'w') return 0;
    else if (current == 'r') return 1;
    else if (current == 'b') return -1;
    else return 9;
}
int main() {
    int n;
    string s, str;
    int prev, cur, curStart = 0, curLength = 1;
    int color, max = -1;
    int whiteStart = -1, whiteLength;
    fin >> n >> s;
    str = s + s;
    int lengths[str.length()][2] = {0};
    prev = charToInt(str[0]);
    if (prev != 0) color = prev;
    else color = 1;
    for (int i = 1; i < str.length(); i++) {
        cur = charToInt(str[i]);
        /*
        cout << "Current location is : " << i;
        cout << "; Previous is: " << prev;
        cout << "; Current is: " << cur;
        cout << "; Current color is: " << color << endl;
        */
        if (prev != 0) { //color beads
            if (!cur) {
                curLength ++;
                whiteStart = i;
                whiteLength = 1;
            } else if (cur == color) { //same color
                curLength ++;
            } else {
                lengths[i][0] = curLength;
                lengths[curStart][1] = curLength;
                curLength = 1;
                color = -(color);
                curStart = i;
            }
        } else { //White
            if (!cur) { //white
                curLength++;
                whiteLength++;
            } else if (cur == color) { //same color
                curLength++;
                whiteLength = 0;
            } else { //different color
                lengths[i][0] = curLength;
                lengths[curStart][1] = curLength;
                curLength = whiteLength + 1;
                color = -(color);
                curStart = i;
                whiteLength = 0;
            }
        }
        prev = cur;
    }
    for (int i = 0; i < str.length(); i++) {
        if (lengths[i][0] + lengths[i][1] > max) max = lengths[i][0] + lengths[i][1];
    }
    fout << max;
	return 0;
}
