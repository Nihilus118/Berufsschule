#include <iostream>
#include <iomanip>
#include <windows.h> //Sleep Beep
#include <cstdlib> //Zufallszahlen
#include <time.h> //Zeit
#include <conio.h> //Fuer Keyinputs
#include <fstream> //Fuer Highscore Datei
using namespace std;

//Variablen
bool gameOver, solidWalls;
const int width = 50, height = 20; //Format Spiel
int x, y, wallX, wallY, score, frametime, highscore; //Position Spieler, Früchte, Punktestand und Frametime
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN}; //Alle moeglichen Richtungen
eDirection dir; //Variable die einen der vordefinierten Werte enthaelt
ofstream hsFile;
ifstream hsFileIn;

//Strings für GameObjects
string Wall = "#", Player = "0", Ground = "_", Empty = " ";

void newWall(){ //Neue Wand mit Luecke
	
}

void gameOverScreen(){
	//Game Over Screen
	system("cls");
	cout << fixed << left << endl <<
	"   XXXXXXXXXXXXXXXXXXXXXXX" << endl <<
	"   X                     X" << endl <<
	"   X   !  GAME OVER  !   X" << endl <<
	"   X                     X" << endl <<
	"   XXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;
	Beep(330, 250);
	Beep(240, 600);
	cout << "   Your score: " << score << endl;
	
	if (score > highscore){
		Sleep(1500);
		cout << endl << "   ---  New Highscore!  ---" << endl;
		Beep(700,150);
		Beep(1200,550);
		//HS-Datei oeffnen
		hsFile.open("highscores.txt");
		hsFile << score;
		//HS-Datei schließen
		hsFile.close();
	}
}

void Setup(){ //Startwerte
	frametime = 50;
	score = 0;
	gameOver = false;
	dir = STOP;
	
	//Aktueller Highscore
	hsFileIn.open("highscores.txt");
	hsFileIn >> highscore;
	hsFileIn.close();
	
	//Start genau in der Mitte
	x = 6;
	y = height / 2;
	
	//Erste Wand
	newWall();
}

void Draw(){ //Einzelne Frames zeichnen
	//Konsole leeren
	system("cls");
	
	//Debuginfos
	if(true){
		cout << "Refreshrate: " << 1000 / frametime << "Hz - Frametime: " << frametime << "ms" << endl; // 1 s = 1000 ms; 1000 ms / 50 hz = 20ms -> 50hz Refreshrate
		cout << "Spieler X: " << x << "  Spieler Y: " << y << endl;
	}

	//Highscore und Punktestand
	cout << endl << left << " Highscore: " << highscore << setw(width - 17) << right << "Score: " << score << endl << endl;
	
	//Rand und Spielflaeche
	for (int i = 0; i < height + 1; i++){
		for (int j = 0; j < width + 1; j++){
			//Boden
			if (i == height){
				cout << Ground;
			}
			
			//Waende
			else if (false){
				cout << Wall;
			}
			
			//Spieler
			else if (j == x && i == y){
				cout << Player;
			}
			
			//Wenn nix zu zeichnen ist Spielflaeche
			else {
				cout << Empty;
			}
		}
		//In naechste Zeile
		cout << endl;
	}
}

void Input(){ //Steuerung
	if (_kbhit()){ //Wird eine Taste gedrueckt?
		//Welche Taste wurde gedrueckt
		switch(_getch()){
			case '32': // 32 = Leertaste
				dir = UP;
				break;
		}
	}
}

void Logic(){ //Spezielle Events
	//Trifft Spieler eine Wand
}

//Main-Funktion
int main() {
	Setup();
	
	while(!gameOver){ //Solange NICHT gameOver
		Input();
		Logic();
		Draw();
		Sleep(frametime);
	}
	
	gameOverScreen();
	
	return 0;
}
