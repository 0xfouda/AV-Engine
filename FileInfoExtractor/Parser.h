#ifndef Parser_H
#define Parser_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


struct TypeRule
{
	string typeName;
	string typeIdentifier;
	int typeOffset;
	int identiferLength;

};


class parser
{
private:
	string rulesFilePath; //path to the file containing the rules
	vector<TypeRule> typesList; //list that contains the rules in file
	bool checkRule(ifstream* f, struct TypeRule r);
public:
	parser(string rulesFilePath); //parser constructor to take the rules file path
	string parseFile(string filePath); //parser function that parses a given file and return it's type

};


#endif