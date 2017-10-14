#include <iostream>
#include "HotMap.h"

int main()
{
	HotMap h;
	std::vector<std::string> vec_cmds;
	std::vector<std::string> vec_keys;
	std::vector<std::string> vec;
	std::string str("ctrl+c");
	std::string s;
	
	vec_cmds=h.get_cmds();
	std::cout << std::endl;
	vec_keys = h.get_keys();

	
	std::cout << "Mapping:" << std::endl;
	h.mapping(vec_cmds, vec_keys);

	std::cout << "s: " <<h["ctrl+y"] << std::endl;
	system("pause");
	return 0;
}