#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>

class HotMap
{
private:

	std::vector<std::string> get_it();
	std::vector<std::string> vec = get_it();
	std::map <std::string, std::string> map;
	std::map <std::string, std::string>::iterator iter;
	std::ofstream * OutStream= new std::ofstream;
	
	
public:
	
	std::vector<std::string> vec1 = {"error"};
	HotMap() {};
	HotMap(std::map <std::string, std::string> map) {};
	
	std::vector<std::string> get_cmds(void)const;
	std::vector<std::string> get_keys(void)const;

	bool add_pair(std::string hot_key, std::string cmd);
	size_t add_cmd(std::string cmd, std::vector<std::string> keys);

	void mapping(std::vector<std::string> v1, std::vector<std::string> v2);
	void clean(std::vector<std::string> vec_cmds);

	bool remove_key(std::string str);
	bool remove_cmd(std::string str);
	HotMap copy(void)const;

	std::vector<std::string> merge(const HotMap &map);

	std::string & operator[](std::string  key);
	~HotMap() {};//close files
};

