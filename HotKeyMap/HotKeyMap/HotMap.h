#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iterator>
class HotMap
{
private:
	std::map <std::string, std::string> map;
	std::map <std::string, std::string>::iterator iter;
	std::ofstream * OutStream= new std::ofstream;
	std::string * MyString = new std::string;
	
public:
	HotMap() {};
	
	std::vector<std::string> get_cmds(void)const;
	std::vector<std::string> get_keys(void)const;
	void add_key();
	void mapping(std::vector<std::string> v1, std::vector<std::string> v2);
	void clean(std::vector<std::string> vec_cmds);
	~HotMap() {};
};

