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
#include <array>
#include <list>
#include <functional>
#include <cassert>
#include <chrono>
#include <deque>
#include <map>
#include <deque>


int main()
{
	constexpr auto players_number = 2;
	constexpr auto recipes_count = 209231;
	constexpr auto iteration_size = 10 + recipes_count;
	std::vector<unsigned> scoreboard{ 3,7 };
	std::vector<unsigned> pattern = { 2,0,9,2,3,1 };
	std::array<unsigned, players_number> recipes{};
	auto first_index = 0;
	auto second_index = 1;

	auto move = [&](auto it)
	{
		const auto size = 1 + *it;
		for (auto i = 0u; i < size; ++i)
		{
			if (it == scoreboard.end())
			{
				it = scoreboard.begin();
			}
			++it;
		}
	};

	const auto compare = [&](auto s_beg, auto s_end)
	{
		auto j = 0u;
		for (auto i = s_beg; i < s_end; ++i, ++j)
		{
			if (scoreboard[i] != pattern[j]) return false;
		}
		return true;
	};

	while (true)
	{
		const auto sum = scoreboard[first_index] + scoreboard[second_index];
		const auto newValueFirst = sum / 10;
		const auto newValueSecond = sum % 10;
		if (newValueFirst) scoreboard.push_back(newValueFirst);
		scoreboard.push_back(newValueSecond);
		const auto f = scoreboard[first_index] + 1;
		const auto s = scoreboard[second_index] + 1;
		first_index = (first_index + f) % scoreboard.size();
		second_index = (second_index +s) % scoreboard.size();

		if (scoreboard.size() > pattern.size())
		{
			if (newValueFirst)
			{
				const auto starting_pos = scoreboard.size() - pattern.size() - 1;
				const auto ending_pos = scoreboard.size() - 1;
				if (compare(starting_pos, ending_pos))
				{
					std::cout << starting_pos << std::endl;
					break;
				}
			}
			const auto starting_pos = scoreboard.size() - pattern.size();
			const auto ending_pos = scoreboard.size();
			if (compare(starting_pos, ending_pos))
			{
				std::cout << starting_pos << std::endl;
				break;
			}
		}
	}

	std::cout << std::endl;
	return 0;
}