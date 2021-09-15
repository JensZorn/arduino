#include <iostream>
using namespace std;

int main(){
    float x;
    float y;
    cout << "Ein kleiner Rechner, der addiert.\nBitte gebe eine Zahl ein: ";
    cin >> x;
    cout << "Bitte gebe eine weitere Zahl ein: ";
    cin >> y;
    float sum = x + y;
    cout << "Das Ergebnis von " << x << " plus " << y << " ist: " << sum;
    return 0;
} 