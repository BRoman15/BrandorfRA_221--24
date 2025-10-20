#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string line;
    ifstream file("Testimag.pgm", ios::binary);
    string format;
    int a, b, c;
    char l,k,j,h;
    if (file.is_open()){
        file >> format >> a >> b >> c;
    }
    cout << format << " " << a << " " << b << " " << c << endl;
    file >> l >> k >> j >> h;
    cout << l << " " << k << " " << j << " " << h << endl;
    file.close();
}