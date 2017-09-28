#include "HotMap.h"
#include <sstream>
#include <utility>
//#include <boost/algorithm/string.hpp>


std::vector<std::string> HotMap::get_cmds(void) const
{	
	int i = 0;
	std::string line;
	std::vector<std::string> vec_cmds;
	std::string file_name_cmds("read_cmds.txt");
	std::ifstream file_cmds(file_name_cmds,std::ios::in);

	if (!file_cmds.is_open())
		std::cout << "Error: Can't open "<< file_name_cmds<< std::endl;
	else
	{
		std::cout << "read CMDS from a file ONE,below" << std::endl;
		while (std::getline(file_cmds, line))
		{
			vec_cmds.push_back(line);
			std::cout <<"["<< i <<"] - "<<line<<std::endl;
			i++;
		}
	}

	return std::vector<std::string>(vec_cmds);
}

std::vector<std::string> HotMap::get_keys(void) const
{
	int i = 0;
	std::string line;
	std::vector<std::string> vec_keys;
	std::string file_name_keys("read_keys.txt");
	std::ifstream file_keys(file_name_keys, std::ios::in);

	if (!file_keys.is_open())
		std::cout << "Error: Can't open " << file_name_keys << std::endl;
	else
	{
		std::cout << "read KEYS from a file TWO,below" << std::endl;
		while (std::getline(file_keys,line ))
		{
			vec_keys.push_back(line);
			std::cout << "[" << i << "] - " <<line << std::endl;
			i++;
		}

		
	}
	return std::vector<std::string>(vec_keys);
}

void HotMap::add_key()
{
	std::string key;
	std::string value;
	std::cout << "Key:";
	std::cin >> key;
	for (auto & k : key) k = tolower(k);

	std::cout << "Value:";
	std::cin >> value;
	for (auto & v : value) v = tolower(v);
//	OutStream->open("out.txt");
	std::ofstream file;
	file.open("out.txt");
	

	// Create a pair object that will contain the result of a call to insert().
	std::pair<std::map<std::string, std::string>::iterator, bool> result;

	// Duplicate keys are not allowed, as the following proves.
	result = map.insert(std::pair<std::string, std::string>(key, value));

	if (result.second)
		std::cout << "Added!\n";
	else
		std::cout << "Duplicate not allowed.\n";

	for (iter = map.begin(); iter != map.end(); iter++)
	{
		file<< iter->first << " : " << iter->second << std::endl;
		std::cout << iter->first << " : " << iter->second << std::endl;
	}
}

void HotMap::mapping(std::vector<std::string> v1, std::vector<std::string> v2)
{
	OutStream->open("out.txt");

	std::string key;
	std::string value;


	for (int i = 0; i < 3; i++)
	{
		key = v1[i];
		for (auto & c : key) c = tolower(c);
		value = v2[i];
		for (auto & s : value) s = tolower(s);
		map[key] = value;
	}

	for (iter = map.begin(); iter != map.end(); iter++)
	{
		(*OutStream) << iter->first<< " : "<< iter->second << std::endl;
		std::cout << iter->first <<" : "<< iter->second << std::endl;
	}
		
	
}

void HotMap::clean(std::vector<std::string> vec_cmds)
{
	vec_cmds.clear();
	if (!vec_cmds.empty())
	{
		std::cout << "Not empty";
		vec_cmds.clear();
	}	
	else
	{
		std::cout << "Empty" << std::endl;
	}
}
