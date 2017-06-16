#include "aplication_txt.h"
// #include "Data\Enginer\enginer.h"     nie widzi tego!
#include <cstdlib>
#include <Windows.h>

C_aplication_txt::C_aplication_txt() {
	system("echo %USERPROFILE%>>operation.ope");
	std::ifstream file;
	file.open("operation.ope");
	if (file.good())
	{
		name_user_profile.m_getline(file);
		//name_user_profile.m_push_back("\\");
		//std::cout << name_user_profile << "\n";
		N_striing s_data = name_user_profile;
		s_data += "\\";
		s_data += op_name_catalog;
		m_get_index_value_tree(s_data);
		file.close();
	}
	Lista=m_add_to_operation(true, Lista);
	if (m_what_files())
	{	
		system("attrib -a +h +r +s operation.ope");
		system("md %USERPROFILE%\\.tree&&%USERPROFILE%>>echo  >>%USERPROFILE%\\.tree\\init.&&cd %USERPROFILE%\\.tree\\&&ATTRIB -A +H init."); //dziala
	}
	SetWindow(150, 70);
	MainMenu();
}
C_aplication_txt::C_aplication_txt(const C_aplication_txt & aplication_txt) {
	if (this != &aplication_txt) *this = aplication_txt;
	system("echo %USERPROFILE%>>operation.ope");
	std::ifstream file;
	file.open("operation.ope");
	if (file.good())
	{
		name_user_profile.m_getline(file);
		//name_user_profile.m_push_back("\\");
	//	std::cout << name_user_profile << "\n";
		N_striing s_data = name_user_profile;
		s_data += "\\";
		s_data += op_name_catalog;
		m_get_index_value_tree(s_data);
		file.close();
	}
	Lista = m_add_to_operation(true, Lista);
	if (m_what_files())
	{
		system("attrib -a +h +r +s operation.ope");
		system("md %USERPROFILE%\\.tree&&%USERPROFILE%>>echo  >>%USERPROFILE%\\.tree\\init.&&cd %USERPROFILE%\\.tree\\&&ATTRIB -A +H init."); //dziala
	}
	SetWindow(150, 70);
	MainMenu();
}
C_aplication_txt& C_aplication_txt::operator=(const C_aplication_txt& aplication_txt) {
	if (this == &aplication_txt) return *this;
	if (*this == aplication_txt) return *this;
	Lista = aplication_txt.Lista;
	V_ID = aplication_txt.V_ID;
	name_user_profile = aplication_txt.name_user_profile;
	return *this;
}
bool C_aplication_txt::operator==(const C_aplication_txt& aplication_txt) {
	if (Lista==aplication_txt.Lista&&V_ID==aplication_txt.V_ID&&name_user_profile == aplication_txt.name_user_profile) return true;
	return false;
}
bool C_aplication_txt::operator!=(const C_aplication_txt& aplication_txt) {
	if (Lista != aplication_txt.Lista&&V_ID != aplication_txt.V_ID&&name_user_profile != aplication_txt.name_user_profile) return true;
	return false;
}
C_aplication_txt::~C_aplication_txt() {}
bool C_aplication_txt::m_what_files() {
	N_striing data;
	int i;
	std::ifstream file;
	data = "cd ";
	data += name_user_profile;
	data += "\\.tree\\&&attrib +A -H init.";
	system(data.m_c_str());
	data = name_user_profile;
	data += "\\.tree\\init.";
	file.open(data.m_c_str());
	if (file.good())
	{
		file.close();
		data = "cd ";
		data += name_user_profile;
		data += "\\.tree\\&&attrib -A +H init.";
		system(data.m_c_str());
		return false;
	}
	return true;
}

void C_aplication_txt::SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_BOLD;			//FW_NORMAL
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}



void C_aplication_txt::CreateLogo()       // metoda tworzy logo (atrape "drzewka")
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   // metoda ustawia kolory = 15 to bialy
	cout << "\n\n\t\t\t | \n \t\t\t | \n \t\t     ========= \n  \t\t    |         | \n \t\t    | \t      |";
	cout << "\n \t   =============      ====\n";
	cout << "\t  |      |      |\t  |\n";
	cout << "\t  |      |      |\t  |\n";
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\n\n" << "\t\t\t" << "DRZEWO GENEALOGICZNE - FAMILY TREE\n\n";
}

void C_aplication_txt::MainMenu() //start
{
	N_striing Menu[3] = { "1. New Tree", "2. Load Tree", "3. Exit" };
	N_striing SubMenu[3] = { "[Create New Tree]", "[Import Your Created Trees]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
	{
		Lista.m_close();
		Lista = m_add_to_operation(true, Lista);
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu[i] << "  " << SubMenu[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{

				case 0:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					Sub1();
				} break;

				case 1:
				{
					Sleep(1500);
					SubMenu2();
				} break;

				case 2:
				{
					return;
				} break;

				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}

void C_aplication_txt::Sub1()
{

	N_striing MenuSub1[3] = { "1. Create New Tree", "2. Import Tree" ,"3. Exit" };
	N_striing SubSub1[3] = { "[Create Your New Tree]", "[Import Your Created Trees]", "[Exit From Program]" };
	int ptr = 0, p = 0;
	char c;
	N_striing data;
	while (true)
	{
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE) !=0) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr <= -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr >= 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
					switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
					{
						case 0:
						{
							m_menu_name_tree();
							return;
							break;
						}

						case 1:
						{
							Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
							break;
						}

						case 2:
						{
							return;
							break;
						}
					}
				}
			}
		}

	Sleep(150);     // szybkosc poruszania sie po menu
}


void C_aplication_txt::EditTree()
{
	char C;
	C_human human,HHuman; //id dodaje sie dopiero w silniku
	N_striing data;
	N_striing MenuSub1[5] = { "1. Add a person", "2. Edit a person", "3. Add a relation", "4. Edit a relation", "5. Exit" }; //do rozbudowy
	N_striing SubSub1[5] = { "[You can add a person to your tree]", "[You can edit a person]", "[You can add a relation to a person]",
		"[You can edit a relation to a person]", "[Exit From Program]" };
	int ptr = 0, p = 0;
	int i;
	while (true)
	{
		Sleep(150);
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (i = 0; i < 5; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 5)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(1500);
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0: 
					m_menu_add_human();
					return;
				case 1:
					m_lista(true);
					return;
				//menu do tetetetetete

						Sleep(150);     // szybkosc poruszania sie po menu
				}
				Sleep(150);     // szybkosc poruszania sie po menu
			}
			//Sleep(150);
		}
		//Sleep(150);
	}
	//Sleep(150);
}
/*	case 1:
{

} break;

case 2:
{

} break;

case 3:
{

} break;

case 4:
{
return;
} break;
default:
break;*/




void C_aplication_txt::SearchTree()
{
	N_striing MenuSub1[3] = { "1. Search by personal data", "2. Search by date" , "3. Exit" };
	N_striing SubSub1[3] = { "[You can search person by personal data]", "[You can search person by dates]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
	{
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
									//SubMenu3();
				} break;

				case 1:
				{

				} break;

				case 2:
				{
					return;
				} break;

				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}


void C_aplication_txt::DisplayTree()
{
	N_striing MenuSub1[3] = { "1. Display from the oldest", "2. Search" , "3. Exit" };
	N_striing SubSub1[3] = { "[You can display trees from the oldest]", "[Search your created trees]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
	{
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 3; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << " \n\t\t " << SubSub1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 2;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 3)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
									//SubMenu3();
				} break;

				case 1:
				{
					Sleep(1500);
					SearchTree();
				} break;

				case 2:
				{
					return;
				} break;

				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}



void C_aplication_txt::SubMenu2()
{
	//moim zadniem lista z wczytanymi drzewami do wyboru:P
	m_lista(false); //lista drzew
	return;
//	m_lista(true);
	N_striing Menu2[4] = { "1. Display Tree", "2. Edit Tree", "3. Export Tree", "4. Exit" };
	N_striing SubMenu2[4] = { "[Display Your Created Trees]", "[Edit Your Created Trees]", "[Export Your Created Trees]", "[Exit From Program]" };
	int pt = 0;

	while (true)
	{

		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		for (int i = 0; i < 4; ++i)
		{
			if (i == pt)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu2[i] << " \n\t\t " << SubMenu2[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu2[i] << endl;
			}
		}


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";


		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				pt -= 1;
				if (pt == -1)      // gdy wykracza wraca na koniec
				{
					pt = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				pt += 1;
				if (pt == 4)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					pt = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pt)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					DisplayTree();
					//ImportTree();
					//system("dir /s H:\TREE_INOP");
					//system("tree /f H:\TREE_INOP\\Drzewo_genealogiczne\\Drzewo_genealogiczne\\Data");	//w CodeBlocks dzia�a, tu nie...
					//system("PAUSE");

				} break;

				case 1:
				{
					Sleep(1500);
					EditTree();
				} break;

				case 2:
				{
					//EditTree();
				} break;


				case 3:
				{
					return;
				} break;

				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}



void C_aplication_txt::ImportTree()
{
	N_striing MenuSub1[2] = { "1. Give your tree name", "2. Exit" };
	N_striing SubSub1[2] = { "[You can give your created tree name]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
	{
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 2; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "SPACEBAR";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";

		while (true)
		{
			if (GetAsyncKeyState(VK_SPACE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{
				case 0:
				{
					Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
									//SubMenu3();
				} break;

				case 1:
				{
					return;
				}
				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}
char C_aplication_txt::m_get_key() {
	char C;
	int Tab_key[26] = { 0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
		0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A };
	int Tab_key_number[2][10] = { 0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39 };
	char Tab_letter[2][26];
	char Tab_number[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char Tab_polish[9] = { (char)185,(char)230,(char)234,(char)179,(char)241,(char)243,(char)156,(char)159,(char)191 }; //Polskie litery male
	char Tab_Polish[9] = { (char)165,(char)198,(char)202,(char)163,(char)209,(char)211,(char)140,(char)143,(char)175 }; //Polskie lityry duze
	int Tab_npolish[9] = { 0x41,0x43,0x45,0x4C,0x4E,0x4F,0x53,0x58,0x5A };
	int i;
	for (i = 0; i < 26; i++)
	{
		Tab_letter[0][i] = 'a' + i;
		Tab_letter[1][i] = 'A' + i;
	}
	while (true) {
		for (i = 0; i < 10; i++)
		{
			if (GetAsyncKeyState(Tab_key_number[0][i]) != 0)
			{
				C = Tab_number[i];
				Sleep(100);
				return C;
			}
		}
		for (i = 0; i < 9; i++)
		{
			if ((GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) == 0) &&
				(GetAsyncKeyState(VK_CAPITAL) == 0) && (GetAsyncKeyState(VK_MENU) != 0)) {
				C = Tab_polish[i];
				Sleep(100);
				return C;
			}
			if ((GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) != 0) && (GetAsyncKeyState(VK_MENU) != 0) ||
				(GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(Tab_npolish[i]) != 0) && (GetAsyncKeyState(VK_MENU) != 0)) {
				C = Tab_Polish[i];
				Sleep(100);
				return C;
			}
		}
		for (i = 0; i < 26; i++)
		{
			if ((GetAsyncKeyState(Tab_key[i]) != 0) && (GetAsyncKeyState(VK_SHIFT) == 0) && (GetAsyncKeyState(VK_CAPITAL) == 0) && (GetAsyncKeyState(VK_MENU) == 0))   // strzalka do gory przesuwa wyzej po menu
			{
				C = (Tab_letter[0][i]);
				Sleep(100);
				return C;
			}
			else if (((GetAsyncKeyState(VK_SHIFT) != 0) && (GetAsyncKeyState(Tab_key[i]) != 0)) && (GetAsyncKeyState(VK_MENU) == 0) || ((GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(VK_CAPITAL) != 0) && (GetAsyncKeyState(VK_MENU) == 0)))
			{
				C = (Tab_letter[1][i]);
				Sleep(100);
				return C;
			}
			else if ((GetAsyncKeyState(VK_SPACE) != 0))
			{
				Sleep(100);
				return ' ';
			}
			else if ((GetAsyncKeyState(VK_RETURN) != 0) || (GetAsyncKeyState(VK_BACK) != 0) || (GetAsyncKeyState(VK_DOWN) != 0) || (GetAsyncKeyState(VK_UP) != 0) || (GetAsyncKeyState(VK_ESCAPE) != 0)) {
				return '\0';
			}
		}
	}
}
bool C_aplication_txt::m_what_return() {
	N_striing MenuSub1[4] = { "Do you want back to the menu?","1. Yes","2. No", "3. Cancel" }; 
	N_striing SubSub1[4] = { "","[All data will be deleted]","[Continue]" ,"[Cancel and return to adding data]" };
	int ptr = 1, p = 0;

	while (true)
	{
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 4; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub1[i] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr == 0)      // gdy wykracza wraca na koniec
				{
					ptr = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr == 4)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 1;
				}
				break;
			}
			else if (ptr==1&&GetAsyncKeyState(VK_RETURN) != 0)
			{
				return true;
			}
			else if (ptr == 2 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				return false;
			}
			else if (ptr == 3 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				return false;
			}
		}
		 
		Sleep(150);     // szybkosc poruszania sie po menu
	}
//	return false;
}
bool C_aplication_txt::m_what_menu() {
	return true; //do dokonczenia
}
void C_aplication_txt::m_menu_add_human() {
//	m_load_files(true);
	C_human human, HHuman;
	int ptr=0,i;
	bool b_what = false;
	while (true) {
		if (human == HHuman) {
			N_striing MenuSub_add_person[5] = { "1. Add a first name", "2. Add a surname", "3. Add a gender", "4. Add a date", "6. Return" };
			N_striing SubSub_add_person[5] = { "[You can add a first name to your person]", "[You can add a surname to your person]", "[You can add a gender to your person]",
				"[You can add a date to your person]","[Return From Add Person]" }; //dla Mateusza
			Sleep(150);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
							// tutaj powinna byc metoda dolaczenia nowej osoby
			while (true)
			{
				system("cls");
				CreateLogo();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				for (i = 0; i < 5; ++i)
				{
					if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t" << "--> " << MenuSub_add_person[i] << " \n\t\t " << SubSub_add_person[i] << endl;
					}
					else                // niewybrane opcje sa biale
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\t\t\t\t" << MenuSub_add_person[i] << endl;
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				cout << "\n\n\n\n Use the arrows to navigate the menu ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << char(24) << " " << char(25);        // kody ASCII strzalek
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << ". Confirm your choice with ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "ENTER.";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n Click ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "SPACEBAR";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << " if you want back to main menu.";
				while (true)
				{
					if (GetAsyncKeyState(VK_SPACE)) {
						//Sleep(150);
						if (m_what_menu())
							MainMenu();
						break;
					}
					if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
					{
						//Sleep(150);
						ptr -= 1;
						if (ptr == -1)      // gdy wykracza wraca na koniec
						{
							ptr = 4;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
					{
						//Sleep(150);
						ptr += 1;
						if (ptr == 5)       // gdy wykracza poza menu, znow wraca na poczatek
						{
							ptr = 0;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						//Sleep(1500);
						switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
						{
						case 0: {
							Sleep(150);
							human.m_get_first_name(m_menu_add_first_name().m_set_first_name());
							break;
						}
						case 1: {
							Sleep(150);
							human.m_get_last_name(m_menu_add_last_name().m_set_last_name());
							break;
						}
						case 2: {
							Sleep(150);
							human.m_get_gender(m_menu_add_gender().m_set_gender());
							break;
						}
						case 3: {
							Sleep(150);
							b_what = true;
							human.m_get_date(m_menu_add_date().m_set_date());
							break;
						}
						case 4: {
							return;
						}
					//	break;
						}
						break;
					}
					//Sleep(150);
				}
				break;
			}
		}
		else
		{
			//ptr = 0;
			N_striing MenuSub_add_person[6] = { "1. Add a first name", "2. Add a surname", "3. Add a gender", "4. Add a date","5. Save Person" ,"6. Return" };
			N_striing SubSub_add_person[6] = { "[You can add a first name to your person]", "[You can add a surname to your person]","[You can choose your gender]", "[You can add a date of birth]",
				"[Save your person]", "[Return From Add Person]" };
			Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
							// tutaj powinna byc metoda dolaczenia nowej osoby
			while (true)
			{
				system("cls");
				CreateLogo();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				for (i = 0; i < 6; ++i)
				{
					if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						cout << "\t\t\t\t" << "--> " << MenuSub_add_person[i] << " \n\t\t " << SubSub_add_person[i] << endl;
					}
					else                // niewybrane opcje sa biale
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						cout << "\t\t\t\t" << MenuSub_add_person[i] << endl;
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				cout << "\n\n\n\n Use the arrows to navigate the menu ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << char(24) << " " << char(25);        // kody ASCII strzalek
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << ". Confirm your choice with ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "ENTER.";

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\n Click ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "SPACEBAR";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << " if you want back to main menu.";
				cout << " \n\n";
				cout << human;
				while (true)
				{
					if (GetAsyncKeyState(VK_SPACE)) {
					//	Sleep(150);
						if (m_what_menu())
							MainMenu();
						break;
					}
					if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
					{
					//	Sleep(150);
						ptr -= 1;
						if (ptr == -1)      // gdy wykracza wraca na koniec
						{
							ptr = 5;
						}
						break;
					}
					else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
					{
					//	Sleep(150);
						ptr += 1;
						if (ptr == 5)       // gdy wykracza poza menu, znow wraca na poczatek
						{
							ptr = 0;
						}
						break;
					}
					//else if (ptr == 4 && GetAsyncKeyState(VK_RETURN) != 0)
					//{
					//	Sleep(150);
					//	m_new_human(human);
					//	m_save_files(true);
					//
					//	break;
					//	//if
					//}
					else if (GetAsyncKeyState(VK_RETURN) != 0)
					{
						//Sleep(1500);
						switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
						{
						case 0: {
							Sleep(150);
							human.m_get_first_name(m_menu_add_first_name().m_set_first_name());
							break;
						}
						case 1: {
							Sleep(150);
							human.m_get_last_name(m_menu_add_last_name().m_set_last_name());
							break;
						}
						case 2: {
							Sleep(150);
							human.m_get_gender(m_menu_add_gender().m_set_gender());
							break;
						}
						case 3: {
							Sleep(150);
							b_what = true;
							human.m_get_date(m_menu_add_date().m_set_date());
							break;
						}
						case 4: {
							Sleep(150);
							if (!b_what)
							{
								C_date date;
								human.m_get_date(date);
							}
							m_new_human(human);
							Sleep(150);
							m_save_files(true);
							//Sleep(150000);
					//		int x;
					//		std::cin >> x;
							//m_what_menu();
							return;
							//czy chcesz kontynulowac??
							//break;
						}
						case 5: {
							Sleep(150);
							return;
						}
					//	break;
						}
						break;
					}
				//	Sleep(150);
				}
				break;
				//Sleep(150);
			}
		}
	}
}
C_human C_aplication_txt::m_menu_add_first_name() {
	int ptr = 0;
	int i;
	C_human human;
	N_striing data;
	char C;
	//WH_KEYBOARD_LL;//hak do klawiatury
	//bool b_what;

	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					// tutaj powinna byc metoda dolaczenia nowej osoby
	while (true)
	{
		//	b_what = false;
		N_striing MenuSub_add_first_name[2] = { "First name:", "Return" };
		N_striing SubSub_add_first_name[2] = { data ,"[Return From Add Person]" };
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


		for (i = 0; i < 2; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub_add_first_name[i] << " \n\t\t " << SubSub_add_first_name[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub_add_first_name[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ESCAPE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_ESCAPE)) MainMenu();
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu					//naprawione:)
			{
				Sleep(150);
				ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				Sleep(150);
				ptr += 1;
				if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
			{
				Sleep(150);
				data.m_pop_back();
				Sleep(150);
				break;
			}
			else if (ptr == 0 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(150);
				if (data.m_size() > 0)
				{
					C_first_name First(data);
					human.m_get_first_name(First);
					data.m_clear();
					return human;
				}
			}
			else if (ptr == 0)
			{
				C = m_get_key();
				if (C != '\0') {
					data.m_push_back(C);
				}
				break;
			}
			else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(150);
				if (m_what_return()) {
					data.m_clear();
					return human;
				}
				break;
			}
		
		}
	}
}
C_human C_aplication_txt::m_menu_add_last_name() {
	int ptr = 0,i;
	C_human human;
	N_striing data;
	char C;
	//WH_KEYBOARD_LL;//hak do klawiatury
	bool b_what;

	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
//	tutaj powinna byc metoda dolaczenia nowej osoby
		while (true)
		{
			b_what = false;
			N_striing MenuSub_add_last_name[2] = { "Last name:", "Return" };
			N_striing SubSub_add_last_name[2] = { data ,"[Return From Add Person]" };
			system("cls");
			CreateLogo();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


			for (i = 0; i < 2; ++i)
			{
				if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
				}
				else                // niewybrane opcje sa biale
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			cout << "\n\n\n\n Use the arrows to navigate the menu ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << char(24) << " " << char(25);        // kody ASCII strzalek
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << ". Confirm your choice with ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "ENTER.";

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "\n Click ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "ESCAPE";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << " if you want back to main menu.";
			while (true)
			{
				if (GetAsyncKeyState(VK_ESCAPE)) {
					Sleep(150);
					if (m_what_menu())
						MainMenu();
					break;
				}
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
				{
					Sleep(150);
					ptr -= 1;
				if (ptr == -1)      // gdy wykracza wraca na koniec
				{
					ptr = 1;
				}
				break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					Sleep(150);
					ptr += 1;
					if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						ptr = 0;
					}
					break;
				}
				else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
				{
					Sleep(150);
					data.m_pop_back();
					break;
				}
				else if (ptr == 0 && GetAsyncKeyState(VK_RETURN) != 0)
				{
						if (data.m_size() > 0) {
							C_last_name Last(data);
							human.m_get_last_name(Last);
							data.m_clear();
							return human;
						}
				}
				else if (ptr == 0)
				{
						C = m_get_key();
						if (C != '\0') {
							data.m_push_back(C);
						}
					break;
				}
				else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
					{
					//Sleep(150);
						if (m_what_return()) {
							data.m_clear();
						return human;
						}
					}
				}
		//	Sleep(150);
				}
			
			//Sleep(150);
		}
C_human C_aplication_txt::m_menu_add_gender() {
	int ptr = 1,i;
	char C;
	N_striing data;
	C_human human;
	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					// tutaj powinna byc metoda dolaczenia nowej osoby
	while (true)
	{
		//	b_what = false;
		N_striing MenuSub_add_last_name[4] = { "Gender:","- Men","- Women", "Return" };
		N_striing SubSub_add_last_name[4] = { "","","" ,"[Return From Add Person]" };
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


		for (i = 0; i < 4; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ESCAPE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_ESCAPE)) {
				Sleep(150);
				if (m_what_menu())
					MainMenu();
				break;
			}
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po me					//naprawione:)
			{
				Sleep(150);
				ptr -= 1;
				if (ptr == 0)      // gdy wykracza wraca na koniec
				{
					ptr = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				Sleep(150);
				ptr += 1;
				if (ptr == 4)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 1;
				}
				break;
			}
			else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
			{
			//	Sleep(150);
				human.m_get_gender(true);
				Sleep(150);
				return human;
			}
			else if (ptr == 2 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				//Sleep(150);
				human.m_get_gender(false);
				Sleep(150);
				return human;
			}
			else if (ptr == 3 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(150);
				if (m_what_return()) {
					return human;
				}
				break;
			}
		//	Sleep(150);
		}
	//Sleep(150);
	}
}
C_human C_aplication_txt::m_menu_add_date() {
	int ptr = 0, i;
	char C;
	N_striing data;
	C_human human;
	N_striing dd, mm, yy;
	Sleep(1500);    // sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					// tutaj powinna byc metoda dolaczenia nowej osoby
	while (true)
	{
		//	b_what = false;
		data = dd;
		data += '-';
		data += mm;
		data += '-';
		data += yy;
		N_striing MenuSub_add_last_name[2] = { "Date:", "Return" };
		N_striing SubSub_add_last_name[2] = { data ,"[Return From Add Person]" };
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


		for (i = 0; i < 2; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << MenuSub_add_last_name[i] << " \n\t\t " << SubSub_add_last_name[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << MenuSub_add_last_name[i] << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ENTER.";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n Click ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "ESCAPE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " if you want back to main menu.";
		while (true)
		{
			if (GetAsyncKeyState(VK_ESCAPE)) {
				if (m_what_menu())
					MainMenu();
				break;
			}
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
												//naprawione:)
			{
				ptr -= 1;
				if (ptr <= -1)      // gdy wykracza wraca na koniec
				{
					ptr = 1;
				}
				Sleep(150);
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr >= 2)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				Sleep(150);
				break;
			}
			else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
			{
				if (yy.m_size() > 0)
				{
					yy.m_pop_back();
					Sleep(150);
					break;
				}
				else
				{
					if (mm.m_size() > 0)
					{
						mm.m_pop_back();
						Sleep(150);
						break;
					}
					else
					{
						if (dd.m_size() > 0)
						{
							dd.m_pop_back();
							Sleep(150);
							break;
						}
						Sleep(150);
						break;
					}
				}
				Sleep(150);
				break;
			}
			else if (ptr == 0)
			{
				if (dd.m_size() < 2) {
					C = m_get_key();
					if (C != '\0') {
						dd.m_push_back(C);
						break;
					}
				}
				else
				{
					if (mm.m_size() < 2) {
						C = m_get_key();
						if (C != '\0') {
							mm.m_push_back(C);
							break;
						}
					}
					else
					{
						if (yy.m_size() < 4) {
							C = m_get_key();
							if (C != '\0') {
								yy.m_push_back(C);
								break;
							}
						}
						C_date date;
						date.m_get_day(dd);
						date.m_get_month(mm);
						date.m_get_year(yy);
						human.m_get_date(date);
						return human;
					}
				}
				break;
			}

			else if (ptr == 1 && GetAsyncKeyState(VK_RETURN) != 0)
			{
				if (m_what_return())
				{
					data.m_clear();
					return human;
				}
				break;
			}
			Sleep(150);
		}
	Sleep(150);
	}
}
void C_aplication_txt::m_load_lista() {
	Lista.m_close();
	m_load_files(true);
	N_striing s_Data;
	int i, end = V_goverment_personaly.m_size(); //mam nadzieje ze sluszna poprawa
	for (i = 1; i <=end; i++)
	{
		s_Data.m_clear();
		C_human human;
		human = m_create_human(i);
		s_Data += human.m_set_first_name().m_set_contens();
		s_Data += '  ';
		s_Data += human.m_set_last_name().m_set_contens();
		s_Data += "\n\t\t\t\t";
		if (human.m_set_date(0).m_day_set() == '0'||human.m_set_date(0).m_month_set() == '0') {
			s_Data += " - - ";
		}
		else
		{
			s_Data += human.m_set_date(0).m_day_set();
			//std::cout << s_Data << "\n";
			s_Data += '-';
			s_Data += human.m_set_date(0).m_month_set();
			//std::cout << s_Data << "\n";
			s_Data += '-';
			s_Data += human.m_set_date(0).m_year_set();
			//std::cout << s_Data << "\n";
			//Sleep(2000);
		}
		Lista.m_push_back(s_Data);
		V_ID.m_push_back(human.m_set_id());
	}
}
void C_aplication_txt::m_lista(bool b_pointer) {
	bool b_where = false;
	if (b_pointer)
	{
		m_load_lista(); //bagi z nadpisywaniem sie listy
		if (Lista.m_size() == 0)
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			std::cout << "\t\t\t\t" << "Brak Ludzi!" << "\n";
			Sleep(2000);
			return;
		}
	}
	else
	{
		Lista.m_close();
		Lista = m_add_to_operation(true, Lista);
		b_where = true;
	}
	if (Lista.m_size() == 0)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "\t\t\t\t" <<"Brak drzew!" << "\n";
			Sleep(2000);
		return;
	}
	system("cls");
	int ptr = 0, p = 0, i;
	int cykl = 0, pentla = 0;
	//for (i = 0; i < 100; i++)
	//	std::cout << "*";
	//std::cout << '\n';
	if (Lista.m_size() < 5)
	{
		cykl = Lista.m_size(); //- cykl;
	}
	else
	{
		cykl = 5;
	}
	while (true)
	{
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (ptr > 2) {
			if (cykl + 1 <= Lista.m_size())
				cykl += 1;
			else
			{
				cykl = Lista.m_size(); //- cykl;
			}
		}
		for (i = pentla; i < cykl; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << i+1 << "\t" << Lista[i] << endl;
			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << i+1 << "\t" << Lista[i] << endl;
			}
		}
		while (true)
		{
			//if (Lista.m_size() > 1) {
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
				{
					ptr -= 1;
					//cykl -= 2;
					if (ptr < 0)      // gdy wykracza wraca na koniec
					{
						cykl = Lista.m_size();
						if (Lista.m_size() > 5)
							pentla = Lista.m_size() - 5;
						else
							pentla = 0;
						ptr = Lista.m_size();
						continue;
					}
					if (pentla > 0 && ptr < Lista.m_size() - 3)
					{
						pentla--;
					}
					if (cykl > 5 && ptr < Lista.m_size() - 3)
					{
						if (cykl > 6)
							cykl -= 2;
						else
							cykl -= 1;
					}

					//if (pentla>0&&ptr<Lista.m_size() -3)

					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					ptr += 1;
					if (ptr > 2 && ptr < Lista.m_size() - 2)
						pentla++;
					if (ptr > Lista.m_size() - 1)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						pentla = 0;
						if (Lista.m_size() > 5)
							cykl = 5;
						else
							cykl = Lista.m_size();
						ptr = 0;
					}
					break;
				}
			//}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
			//	m_create_human(V_ID[ptr]);
			//	break;
				//przejscie do edycji danych
				Sleep(150);
				if (b_where) {
					N_striing s_data = name_user_profile;
					s_data += "\\"; s_data += op_name_catalog; s_data += "\\"; //poprawa mam nadzieje ze na lepsze
					s_data += Lista[ptr];
					m_get_index_value_tree(s_data);
				}
			//	Lista.m_close();
				
				m_menu_tree();
				return;
			}

		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
	//	return false;
}
void C_aplication_txt::m_menu_name_tree() {
	//Lista.m_close();
	//Lista = m_add_to_operation(true, Lista);
	int ptr = 0, p = 0;
	char c;
	N_striing data;
	bool b_pointer = true;
	while (true)
	{
		if (b_pointer)
		{
			N_striing MenuSub1[2] = { "Give your tree name:", "Back: " };
			N_striing SubSub1[2] = { data, "[Back To Main Menu]" }; 
			system("cls");
			CreateLogo();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			for (int i = 0; i < 2; ++i)
			{
				if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;
				}
				else                // niewybrane opcje sa biale
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\t\t\t\t" << MenuSub1[i] << endl;
				}
			}
			while (true) {
				// sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
				{
					Sleep(1500);
					ptr -= 1;
					if (ptr == 0)      // gdy wykracza wraca na koniec
					{
						ptr = 2;
					}
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					Sleep(1500);
					ptr += 1;
					if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						ptr = 0;
					}
					break;
				}
				else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
				{
					Sleep(1500);
					data.m_pop_back();
					break;
				}
				else
				{
					c = m_get_key();
					if (c != '\0') {
						data.m_push_back(c);
						break;
					}
					if (GetAsyncKeyState(VK_RETURN) != 0 && data.m_size() > 0)
					{
						Sleep(1500);
						//stworzyc zabezpieczenie przed ponownym stworzeniem tego samego dystryktu
						N_striing s_data = name_user_profile;
						s_data += "\\";
						s_data += op_name_catalog;
						s_data += "\\";
						m_get_index_value_tree(s_data);
						int value;
						for (value = 0; value < Lista.m_size(); value++)
						{
							if (Lista[value] == data) {
								b_pointer = false;
								break;
							}
						}
						if (b_pointer)
						{
							//Lista = m_add_to_operation(false, Lista);
							Lista.m_push_back(data);
							m_create_new_location(data);
							Lista=m_add_to_operation(false,Lista);
							N_striing s_data = name_user_profile;
							s_data += "\\";
							s_data += op_name_catalog;
							s_data += "\\";
							s_data +=data;
							//Lista.m_close();
							m_get_index_value_tree(s_data);
							//m_load_files(true);
						//	m_menu_add_human();
							m_menu_tree();
							return;
						}
						break;
						//przeskok do edycji w wczytanu tej lokalizacji
					}

				}

			}
		}
		else
		{
			N_striing MenuSub1[3] = { "Give your tree name:", "Back: ","This name already exists" };
			N_striing SubSub1[3] = { data, "[Back To Main Menu]","" }; 
			system("cls");
			CreateLogo();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			for (int i = 0; i < 3; ++i)
			{
				if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					cout << "\t\t\t\t" << "--> " << MenuSub1[i] << "  " << SubSub1[i] << endl;
				}
				else                // niewybrane opcje sa biale
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << "\t\t\t\t" << MenuSub1[i] << endl;
				}
			}
			while (true) {
				// sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
				if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
				{
					Sleep(1500);
					ptr -= 1;
					if (ptr == 0)      // gdy wykracza wraca na koniec
					{
						ptr = 2;
					}
					break;
				}
				else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
				{
					Sleep(1500);
					ptr += 1;
					if (ptr == 2)       // gdy wykracza poza menu, znow wraca na poczatek
					{
						ptr = 0;
					}
					break;
				}
				else if (ptr == 0 && GetAsyncKeyState(VK_BACK) != 0)
				{
					Sleep(1500);
					data.m_pop_back();
					break;
				}
				else
				{
					c = m_get_key();
					if (c != '\0') {
						data.m_push_back(c);
						break;
					}
					if (GetAsyncKeyState(VK_RETURN) != 0 && data.m_size() > 0)
					{
						Sleep(1500);
						//stworzyc zabezpieczenie przed ponownym stworzeniem tego samego dystryktu
						m_get_index_value_tree(name_user_profile + "\\.tree\\" + data);
						int value;
						b_pointer = true;
						for (value = 0; value < Lista.m_size(); value++)
						{
							if (Lista[value] == data) {
								b_pointer = false;
								break;
							}
						}
						if (b_pointer)
						{
							Lista.m_push_back(data);
							Lista = m_add_to_operation(false, Lista);
							m_create_new_location(data);
							//Lista.m_close();
							m_get_index_value_tree(data);
						//	m_load_files(true);
							m_menu_add_human();
						}
						break;
						//przeskok do edycji w wczytanu tej lokalizacji
					}

				}

			}
		}
		}
}
//void C_aplication_txt::m_menu_edit_human() {

//}
void C_aplication_txt::m_menu_tree() {
	
	N_striing Menu[4] = { "1. Display", "2. Edit Tree","3. Export", "4. Exit" };
	N_striing SubMenu[4] = { "[Display Tree]", "[Edit your tree content]","[Export your tree]", "[Exit From Program]" };
	int ptr = 0, p = 0;

	while (true)
	{
		m_load_files(true);
		system("cls");
		CreateLogo();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < 4; ++i)
		{
			if (i == ptr)       // podswietla dana opcje na niebiesko, dopisuje strzalke
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << "\t\t\t\t" << "--> " << Menu[i] << "\n" << SubMenu[i] << endl;


			}
			else                // niewybrane opcje sa biale
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "\t\t\t\t" << Menu[i] <<"\n"<< endl;
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "\n\n\n\n Use the arrows to navigate the menu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << char(24) << " " << char(25);        // kody ASCII strzalek
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << ". Confirm your choice with ";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		cout << "ENTER.";

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)   // strzalka do gory przesuwa wyzej po menu
			{
				ptr -= 1;
				if (ptr < 0 )      // gdy wykracza wraca na koniec
				{
					ptr = 3;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)    // strzalka na dol przesuwa nizej po menu
			{
				ptr += 1;
				if (ptr >= 4)       // gdy wykracza poza menu, znow wraca na poczatek
				{
					ptr = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (ptr)        // po wybraniu opcji w case'ach beda instrukcje do wykonania
				{

				case 0:
				{
					Sleep(1500); 
				//	Lista.m_close();// sleepy musza byc, by uniknac "podwojnego" ENTERA!!!
					m_lista(true);
				} break;

				case 1:
				{
					Sleep(1500);
					EditTree();
					//return;
				} break;

				case 2:
				{
					//eksportuj
					return;
				} break;
				case 3:
				{
					return;
				}
				}
				break;
			}
		}

		Sleep(150);     // szybkosc poruszania sie po menu
	}
}