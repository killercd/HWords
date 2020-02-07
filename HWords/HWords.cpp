// HWords.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <Windows.h>

using namespace std;


void usage() {
	cout << "Usage: HWords regex file" << endl;
}
int main(int argc, char* argv[]) {

	if (argc < 3) {
		usage();
		return -1;
	}
	regex pattern(argv[1]);

	HANDLE                      m_hConsole;
	WORD                        m_currentConsoleAttr;
	CONSOLE_SCREEN_BUFFER_INFO   csbi;

	//retrieve and save the current attributes
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (GetConsoleScreenBufferInfo(m_hConsole, &csbi))
		m_currentConsoleAttr = csbi.wAttributes;
	
	std::ifstream file(argv[2]);
	std::string str;

	string line = "";
	while (std::getline(file, line)) {
		smatch m;


		if (regex_search(line, m, pattern)) {
			SetConsoleTextAttribute(
				m_hConsole,
				FOREGROUND_GREEN |
				FOREGROUND_GREEN);
			//cout << "TROVATO" << endl;
			cout << line << endl;
			cin.get();
			//set the ttribute to the original one
			SetConsoleTextAttribute(
				m_hConsole,
				m_currentConsoleAttr);

		}
		else {
			cout << line << endl;
		}

	}
	



	return 0;
}