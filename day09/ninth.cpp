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

int main()
{
	constexpr auto players_number = 459u;
	constexpr auto marbles_count = 100u * 71790u;
	std::list<unsigned> marbles(1);
	std::array<unsigned, players_number> players{};
	auto current_marble = 1;
	auto current_player = 0u;
	auto current_index = marbles.begin();

	const auto start = std::chrono::steady_clock::now();
	while (current_marble <= marbles_count)
	{
		if (current_marble % 100000 == 0)
		{
			const auto end = std::chrono::steady_clock::now();
			const auto diff = end - start;
			std::cout << "[" << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
				<< " ms]: " << current_marble << "\n";
		}

		if (current_marble % 23 == 0)
		{
			for (auto i = 0; i < 7; ++i)
			{
				if (current_index == marbles.begin()) current_index = marbles.end();
				--current_index;
			}
			players[current_player] += current_marble + *current_index;
			current_index = marbles.erase(current_index);
			if (current_index == marbles.end()) current_index = marbles.begin();
		}
		else
		{
			for (auto i = 0; i < 2; ++i)
			{
				if (current_index == marbles.end()) current_index = marbles.begin();
				++current_index;
			}
			current_index = marbles.insert(current_index, current_marble);
		}
		++current_marble;
		++current_player;
		if (current_player == players_number)
		{
			current_player = 0;
		}
	}
	const auto end = std::chrono::steady_clock::now();
	const auto diff = end - start;
	std::cout << "[" << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count()
		<< " ms]: " << current_marble << "\n";
	

	const auto val = *std::max_element(players.begin(), players.end());
	std::cout << "answer: " << val << std::endl;
	return 0;
}