/*
 * associative_containers.hpp
 *
 *  Created on: 05-Mar-2016
 *      Author: uknowit
 */

#include "../include/associative_containers.hpp"

typedef std::map<std::string, std::string>::value_type string_map_value;
typedef std::map<std::string, int>::iterator my_mmap_iter;


bool operator<(const Record& a, const Record& b)
{
	return a.label < b.label;
}

void AssociativeContainer::associative_container_usage()
{
	std::initializer_list<string_map_value>  my_int_list =
							{{"Taluk","Thirthahalli"}, {"District","Shimoga"}, { "State","Karnataka"}};
	std::map<std::string, std::string> my_map{my_int_list};
	std::cout<<"Initializer_list::"<<my_int_list.size()<<std::endl;
	std::cout<<"Map::"<<my_map.size()<<std::endl;

	std::string place = my_map["Taluk"];
	std::cout<<"Index...."<<place<<std::endl;
	my_map["Street"] =  "Soppugudde" ;
	std::cout<<"Map::"<<my_map.size()<<std::endl;
	std::cout<<"Street::"<<my_map.at("Street")<<std::endl;

	std::map<std::string, std::string>::iterator my_map_iter = my_map.lower_bound("District");
	std::map<std::string, std::string>::iterator my_map_end = my_map.end();
	my_map_iter = my_map.lower_bound("District");
	my_map.emplace_hint(my_map_iter, string_map_value{"ZHouse_no","75"});
	my_map_iter = my_map.begin();
	for(; my_map_iter != my_map_end; my_map_iter++)
			std::cout<<my_map_iter->first<<std::endl;
	std::cout<<my_map.count("ZHouse_no")<<std::endl;

	std::multimap<std::string, int> my_multi_map {{"apple", 2},{"orange", 3},{"apple", 4},{"apple", 5},{"pear", 7}};
	const std::string key("apple");

	std::pair<my_mmap_iter, my_mmap_iter> m_map_pair = my_multi_map.equal_range(key);
	if(m_map_pair.first != m_map_pair.second)
	{
		for(auto pp = m_map_pair.first; pp != m_map_pair.second; pp++)
			std::cout<<pp->first<<" "<<pp->second<<std::endl;
	}
	std::cout<<"============"<<std::endl;

	std::pair<my_mmap_iter, my_mmap_iter> m_map_pair_1 = std::make_pair(my_multi_map.lower_bound(key), my_multi_map.upper_bound(key));
	if(m_map_pair_1.first != m_map_pair_1.second)
	{
		for(auto pp = m_map_pair_1.first; pp != m_map_pair_1.second; pp++)
			std::cout<<pp->first<<" "<<pp->second<<std::endl;
	}

	std::set<Record> my_set{{"Duck", 10 }, {"Pork", 12}};
	std::cout<<"============"<<std::endl;
	for(auto& set_tra: my_set)
	{
		std::cout<<set_tra.label<<"::"<<set_tra.value<<std::endl;
		//++set_tra.value; modification of values is not allowed.
	}
	std::cout<<"============"<<std::endl;
	std::unordered_set<Record, Nocase_hash, Nocase_equal> un_my_set{{{"Ali", 7}, {"Andy", 9}, {"Bill", -3}, {"Basava", 12}}, 20, Nocase_hash{2}, Nocase_equal{}};
	for(auto& set_tra: un_my_set)
	{
		std::cout<<set_tra.label<<"::"<<set_tra.value<<std::endl;
	}
}


