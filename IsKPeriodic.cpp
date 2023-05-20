#include "IsKPeriodic.h"
#include <string>
#include "Source.h"
void IsKPeriodic() {
	std::string txt= "abababab";// строка для теста функции
	//std::string txt = "abcabcabc";// строка для теста функции
	std::string subStr = "";
	cout << "Test string  :" << txt<<endl;
	int sizeTxt = txt.size() - 1;
	int* arrCount = new int[sizeTxt];
	int counter;
	int* lps = new int[txt.size()];
	int zerro_counter = computeLPS(txt, lps);
	subStr = txt.substr(0, zerro_counter);
	counter = KMPSearch(subStr, txt);
	cout << "------------------------------------------" << endl;
	cout << "Test string  :" << txt << endl;
	cout << "Substring of teststring :"<<subStr <<"  periodic = " << zerro_counter << endl;
	cout << "Number elements" << counter<< endl;
	delete lps;
}
//arrCount[i] = counter;
//computeLPS(txt, lps);