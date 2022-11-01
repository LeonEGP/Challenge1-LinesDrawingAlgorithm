
#include <iostream>
#include <vector>

using namespace std;

struct Punto {
    int x;
    int y;
};

void imprimirLinea(Punto p1, Punto p2) {

    vector <float> x;
    vector <float> y;
    Punto primero;
    Punto segundo;
    float pendiente;

    if (p1.x < p2.x) {
        primero = p1;
        segundo = p2;
    }
    else {
        primero = p2;
        segundo = p1;
    }

    float discriminante1 = (segundo.y - primero.y);
    float discriminante2 = (segundo.x - primero.x);

    pendiente = discriminante1 / discriminante2;

    float pendienteMenorPaso = pendiente / 10.00;

    float yAux = primero.y;

    for (float i = primero.x; i < segundo.x; i+=0.1) {
        x.push_back(i);
        y.push_back(yAux);
        yAux += pendienteMenorPaso;
    }

    for (int j = 0; j < x.size(); j++) {
        cout << "(" << x[j] << "," << y[j] << ")" << endl;
    }

}

int main() {

    Punto p1;
    Punto p2;
    
    cin >> p1.x;
    cin >> p1.y;
    cin >> p2.x;
    cin >> p2.y;

    imprimirLinea(p1, p2);

    cout << endl;

    return 0;
}