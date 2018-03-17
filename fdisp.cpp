#include <iostream>
#include <fstream>
#include <string>
#include "version.h"

using namespace std;

// make changes by adding comments

int main(int argc, char *argv[])
{
	displayVersion();
	if (strncmp(argv[1],"-f",2) == 0)
	{
		for(int i = 2; i <= 11; i++) {
			cout << argv[i] << " ";
		}
		cout << endl;

		
	} else if(strncmp(argv[1],"-d",2) == 0) {
		
		for(int i = 12; i <= 21; i++) {
			cout << argv[i] << " ";
		}
		cout << endl;

	} 
	else if(strncmp(argv[1],"-b",2) == 0) {
	
		for(int i = 22; i <= 35; i++) {
			cout << argv[i] << " ";
		}
		cout << endl;
	}
	else {
		
		cout << "Invalid." << endl;
	}

	return 0;
}