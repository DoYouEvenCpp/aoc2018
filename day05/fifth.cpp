#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iterator>
#include <vector>
#include <fstream>
#include <cctype>
#include <numeric>
#include <set>


constexpr auto diff = 'a' - 'A';

int main()
{
	std::vector<char> s;
	

	const auto comp = [](char c1, char c2)
	{
		if (std::abs(c1 - c2) != diff)
			return false;
		return true;
	};

	char ch;
	
	
	std::ifstream fin("input", std::fstream::in);
	while (fin >> std::noskipws >> ch)
	{
		s.push_back(ch);
	}
	fin.clear();
	fin.close();

	
	//while (std::adjacent_find(s.begin(), s.end(), comp) != s.end())
	//{
	//	auto it = std::adjacent_find(s.begin(), s.end(), comp);
	//	//std::cout << "removing: " << *it  << " and " << *it+1 << std::endl;
	//	it = s.erase(it);
	//	s.erase(it);
	//}
	//std::cout << s.size() << std::endl;
	//
	std::size_t min = std::numeric_limits<int>::max();

	for (char c = 'a'; c <= 'z'; ++c)
	{
		auto v = s;
		v.erase(std::remove_if(v.begin(), v.end(), [c](auto c1) {return c1 == c || c1 == (c - diff); }), v.end());
		v.shrink_to_fit();
		while (std::adjacent_find(v.begin(), v.end(), comp) != v.end())
		{
			auto it = std::adjacent_find(v.begin(), v.end(), comp);
			it = v.erase(it);
			v.erase(it);
		}
		if (v.size() < min)
			min = v.size();
	}
	std::cout << min;
	return 0;
}