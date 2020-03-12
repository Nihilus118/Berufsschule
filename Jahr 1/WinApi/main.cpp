#include <windows.h>
#include <cassert>
#include <iostream>
#include <graphics.h>

// IDs fuer Steuerelemente
#define IDC_SELF_DESTROY_BUTTON 100
#define ID_NEW 101
#define ID_LOAD 102
#define ID_SAVE 103
#define ID_CLOSE 104

// Handles fuer Steuerelemten
HWND hEdit;
char buffer[1024];

//Funktion zum verarbeiten von Messages
LRESULT CALLBACK MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	switch(uMsg){
		case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_COMMAND: // Steuerelement wurde bedient
			if(LOWORD(wParam) == IDC_SELF_DESTROY_BUTTON){
				GetWindowText(hEdit,buffer,1024);
				std::cout << "Hallo " << buffer << std::endl;
			}
			else if (LOWORD(wParam) == ID_SAVE){
				char filename[1024]; // 1kb
				filename[0] = 0;
				OPENFILENAME saveDialog = {};
				saveDialog.lStructSize = sizeof(OPENFILENAME);
				saveDialog.lpstrFile = filename;
				saveDialog.nMaxFile = 1024;
				saveDialog.lpstrFilter = "Text-Dateien\0*.txt";
				saveDialog.nFilterIndex = 1;
				saveDialog.lpstrTitle = "Speichern";
				saveDialog.Flags = OFN_OVERWRITEPROMPT;
				saveDialog.lpstrDefExt = ".txt";
				if(GetSaveFileName(&saveDialog) != 0){
					std::cout << "Speicherpfad: " << filename << std::endl;
				}
			}
			else if (LOWORD(wParam) == ID_CLOSE){
				PostQuitMessage(0);
				return 0;
			}
	}
	
	// Standard Handler
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// Hauptfunktion
int main(){
	
	HINSTANCE hInstance = GetModuleHandle(0);
	HWND hWnd;
	WNDCLASS wc; // Window Klasse
	MSG msg;
	// Handles fuer Steuerelemente
	HWND hButton;
	// Handles fuer Menus
	HMENU hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu,"File");
	AppendMenu(hFileMenu,MF_STRING,ID_NEW,"New");
	AppendMenu(hFileMenu,MF_STRING,ID_LOAD,"Load");
	AppendMenu(hFileMenu,MF_STRING,ID_SAVE,"Save");
	AppendMenu(hFileMenu,MF_STRING,ID_CLOSE,"Close");
	
	wc = {}; // Alles auf NULL
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MessageHandler;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName = "WINAPITest";
	
	// Klasse Speicherplatz geben
	assert(RegisterClass(&wc));
	
	// Fenster erstellen
	hWnd = CreateWindow("WINAPITest","Titel",WS_OVERLAPPEDWINDOW | WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,1280,720,0,0,hInstance,0);
	hButton = CreateWindow("button","Klick mich!",WS_TABSTOP | WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,10,70,200,50,hWnd /*Fenster in dem Button angezeigt wird*/,(HMENU)IDC_SELF_DESTROY_BUTTON,hInstance,0);
	hEdit = CreateWindow("edit","Gib deinen Namen ein...",WS_TABSTOP | WS_CHILD | WS_BORDER | WS_VISIBLE,10,10,200,50,hWnd,0,0,0);
	
	SetMenu(hWnd, hMenu);
	
	std::cout << "Fenster geoeffnet!" << std::endl;
	
	bool running = true;
	
	while(running){
		while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){ //Alle Messages abfragen (PM_REMOVE -> Wenn verarbeitet loeschen)
			if(msg.message == WM_QUIT){
				running = false;
				std::cout << "Fenster wird geschlossen!" << std::endl;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//Alle Inputs erfasst -> Frames zeichnen
		
	}
}
