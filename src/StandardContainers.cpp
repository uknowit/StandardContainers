//============================================================================
// Name        : StandardContainers.cpp
// Author      : Shashikumar H N
// Version     :
// Copyright   : Silence is better than bull shit !!!
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "../include/forward_list_example.hpp"
#include "../include/associative_containers.hpp"
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int random_number_generator()
{
    random_device r;
    std::mt19937 gen(r());
	uniform_int_distribution<> uniform_dist(1, 1340);
	return uniform_dist(gen);
}
void paritial_sort_test()
{
	vector<int> vec;
	constexpr int n = 30;
	vector<int> copied_vec(n);
	int value = 0;
	for(int index = 0;index < 5;index++)
		for(int inner_index = 0;inner_index < 10; inner_index++)
		{
			value = random_number_generator();
			std::cout<<value<<" ,";
			vec.push_back(value);
		}
	std::cout<<"\n====="<<std::endl;

	partial_sort(vec.begin(), vec.begin()+n, vec.end());
	partial_sort_copy(vec.begin(), vec.end(),copied_vec.begin(), copied_vec.end());

	cout<<"nth element "<<vec[n]<<'\n';

	for(int index = 0; index < n ; index++)
	cout<<vec[index]<<' ';
	std::cout<<"\n====="<<std::endl;

	for(auto  val:copied_vec){
		cout<<val<<' ';
	}

}
int main()
{
	ForwardListExample forward_list_example;
	forward_list_example.method_examples();

	AssociativeContainer associative_cont_example;
	associative_cont_example.associative_container_usage();

	paritial_sort_test();

}
