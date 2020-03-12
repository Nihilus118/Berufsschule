#include "./game.cpp"

using namespace std;

int main() {
    game Snake(50, 25, 0, ' ', '#');

    Snake.play();
}