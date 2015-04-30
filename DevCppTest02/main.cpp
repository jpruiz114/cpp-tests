#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
	ifstream alphabet("1.txt");
	
	string alphabetCurrentLine;
	
	int iterationToGet = 6;
	
	int numberFileToRead = iterationToGet - 1;
	
	stringstream nameOfFileToRead;
	nameOfFileToRead << numberFileToRead << ".txt";
	cout << "File to read: " << nameOfFileToRead.str() << endl;
	
	string prevIterFileName = nameOfFileToRead.str();
	ifstream prevIterFile(prevIterFileName.c_str());
	
	string prevIterFileCurrentLine;
	
	/* ***** */
	
	stringstream nameOfFileToCreate;
	nameOfFileToCreate << iterationToGet << ".txt";
	
	string strNameOfFileToCreate = nameOfFileToCreate.str();
	
	cout << "File to create: " << strNameOfFileToCreate << endl;
	
	/* ***** */
	
	ofstream outStream(strNameOfFileToCreate.c_str());
    
	/* ***** */
	
	while(getline(alphabet, alphabetCurrentLine)) {
    	while(getline(prevIterFile, prevIterFileCurrentLine)) {
    		cout << alphabetCurrentLine << prevIterFileCurrentLine << endl;
    		
    		outStream << alphabetCurrentLine << prevIterFileCurrentLine << endl;
		}
		
		prevIterFile.close();
		prevIterFile.clear();
		prevIterFile.open(prevIterFileName.c_str());
    }
	
	outStream.close();
	
	return 0;
}
