#include <windows.h>
#include "WindowsMessageMap.h"
#include <sstream>

// Inputs verarbeiten
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	static WindowsMessageMap mm;
	OutputDebugString( mm( msg,lParam,wParam).c_str() );
	
	switch( msg ) // msg enthaelt Input
	{
		case WM_CLOSE: //Fenster wird geschlossen
			PostQuitMessage( 0 );
			break;
		case WM_KEYDOWN: // Taste wird gedrueckt
			if ( wParam == 'F' )
			{
				SetWindowText( hWnd,"Paying Respect..." );
			}
			break;
		case WM_KEYUP: // Taste wird losgelassen
			if ( wParam == 'F' ){
				SetWindowText( hWnd,"GameEngine" );
			}
			break;
		case WM_CHAR: // Gedrueckte Taste erkennen und in Titel schreiben
			{
				static std::string title;
				title.push_back( (char)wParam ); // push_back -> an String anfuegen
				SetWindowText( hWnd,title.c_str() );
			}
			break;
		case WM_LBUTTONDOWN: // linke Maustaste gedrueckt
			{
				POINTS pt = MAKEPOINTS( lParam );
				std::ostringstream oss;
				oss << "(" << pt.x << "," << pt.y << ")";
				SetWindowText( hWnd, oss.str().c_str() );
			}
			break;
	}
	return DefWindowProc ( hWnd,msg,wParam,lParam );
}

int CALLBACK WinMain( // Ruft Window auf
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR 	  lpCmdLine,
	int 	  nCmdShow )
{
	const auto pClassName = "hw3dClass";
	// Klasse mit Werten fuer Window
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof( wc );
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIcon = nullptr;
	RegisterClassEx( &wc );
	
	// Window nach vorbild der Klasse erstellen
	HWND hWnd = CreateWindowEx(
		0,pClassName,
		"GameEngine",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 1280, 720,
		nullptr, nullptr, hInstance, nullptr
	);
	// Window anzeigen
	ShowWindow(hWnd, SW_SHOW);
	
	// Input pruefen
	MSG msg;
	BOOL gResult;
	while ( (gResult = GetMessage( &msg,nullptr,0,0 )) > 0){
		TranslateMessage( &msg );
		DispatchMessage ( &msg );
	}
	
	if ( gResult == -1 ){ // -1 -> Fehler -> Beenden
		return -1;
	}else{
		return msg.wParam;
	}
}
