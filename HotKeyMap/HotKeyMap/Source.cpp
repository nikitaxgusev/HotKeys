#include <iostream>
#include "HotMap.h"

int main()
{
	HotMap h;
	std::vector<std::string> vec_cmds;
	std::vector<std::string> vec_keys;

	vec_cmds=h.get_cmds();
	std::cout << std::endl;
	vec_keys = h.get_keys();

	h.mapping(vec_cmds, vec_keys);
	h.add_key();
	h.clean(vec_cmds);
	h.clean(vec_keys);
	system("pause");

	return 0;
}