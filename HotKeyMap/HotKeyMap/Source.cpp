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

	std::cout << "Mapping:" << std::endl;
	h.mapping(vec_cmds, vec_keys);
	//std::string str();
	std::cout << "N:" << h.add_cmd("move", vec_keys);
	//if (h.remove_cmd("move"))
	//	std::cout << "ok\n";
	//vec_cmds=h.remove_element(vec_cmds);
	//vec_keys=h.remove_element(vec_keys);

	//vec_cmds=h.add_element(vec_cmds);
	//h.add_pair();
	//std::string str("move");
	//h.test(str);
	//std::cout << std::endl;

	h.clean(vec_cmds);
	h.clean(vec_keys);
	system("pause");

	return 0;
}