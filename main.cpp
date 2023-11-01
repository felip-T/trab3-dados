#include "hanoi.h"
#include <iostream>
#include <regex>

int main(int argc, char* argv[]){
	if(argc != 2 || !std::regex_match(argv[1], std::regex("[0-9]+"))){
		std::cout << "Uso: hanoi <numero de discos>" << std::endl;
		return 1;
	}
	hanoi h(std::stoi(argv[1]));
	h.solve();
	return 0;
}
