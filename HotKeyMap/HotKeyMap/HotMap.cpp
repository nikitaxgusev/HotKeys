#include "HotMap.h"
#include <sstream>
#include <utility>
#include <cstring>


std::vector<std::string> HotMap::get_cmds(void) const
{	
	//Almost the same method as get_keys() is but the deffirence is that , its reading from another file
	//The main idea is the same. That's why I'm trying to rethink
	// May be I need to do only one function..... 

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
			for (auto & c : line) c = tolower(c);

			vec_cmds.push_back(line);
			std::cout <<"["<< i <<"] - "<<line<<std::endl;
			i++;
		}
	}

	return std::vector<std::string>(vec_cmds);
}

std::vector<std::string> HotMap::get_keys(void) const
{
	int i = 1;
	std::string line;
	std::vector<std::string> vec_keys;
	std::string file_name_keys("read_keys.txt");							
	std::ifstream file_keys(file_name_keys, std::ios::in);					//trying to read a file with the name under

	if (!file_keys.is_open())												//Checking for opening a file
	{												
		std::cout << "Error: Can't open " << file_name_keys << std::endl;
		exit(-1);
	}
	else
	{
		std::cout << "read KEYS from a file TWO,below" << std::endl;
		while (std::getline(file_keys,line ))								//Using getline for reading line by line in a string "line"
		{
			for (auto & c : line) c = tolower(c);							//For the standard, all letter are in lower registr
			vec_keys.push_back(line);										//Push back in a vector every string
			std::cout << "[" << i << "] - " <<line << std::endl;			// for checking myself
			i++;
		}

		
	}
	return std::vector<std::string>(vec_keys);								//return filling vector
}

bool HotMap::add_pair(std::string hot_key,std::string cmd)
{
	//This very method ad key and check for the same variant, that's why I use pair<>..
	//In order to check if the key exists or not.No? Write in a file a new one. 


	for (auto & k : hot_key) k = tolower(k);									//In order to create the right order in a file and in a process writting 																		//All letters are with lower registr
																			//That's why ctrl+a or CTRL+A or Ctrl+A is the sam
	for (auto & v : cmd) v = tolower(v);									//just the right order all are lower, not special

	std::ofstream file;
	file.open("out.txt",std::ios_base::out);
	

	// Create a pair object that will contain the result of a call to insert().
	std::pair<std::map<std::string, std::string>::iterator, bool> result;	//bool for check a key in a map

	// Duplicate keys are not allowed, as the following proves.
	result = map.insert(std::pair<std::string, std::string>(hot_key, cmd));

	if (result.second)
	{
		
		for (iter = map.begin(); iter != map.end(); iter++)						//outputting and writting
		{
			file << iter->first << " : " << iter->second << std::endl;
			std::cout << iter->first << " : " << iter->second << std::endl;
		}
		std::cout << "Added!" << std::endl;
		return true;
	}
		
	else 
	{
		std::cout << "Duplicate not allowed.\n";
		return false;
	}

}

size_t HotMap::add_cmd(std::string cmd, std::vector<std::string> keys)
{
	std::string line;
	std::string hot_key;
	std::vector<std::string> vec_keys;
	std::string file_name_keys("out.txt");
	std::ifstream file_keys(file_name_keys, std::ios_base::in);

	std::ofstream file("res.txt", std::ios_base::out);
	std::vector<std::string>::iterator iter_vec;


	while (std::getline(file_keys, line))
	{
		for (auto & c : line) c = tolower(c);
		vec_keys.push_back(line);
	}

	std::string found_str;
	for (int i = 0; i < 3; i++)
	{
		if (vec_keys[i].find(cmd) != std::string::npos)
		{

			found_str = vec_keys[i];
			std::cout << "" << found_str << std::endl;
			std::cout << "Enter key:" << std::endl;
			std::cin >> hot_key;

			if (found_str.find(hot_key) != std::string::npos)
			{
				std::cout << "Ooops" << std::endl;
				return 404;
			}
			else
			{
				
				std::cout << found_str + hot_key << std::endl;
				return 24;
			}
			return true;
		}
	}
	return false;

}





void HotMap::mapping(std::vector<std::string> v1, std::vector<std::string> v2)
{
	//Mapping my keys and values from vectors which were filled by files

	OutStream->open("out.txt");

	std::string key;
	std::string value;


	for (int i = 0; i < 3; i++)
	{
		key = v1[i];														//take a key 
		for (auto & c : key) c = tolower(c);								// lower it for the rigth structure	
		value = v2[i];														// take a value for a key
		for (auto & s : value) s = tolower(s);								// lower it too
		map[key] = value;													// now keys gets their values 
	}

	for (iter = map.begin(); iter != map.end(); iter++)						// outputting and writting
	{
		(*OutStream) << iter->first<< " : "<< iter->second << std::endl;	
		std::cout << iter->first <<" : "<< iter->second << std::endl;
	}
		
	
}

void HotMap::clean(std::vector<std::string> vec_cmds)
{
	//Clean vectors

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

bool HotMap::remove_cmd(std::string str)
{	
		std::string line;
		std::vector<std::string> vec_keys;
		std::string file_name_keys("out.txt");
		std::ifstream file_keys(file_name_keys, std::ios_base::in);
	
		std::ofstream file("res.txt", std::ios_base::out);
		std::vector<std::string>::iterator iter_vec;


		while (std::getline(file_keys, line))
		{
			for (auto & c : line) c = tolower(c);
			vec_keys.push_back(line);
		}

		std::string found_str;
		for (int i = 0; i < 3; i++)
		{
			if (vec_keys[i].find(str) != std::string::npos)
			{
				
				found_str = vec_keys[i];
				std::cout << "" << found_str << std::endl;
				iter_vec =std::find(vec_keys.begin(), vec_keys.end(), found_str);
				std::cout << "<:"<<*iter_vec << std::endl;

				if (iter_vec != vec_keys.end())
				{
					std::cout << "The key was removed" << std::endl;
					vec_keys.erase(iter_vec);

					for (iter_vec = vec_keys.begin(); iter_vec != vec_keys.end(); iter_vec++)
					{
						std::cout << *iter_vec<<std::endl;
						 file<< *iter_vec<<std::endl;
					}
						
				
				}
				return true;
			}
		}	
		return false;
		
}

bool HotMap::remove_key(std::string str)
{
	//for (auto & c : str) c = tolower(c);
	std::string line;
	std::vector<std::string> vec_keys;
	std::string file_name_keys("read_keys.txt");
	std::ifstream file_keys(file_name_keys, std::ios::in);
	std::vector<std::string>::iterator iter_vec;

	
	while (std::getline(file_keys, line))								//Using getline for reading line by line in a string "line"
	{
		for (auto & c : line) c = tolower(c);							//For the standard, all letter are in lower registr
		vec_keys.push_back(line);										//Push back in a vector every string
	}

	iter_vec = std::find(vec_keys.begin(), vec_keys.end(), str);

	if (iter_vec != vec_keys.end())
	{
		std::cout << "The key was removed" << std::endl;
		vec_keys.erase(iter_vec);

		for (iter_vec = vec_keys.begin(); iter_vec != vec_keys.end(); iter_vec++)
			std::cout << *iter_vec<<std::endl;
		return true;
	}
	else
	{
		std::cout << "The key wasn't found" << std::endl;
		return false;
	}
}