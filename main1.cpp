#include <windows.h>
#include <stdio.h>

char NazwaKlasy[] = "Klasa Okienka";
MSG Komunikat;
HPEN BialePioro,CzarnePioro;
HWND hwnd;
POINT stary_punkt;
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );
HDC hdcOkno;
HWND P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14,P15,P16,P17,P18,P19,P20;
HWND S1,S2,S3,S4,S5,S6,S7;
int py1=548,py2=448,py3=348,py4=248,py5=148;
int px1=40,px2=1450,px3=40,px4=1450,px5=40;
bool otwarte3=false,otwarte1=false,otwarte2=false,otwarte4=false,otwarte5=false,zabezpieczenie=true;
int oczekujacy=0;
int oczekiwanie[50];
int test12=0;
int powrot=0,ck=0;
//Test
int ilosc=0;
class drzwi{
	public:
	bool zamkniete;
	void otworz_drzwi();
	void zamknij_drzwi();
	drzwi();
};

drzwi::drzwi(){
	zamkniete=true;
}
class kwadrat{
	public:
		RECT koordynaty;
	HWND classhwnd;
	HBITMAP hbmObraz;
	BITMAP bmInfo;
	HDC hdcNowy;
	int bleft,bright,uleft,uright;
	int start,finish,X,Y;
	bool respawn,winda1,koniec,move_right,move_up,move_down,move_left,przycisk,rysuj, cos1,cos2;
	void rys_up();
	void rys_down();
	void rys_right();
	void rys_left();
	void wejdz();
	void sprawdz();
	void sprawdz1();
	int lvl,kolejnosc;
	kwadrat();

};



kwadrat::kwadrat(){
respawn=true;
winda1=false;
koniec=false;

przycisk=false;

move_down=false;
move_up=false;
rysuj=true;
cos1=true;
cos2=true;
}
void kwadrat::wejdz(){
	


	HDC hdc = GetDC( hwnd );
	BitBlt( hdc, X, Y, bmInfo.bmWidth, bmInfo.bmHeight, hdcNowy, 0, 0, SRCCOPY );
X+=2;
ReleaseDC( hwnd, hdc );

}
void kwadrat::sprawdz(){
	if(X>500 and !otwarte5 and start==5 and koniec==false){
		move_right=false;
	}
	if(X>500 and !otwarte3 and start==3 and koniec==false){
		move_right=false;
	}
	if(X>500 and !otwarte1 and start==1 and koniec==false){
		move_right=false;
	}
	if(X<1000 and !otwarte4 and start==4 and koniec==false){
		move_left=false;
	}
	if(X<1000 and !otwarte2 and start==2 and koniec==false){
		move_left=false;
	}
}


void kwadrat::rys_right(){
	if(rysuj){
	
HDC hdc = GetDC( hwnd );
FillRect( hdc, & koordynaty,( HBRUSH ) GetStockObject( WHITE_BRUSH ) );
BitBlt( hdc, X, Y, bmInfo.bmWidth, bmInfo.bmHeight, hdcNowy, 0, 0, SRCCOPY );
X+=2;
if(X>1400){
	rysuj=false;
	SetRect( & koordynaty, X-2, Y, X+40+2, Y+40 );
	FillRect( hdc, & koordynaty,( HBRUSH ) GetStockObject( WHITE_BRUSH ) );
}
SetRect( & koordynaty, X-2, Y, X+40-2, Y+40 );
ReleaseDC( hwnd, hdc );
}
}

void kwadrat::rys_down(){
HDC hdc = GetDC( hwnd );
FillRect( hdc, & koordynaty,( HBRUSH ) GetStockObject( WHITE_BRUSH ) );
BitBlt( hdc, X, Y, bmInfo.bmWidth, bmInfo.bmHeight, hdcNowy, 0, 0, SRCCOPY );
Y++;
SetRect( & koordynaty, X, Y-2, X+40, Y+40-2 );
ReleaseDC( hwnd, hdc );
}
void kwadrat::rys_up(){
HDC hdc = GetDC( hwnd );
FillRect( hdc, & koordynaty,( HBRUSH ) GetStockObject( WHITE_BRUSH ) );
BitBlt( hdc, X, Y, bmInfo.bmWidth, bmInfo.bmHeight, hdcNowy, 0, 0, SRCCOPY );
Y--;
SetRect( & koordynaty, X, Y+2, X+40, Y+40+2 );
ReleaseDC( hwnd, hdc );
}
void kwadrat::rys_left(){
	if(rysuj){
	
HDC hdc = GetDC( hwnd );
FillRect( hdc, & koordynaty,( HBRUSH ) GetStockObject( WHITE_BRUSH ) );
BitBlt( hdc, X, Y, bmInfo.bmWidth, bmInfo.bmHeight, hdcNowy, 0, 0, SRCCOPY );
X-=2;
if(X<32){
	rysuj=false;
	SetRect( & koordynaty, X, Y, X+40+2, Y+40 );
	FillRect( hdc, & koordynaty,( HBRUSH ) GetStockObject( WHITE_BRUSH ) );
}
SetRect( & koordynaty, X+2, Y, X+40+2, Y+40 );
ReleaseDC( hwnd, hdc );
}
}
class winda{
	public:
	kwadrat P; 
	int PIETRO;
	winda();
	bool wolne,wmove;
	void rysuj_windeup();
	void rysuj_windedown();
	int wy1,wy2;
};
winda::winda(){
	PIETRO=1;
	wy1=600;
	wy2=500;
	wolne=true;
	wmove=true;
}
void winda::rysuj_windedown(){
	
MoveToEx( hdcOkno, 560, wy1, & stary_punkt );
LineTo( hdcOkno, 970, wy1 );
LineTo( hdcOkno, 970, wy2 );
LineTo( hdcOkno, 560, wy2 );
LineTo( hdcOkno, 560, wy1 );

wy1++;
wy2++;
SelectObject( hdcOkno, BialePioro );
MoveToEx( hdcOkno, 560, wy1-2, & stary_punkt );
LineTo( hdcOkno, 971, wy1-2 );
MoveToEx( hdcOkno, 560, wy1-102, & stary_punkt );
LineTo( hdcOkno, 971, wy1-102 );
SelectObject( hdcOkno, CzarnePioro );
}


void winda::rysuj_windeup(){

MoveToEx( hdcOkno, 560, wy1, & stary_punkt );
LineTo( hdcOkno, 970, wy1 );
LineTo( hdcOkno, 970, wy2 );
LineTo( hdcOkno, 560, wy2 );
LineTo( hdcOkno, 560, wy1 );

wy1--;
wy2--;
SelectObject( hdcOkno, BialePioro );
MoveToEx( hdcOkno, 560, wy1+2, & stary_punkt );
LineTo( hdcOkno, 971, wy1+2 );
MoveToEx( hdcOkno, 560, wy1-98, & stary_punkt );
LineTo( hdcOkno, 971, wy1-98 );
SelectObject( hdcOkno, CzarnePioro );

}


winda W;
class pietro{
	
};
const WORD ID_TIMER = 1;
kwadrat *K[5];
drzwi D[5];
//

void rysuj_wszystko(HWND hwnd,HDC hdcOkno,POINT stary_punkt);
void zamknij_drzwi5(HWND hwnd,HDC hdcOkno,POINT stary_punkt);
void otworz_drzwi5(HWND hwnd,HDC hdcOkno,POINT stary_punkt);

void zamknij_drzwi4(HWND hwnd,HDC hdcOkno,POINT stary_punkt);
void otworz_drzwi4(HWND hwnd,HDC hdcOkno,POINT stary_punkt);

void zamknij_drzwi3(HWND hwnd,HDC hdcOkno,POINT stary_punkt);
void otworz_drzwi3(HWND hwnd,HDC hdcOkno,POINT stary_punkt);

void zamknij_drzwi2(HWND hwnd,HDC hdcOkno,POINT stary_punkt);
void otworz_drzwi2(HWND hwnd,HDC hdcOkno,POINT stary_punkt);

void zamknij_drzwi1(HWND hwnd,HDC hdcOkno,POINT stary_punkt);
void otworz_drzwi1(HWND hwnd,HDC hdcOkno,POINT stary_punkt);

void sprawdz(int k);
void sprawdz2(int k);

bool otwarcie(HWND hwnd,HDC hdcOkno,POINT stary_punkt,int x,int y,bool mover,bool movel,bool kon,bool cos );
bool zamkniecie(HWND hwnd,HDC hdcOkno,POINT stary_punkt,int x,int y,bool mover,bool movel,bool kon,bool cos,bool cos2 );
void wypelnij(){
	for(int i=0;i<50;i++){
		oczekiwanie[i]=0;
	}
}


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    WNDCLASSEX wc;
   
    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );

    if( !RegisterClassEx( &wc )){
        MessageBox( NULL, "okno nie stworzone", "Popraw",
        MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }
   
    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "okno", WS_OVERLAPPEDWINDOW | WS_MAXIMIZE,
    CW_USEDEFAULT, CW_USEDEFAULT, 240, 120, NULL, NULL, hInstance, NULL );
    ShowWindow( hwnd, nCmdShow ); 
    UpdateWindow( hwnd );
    wypelnij();
    //Test
    
    
   
    
    
    
    																					//TIMER
    
		if( SetTimer( hwnd, ID_TIMER, 1, NULL ) == 0 )
     MessageBox( hwnd, "Nie stworzono", "unlucky", MB_ICONSTOP );
	
    //
    
    BialePioro = CreatePen( PS_SOLID, 1, 0xFFFFFF );
    CzarnePioro = CreatePen( PS_SOLID, 1, 0x000000 );
    if( hwnd == NULL ){
        MessageBox( NULL, "nie stworzono", "Unlucky", MB_ICONEXCLAMATION );
        return 1;
    }
	
	//Winda
   	hdcOkno = GetDC( hwnd );
	rysuj_wszystko(hwnd,hdcOkno,stary_punkt);
	//Przyciski pietro 5
P1 = CreateWindowEx( 0, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
0, 160, 30, 40, hwnd, NULL, hInstance, NULL );
P2 = CreateWindowEx( 0, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
0, 120, 30, 40, hwnd, NULL, hInstance, NULL );
P3 = CreateWindowEx( 0, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
0, 80, 30, 40, hwnd, NULL, hInstance, NULL );
P4 = CreateWindowEx( 0, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
0, 40, 30, 40, hwnd, NULL, hInstance, NULL );
//Przycikis pietro 3
P5 = CreateWindowEx( 0, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
0, 360, 30, 40, hwnd, NULL, hInstance, NULL );
P6 = CreateWindowEx( 0, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
0, 320, 30, 40, hwnd, NULL, hInstance, NULL );
P7 = CreateWindowEx( 0, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
0, 240, 30, 40, hwnd, NULL, hInstance, NULL );
P8 = CreateWindowEx( 0, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
0, 200, 30, 40, hwnd, NULL, hInstance, NULL );
//Przycikis pietro 1
P9 = CreateWindowEx( 0, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
0, 520, 30, 40, hwnd, NULL, hInstance, NULL );
P10 = CreateWindowEx( 0, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
0, 480, 30, 40, hwnd, NULL, hInstance, NULL );
P11 = CreateWindowEx( 0, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
0, 440, 30, 40, hwnd, NULL, hInstance, NULL );
P12 = CreateWindowEx( 0, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
0, 400, 30, 40, hwnd, NULL, hInstance, NULL );
//Przyciski pietro 4
P13 = CreateWindowEx( 0, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
1500, 260, 30, 40, hwnd, NULL, hInstance, NULL );
P14 = CreateWindowEx( 0, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
1500, 220, 30, 40, hwnd, NULL, hInstance, NULL );
P15 = CreateWindowEx( 0, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
1500, 180, 30, 40, hwnd, NULL, hInstance, NULL );
P16 = CreateWindowEx( 0, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
1500, 100, 30, 40, hwnd, NULL, hInstance, NULL );
//Przyciski pietro 2
P17 = CreateWindowEx( 0, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
1500, 460, 30, 40, hwnd, NULL, hInstance, NULL );
P18 = CreateWindowEx( 0, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
1500, 380, 30, 40, hwnd, NULL, hInstance, NULL );
P19 = CreateWindowEx( 0, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
1500, 340, 30, 40, hwnd, NULL, hInstance, NULL );
P20 = CreateWindowEx( 0, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
1500, 300, 30, 40, hwnd, NULL, hInstance, NULL );
//Oznaczenia pieter	
S5= CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE,535,50, 10, 15, hwnd, NULL, hInstance, NULL );
SetWindowText( S5, "5" );
S4= CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE,990,150,10, 15, hwnd, NULL, hInstance, NULL );
SetWindowText( S4, "4" );
S3= CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE,535,250, 10, 15, hwnd, NULL, hInstance, NULL );
SetWindowText( S3, "3" );
S2= CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE,990,350, 10, 15, hwnd, NULL, hInstance, NULL );
SetWindowText( S2, "2" );
S1= CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE,535,450, 10, 15, hwnd, NULL, hInstance, NULL );
SetWindowText( S1, "1" );
    

    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }
    return Komunikat.wParam;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
    	
    case WM_COMMAND:
                           																										//PRZYCISKI
    	if(( HWND ) lParam == P1 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=5;
    	K[ilosc]->finish=1;
    	K[ilosc]->X=px5;
    	K[ilosc]->Y=py5;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px5-2, 108, px5+40-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
		if(( HWND ) lParam == P2 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=5;
    	K[ilosc]->finish=2;
    	K[ilosc]->X=px5;
    	K[ilosc]->Y=py5;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px5-2, 108, px5+40-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
		if(( HWND ) lParam == P3 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=5;
    	K[ilosc]->finish=3;
    	K[ilosc]->X=px5;
    	K[ilosc]->Y=py5;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px5-2, 108, px5+40-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
		if(( HWND ) lParam == P4 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=5;
    	K[ilosc]->finish=4;
    	K[ilosc]->X=px5;
    	K[ilosc]->Y=py5;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px5-2, 108, px5+40-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
		if(( HWND ) lParam == P5 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=3;
    	K[ilosc]->finish=1;
    	K[ilosc]->X=px3;
    	K[ilosc]->Y=py3;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px3-2, 108, 80-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
		oczekujacy++;
	}
		if(( HWND ) lParam == P6 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=3;
    	K[ilosc]->finish=2;
    	K[ilosc]->X=px3;
    	K[ilosc]->Y=py3;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px3-2, 108, 80-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
		oczekujacy++;
	}
		if(( HWND ) lParam == P7 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=3;
    	K[ilosc]->finish=4;
    	K[ilosc]->X=px3;
    	K[ilosc]->Y=py3;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px3-2, 108, 80-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
		if(( HWND ) lParam == P8 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=3;
    	K[ilosc]->finish=5;
    	K[ilosc]->X=px3;
    	K[ilosc]->Y=py3;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px3-2, 108, 80-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;		
	}
	if(( HWND ) lParam == P9 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=1;
    	K[ilosc]->finish=2;
    	K[ilosc]->X=px1;
    	K[ilosc]->Y=py1;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px1-2, 108, 80-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
	if(( HWND ) lParam == P10 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=1;
    	K[ilosc]->finish=3;
    	K[ilosc]->X=px1;
    	K[ilosc]->Y=py1;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px1-2, 108, 80-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
	if(( HWND ) lParam == P11 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=1;
    	K[ilosc]->finish=4;
    	K[ilosc]->X=px1;
    	K[ilosc]->Y=py1;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px1-2, 108, 80-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
	if(( HWND ) lParam == P12 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=1;
    	K[ilosc]->finish=5;
    	K[ilosc]->X=px1;
    	K[ilosc]->Y=py1;
    	K[ilosc]->move_right=true;
    	SetRect( & K[ilosc]->koordynaty, px1-2, 108, 80-2, 148 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
		ilosc++;
	}
	if(( HWND ) lParam == P13 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=4;
    	K[ilosc]->finish=1;
    	K[ilosc]->X=px4;
    	K[ilosc]->Y=py4;
    	K[ilosc]->move_left=true;
    	SetRect( & K[ilosc]->koordynaty, px4-2, 208, px4+40-2, 248 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
    	oczekiwanie[0]=4;
		ilosc++;
		oczekujacy++;
	}
	if(( HWND ) lParam == P14 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=4;
    	K[ilosc]->finish=2;
    	K[ilosc]->X=px4;
    	K[ilosc]->Y=py4;
    	K[ilosc]->move_left=true;
    	SetRect( & K[ilosc]->koordynaty, px4-2, 208, px4+40-2, 248 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
    	oczekiwanie[0]=4;
		ilosc++;
		oczekujacy++;
	}
	
	if(( HWND ) lParam == P15 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=4;
    	K[ilosc]->finish=3;
    	K[ilosc]->X=px4;
    	K[ilosc]->Y=py4;
    	K[ilosc]->move_left=true;
    	SetRect( & K[ilosc]->koordynaty, px4-2, 208, px4+40-2, 248 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
    	oczekiwanie[0]=4;
		ilosc++;
		oczekujacy++;
	}
	if(( HWND ) lParam == P16 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=4;
    	K[ilosc]->finish=5;
    	K[ilosc]->X=px4;
    	K[ilosc]->Y=py4;
    	K[ilosc]->move_left=true;
    	SetRect( & K[ilosc]->koordynaty, px4-2, 208, px4+40-2, 248 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
    	oczekiwanie[0]=4;
		ilosc++;
		oczekujacy++;
	}
	if(( HWND ) lParam == P17 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=2;
    	K[ilosc]->finish=1;
    	K[ilosc]->X=px2;
    	K[ilosc]->Y=py2;
    	K[ilosc]->move_left=true;
    	SetRect( & K[ilosc]->koordynaty, px2-2, 408, px2+40-2, 448 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
    	oczekiwanie[0]=2;
		ilosc++;
		oczekujacy++;
	}
	if(( HWND ) lParam == P18 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=2;
    	K[ilosc]->finish=3;
    	K[ilosc]->X=px2;
    	K[ilosc]->Y=py2;
    	K[ilosc]->move_left=true;
    	SetRect( & K[ilosc]->koordynaty, px2-2, 408, px2+40-2, 448 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
    	oczekiwanie[0]=2;
		ilosc++;
		oczekujacy++;
	}
	if(( HWND ) lParam == P19 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=2;
    	K[ilosc]->finish=4;
    	K[ilosc]->X=px2;
    	K[ilosc]->Y=py2;
    	K[ilosc]->move_left=true;
    	SetRect( & K[ilosc]->koordynaty, px2-2, 408, px2+40-2, 448 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
    	oczekiwanie[0]=2;
		ilosc++;
		oczekujacy++;
	}
	if(( HWND ) lParam == P20 ){
    	K[ilosc]=new kwadrat; 
    	K[ilosc]->hbmObraz=( HBITMAP ) LoadImage( NULL, "k5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
    	HDC hdc=GetDC(hwnd);
    	K[ilosc]->hdcNowy=CreateCompatibleDC( hdc );
    	K[ilosc]->start=2;
    	K[ilosc]->finish=5;
    	K[ilosc]->X=px2;
    	K[ilosc]->Y=py2;
    	K[ilosc]->move_left=true;
    	SetRect( & K[ilosc]->koordynaty, px2-2, 408, px2+40-2, 448 );
    	SelectObject( K[ilosc]->hdcNowy, K[ilosc]->hbmObraz );
    	GetObject( K[ilosc]->hbmObraz, sizeof( K[ilosc]->bmInfo ), & K[ilosc]->bmInfo );
    	oczekiwanie[0]=2;
		ilosc++;
		oczekujacy++;
	}
	break;
	
																									//TIMER
    case WM_TIMER:
    powrot++;
    for(int k=0;k<ilosc;k++){
    	
    	
    	if( K[k]->start%2!=0 and K[k]->move_right==true and K[k]->rysuj==true ){
    		K[k]->rys_right();    	
    	}
    	
    	if(K[k]->start%2!=1 and K[k]->move_left and K[k]->rysuj==true ){
    		K[k]->rys_left();
    	}
    	ck=0;
    	for(int i=0;i<ilosc;i++){ 		
		if(K[i]->X>501 and K[i]->X<1000 and K[i]->koniec==true ){
		
			zabezpieczenie=false;
			ck++;
		}
		}
		if(ck==0){
			zabezpieczenie =true;
		}
		
    	if(K[k]->koniec==true and K[k]->finish%2==1){
    		K[k]->rys_left();
		}
		if(K[k]->koniec==true and K[k]->finish%2==0){
    		K[k]->rys_right();
		}
		
		if(K[k]->cos1==true and K[k]->koniec==true){
			if(otwarcie(hwnd,hdcOkno, stary_punkt,K[k]->X,K[k]->Y,K[k]->move_right,K[k]->move_left,K[k]->koniec,K[k]->cos1)){
			
			K[k]->cos1=false;
			}
		}
		if(K[k]->cos2==true and K[k]->koniec==true){
			if(zamkniecie(hwnd,hdcOkno, stary_punkt,K[k]->X,K[k]->Y,K[k]->move_right,K[k]->move_left,K[k]->koniec,K[k]->cos1,K[k]->cos2)){
			
			K[k]->cos2=false;
			}
		}
    	
    	if(K[k]->rysuj==true or !K[k]->koniec){
		powrot=0;
		}
    	K[k]->sprawdz();		
		if( K[k]->koniec==false and zabezpieczenie){
		
				
    	if(K[k]->move_right==false and K[k]->move_left==false){
    		if(W.PIETRO<K[k]->start){
    			test12=K[k]->start-W.PIETRO;
    			
    			for(int h=0;h<test12*100;h++){
    				W.rysuj_windeup();
    				Sleep(1);
				}
				W.PIETRO=K[k]->start;
				
				if(K[k]->move_right==false and !otwarte5 and K[k]->start==5){
					otworz_drzwi5(hwnd,hdcOkno, stary_punkt);
					if(otwarte5){
						for(int i=0;i<35;i++){
							K[k]->rys_right();
							K[k]->winda1=true;
						}
						zamknij_drzwi5(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
				if(K[k]->move_left==false and !otwarte4 and K[k]->start==4){
					otworz_drzwi4(hwnd,hdcOkno, stary_punkt);
					if(otwarte4){
						for(int i=0;i<35;i++){
							K[k]->rys_left();
							K[k]->winda1=true;
						}
						zamknij_drzwi4(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
				if(K[k]->move_left==false and !otwarte2 and K[k]->start==2){
					otworz_drzwi2(hwnd,hdcOkno, stary_punkt);
					if(otwarte2){
						for(int i=0;i<35;i++){
							K[k]->rys_left();
							K[k]->winda1=true;
						}
						zamknij_drzwi2(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
				if(K[k]->move_right==false and !otwarte3 and K[k]->start==3){
					otworz_drzwi3(hwnd,hdcOkno, stary_punkt);
					if(otwarte3){
						for(int i=0;i<35;i++){
							K[k]->rys_right();
							K[k]->winda1=true;
						}
						zamknij_drzwi3(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
				
				
				
			}
			else{
				test12=W.PIETRO-K[k]->start;
				for(int h=0;h<test12*100;h++){
    				W.rysuj_windedown();
				}
				W.PIETRO=K[k]->start;
				if(K[k]->move_right==false and !otwarte5 and K[k]->start==5 and K[k]->koniec==false){
					otworz_drzwi5(hwnd,hdcOkno, stary_punkt);
					if(otwarte5){
						for(int i=0;i<35;i++){
							K[k]->rys_right();
							K[k]->winda1=true;
						}
						zamknij_drzwi5(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
				if(K[k]->move_left==false and !otwarte4 and K[k]->start==4 and K[k]->koniec==false){
					otworz_drzwi4(hwnd,hdcOkno, stary_punkt);
					if(otwarte4){
						for(int i=0;i<35;i++){
							K[k]->rys_left();
							K[k]->winda1=true;
						}
						zamknij_drzwi4(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
				if(K[k]->move_left==false and !otwarte2 and K[k]->start==2 and K[k]->koniec==false){
					otworz_drzwi2(hwnd,hdcOkno, stary_punkt);
					if(otwarte2){
						for(int i=0;i<35;i++){
							K[k]->rys_left();
							K[k]->winda1=true;
						}
						zamknij_drzwi2(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
				if(K[k]->move_right==false and !otwarte3 and K[k]->start==3 and K[k]->koniec==false){
					otworz_drzwi3(hwnd,hdcOkno, stary_punkt);
					if(otwarte3){
						for(int i=0;i<35;i++){
							K[k]->rys_right();
							Sleep(1);
						}
						K[k]->winda1=true;
						zamknij_drzwi3(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
				if(K[k]->move_right==false and !otwarte1 and K[k]->start==1 and K[k]->koniec==false){
					otworz_drzwi1(hwnd,hdcOkno, stary_punkt);
					if(otwarte1){
						for(int i=0;i<35;i++){
							K[k]->rys_right();
							Sleep(1);
						}
						K[k]->winda1=true;
						zamknij_drzwi1(hwnd,hdcOkno, stary_punkt);
						W.wolne=false;
					}
				}
			}
		}
		
		if(!W.wolne and !K[k]->koniec){
		if(K[k]->finish<W.PIETRO){
			test12=W.PIETRO-K[k]->finish;
			for(int i=0;i<test12*100;i++){
				W.rysuj_windedown();
				K[k]->rys_down();
				Sleep(1);
			}
			W.PIETRO=K[k]->finish;
		}
		else{
			test12=K[k]->finish-W.PIETRO;
			for(int i=0;i<test12*100;i++){
				W.rysuj_windeup();
				K[k]->rys_up();
				Sleep(1);
			}
			W.PIETRO=K[k]->finish;
			
		}
		}
		if(!W.wolne){
		
		if(K[k]->finish==W.PIETRO and K[k]->finish%2==1){
			K[k]->move_left=true;
			K[k]->koniec=true;
		
		}
		if(K[k]->finish==W.PIETRO and K[k]->finish%2==0){
			K[k]->move_right=true;
			K[k]->koniec=true;
			
		}
		W.wolne=true;
		
		}
		
		}
		
		
	
	}
	
	if(powrot>280 and W.PIETRO!=1){
		if(W.PIETRO==1){
			powrot=0;
		}
		
		if(W.PIETRO==5){
			for(int z=0;z<400;z++){
				W.rysuj_windedown();
				Sleep(5);
			}
			W.PIETRO=1;
		}
		if(W.PIETRO==4){
			for(int z=0;z<300;z++){
				W.rysuj_windedown();
				Sleep(5);
			}
			W.PIETRO=1;
		}
		if(W.PIETRO==3){
			for(int z=0;z<200;z++){
				W.rysuj_windedown();
				Sleep(5);
			}
			W.PIETRO=1;
		}
		if(W.PIETRO==2){
			for(int z=0;z<100;z++){
				W.rysuj_windedown();
				Sleep(5);
			}
			W.PIETRO=1;
		}
	}
	
	break;
    case WM_CLOSE:
        DestroyWindow( hwnd );
        break;
       
    case WM_DESTROY:
    	KillTimer( hwnd, ID_TIMER );
        PostQuitMessage( 0 );
        break;
       
        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }
   
    return 0;
}
//Rysowanie calego pomieszczenia
void rysuj_wszystko(HWND hwnd,HDC hdcOkno,POINT stary_punkt){
MoveToEx( hdcOkno, 0, 200, & stary_punkt );
LineTo( hdcOkno, 550, 200 );
MoveToEx( hdcOkno, 0, 201, & stary_punkt );
LineTo( hdcOkno, 550, 201 );

MoveToEx( hdcOkno, 0, 400, & stary_punkt );
LineTo( hdcOkno, 550, 400 );
MoveToEx( hdcOkno, 0, 401, & stary_punkt );
LineTo( hdcOkno, 550, 401 );

MoveToEx( hdcOkno, 0, 600, & stary_punkt );
LineTo( hdcOkno, 550, 600 );
MoveToEx( hdcOkno, 0, 601, & stary_punkt );
LineTo( hdcOkno, 550, 601 );

MoveToEx( hdcOkno, 1530, 500, & stary_punkt );
LineTo( hdcOkno, 980, 500 );
MoveToEx( hdcOkno, 1530, 501, & stary_punkt );
LineTo( hdcOkno, 980, 501 );

MoveToEx( hdcOkno, 1530, 300, & stary_punkt );
LineTo( hdcOkno, 980, 300 );
MoveToEx( hdcOkno, 1530, 301, & stary_punkt );
LineTo( hdcOkno, 980, 301 );

MoveToEx( hdcOkno, 550, 0, & stary_punkt );
LineTo( hdcOkno, 550, 1000 );
MoveToEx( hdcOkno, 549, 0, & stary_punkt );
LineTo( hdcOkno, 549, 1000 );

MoveToEx( hdcOkno, 980, 0, & stary_punkt );
LineTo( hdcOkno, 980, 1000 );
MoveToEx( hdcOkno, 981, 0, & stary_punkt );
LineTo( hdcOkno, 981, 1000 );

MoveToEx( hdcOkno, 560, 600, & stary_punkt );
LineTo( hdcOkno, 970, 600 );
LineTo( hdcOkno, 970, 500 );
LineTo( hdcOkno, 560, 500 );
LineTo( hdcOkno, 560, 600 );
}

void zamknij_drzwi5(HWND hwnd,HDC hdcOkno,POINT stary_punkt){	
	for(int i=110;i<201;i++){
	MoveToEx( hdcOkno, 550, i, & stary_punkt );
	LineTo(hdcOkno,550,i+1);
	MoveToEx( hdcOkno, 549, i, & stary_punkt );
	LineTo(hdcOkno,549,i+1);
	MoveToEx( hdcOkno, 560, i, & stary_punkt );
	LineTo(hdcOkno,560,i+1);
	Sleep(5);
}
otwarte5=false;
}

void otworz_drzwi5(HWND hwnd,HDC hdcOkno,POINT stary_punkt){
	SelectObject( hdcOkno, BialePioro );
	for(int i=200;i>110;i--){
	LineTo(hdcOkno,550,i);
	LineTo(hdcOkno,549,i);
	
	LineTo(hdcOkno,560,i);
	Sleep(5);
}
otwarte5=true;
SelectObject( hdcOkno, CzarnePioro );
}
void zamknij_drzwi4(HWND hwnd,HDC hdcOkno,POINT stary_punkt){

	for(int i=210;i<301;i++){
	MoveToEx( hdcOkno, 980, i, & stary_punkt );
	LineTo(hdcOkno,980,i+1);
	MoveToEx( hdcOkno, 981, i, & stary_punkt );
	LineTo(hdcOkno,981,i+1);
	MoveToEx( hdcOkno, 970, i, & stary_punkt );
	LineTo(hdcOkno,970,i+1);
	Sleep(5);
}
otwarte4=false;
}

void otworz_drzwi4(HWND hwnd,HDC hdcOkno,POINT stary_punkt){
	SelectObject( hdcOkno, BialePioro );
	for(int i=300;i>210;i--){
	LineTo(hdcOkno,980,i);
	LineTo(hdcOkno,981,i);
	
	LineTo(hdcOkno,970,i);
	Sleep(5);
}
otwarte4=true;
SelectObject( hdcOkno, CzarnePioro );
}

void zamknij_drzwi3(HWND hwnd,HDC hdcOkno,POINT stary_punkt){	

	for(int i=310;i<401;i++){
	MoveToEx( hdcOkno, 550, i, & stary_punkt );
	LineTo(hdcOkno,550,i+1);
	MoveToEx( hdcOkno, 549, i, & stary_punkt );
	LineTo(hdcOkno,549,i+1);
	MoveToEx( hdcOkno, 560, i, & stary_punkt );
	LineTo(hdcOkno,560,i+1);
	Sleep(5);
}
otwarte3=false;
}

void otworz_drzwi3(HWND hwnd,HDC hdcOkno,POINT stary_punkt){
	SelectObject( hdcOkno, BialePioro );
	for(int i=400;i>310;i--){
		
	LineTo(hdcOkno,550,i);
	LineTo(hdcOkno,549,i);
	
	LineTo(hdcOkno,560,i);
	Sleep(5);
}
otwarte3=true;
SelectObject( hdcOkno, CzarnePioro );
}

void zamknij_drzwi2(HWND hwnd,HDC hdcOkno,POINT stary_punkt){	
	for(int i=410;i<501;i++){
MoveToEx( hdcOkno, 980, i, & stary_punkt );
	LineTo(hdcOkno,980,i+1);
	MoveToEx( hdcOkno, 981, i, & stary_punkt );
	LineTo(hdcOkno,981,i+1);
	MoveToEx( hdcOkno, 970, i, & stary_punkt );
	LineTo(hdcOkno,970,i+1);
	Sleep(5);
}
otwarte2=false;
}

void otworz_drzwi2(HWND hwnd,HDC hdcOkno,POINT stary_punkt){
	SelectObject( hdcOkno, BialePioro );
	for(int i=500;i>410;i--){
		
	LineTo(hdcOkno,980,i);
	LineTo(hdcOkno,981,i);
	
	LineTo(hdcOkno,970,i);
	Sleep(5);
}
otwarte2=true;
SelectObject( hdcOkno, CzarnePioro );
}

void zamknij_drzwi1(HWND hwnd,HDC hdcOkno,POINT stary_punkt){	
	for(int i=510;i<601;i++){
	MoveToEx( hdcOkno, 550, i, & stary_punkt );
	LineTo(hdcOkno,550,i+1);
	MoveToEx( hdcOkno, 549, i, & stary_punkt );
	LineTo(hdcOkno,549,i+1);
	MoveToEx( hdcOkno, 560, i, & stary_punkt );
	LineTo(hdcOkno,560,i+1);
	Sleep(5);
}
otwarte1=false;
}

void otworz_drzwi1(HWND hwnd,HDC hdcOkno,POINT stary_punkt){
	SelectObject( hdcOkno, BialePioro );
	for(int i=600;i>510;i--){
	
	LineTo(hdcOkno,550,i);
	LineTo(hdcOkno,549,i);
	
	LineTo(hdcOkno,560,i);
	Sleep(5);
}
otwarte1=true;
SelectObject( hdcOkno, CzarnePioro );
}

bool otwarcie(HWND hwnd,HDC hdcOkno,POINT stary_punkt,int x,int y,bool mover,bool movel,bool kon,bool cos ){
	
	if(cos){
		
	
	if(mover==true and kon==true and x>921){
	SelectObject( hdcOkno, BialePioro );
	
	for(int i=y+50+1;i>y-40+1;i--){
	
	LineTo(hdcOkno,980,i);
	LineTo(hdcOkno,981,i);
	
	LineTo(hdcOkno,970,i);
	Sleep(5);
	}
	return true;
	}
	if(movel==true and kon==true and x<570  ){
	SelectObject( hdcOkno, BialePioro );
	MoveToEx( hdcOkno, x-20, y+50, & stary_punkt );
	for(int i=y+50+1;i>y-40+1;i--){
	
	LineTo(hdcOkno,550,i);
	LineTo(hdcOkno,549,i);
	
	LineTo(hdcOkno,560,i);
	Sleep(5);
	}
		return true;
	}
	
}
return false;
}

bool zamkniecie(HWND hwnd,HDC hdcOkno,POINT stary_punkt,int x,int y,bool mover,bool movel,bool kon,bool cos,bool cos2 ){
	
	if(cos==false and cos2){
		
	
	if(mover==true and kon==true and x>982){
	SelectObject( hdcOkno, CzarnePioro );
	
	for(int i=y-48;i<y+52;i++){
	MoveToEx( hdcOkno, 980, i, & stary_punkt );
	LineTo(hdcOkno,980,i+1);
	MoveToEx( hdcOkno, 981, i, & stary_punkt );
	LineTo(hdcOkno,981,i+1);
	MoveToEx( hdcOkno, 970, i, & stary_punkt );
	LineTo(hdcOkno,970,i+1);
	Sleep(5);
	}
	return true;
	}
	if(movel==true and kon==true and x<508  ){
	SelectObject( hdcOkno, CzarnePioro );

	for(int i=y-48;i<y+52;i++){
	
	MoveToEx( hdcOkno, 550, i, & stary_punkt );
	LineTo(hdcOkno,550,i+1);
	MoveToEx( hdcOkno, 549, i, & stary_punkt );
	LineTo(hdcOkno,549,i+1);
	MoveToEx( hdcOkno, 560, i, & stary_punkt );
	LineTo(hdcOkno,560,i+1);
	Sleep(5);
	}
		return true;
	}
	
}
return false;
}




