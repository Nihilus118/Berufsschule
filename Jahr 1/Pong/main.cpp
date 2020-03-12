#include <iostream>
#include <iomanip>
#include <windows.h> //Sleep Beep
#include <cstdlib> //Zufallszahlen
#include <time.h> //Zeit
using namespace std;

//Variablen
bool gameOver;
const int width = 60, height = 13, goal = 3; //Format Spiel
int frametime, x1 = 3, y1, x2 = 3, y2, xBall, yBall, speedBall = 1, score[2]; //Position Spieler, Früchte, Punktestand und Frametime
enum plDir { STOP = 0, UP = 1, DOWN = 2 }; //Alle moeglichen Richtungen fuer Spieler
enum bDir {LEFT = false, RIGHT = true }; 
plDir dir1; //Variable die einen der vordefinierten Werte enthaelt
plDir dir2;
bDir dirBall;

//Strings für GameObjects
string Border = "*", Player1 = "|", Player2 = "|", Ball = "O", Ground = " ";

void gameOverScreen(){
	//Game Over Screen
	system("cls");
	int winner;
	
	if(score[0] > score[1]){ //Player1
		winner = 1;
	}
	else{ //Player2
		winner = 2;
	}
	cout << fixed << left << endl <<
	"   XXXXXXXXXXXXXXXXXXXXXXX" << endl <<
	"   X                     X" << endl <<
	"   X    PLAYER " << winner << " WON!    X" << endl <<
	"   X                     X" << endl <<
	"   X    SCORE " << score[0] << " - " << score[1] << "      X" << endl <<
	"   X                     X" << endl <<
	"   XXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;
	Sleep(1500);
}

spawnBall(){
	//Ball in der Mitte
	xBall = width / 2;
	yBall = height / 2;
	
	//Start in zufaellige Richtung
	time_t sec;
	time(&sec);
	srand(sec);
	if(rand() % 2 == 0){
		dirBall = LEFT;
	}
	else {
		dirBall = RIGHT;
	}
}

void Setup(){ //Startwerte
	frametime = 55;
	gameOver = false;
	score[0] = 0;
	score[1] = 0;
	dir1 = STOP;
	dir2 = STOP;
	
	//Start pos Spieler
	x1 = 3;
	x2 = width - 3;
	y1 = height / 2;
	y2 = height / 2;
	
	//Erster Ball
	spawnBall();
}

void Draw(){ //Einzelne Frames zeichnen
	//Konsole leeren
	system("cls");
	
	//Debuginfos
	if(false){
		cout << "Refreshrate: " << 1000 / frametime << "Hz - Frametime: " << frametime << "ms" << endl; // 1 s = 1000 ms; 1000 ms / 50 hz = 20ms -> 50hz Refreshrate
		cout << "Spieler1 X: " << x1 << "  Spieler1 Y: " << y1 << " Dir1: " << dir1 << endl;
		cout << "Spieler2 X: " << x2 << "  Spieler2 Y: " << y2 << " Dir2: " << dir2 << endl;
		cout << "Ball X: " << xBall << "  Ball Y: " << yBall << " DirBall: " << dirBall << endl;
	}

	//Punktestand
	cout << endl << left << " Player 1: " << score[0] << setw(width - 17) << right << "Player 2: " << score[1] << endl << endl;
	
	//Spielflaeche (width * height)
	for (int i = 0; i < height + 1; i++){
		for (int j = 0; j < width + 1; j++){
			//Raender der Spielflaeche zeichnen
			if (j == 0 || j == width || i == 0 || i == height){ //Sind wir am Rand?
				//Wenn ja Abgrenzung
				cout << Border;
			}
			
			//Ball
			else if (j == xBall && i == yBall){
				cout << Ball;
			}
			
			//Spieler 1
			else if (j == x1 && i == y1 || j == x1 && i == y1 + 1 || j == x1 && i == y1 - 1){
				cout << Player1;
			}
			
			//Spieler 1
			else if (j == x2 && i == y2 || j == x2 && i == y2 + 1 || j == x2 && i == y2 - 1){
				cout << Player2;
			}
			
			//Wenn nix zu zeichnen ist Spielflaeche
			else {
				cout << Ground;	
			}
		}
		//In naechste Zeile
		cout << endl;
	}
	
	cout << endl << setw(width - 15) << left << "Use the WS-Keys!" << right << "Use the OL-Keys!" << endl << endl;
}

void Input(){ //Steuerung

	//Player 1
	if((GetKeyState('W') & 0x100) != 0){
		dir1 = UP;
	}
	else if ((GetKeyState('S') & 0x100) != 0){
		dir1 = DOWN;
	}
	else{
		dir1 = STOP;
	}
	
	//Player 2
	if((GetKeyState('O') & 0x100) != 0){
		dir2 = UP;
	}
	else if ((GetKeyState('L') & 0x100) != 0){
		dir2 = DOWN;
	}
	else{
		dir2 = STOP;
	}
	
	//Restart
	if((GetKeyState('R') & 0x100) != 0){
		Setup();
	}
	
	//End game
	if((GetKeyState('X') & 0x100) != 0){
		gameOver = true;
	}
}

void Logic(){ //Input verarbeiten
	
	switch (dir1){ //In welche Richtung gehen wir?
		case UP:
			y1--;
			break;
		case DOWN:
			y1++;
			break;
		default:
			break;
	}
	
	switch (dir2){ //In welche Richtung gehen wir?
		case UP:
			y2--;
			break;
		case DOWN:
			y2++;
			break;
		default:
			break;
	}
	
	//Trifft ein Spieler den Ball?
	if ((x1 == xBall - 1 && y1 == yBall) || (x2 == xBall + 1 && y2 == yBall) || 
		(x1 == xBall - 1 && y1 + 1 == yBall) || (x2 == xBall + 1 && y2 + 1 == yBall) ||
		(x1 == xBall - 1 && y1 - 1 == yBall) || (x2 == xBall + 1 && y2 - 1 == yBall)){
		//x-Richtung umkehren
		if(dirBall == RIGHT){
			dirBall = LEFT;
		}
		else{
			dirBall = RIGHT;
		}
	}
	
	//Trifft Ball die Decke?
	if(yBall == 0 || yBall == height){
		//y-Richtung umkehren
		speedBall = -1 * speedBall;
	}
	
	//Trifft Ball die Wand?
	if(xBall == 0){
		score[1]++;
		Sleep(1000);
		spawnBall();
	}
	if(xBall == width){
		score[0]++;
		Sleep(1000);
		spawnBall();
	}
	
	//Ball bewegen
	if (dirBall == LEFT){
		xBall--;
	}
	else{
		xBall++;
	}
	yBall = yBall + speedBall;
}

//Main-Funktion
int main() {
	bool restart = true;
	while(restart){
		Setup();
		while(score[0] < goal && score[1] < goal && !gameOver){ //Solange nicht ein Spieler die Siegpunktzahl erreicht
			Input();
			Logic();
			Draw();
			Sleep(frametime);
		}
		gameOverScreen();
		
		string restartStr;
		cout << "Restart? y / n" << endl;
		cin >> restartStr;
		if (restartStr == "n"){
			restart = false;
		}
	}
	
	return 0;
}
