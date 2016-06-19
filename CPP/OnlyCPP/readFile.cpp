#include <fstream>
#include <string>
#include <iostream>
#include <regex>
#include <windows.h>


using namespace std;
//using namespace boost; 

int main () 
{
    string inputBuffer;
	string finalstring;
    
	do{
		ifstream fin;
		fin.open ("Preferences");
		
		do {
		int current(0);
		getline(fin, inputBuffer);          
		while(current < 1500 && current < inputBuffer.size())
		{
			//cout << inputBuffer[current++];
			finalstring += inputBuffer[current++];
		}
		cout << endl;
		} while (!fin.eof());
		
		fin.close();
		
		//cout << "|||" << finalstring << "DONE"; 
		
		smatch m; 
		
		regex e1("\"show_apps_shortcut\":false,\"show_on_all_tabs\":false");
		
		//std::cout << "Target sequence: " << finalstring << std::endl;
		//std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
		std::cout << "\nThe following matches and submatches were found for e1:" << std::endl;
		
		string foundString;
		
		try{
			while (std::regex_search (finalstring,m,e1)) {
				for (auto x:m) {
					//std::cout << x << " ";
					foundString += x;
				}
				//std::cout << std::endl;
				finalstring = m.suffix().str();
			}
		}catch (const std::regex_error& e1) {
			std::cout << "regex_error caught: " << e1.what() << '\n';
			if (e1.code() == std::regex_constants::error_brack) {
				std::cout << "The code was error_brack\n";
			}
		}
		
		cout << foundString << "\n";
		Sleep(1000);
	}while(true);
	


    return 0;
}