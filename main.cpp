//Programa que implementa la definición de puntos de una línea, dados dos puntos (x,y).
//Programador: León Emiliano García Pérez (A00573074).
//Fecha de entrega: 01.11.2022.

//Forma de ejecutar: En Terminal
//  1.- g++ main.cpp -o a.out
//  2.- ./a.out

//Inclusión de librerías
#include <iostream>
#include <cmath>
#include <vector>


//Ajuste a estandar
using namespace std;

//Definición de la Estructura Punto (int x, int y);
struct Punto {
    int x;
    int y;
};

//Función que imprime en consola los puntos para la formación entre dos puntos, recibe dos Estructuras Punto y no tiene valor de retorno.
void imprimirLinea(Punto p1, Punto p2) {

    vector <float> x;
    vector <float> y;

    Punto primero;
    Punto segundo;

    float pendiente;

    //Se determina cuál está a la izquierda.
    if (p1.x < p2.x) {
        primero = p1;
        segundo = p2;
    }
    else {
        primero = p2;
        segundo = p1;
    }

    // Se crean los dos discriminantes de la formula de la pendiente.
    float discriminante1 = (segundo.y - primero.y);
    float discriminante2 = (segundo.x - primero.x);

    pendiente = discriminante1 / discriminante2; // Se calcula la pendiente, se realiza de esta forma para no perder información. 

    float yAux = primero.y; //Se crea una y auxiliar para controlar el paso dentro del ciclo for. 

    for (float i = primero.x; i <= segundo.x; i++) { //Se va de x en x, y se avanza de y en y en función de la pendiente. Se redondea el valor de y ya que no se buscan decimales.
        int nuevaY;
        nuevaY = round(yAux);
        x.push_back(i);
        y.push_back(nuevaY);
        yAux += pendiente;
    }

    for (int j = 0; j < x.size(); j++) { //Se imprimen en consola todos los puntos.
        cout << "(" << x[j] << "," << y[j] << ")" << endl;
    }

}

//Función main de ejecuciónn del programa, no recibe parámetro alguno, no tiene valor de retorno. [return 0].
int main() {

    Punto p1;
    Punto p2;
    
    //Se determinan los datos de los dos puntos.
    cin >> p1.x;
    cin >> p1.y;
    cin >> p2.x;
    cin >> p2.y;

    cout << endl;
    imprimirLinea(p1, p2);
    cout << endl;

    return 0;
}