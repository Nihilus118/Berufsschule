#include <iostream>

using namespace std;

enum eDirection { STOP = 0,
                  LEFT,
                  RIGHT,
                  UP,
                  DOWN };

class snake {
   private:
    int posX;
    int posY;
    int tailLen;
    int tailX[100];
    int tailY[100];
    eDirection dir;
    char head;
    char body;

   public:
    //Methoden
    snake(){};
    snake(int screenX, int screenY, char h, char b);
    ~snake();
    bool checkCollisions(int screenX, int screenY);
    bool checkFruit(int fruitX, int fruitY);
    void move();
    //Getter
    int getposX() {
        return posX;
    }
    int getposY() {
        return posY;
    }
    int gettailLen() {
        return tailLen;
    }
    int gettailX(int pos) {
        return tailX[pos];
    }
    int gettailY(int pos) {
        return tailY[pos];
    }
    eDirection getdir() {
        return dir;
    }
    char gethead() {
        return head;
    }
    char getbody() {
        return body;
    }
    //Setter
    void setposX(int n) {
        posX = n;
    }
    void setposY(int n) {
        posY = n;
    }
    void settailLen(int n) {
        tailLen = n;
    }
    void settailX(int pos, int n) {
        tailX[pos] = n;
    }
    void settailY(int pos, int n) {
        tailY[pos] = n;
    }
    void setdir(eDirection n) {
        dir = n;
    }
};

snake::snake(int screenX, int screenY, char h, char b) {
    //Standartwerte setzen
    posX = screenX / 2;
    posY = screenY / 2;
    tailX[100] = {};
    tailY[100] = {};
    head = h;
    body = b;
    dir = STOP;
    tailLen = 0;
}

snake::~snake() {
}

bool snake::checkCollisions(int screenX, int screenY) {
    //Trifft der Spieler die Wand
    if (posX == 0 || posX == screenX || posY == 0 || posY == screenY) {
        return true;
    }

    //Trifft der Spieler sich selbst?
    for (int i = 0; i < tailLen; i++) {
        if (tailX[i] == posX && tailY[i] == posY) {  //Kopf trifft irgendein Koerperteil
            return true;
        }
    }

    return false;
}

bool snake::checkFruit(int fruitX, int fruitY) {
    //Trifft der Spieler die Frucht?
    if (posX == fruitX && posY == fruitY) {
        return true;
    }

    return false;
}

void snake::move() {
    //Alle teile in neue Richtung bewegen
    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = posX;
    tailY[0] = posY;

    for (int i = 1; i < tailLen; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {  //In welche Richtung gehen wir?
        case LEFT:
            posX--;
            break;
        case RIGHT:
            posX++;
            break;
        case UP:
            posY--;
            break;
        case DOWN:
            posY++;
            break;
        default:
            break;
    }
}