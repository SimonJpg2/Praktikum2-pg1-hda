#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

int anzahlFestlegen() {
    int n = 0;
    std::cout << "Anzahl n eingeben:";
    std::cin >> n;
    std::cout << std::endl;

    if (n < 0) {
        std::cout << "Falsche Eingabe! Die Zahl darf nicht negativ sein." << std::endl;
        return 0;
    }
    return n;
}

double zahlenEingeben(int n, bool festgelegt) {
    if (!festgelegt) {
        std::cout << "Anzahl wurde noch nicht festgelegt." << std::endl;
        return 0;
    }

    double min = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << (i+1) << ". Zahl eingeben:";
        double temp = 0;
        std::cin >> temp;

        if (temp < 0) {
            std::cout << "Falsche Eingabe! Die Zahl darf nicht negativ sein." << std::endl;
            i--;
            continue;
        }

        if (i == 0) {
            min = temp;
        }

        if (temp < min) {
            min = temp;
        }
    }
    return min;
}

void aufgabe7() {
    char input = ' ';
    int anzahl = 0;
    double min = 0;
    bool anzahlFestgelegt = false;

    do {
        // Menü ausgeben
        std::cout << "\nMenu\n1 - Anzahl festlegen\n2 - Zahlen eingeben\n3 - Minimum anzeigen\nx - Beenden\n\n";
        std::cin >> input;
        std::cout << std::endl;

        switch (input) {
            case '1':
                anzahl = anzahlFestlegen();
                anzahlFestgelegt = true;
                break;
            case '2':
                min = zahlenEingeben(anzahl, anzahlFestgelegt);
                break;
            case '3':
                std::cout << "Minimum: " << min << std::endl;
                break;
            case 'x':
                std::cout << "Programm wurde beendet.\n\n";
                break;
            default:
                std::cout << "Ungültige Eingabe!\n\n";
        }

    } while (input != 'x');
}

void aufgabe8() {
    double a = 0;
    double y = 1;

    std::cout << "Beliebige Reelle Zahl als Startwert eingeben: ";
    std::cin >> a;

    double x = a;
    while (x > y) {
        x = (x+y) / 2;
        y = a / x;
    }
    std::cout << "\n\nQuadratwurzel von " << a << " ergibt " << x << std::endl;
}

void aufgabe9() {
    int valueX[2];
    int valueY[2];
    bool koordinatensystem[50][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 50; j++) {
            koordinatensystem[j][i] = false;
        }
    }

    std::cout << "Nachfolgend die Koordinaten x aus [1...50] und y aus [1...9] angeben. " << std::endl;
    for (int i = 0; i < 2; i++) {
        int x,y;

        std::cout << (i+1) << ". Eingabe (x, y): ";
        std::cin >> x >> y;

        if (x < 1 || x > 50 || y < 1 || y > 9) {
            std::cout << "Falsche Eingabe!" << std::endl;
            i--;
            continue;
        }
        valueX[i] = x;
        valueY[i] = y;
        koordinatensystem[--x][--y] = true; // Wir zählen von 0..49 oder 0..8, die Eingabe von 1...50 oder 1...9
    }

    // Ausgabe Zeilen 9...1
    for (int i = 8; i >= 0; i--) {
        std::cout << (i+1) << "|";
        for (int j = 0; j < 50; j++) {
            if (koordinatensystem[j][i]) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // Ausgabe Zeile 0
    for (int i = 0; i <= 50; i++) {
        if (i == 0) {
            std::cout << "0|";
        } else if (i % 10 == 0) {
            std::cout << (i / 10);
        } else {
            std::cout << "-";
        }
    }
    std::cout << std::endl;

    //Abstand zwischen den beiden Punkten berechnen
    int x1 = valueX[0];
    int x2 = valueX[1];
    int y1 = valueY[0];
    int y2 = valueY[1];

    double temp = std::pow(y2 - y1, 2) + std::pow(x2 - x1, 2);
    double d = std::sqrt(temp);

    std::cout << std::endl << "Abstand zwischen den beiden Punkten: " << d << std::endl;
}

void aufgabe10() {
    char input = ' ';
    int arr[10];
    /*
     * currentPosition ist der aktuelle Index, an welchem ein neues Element hinzugefügt werden soll
     * value ist das eigentliche Element, das an der aktuellen Position eingefügt werden soll
     * Elements ist die Anzahl der aktuellen Elemente in dem Feld
    */
    int currentPosition = 0, value = 0, elements = 0;

    do {
        // Menü auf der Konsole ausgeben
        std::cout << "Menu\n"
                  << "i/I - Eingabe eines neuen Wertes\n"
                  << "s/S - Anzahl belegter Felder ausgeben\n"
                  << "o/O - Alle belegten Felder ausgeben\n"
                  << "d/D - Erstes Element loeschen und rest nach links verschieben\n"
                  << "q/Q - Beenden"
                  << std::endl;
        std::cout << std::endl;
        std::cin >> input; // Auswahl durch User

        switch(input) {
            // Neues Element einfügen
            case 'i':
            case 'I':
                std::cout << "Neuen Wert eingeben: ";
                std::cin >> value;

                // Abbruchbedingung, wenn Index out of bounds
                if (currentPosition > 9) {
                    std::cout << "Die groesse des Feldes wurde ueberschritten. Abbruch." << std::endl;
                    break;
                }

                arr[currentPosition] = value; // Einfügen des Elements
                currentPosition++;
                elements++;
                break;

            // Anzahl belegter Felder ausgeben
            case 's':
            case 'S':
                std::cout << "Anzahl belegter Felder: " << elements << std::endl;
                break;

            // Alle belegten Felder ausgeben
            case 'o':
            case 'O':
                if (elements == 0) {
                    std::cout << "Das Feld beinhaltet keine Elemente, die ausgegeben werden können" << std::endl;
                    break;
                }

                std::cout << "Alle belegten Felder: " << std::endl;
                for (int i = 0; i < elements; i++) {
                    std::cout << (i + 1) << ". Element: " << arr[i] << std::endl;
                }
                break;

            // Element löschen und andere Elemente nach links verschieben
            case 'd':
            case 'D':
                if (elements == 0) {
                    std::cout << "Das Feld beinhaltet keine Werte, die geloescht werden koennen." << std::endl;
                    break;
                }

                // Elemente im Array um eine Position nach links verschieben
                for (int i = 0; i < currentPosition - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                arr[currentPosition] = 0; // Wert des letzten Elements "löschen"
                currentPosition--;
                elements--;
                break;

            // Programm beenden
            case 'q':
            case 'Q':
                std::cout << "Programm beendet." << std::endl;
                return;

            default:
                std::cout << "Fehlerhafte Eingabe! Bitte versuchen Sie es erneut.\n" << std::endl;
        }

    } while(input != 'q' || input != 'Q');
}

void aufgabe11() {
    std::vector<int> vec;
    int temp = 0;
    std::cout << "Beliebige Reihenfolge von Elementen eingeben:" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << (i + 1) << ". Element: ";
        std::cin >> temp;
        std::cout << std::endl;

        vec.push_back(temp);
    }
    std::cout << (std::is_sorted(vec.begin(), vec.end()) ? "Vektor ist sortiert" : "Vektor ist nicht sortiert") << std::endl;
}

int main() {
    //aufgabe7();
    //aufgabe8();
    //aufgabe9();
    //aufgabe10();
    aufgabe11();
    return 0;
}
