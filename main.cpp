/*
Desenvolvido por:

Programado pro Fabio FJA, para fins de estudo e pesquisa em C/C++.
Codigo escrito em  C++ WIN32 API, IDE CodeBlocks 13.12
Edita o jogo Pro Evolution Soccer 1 psx
Compilador: GNU GCC Collection

Ano:2016
*/


#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <tchar.h>


#define BUTTON1	101			// Identificador do botão
#define BUTTON2	102			// Identificador do botão
#define BUTTON3	103			// Identificador do botão
#define BUTTON4	104			// Identificador do botão
#define BUTTON5	105			// Identificador do botão
#define BUTTON6	106			// Identificador do botão
#define BUTTON7	107			// Identificador do botão
#define BUTTON8	108			// Identificador do botão
#define BUTTON9	109			// Identificador do botão
#define BUTTON10	110	    // Identificador do botão
#define BUTTON11	115	    // Identificador do botão

#define IDC_MAIN_EDIT	111 // TextBox
#define txtbox 2

#define lb11  112
#define lb12  113
#define lb13  114
#define lb14  115
#define lb15  116
#define lb16  117
#define lb17  118
#define lb18  119
#define lb19  120
#define lb10  118
#define lb11  119
#define lb12  120

#define btn11 1
#define btn20 10
#define btn21 11
#define btn22 12
#define btn23 13
#define btn24 14
#define btn25 15
#define btn26 16
#define btn27 17
#define btn28 18
#define btn29 19
#define btn30 20
#define btn31 21
#define btn32 22
#define btn33 23
#define btn34 24
#define btn35 25
#define btn36 26
#define btn37 27

#define comb1 28


using namespace std;

char szFileName[MAX_PATH] = "";

HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);//declaraçao de fonte vale pra todos os buttons


LRESULT CALLBACK WinProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{

	WNDCLASSEX wClass;
	ZeroMemory(&wClass,sizeof(WNDCLASSEX));
	wClass.cbClsExtra=NULL;
	wClass.cbSize=sizeof(WNDCLASSEX);
	wClass.cbWndExtra=NULL;
	wClass.hbrBackground=(HBRUSH)COLOR_WINDOW;
	wClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wClass.hIcon=NULL;
	wClass.hIconSm=NULL;
	wClass.hInstance=hInst;
	wClass.lpfnWndProc=(WNDPROC)WinProc;
	wClass.lpszClassName="Window Class";
	wClass.lpszMenuName=NULL;
	wClass.style=CS_HREDRAW|CS_VREDRAW;

	if(!RegisterClassEx(&wClass))
	{
		int nResult=GetLastError();
		MessageBox(NULL,
			"Window class creation failed\r\n",
			"Window Class Failed",
			MB_ICONERROR);
	}

	HWND hWnd=CreateWindowEx(NULL,
			"Window Class",
			"Opções PES 1 v_BETA by fja" ,
			WS_OVERLAPPEDWINDOW,
			200,
			100,
			575,
			500,
			NULL,
			NULL,
			hInst,
			NULL);

	if(!hWnd)
	{
		int nResult=GetLastError();

		MessageBox(NULL,
			"Window creation failed\r\n",
			"Window Creation Failed",
			MB_ICONERROR);
	}

    ShowWindow(hWnd,nShowCmd);

	MSG msg;
	ZeroMemory(&msg,sizeof(MSG));

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


void loadbox()
{
//openfiledialog
    OPENFILENAME ofn ;
   // char szFileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
   // ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = "PES_1 (*.bin)\0*.bin\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "bin";

    if(GetOpenFileName(&ofn))
    {
        // nome do arquivo armazenado em  szFileName
      MessageBox(NULL, szFileName, "Pro Evolution Soccer 1 psx ", MB_OK | MB_ICONINFORMATION | MB_TOPMOST );

    }
}

//################################################################################################################
void  writeBox(int offset1,int valor1,int offset2,int valor2)
{
//escrever no arquivo
   std::ofstream f;
   f.open(szFileName,ios::binary | ios::in  );

   f.seekp(offset1);
   char a = valor1 ;
   f.put(a);

   f.seekp(offset2);
   char b = valor2 ;
   f.put(b);

   MessageBox(NULL, "Salvo com sucesso.","PES 1 EDITOR", MB_OK | MB_ICONINFORMATION | MB_TOPMOST  );

   f.close();

}

//################################################################################################################
void  desabilitado()
{
   MessageBox(NULL, "Não esta habilitado","PES 1 EDITOR", MB_OK | MB_ICONEXCLAMATION | MB_TOPMOST  );
}

void AlterarEstadoBotoes(HWND hWnd, const int* IDsBotoes, int numeroDeBotoes, bool habilitar) {
    for (int i = 0; i < numeroDeBotoes; ++i) {
        EnableWindow(GetDlgItem(hWnd, IDsBotoes[i]), habilitar);
    }
}

// Array com os IDs dos botões a serem habilitados/desabilitados
const int botoesParaAlterar[] = { BUTTON2, BUTTON3, BUTTON4, BUTTON5, BUTTON6, BUTTON7, BUTTON8, BUTTON9, BUTTON10,
                                  btn11, btn20, btn21, btn22, btn23, btn24, btn25, btn26, btn27, btn28,
                                  btn29, btn30, btn31, btn32, btn33, btn34, btn35, btn36, btn37, comb1 };
// Número total de botões no array
const int numeroDeBotoesParaAlterar = sizeof(botoesParaAlterar) / sizeof(botoesParaAlterar[0]);



LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam )
{

	switch(msg)
	{

        break;

		case WM_CREATE:
		{

		    //Criar textbox
             HWND hEdit=CreateWindowEx(WS_EX_CLIENTEDGE,
				"EDIT",
				"",
				WS_CHILD|WS_VISIBLE|
				ES_MULTILINE|ES_AUTOVSCROLL|ES_AUTOHSCROLL,
				//142,
				//30,
				//519,
				//25,
				20,
				420,
				520,
				20,
				hWnd,
				(HMENU)IDC_MAIN_EDIT,
				GetModuleHandle(NULL),
				NULL);
               // hfDefault=GetStockObject(DEFAULT_GUI_FONT);//declaraçao de fonte vale pra todos os buttons
			SendMessage(hEdit,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));
			SendMessage(hEdit,
				WM_SETTEXT,
				NULL,
				(LPARAM)"Offsets >>>    Iori8421 - Tepman - Polipoli - Fabio FJA ");//detectando o filename

// objetos sem indentanção para ser mais rápido de programar e fácil compreensão
HWND label1 = CreateWindowEx(NULL,"STATIC","Velocidade :" ,WS_CHILD|WS_VISIBLE,20,100,150,20,hWnd,(HMENU)lb11,0,0);//Cria label
HWND label2 = CreateWindowEx(NULL,"STATIC","Master liga dinheiro / contratações :" ,WS_CHILD|WS_VISIBLE,200,100,400,50,hWnd,(HMENU)lb12,0,0);//Cria label
//HWND label3 = CreateWindowEx(NULL,"STATIC","Master liga contrataçoes :" ,WS_CHILD|WS_VISIBLE,387,100,450,50,hWnd,(HMENU)lb13,0,0);//Cria label

HWND label4 = CreateWindowEx(NULL,"STATIC","Copa :" ,WS_CHILD|WS_VISIBLE,20, 269,150, 20,hWnd,(HMENU)lb14,0,0);//Cria label
HWND label5 = CreateWindowEx(NULL,"STATIC","" ,WS_CHILD|WS_VISIBLE,20, 299,150, 20,hWnd,(HMENU)lb15,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(label5,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria label
HWND label6 = CreateWindowEx(NULL,"STATIC","" ,WS_CHILD|WS_VISIBLE,102, 299,150, 20,hWnd,(HMENU)lb16,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(label6,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria label

HWND label7 = CreateWindowEx(NULL,"STATIC","Liga :" ,WS_CHILD|WS_VISIBLE,201, 269,150, 20,hWnd,(HMENU)lb17,0,0);//Cria label
HWND label8 = CreateWindowEx(NULL,"STATIC","Tempo" ,WS_CHILD|WS_VISIBLE,201, 299,150, 20,hWnd,(HMENU)lb18,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(label8,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria label
HWND label9 = CreateWindowEx(NULL,"STATIC","Dificuldade" ,WS_CHILD|WS_VISIBLE,284, 299,150, 20,hWnd,(HMENU)lb19,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(label9,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria label

HWND label10 = CreateWindowEx(NULL,"STATIC","Master liga :" ,WS_CHILD|WS_VISIBLE,384, 269,150, 20,hWnd,(HMENU)lb10,0,0);//Cria label
HWND label11 = CreateWindowEx(NULL,"STATIC","Tempo" ,WS_CHILD|WS_VISIBLE,386, 299,150, 20,hWnd,(HMENU)lb11,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(label11,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria label
HWND label12 = CreateWindowEx(NULL,"STATIC","Dificuldade" ,WS_CHILD|WS_VISIBLE,469, 299,150, 20,hWnd,(HMENU)lb12,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(label12,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria label


HWND bot11 = CreateWindowEx(0,"BUTTON","Destravar o menu copas" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,21, 315,150,93,hWnd,(HMENU)btn11,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot11,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));
//HWND bot12 = CreateWindowEx(0,"BUTTON","10" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,21, 315,150,93,hWnd,(HMENU)btn12,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot12,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));
//HWND bot13 = CreateWindowEx(0,"BUTTON","15" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,21, 381,30, 27,hWnd,(HMENU)btn13,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot13,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));
//HWND bot14 = CreateWindowEx(0,"BUTTON","20" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,57, 315,31, 27,hWnd,(HMENU)btn14,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot14,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
//HWND bot15 = CreateWindowEx(0,"BUTTON","25" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,57, 348,31, 27,hWnd,(HMENU)btn15,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot15,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria botão
//HWND bot16 = CreateWindowEx(0,"BUTTON","30" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,57, 381,31, 27,hWnd,(HMENU)btn16,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot16,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
//HWND bot17 = CreateWindowEx(0,"BUTTON","Facil" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,101, 315,70, 27,hWnd,(HMENU)btn17,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot17,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
//HWND bot18 = CreateWindowEx(0,"BUTTON","Normal" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,101, 348,70, 27,hWnd,(HMENU)btn18,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot18,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria botão
//HWND bot19 = CreateWindowEx(0,"BUTTON","Dificil" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,101, 381,70, 27,hWnd,(HMENU)btn19,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot19,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot20 = CreateWindowEx(0,"BUTTON","5" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,203, 315,31, 27,hWnd,(HMENU)btn20,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot20,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot21 = CreateWindowEx(0,"BUTTON","10" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,203, 348,31, 27,hWnd,(HMENU)btn21,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot21,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria botão
HWND bot22 = CreateWindowEx(0,"BUTTON","15" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,203, 381,31, 27,hWnd,(HMENU)btn22,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot22,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria botão
HWND bot23 = CreateWindowEx(0,"BUTTON","20" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,240, 315,31, 27,hWnd,(HMENU)btn23,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot23,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot24 = CreateWindowEx(0,"BUTTON","25" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,240, 348,31, 27,hWnd,(HMENU)btn24,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot24,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot25 = CreateWindowEx(0,"BUTTON","30" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,240, 381,31, 27,hWnd,(HMENU)btn25,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot25,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot26 = CreateWindowEx(0,"BUTTON","Fácil"  ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,284, 315,70, 27,hWnd,(HMENU)btn26,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot26,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot27 = CreateWindowEx(0,"BUTTON","Normal" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,284, 348,70, 27,hWnd,(HMENU)btn27,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot27,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot28 = CreateWindowEx(0,"BUTTON","Dificil" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,284, 381,70, 27,hWnd,(HMENU)btn28,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot28,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot29 = CreateWindowEx(0,"BUTTON","5" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,387, 315,31, 27,hWnd,(HMENU)btn29,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot29,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot30 = CreateWindowEx(0,"BUTTON","10" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,387, 348,31, 27,hWnd,(HMENU)btn30,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot30,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot31 = CreateWindowEx(0,"BUTTON","15" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,387, 381,31, 27,hWnd,(HMENU)btn31,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot31,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot32 = CreateWindowEx(0,"BUTTON","20" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,425, 315,31, 27,hWnd,(HMENU)btn32,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot32,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot33 = CreateWindowEx(0,"BUTTON","25" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,425, 348,31, 27,hWnd,(HMENU)btn33,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot33,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot34 = CreateWindowEx(0,"BUTTON","30" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,425, 381,31, 27,hWnd,(HMENU)btn34,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot34,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));//Cria botão
HWND bot35 = CreateWindowEx(0,"BUTTON","Fácil" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,469, 315,70, 27,hWnd,(HMENU)btn35,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot35,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot36 = CreateWindowEx(0,"BUTTON","Normal" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,469, 348,70, 27,hWnd,(HMENU)btn36,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot36,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
HWND bot37 = CreateWindowEx(0,"BUTTON","Dificil" ,WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,469, 381,70, 27,hWnd,(HMENU)btn37,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(bot37,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão


HWND combo1 = CreateWindowEx(0,"COMBOBOX","",WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST,440,200,100,400,hWnd,(HMENU)comb1,GetModuleHandle(NULL),NULL); hfDefault=GetStockObject(DEFAULT_GUI_FONT);SendMessage(combo1,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0)); //Cria botão
SendMessage(combo1,
         (UINT)CB_ADDSTRING,
            (WPARAM)0,(LPARAM)TEXT("Offsets Pes 1 by fja"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)1,(LPARAM)TEXT("942440"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)2,(LPARAM)TEXT("942441"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)3,(LPARAM)TEXT("3369556"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)4,(LPARAM)TEXT("3369557"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)5,(LPARAM)TEXT("3369672"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)6,(LPARAM)TEXT("2792677"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)7,(LPARAM)TEXT("2792682"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)8,(LPARAM)TEXT("2792693"));
SendMessage(combo1,
           (UINT)CB_ADDSTRING,
            (WPARAM)9,(LPARAM)TEXT("2792698"));


			// Criar Button1
			HWND hWndButton1=CreateWindowEx(NULL,
				"BUTTON",
				"Pro Evolution Soccer - SLES-03795",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				20,
				20,
				520,
				50,
				hWnd,
				(HMENU)BUTTON1,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton1,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));


             	// Criar Button2
			HWND hWndButton2=CreateWindowEx(NULL,
				"BUTTON",
				"Normal",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				20,
				120,
				80,
				30,
				hWnd,
				(HMENU)BUTTON2,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton2,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

             	// Criar Button3
			HWND hWndButton3=CreateWindowEx(NULL,
				"BUTTON",
				"Máxima",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				20,
				160,
				80,
				30,
				hWnd,
				(HMENU)BUTTON3,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton3,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

				// Criar Button4
			HWND hWndButton4=CreateWindowEx(NULL,
				"BUTTON",
				"Turbo",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				20,
				200,
				80,
				30,
				hWnd,
				(HMENU)BUTTON4,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton4,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

             	// Criar Button5
			HWND hWndButton5=CreateWindowEx(NULL,
				"BUTTON",
				"0",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				200,
				120,
				50,
				30,
				hWnd,
				(HMENU)BUTTON5,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton5,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

             	// Criar Button6
			HWND hWndButton6=CreateWindowEx(NULL,
				"BUTTON",
				"20",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				200,
				160,
				50,
				30,
				hWnd,
				(HMENU)BUTTON6,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton6,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

		// Criar Button7
			HWND hWndButton7=CreateWindowEx(NULL,
				"BUTTON",
				"999",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				200,
				200,
				50,
				30,
				hWnd,
				(HMENU)BUTTON7,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton7,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

             	// Criar Button8
			HWND hWndButton8=CreateWindowEx(NULL,
				"BUTTON",
                "2",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				255,
				120,
				50,
				30,
				hWnd,
				(HMENU)BUTTON8,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton8,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

				// Criar Button9
            HWND hWndButton9=CreateWindowEx(NULL,
				"BUTTON",
                "255",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				255,
				160,
				50,
				30,
				hWnd,
				(HMENU)BUTTON9,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton9,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

             	// Criar Button10
			HWND hWndButton10=CreateWindowEx(NULL,
				"BUTTON",
				"About",
				WS_TABSTOP|WS_VISIBLE|
				WS_CHILD|BS_DEFPUSHBUTTON,
				440,//HORIZONTAL Y
				120,//VERTICAL  X
				100,//COMPRIMENTO
				70,//LARGURA
				hWnd,
				(HMENU)BUTTON10,
				GetModuleHandle(NULL),
				NULL);
			SendMessage(hWndButton10,
				WM_SETFONT,
				(WPARAM)hfDefault,
				MAKELPARAM(FALSE,0));

            //####################################################################################################
             // desabilitar todos os botões
             AlterarEstadoBotoes(hWnd, botoesParaAlterar, numeroDeBotoesParaAlterar, false); // Desabilitar todos os botões

		}
		break;

		case WM_COMMAND:
			switch(LOWORD(wParam))
            {
				case BUTTON1:
				{
              loadbox();

                   // habilitar todos os botões
                  AlterarEstadoBotoes(hWnd, botoesParaAlterar, numeroDeBotoesParaAlterar, true); // Habilitar todos os botões
                  //  MessageBox(NULL, szFileName, "INFO", MB_OK | MB_ICONINFORMATION );
				}
				break;

				case BUTTON2:
				{
				  // VelocidadeNormal();
				   writeBox(942440,0xE8,942441,0x01);
				}
				break;

				case BUTTON3:
				{
				  //VelocidadeMaxima ();
				    writeBox(942440,0xA0,942441,0x01);
				}
				break;

					case BUTTON4:
				{
                    //VelocidadeTurbo ();
                    writeBox(942440,0x40,942441,0x00);
				}
				break;

					case BUTTON5:
				{
                  //DinheiroMinimoML();
                   writeBox(3369556,0x00,3369557,0x00);
				}
				break;

					case BUTTON6:
				{
                  //DinheiroOriginalML();
                   writeBox(3369556,0x00,3369557,0x14);
				}
				break;

				case BUTTON7:
				{
                  //DinheiroMaximoML();
                     writeBox(3369556,0xE7,3369557,0x03);
				}
				break;

				case BUTTON8:
				{
				   // ContratacoesMLoriginal();
				    writeBox(3369672,0x02,NULL,NULL);
				}
				break;

					case BUTTON9:
				{
				   // ContratacoesMLmaximo();
				   writeBox(3369672,0xFF,NULL,NULL);
				}
				break;

					case BUTTON10:
				{
                  MessageBox(NULL, "Programado por Fabio Fja , C++ Win32 API ,IDE CODE BLOCKS.", "ABOUT",  MB_OK | MB_ICONINFORMATION | MB_TOPMOST  );
				}
				break;

              //case combo :
				//{
				  //  ContratacoesML();
				//}
				//break;

               //################################################################################################
              //tempo e dificuldade copa;
            case btn11:{ writeBox(2493660,0x5C,NULL,NULL);}break; //DESTRAVAR O MENU COPAS


                  //################################################################################################
                  //tempo e dificuldade liga;
					case btn20:
                {
				   writeBox(2792677,0x00,NULL,NULL);//tempo liga 5m
				}
				break;

	               case btn21:
				{
				   writeBox(2792677,0x01,NULL,NULL);//tempo liga 10m
				}
				break;

                   case btn22:
				{
				   writeBox(2792677,0x02,NULL,NULL);//tempo liga 15m
				}
				break;

				     case btn23:
				{
				   writeBox(2792677,0x03,NULL,NULL);//tempo liga 20m
				}
				break;

				     case btn24:
				{
				   writeBox(2792677,0x04,NULL,NULL);//tempo liga 25m
				}
				break;

				     case btn25:
				{
				   writeBox(2792677,0x05,NULL,NULL);//tempo liga 30m
				}
				break;

				     case btn26:
				{
				   writeBox(2792682,0x00,NULL,NULL);//dificuldade liga facil
				}
				break;

				   case btn27:
				{
				   writeBox(2792682,0x01,NULL,NULL);//dificuldade liga normal
				}
				break;

				   case btn28:
				{
				   writeBox(2792682,0x02,NULL,NULL);//dificuldade liga dificil
				}
				break;
             //################################################################################################
              //tempo e dificuldade master liga;
					case btn29:
				{
				   writeBox(2792693,0x00,NULL,NULL);//tempo master liga 5m
				}
				break;

	               case btn30:
				{
				   writeBox(2792693,0x01,NULL,NULL);//tempo master liga 10m
				}
				break;

                   case btn31:
				{
				   writeBox(2792693,0x02,NULL,NULL);//tempo master liga 15m
				}
				break;

				     case btn32:
				{
				   writeBox(2792693,0x03,NULL,NULL);//tempo master liga 20m
				}
				break;

				     case btn33:
				{
				   writeBox(2792693,0x04,NULL,NULL);//tempo master liga 25m
				}
				break;

				     case btn34:
				{
				   writeBox(2792693,0x05,NULL,NULL);//tempo master liga 30m
				}
				break;

				     case btn35:
				{
				   writeBox(2792698,0x00,NULL,NULL);//dificuldade master liga facil
				}
				break;

				   case btn36:
				{
				   writeBox(2792698,0x01,NULL,NULL);//dificuldade master liga normal
				}
				break;

				   case btn37:
				{
				   writeBox(2792698,0x02,NULL,NULL);//dificuldade master liga dificil
				}
				break;

			}
			break;

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
	}

	return DefWindowProc(hWnd,msg,wParam,lParam);
}
