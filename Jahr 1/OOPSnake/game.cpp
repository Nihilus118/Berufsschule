#include <conio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "./fruit.cpp"
#include "./snake.cpp"

using namespace std;

class game {
   private:
    bool go;
    int screenX;
    int screenY;
    int score;
    int delayPerFrame;
    int highscore;
    char ground;
    char wall;
    snake sn;
    fruit fr;
    ofstream hsFile;
    ifstream hsFileIn;

   public:
    game(int x, int y, int dpF, char g, char w);
    ~game();
    void draw();
    void checkGameOver();
    void input();
    void play();
    void logic();
    void gameOverScreen();
};

game::game(int x, int y, int dpF, char g, char w) {
    go = false;
    screenX = x;
    screenY = y;
    score = 0;
    delayPerFrame = dpF;
    ground = g;
    wall = w;
    sn = snake(screenX, screenY, '0', 'o');
    fr = fruit(screenX, screenY, 'x');
    //Aktueller Highscore
    hsFileIn.open("highscores.txt");
    hsFileIn >> highscore;
    hsFileIn.close();
}

game::~game() {
}

void game::draw() {
    //Konsole leeren
    system("cls");

    //Debuginfos
    if (false) {
        cout << "Refreshrate: " << 1000 / delayPerFrame << "Hz - delayPerFrame: " << delayPerFrame << "ms" << endl;
        cout << "Spieler X: " << sn.getposX() << "  Spieler Y: " << sn.getposY() << endl;
        cout << "Frucht X: " << fr.getposX() << "  Frucht Y: " << fr.getposY() << endl;
        cout << "Laenge: " << sn.gettailLen() << endl;
    }

    //Highscore und Punktestand
    cout << endl
         << left << " Highscore: " << highscore << setw(screenX - 17) << right << "Score: " << score << endl
         << endl;

    //Rand und Spielflaeche
    for (int i = 0; i < screenY + 1; i++) {
        for (int j = 0; j < screenX + 1; j++) {
            //Raender der Spielflaeche zeichnen
            if (j == 0 || j == screenX || i == 0 || i == screenY) {  //Sind wir am Rand?
                //Wenn ja Abgrenzung
                cout << wall;
            }

            //Frucht
            else if (j == fr.getposX() && i == fr.getposY()) {
                cout << fr.getfruitLetter();
            }

            //Spieler
            else if (j == sn.getposX() && i == sn.getposY()) {
                cout << sn.gethead();
            }

            //Wenn nix zu zeichnen ist Spielflaeche
            else {
                bool print = false;
                for (int k = 0; k < sn.gettailLen(); k++) {  //ganzes Array nach aktuellen Koordinaten durchsuchen
                    if (sn.gettailX(k) == j && sn.gettailY(k) == i) {
                        //Falls Koordinaten gleich -> Koerperteil zeichnen
                        cout << sn.getbody();
                        print = true;
                    }
                }
                if (!print) {
                    cout << ground;
                }
            }
        }
        //In naechste Zeile
        cout << endl;
    }

    cout << endl
         << setw(screenX / 2) << left << " Control using the WASD-Keys!" << right << "    Press X to exit!" << endl;
}

void game::input() {
    if (_kbhit()) {  //Wird eine Taste gedrueckt?
        //Welche Taste wurde gedrueckt
        switch (_getch()) {
            case 'a':
                sn.setdir(LEFT);
                break;
            case 'd':
                sn.setdir(RIGHT);
                break;
            case 'w':
                sn.setdir(UP);
                break;
            case 's':
                sn.setdir(DOWN);
                break;
            case 'x':
                go = true;  //Spiel beenden
                break;
        }
    }
}

void game::checkGameOver() {
    if (sn.checkCollisions(screenX, screenY)) {
        go = true;
    }
}

void game::logic() {
    sn.move();
    //Prüfen ob Frucht
    if (sn.checkFruit(fr.getposX(), fr.getposY())) {
        score += 10;
        Beep(700, 20);
        fr.newFruit(screenX, screenY);
        sn.settailLen(sn.gettailLen() + 1);
    }
}

void game::gameOverScreen() {
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
             << "   ---  New Highscore!  ---" << endl
             << endl;
        Beep(700, 150);
        Beep(1200, 550);
        //HS-Datei oeffnen
        hsFile.open("highscores.txt");
        hsFile << score;
        //HS-Datei schließen
        hsFile.close();
    }
}

void game::play() {
    while (!go) {  //Solange NICHT gameOver
        input();
        logic();
        draw();
        checkGameOver();
        Sleep(delayPerFrame);
    }
    gameOverScreen();
}