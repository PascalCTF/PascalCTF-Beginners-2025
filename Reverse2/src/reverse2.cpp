#include <iostream>

using namespace std;

void lose() {
    cout << "Wrong :(";
    exit(1);
}

int main() {
    cout << "Welcome to switcharoo! Can you guess my flag?" << endl;
    string f; cin>>f;

    if (f.size() != 32) {
        lose();
    }

    for (int i = 0; i < f.size(); i++) {
        switch(f[i]) {
            case 'a':
                if (i != 1 && i != 4 && i != 11)
                    lose();
                break;
            case 'T':
                if (i != 7 && i != 19)
                    lose();
                break;
            case '4':
                if (i != 17)
                    lose();
                break;
            case 'r':
                if (i != 24)
                    lose();
                break;
            case 'n':
                if (i != 18)
                    lose();
                break;
            case 'c':
                if (i != 3 && i != 16)
                    lose();
                break;
            case 'l':
                if (i != 5 && i != 28)
                    lose();
                break;
            case 'p':
                if (i != 0 && i != 10)
                    lose();
                break;
            case 's':
                if (i != 2)
                    lose();
                break;
            case 'C':
                if (i != 6)
                    lose();
                break;
            case 'D':
                if (i != 21)
                    lose();
                break;
            case 'o':
                if (i != 14)
                    lose();
                break;
            case 'F':
                if (i != 8)
                    lose();
                break;
            case 'L':
                if (i != 13 && i != 30)
                    lose();
                break;
            case 'V':
                if (i != 26)
                    lose();
                break;
            case '0':
                if (i != 12 && i != 29 && i != 22)
                    lose();
                break;
            case '{':
                if (i != 9)
                    lose();
                break;
            case '}':
                if (i != (118 ^ 0x69))
                    lose();
                break;
            case '_':
                if (i != 15 && i != 20 && i != 23 && i != 27)
                    lose();
                break;
            case '3':
                if (i != 25)
                    lose();
                break;
            default:
                lose();
                break;
        }
    }

    cout << "Good job, now submit that flag!";
    return 0;
}