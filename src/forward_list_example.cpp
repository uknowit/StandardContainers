#include "../include/forward_list_example.hpp"

typedef std::list<std::string>::iterator  list_iterator;

void ForwardListExample::method_examples()
{
	std::forward_list<std::string> team_name_list;
	std::forward_list<std::string> team_name_1_list;
	std::forward_list<std::string> team_name_old_list;
	std::forward_list<std::string> sm_name_list;
	std::forward_list<std::string>::iterator sm_list_iter = sm_name_list.before_begin();
	std::forward_list<std::string>::const_iterator list_iter=team_name_list.before_begin();
	std::list<std::string> old_teams;

	old_teams.push_back("Tulip");
	old_teams.push_back("Ebony");
	old_teams.push_front("Balsa");

	sm_name_list.insert_after(sm_list_iter, "Amit");
	sm_name_list.insert_after(sm_list_iter, "Shishir");
	sm_name_list.insert_after(sm_list_iter, "Prabhu");
	sm_name_list.insert_after(sm_list_iter, "Somesh");
	sm_name_list.insert_after(sm_list_iter, "Malay");
	sm_list_iter = sm_name_list.begin();
	sm_name_list.emplace_after(sm_list_iter, "Hemanth");

	team_name_list.insert_after(list_iter, "Avengers");
	list_iter = team_name_list.insert_after(list_iter, "Yashus");
	team_name_list.insert_after(list_iter, "Dynamites");
	team_name_list.emplace_after(list_iter, "Vikings");

	list_iter = team_name_1_list.insert_after(team_name_1_list.before_begin(), "Samurai");
	team_name_1_list.insert_after(list_iter, "Samrat");

	for(auto iter : team_name_list)
		std::cout<<iter<<std::endl;
	std::cout<<"============================"<<std::endl;
	for(auto iter : sm_name_list)
		std::cout<<iter<<std::endl;
	std::cout<<"============================"<<std::endl;

	sm_name_list.sort();
	team_name_list.sort();
	team_name_list.merge(team_name_1_list);

	for(auto iter : team_name_list)
		std::cout<<iter<<std::endl;
	std::cout<<"============================"<<std::endl;
	for(auto iter : sm_name_list)
		std::cout<<iter<<std::endl;
	std::cout<<"============================"<<std::endl;

	sm_name_list.unique();
	sm_name_list.reverse();
	sm_name_list.remove("Hemanth");

	for(auto iter : sm_name_list)
		std::cout<<iter<<std::endl;
	std::cout<<"============================"<<std::endl;

	team_name_old_list.insert_after(team_name_old_list.before_begin(),old_teams.begin(),old_teams.end());
	team_name_list.splice_after(team_name_list.before_begin(), team_name_old_list);//team_name_old_list will be empty after this.

	for(auto iter : team_name_list)
		std::cout<<iter<<std::endl;
	std::cout<<"============================"<<std::endl;

}
