#include "stdafx.h"
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


enum class tile
{
	empty = 0,
	up_down			/* '|' */,
	left_right		/* '-' */,
	curve_left		/* '\' */,
	curve_right		/* '/' */,
	intersection	/* '+' */
};

enum class direction
{
	up,
	down,
	left,
	right
};

struct cart
{
	std::size_t x;
	std::size_t y;
	direction current_move;
	direction last_move;
};

constexpr auto size = 13;
using map_type = std::array<std::array<tile, size>, size>;
using cart_type = std::array<std::array<cart, size>, size>;

map_type map;
cart_type positions;

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
			if (ch == '|') map[line_counter][row_counter] = tile::up_down;
			else if (ch == '-') map[line_counter][row_counter] = tile::left_right;
			else if (ch == '\\') map[line_counter][row_counter] = tile::curve_left;
			else if (ch == '/') map[line_counter][row_counter] = tile::curve_right;
			else if (ch == '+') map[line_counter][row_counter] = tile::intersection;

			else if (ch == '>')
			{
				positions[line_counter][row_counter] = { line_counter, row_counter, direction::right};
				map[line_counter][row_counter] = tile::left_right;
			}
			else if (ch == '<')
			{
				positions[line_counter][row_counter] = { line_counter, row_counter, direction::left };
				map[line_counter][row_counter] = tile::left_right;
			}
			else if (ch == '^')
			{
				positions[line_counter][row_counter] = { line_counter, row_counter, direction::up };
				map[line_counter][row_counter] = tile::up_down;
			}
			else if (ch == 'v')
			{
				positions[line_counter][row_counter] = { line_counter, row_counter, direction::down };
				map[line_counter][row_counter] = tile::up_down;
			}
			else map[line_counter][row_counter] = tile::empty;
			++row_counter;
		}
		++line_counter;
	}
	input.close();
};

const auto print = [](map_type& map)
{
	for (auto& line : map)
	{
		for (auto&i : line)
		{
			if (i == tile::up_down) std::cout << '|';
			else if (i == tile::left_right)		std::cout << '-';
			else if (i == tile::curve_left)		std::cout << '\\';
			else if (i == tile::curve_right)	std::cout << '/';
			else if (i == tile::intersection)	std::cout << '+';
			else								std::cout << ' ';
		}
		std::cout << std::endl;
	}
};


auto move_cart = [](cart& c, map_type& map, cart_type& positions)
{
	assert(positions[c.x][c.y] == c);
	return false;
};

int main()
{
	readFile();
	print(map);
	bool isColisionDetected = false;
	while (!isColisionDetected)
	{
	}
	return 0;
}