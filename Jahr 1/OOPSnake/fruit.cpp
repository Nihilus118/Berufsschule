#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class fruit {
   private:
    int posX;
    int posY;
    char fruitLetter;

   public:
    fruit(){};
    fruit(int screenX, int screenY, char f);
    ~fruit();
    void newFruit(int screenX, int screenY);
    //Getter
    int getposX() {
        return posX;
    }
    int getposY() {
        return posY;
    }
    char getfruitLetter() {
        return fruitLetter;
    }
};

fruit::fruit(int screenX, int screenY, char f) {
    newFruit(screenX, screenY);
    fruitLetter = f;
}

fruit::~fruit() {
}

void fruit::newFruit(int screenX, int screenY) {
    time_t sec;
    time(&sec);
    srand(sec);
    posX = rand() % (screenX - 1) + 1;
    posY = rand() % (screenY - 1) + 1;
}
