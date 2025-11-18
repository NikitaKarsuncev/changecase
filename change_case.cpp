#include <iostream>
#include <fstream>

void help(){
std::cout << "Use \n\tchangecase sourse_file destination_file\n";
std::cout << "\t-L - to lower case";
std::cout << "\t-U - to upper case";
std::cout << "\t-G - to toggle case";
}

void toggle_case(std::ifstream & inFile, std::ofstream & outFile){
	int ch;
	while ((ch = inFile.get())!= EOF) {
		if (ch >= 'a' && ch <= 'z') {
			ch=(ch-'a') + 'A';
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = (ch - 'A') + 'a';
		}
	outFile.put(ch);
	}	
}

void to_lower_case(std::ifstream & inFile, std::ofstream & outFile){
	int ch;
	while ((ch = inFile.get())!= EOF) {
		if (ch >= 'A' && ch <= 'Z') {
			ch=(ch-'a') + 'A';
		}
	outFile.put(ch);
	}	
}

void to_upper_case(std::ifstream & inFile, std::ofstream & outFile){
	int ch;
	while ((ch = inFile.get())!= EOF) {
		if (ch >= 'a' && ch <= 'z') {
			ch=(ch-'a') + 'A';
		}
	outFile.put(ch);
	}	
}

int main(int argc, char* argv[]){


	if (argc != 4){
		help();
		return 0;
	}
	const char* inputfilename = argv[1];
	const char * outputfilename = argv[2];
	
	std::ifstream inFile;
	inFile.open(inputfilename, std::ios_base::binary);
	if (!inFile){
		std::cout<<"Can not open file '" << inputfilename << "'\n";
		return 1;

	}
	std::ofstream outFile;
	outFile.open(outputfilename, std::ios_base::binary);
	if (!outFile){
		std::cout << "Can not open file ' " << outputfilename << "'\n";
		inFile.close();
		return 2;
	}

	if (strcmp(argv[1], "-L") == 0) {
		to_lower_case(inFile, outFile);

	}
	else if (strcmp(argv[1], "-U") == 0) {
		to_upper_case(inFile, outFile);

	}
	else if (strcmp(argv[1], "-G") == 0) {
		toggle_case(inFile, outFile);

	}
	else {
		help();
	}
			
	inFile.close();
	outFile.close();
	return 0;

}