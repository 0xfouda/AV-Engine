#include "Parser.h"
#define RulesFilePath "rules"


void main()
{
	cout << "[+] File Information Extractor " << endl;
	parser p(RulesFilePath);
	cout << "[+] Enter the file path you want to parse : ";
	string file;
	cin >> file; 
	cout << "[+] file type : " << p.parseFile(file) << endl;
	cin.ignore();
}


