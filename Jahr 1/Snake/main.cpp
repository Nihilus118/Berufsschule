#include <conio.h>    //Fuer Keyinputs
#include <time.h>     //Zeit
#include <windows.h>  //Sleep Beep
#include <cstdlib>    //Zufallszahlen
#include <fstream>    //Fuer Highscore Datei
#include <iomanip>
#include <iostream>
using namespace std;

//Variablen
bool gameOver, solidWalls;
const int width = 50, height = 20;                                                       //Format Spiel
int x, y, fruitX, fruitY, score, frametime, tailX[100], tailY[100], tailLen, highscore;  //Position Spieler, Fr�chte, Punktestand und Frametime
enum eDirection { STOP = 0,
                  LEFT,
                  RIGHT,
                  UP,
                  DOWN };  //Alle moeglichen Richtungen
eDirection dir;            //Variable die einen der vordefinierten Werte enthaelt
ofstream hsFile;
ifstream hsFileIn;

//Strings für GameObjects
string Border, Player = "0", PlayerBody = "o", Fruit = "+", Ground = " ";

void newFruit() {  //Neue Frucht
    time_t sec;
    time(&sec);
    srand(sec);
    fruitX = rand() % (width - 1) + 1;
    fruitY = rand() % (height - 1) + 1;
}

void gameOverScreen() {
    //Game Over Screen
    system("cls");
    cout << fixed << left << endl
         << "   XXXXXXXXXXXXXXXXXXXXXXX" << endl
         << "   X                     X" << endl
         << "   X   !  GAME OVER  !   X" << endl
         << "   X                     X" << endl
         << "   XXXXXXXXXXXXXXXXXXXXXXX" << endl
         << endl;
    Beep(330, 250);
    Beep(240, 600);
    cout << "   Your score: " << score << endl;

    if (score > highscore) {
        Sleep(1500);
        cout << endl
             << "   ---  New Highscore!  ---" << endl;
        Beep(700, 150);
        Beep(1200, 550);
        //HS-Datei oeffnen
        hsFile.open("highscores.txt");
        hsFile << score;
        //HS-Datei schlie�en
        hsFile.close();
    }
}

void Setup(bool walls) {  //Startwerte
    frametime = 25;
    score = 0;
    tailLen = 0;
    gameOver = false;
    solidWalls = walls;
    dir = STOP;

    //Aktueller Highscore
    hsFileIn.open("highscores.txt");
    hsFileIn >> highscore;
    hsFileIn.close();

    //Start genau in der Mitte
    x = width / 2;
    y = height / 2;

    //Erste Frucht
    newFruit();
}

void Draw() {  //Einzelne Frames zeichnen
    //Konsole leeren
    system("cls");

    //Debuginfos
    if (false) {
        cout << "Refreshrate: " << 1000 / frametime << "Hz - Frametime: " << frametime << "ms" << endl;  // 1 s = 1000 ms; 1000 ms / 50 hz = 20ms -> 50hz Refreshrate
        cout << "Spieler X: " << x << "  Spieler Y: " << y << endl;
        cout << "Frucht X: " << fruitX << "  Frucht Y: " << fruitY << endl;
        cout << "Laenge: " << tailLen << endl;
    }

    //Highscore und Punktestand
    cout << endl
         << left << " Highscore: " << highscore << setw(width - 17) << right << "Score: " << score << endl
         << endl;

    //Extra Wände falls man nicht durch sie durch kann
    if (solidWalls) {
        Border = "%";
    } else {
        Border = "#";
    }

    //Rand und Spielflaeche
    for (int i = 0; i < height + 1; i++) {
        for (int j = 0; j < width + 1; j++) {
            //Raender der Spielflaeche zeichnen
            if (j == 0 || j == width || i == 0 || i == height) {  //Sind wir am Rand?
                //Wenn ja Abgrenzung
                cout << Border;
            }

            //Frucht
            else if (j == fruitX && i == fruitY) {
                cout << Fruit;
            }

            //Spieler
            else if (j == x && i == y) {
                cout << Player;
            }

            //Wenn nix zu zeichnen ist Spielflaeche
            else {
                bool print = false;
                for (int k = 0; k < tailLen; k++) {  //ganzes Array nach aktuellen Koordinaten durchsuchen
                    if (tailX[k] == j && tailY[k] == i) {
                        //Falls Koordinaten gleich -> Koerperteil zeichnen
                        cout << PlayerBody;
                        print = true;
                    }
                }
                if (!print) {
                    cout << Ground;
                }
            }
        }
        //In naechste Zeile
        cout << endl;
    }

    cout << endl
         << setw(width / 2) << left << " Control using the WASD-Keys!" << right << "    Press X to exit!" << endl
         << setw(width / 2) << left << " Press U to change the Walls!" << right << "    Press R to restart!" << endl
         << endl;
}

void Input() {       //Steuerung
    if (_kbhit()) {  //Wird eine Taste gedrueckt?
        //Welche Taste wurde gedrueckt
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;  //Spiel beenden
                break;
            case 'r':  //Neustart
                Setup(solidWalls);
                break;
            case 'u':  //Neustart und Zustand der Waende aendern
                Setup(!solidWalls);
                break;
        }
    }
}

void Logic() {  //Spezielle Events
    //Schlangenschwanz
    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < tailLen; i++) {
        //Ringtausch um alte Positionen zu speichern
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {  //In welche Richtung gehen wir?
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    //Durch Waende gehen oder nicht?
    if (solidWalls) {
        //Spieler stirbt
        if (x == 0 || x == width || y == 0 || y == height) {
            gameOver = true;
        }
    } else {
        //Durch Waende gehen
        if (x >= width) {
            x = 1;
        } else if (x <= 0) {
            x = width - 1;
        }
        if (y >= height) {
            y = 1;
        } else if (y <= 0) {
            y = height - 1;
        }
    }

    //Trifft der Spieler sich selbst?
    for (int i = 0; i < tailLen; i++) {
        if (tailX[i] == x && tailY[i] == y) {  //Kopf trifft irgendein Koerperteil
            gameOver = true;
        }
    }

    //Trifft der Spieler die Frucht?
    if (x == fruitX && y == fruitY) {
        score += 10;
        Beep(700, 20);
        newFruit();
        tailLen++;
    }
}

//Main-Funktion
int main() {
    Setup(false);

    while (!gameOver) {  //Solange NICHT gameOver
        Input();
        Logic();
        Draw();
        Sleep(frametime);
    }

    gameOverScreen();

    return 0;
}
