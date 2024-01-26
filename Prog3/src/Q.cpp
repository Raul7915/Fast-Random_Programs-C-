#include <iostream>
#include <cmath>
#include <unistd.h>

using namespace std;

// Funcția pentru a roti o gogoașă în jurul axei z
void rotateZ(double &x, double &y, double angle) {
  double x2 = x * cos(angle) - y * sin(angle);
  double y2 = x * sin(angle) + y * cos(angle);
  x = x2;
  y = y2;
}

int main() {
  // Definiți dimensiunile matricii
  const int ROWS = 7;
  const int COLUMNS = 7;

  // Definiți unghiul de rotație pentru gogoașă
  double angle = 0;

  // Definiți matricea pentru gogoașă
  char donut[ROWS][COLUMNS] = {' '};

  // Bucăți gogoașă în timp ce se rotește
  while (true) {
    // Populați matricea cu valorile pentru gogoașă
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        double x = i - 3;
        double y = j - 3;
        rotateZ(x, y, angle);
        if (sqrt(x * x + y * y) < 2.5) {
         donut[i][j] = '*';
        } else {
          donut[i][j] = ' ';
        }
      }
    }

    // Afișați matricea în consolă
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLUMNS; j++) {
        cout << donut[i][j] << " ";
      }
      cout << endl;
    }

    // Incrementați unghiul de rotație
    angle += M_PI / 24;

    // Așteptați 0,1 secunde înainte de a continua
    usleep(100000);
  }

  return 0;
}
