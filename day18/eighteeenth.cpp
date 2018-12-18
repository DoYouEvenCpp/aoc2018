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
#include <map>

enum class tile
{
	open_ground,
	tree,
	lumberyard
};

constexpr auto size = 50;
using map_type = std::array<std::array<tile, size>, size>;

std::array<std::array<tile, size>, size> map{};

const auto readFile = []
{
	std::fstream input("input", std::fstream::in);
	std::string line;
	std::size_t line_counter = 0;
	while (std::getline(input, line))
	{
		std::size_t row_counter = 0;
		for (auto ch : line)
		{
			if (ch == '|') map[line_counter][row_counter] = tile::tree;
			else if (ch == '.') map[line_counter][row_counter] = tile::open_ground;
			else if (ch == '#') map[line_counter][row_counter] = tile::lumberyard;
			++row_counter;
		}
		++line_counter;
	}
	input.close();
};

struct helper
{
	int trees;
	int open_grounds;
	int lumberyards;
};

auto searchAdjacentTiles = [&](int xx, int yy)
{
	helper h{};
	for (int i = -1; i < 2; ++i)
	{
		for (auto j = -1; j < 2; ++j)
		{
			auto y = yy;
			auto x = xx;
			if (y > 0 && y < (size - 1))
			{
				y += i;
			}
			else if (y == 0)
			{
				if (i == -1) continue;
				y += i;
			}
			else if (y == (size - 1))
			{
				if (i == 1) continue;
				y += i;
			}
			
			if (x > 0 && x < (size - 1))
			{
				x += j;
			}
			else if (x == 0)
			{
				if (j == -1) continue;
				x += j;
			}
			else if (x == (size - 1))
			{
				if (j == 1) continue;
				x += j;
			}
			auto& tile = map[y][x];
			if (x == xx && y == yy) continue;
			h.lumberyards += (tile == tile::lumberyard);
			h.trees += tile == tile::tree;
			h.open_grounds += tile == tile::open_ground;
		}
	}
	return h;
};

const auto print_map = [](map_type& mao)
{
	for (auto& line : map)
	{
		for (auto&i : line)
		{
			if (i == tile::open_ground)		std::cout << '.';
			else if (i == tile::lumberyard)	std::cout << '#';
			else if (i == tile::tree)		std::cout << '|';
			else							std::cout << ' ';
		}
		std::cout << std::endl;
	}
};

const auto getNumbers = [](map_type& map)
{
	int wooden = 0;
	int lumberyards = 0;
	for (auto line = 0; line < size; ++line)
	{
		for (auto row = 0; row < size; ++row)
		{
			const auto currentTile = map[line][row];
			switch (currentTile)
			{
			case tile::tree:
			{
				++wooden;
				break;
			}
			case tile::open_ground:
			{
				break;
			}
			case tile::lumberyard:
			{
				++lumberyards;
				break;
			}
			}
		}
	}
	return std::make_pair(wooden, lumberyards);
};


auto iterateMap = [](map_type& map, std::size_t counter)
{
	map_type map_copy = map;
	for (auto ii = 0; ii < counter; ++ii)
	{
		for (auto line = 0; line < size; ++line)
		{
			for (auto row = 0; row < size; ++row)
			{
				const auto currentTile = map[line][row];
				auto h = searchAdjacentTiles(row, line);
				auto& tile = map_copy[line][row];
				switch (currentTile)
				{
				case tile::tree:
				{
					if (h.lumberyards >= 3) tile = tile::lumberyard;
					break;
				}
				case tile::open_ground:
				{
					if (h.trees >= 3) tile = tile::tree;
					break;
				}
				case tile::lumberyard:
				{
					if (!(h.lumberyards >= 1 && h.trees >= 1)) tile = tile::open_ground;
					break;
				}
				}
			}
		}
		map = map_copy;
	}
};


int main()
{
	readFile();

	std::list<map_type> previous_maps;
	previous_maps.push_back(map);
	constexpr auto iteration_number = 1000000000;

	for (auto i = 0; i < iteration_number; ++i)
	{
		auto map_copy = map;
		for (auto line = 0; line < size; ++line)
		{
			for (auto row = 0; row < size; ++row)
			{
				const auto currentTile = map[line][row];
				const auto h = searchAdjacentTiles(row, line);
				auto& tile = map_copy[line][row];
				switch (currentTile)
				{
				case tile::tree:
				{
					if (h.lumberyards >= 3) tile = tile::lumberyard;
					break;
				}
				case tile::open_ground:
				{
					if (h.trees >= 3) tile = tile::tree;
					break;
				}
				case tile::lumberyard:
				{
					if (!(h.lumberyards >= 1 && h.trees >= 1)) tile = tile::open_ground;
					break;
				}
				}
			}
		}
		if (i == 9)
		{
			auto[wooden, lumberyards] = getNumbers(map_copy);
			std::cout << std::endl << "First puzzle answer: " << wooden * lumberyards << " w: " << wooden << " lumberyards: " << lumberyards << std::endl;
		}
		auto it = std::find_if(previous_maps.begin(), previous_maps.end(), [&](auto& m) {return m == map_copy; });
		if (it != previous_maps.end())
		{
			const auto cycle = previous_maps.size() - std::distance(previous_maps.begin(), it);
			const auto left = (iteration_number - i) % cycle;
			iterateMap(map, left);
			auto[wooden, lumberyards] = getNumbers(map);
			std::cout << std::endl << "second puzzle answer: " << wooden * lumberyards << " w: " << wooden << " lumberyards: " << lumberyards << std::endl;
			break;
		}
		map = map_copy;
		previous_maps.push_back(map_copy);
	}
	return 0;
}