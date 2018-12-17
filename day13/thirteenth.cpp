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
	intersection	/* '+' */,
	cart_up			/* '^' */,
	cart_down		/* 'v' */,
	cart_left		/* '<' */,
	cart_right		/* '>' */,
};

enum class direction
{
	up,
	down,
	left,
	right
};

struct position
{
	int x;
	int y;
};

struct cart
{
	int x;
	int y;
	direction last_move;
};

std::array<std::array<tile, 150>, 150> map;

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
			else if (ch == '>') map[line_counter][row_counter] = tile::cart_right;
			else if (ch == '<') map[line_counter][row_counter] = tile::cart_left;
			else if (ch == '^') map[line_counter][row_counter] = tile::cart_up;
			else if (ch == 'v') map[line_counter][row_counter] = tile::cart_down;
			else map[line_counter][row_counter] = tile::empty;
			++row_counter;
		}
		++line_counter;
	}
	input.close();
};

int main()
{
	readFile();
	for (auto& line : map)
	{
		for (auto&i : line)
		{
			if (i == tile::up_down) std::cout << '|';
			else if (i == tile::left_right)		std::cout << '-';
			else if (i == tile::curve_left)		std::cout << '\\';
			else if (i == tile::curve_right)	std::cout << '/';
			else if (i == tile::intersection)	std::cout << '+';
			else if (i == tile::cart_down)		std::cout << 'v';
			else if (i == tile::cart_up)		std::cout << '^';
			else if (i == tile::cart_right)		std::cout << '>';
			else if (i == tile::cart_left)		std::cout << '<';
			else								std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}