#include "Parser.h"

parser::parser(string rulesFilePath)
{
	ifstream rulesFile(rulesFilePath);
	if (!rulesFile.good())
	{
		cout << "[-] Error Openning rules file !! Check rules file path . . ." << endl;
		return;
	}
	int rulesNumber;
	rulesNumber = count(istreambuf_iterator<char>(rulesFile), istreambuf_iterator<char>(), '\n') + 1;
	this->typesList.reserve(rulesNumber);
	rulesFile.seekg(ios::beg);
	for (int i = 0; i < rulesNumber; i++)
	{
		struct TypeRule rule;
		//getline(rulesFile, rule.typeName, ' ');
		rulesFile >> rule.typeName >> rule.typeOffset >> rule.identiferLength >> rule.typeIdentifier;
		this->typesList.push_back(rule);
	}
}
string parser::parseFile(string filePath)
{
	ifstream f(filePath, ios::binary);
	if (!f.good())
	{
		cout << "[-] Error parsing the given file, please check the file or the file path !!" << endl;
		return "CORRUPTED FILE";
	}
	for (int i = 0; i < typesList.size(); i++)
	{
		if (checkRule(&f, typesList[i]) != false)
			return typesList[i].typeName;
	}
	return "UNIDENTFIED";
}

bool parser::checkRule(ifstream* f,struct TypeRule r)
{
	f->seekg(0,r.typeOffset);
	char* iden = new char[r.identiferLength];
	iden[r.identiferLength] = '\0';
	(*f).read(iden, r.identiferLength);
	if (string(iden) == r.typeIdentifier)
		return true;
	else
		return false;
}