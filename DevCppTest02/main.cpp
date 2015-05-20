#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool IsCharDuplication(string s) {   
	for(int i = 0; i < s.length(); i++) {
		for (int j = i+1; j < s.length(); j++) {
			if (s[i] == s[j]) {
				return true;
			}
		}
	}
	
	return false;
}

int stringHasUniqueElements(string strToCheck) {
	int hasUniqueElements = 0;
	
	if(!IsCharDuplication(strToCheck)) {
		hasUniqueElements = 1;
	}
	
	return hasUniqueElements;
}

int main(int argc, char** argv) {
	ifstream alphabet("1.txt");
	
	string alphabetCurrentLine;
	
	int iterationToGet = 9;
	
	/* ***** */
	
	int checkUniqueElements = 1;
	
	int hasUniqueElements = 0;
	
	/* ***** */
	
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
    		
    		if(checkUniqueElements) {
    			hasUniqueElements = stringHasUniqueElements(alphabetCurrentLine + prevIterFileCurrentLine);
    			
    			if(hasUniqueElements) {
    				cout << "WILL ADD " << alphabetCurrentLine << prevIterFileCurrentLine << endl;
    				
    				outStream << alphabetCurrentLine << prevIterFileCurrentLine << endl;
				}
				else {
					cout << "WILL NOT ADD " << alphabetCurrentLine << prevIterFileCurrentLine << endl;
				}
			}
			else {
				outStream << alphabetCurrentLine << prevIterFileCurrentLine << endl;
			}
		}
		
		prevIterFile.close();
		prevIterFile.clear();
		prevIterFile.open(prevIterFileName.c_str());
    }
	
	outStream.close();
	
	return 0;
}
