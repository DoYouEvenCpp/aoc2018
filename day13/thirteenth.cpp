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
#include <queue>

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

enum class turn_orientation
{
	left,
	right,
	straight
};

struct cart
{
	std::size_t x;
	std::size_t y;
	direction orientation;
	turn_orientation last_move;
};

constexpr auto size = 150;
const auto cart_comparator = [](cart& lhs, cart& rhs)
{
	if (lhs.y == rhs.y)
	{
		return lhs.x > lhs.x;
	}
	return lhs.y > rhs.y;
};

using map_type = std::array<std::array<tile, size>, size>;
using cart_collection = std::vector<cart>;
using cart_queue = std::priority_queue<cart, std::vector<cart>, decltype(cart_comparator)>;


map_type map;
cart_collection positions;

const auto readFile = [](map_type& map)
{
	std::fstream input("C:\\Users\\staho\\projects\\dummy\\x64\\Release\\input", std::fstream::in);
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
				positions.push_back({ row_counter, line_counter, direction::right, turn_orientation::left});
				map[line_counter][row_counter] = tile::left_right;
			}
			else if (ch == '<')
			{
				positions.push_back({ row_counter, line_counter,  direction::left, turn_orientation::left });
				map[line_counter][row_counter] = tile::left_right;
			}
			else if (ch == '^')
			{
				positions.push_back({ row_counter, line_counter,  direction::up, turn_orientation::left });
				map[line_counter][row_counter] = tile::up_down;
			}
			else if (ch == 'v')
			{
				positions.push_back({ row_counter, line_counter,  direction::down, turn_orientation::left });
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
	for (auto i = 0; i < size; ++i)
	{
		for (auto j = 0; j < size; ++j)
		{
			if (std::any_of(positions.begin(), positions.end(), [i, j](cart& c)
			{
				return c.x == j && c.y == i;
			}))
			{
				std::cout << 'X';
			}
			else if (map[i][j] == tile::up_down)				std::cout << '|';
			else if (map[i][j] == tile::left_right)		std::cout << '-';
			else if (map[i][j] == tile::curve_left)		std::cout << '\\';
			else if (map[i][j] == tile::curve_right)	std::cout << '/';
			else if (map[i][j] == tile::intersection)	std::cout << '+';
			else										std::cout << ' ';
		}
		std::cout << std::endl;
	}
};
const auto getPriorityQueue = [](cart_collection& c)
{
	cart_queue q(cart_comparator);
	for (auto e : c)
		q.push(e);
	return q;
};

const auto moveCart = [](cart& c, map_type& map)
{
	switch (c.orientation)
	{
		case direction::up: c.y -= 1; break;
		case direction::down: c.y += 1; break;
		case direction::left: c.x -= 1; break;
		case direction::right: c.x += 1; break;
	}
	const auto tile = map[c.y][c.x];
	if (tile == tile::intersection)
	{
		if (c.last_move == turn_orientation::left)
		{
			switch (c.orientation)
			{
				case direction::up: c.orientation = direction::left; break;
				case direction::down: c.orientation = direction::right; break;
				case direction::left: c.orientation = direction::down; break;
				case direction::right: c.orientation = direction::up; break;
			}
			c.last_move = turn_orientation::straight;
		}
		else if (c.last_move == turn_orientation::straight)
		{
			c.last_move = turn_orientation::right;
		}
		else if (c.last_move == turn_orientation::right)
		{
			switch (c.orientation)
			{
			case direction::up: c.orientation = direction::right; break;
			case direction::down: c.orientation = direction::left; break;
			case direction::left: c.orientation = direction::up; break;
			case direction::right: c.orientation = direction::down; break;
			}
			c.last_move = turn_orientation::left;
		}
	}
	else if (tile == tile::curve_left) // '\'
	{
		switch (c.orientation)
		{
		case direction::up: c.orientation = direction::left; break;
		case direction::down: c.orientation = direction::right; break;
		case direction::left: c.orientation = direction::up; break;
		case direction::right: c.orientation = direction::down; break;
		}
	}
	else if (tile == tile::curve_right) // '/'
	{
		switch (c.orientation)
		{
		case direction::up: c.orientation = direction::right; break;
		case direction::down: c.orientation = direction::left; break;
		case direction::left: c.orientation = direction::down; break;
		case direction::right: c.orientation = direction::up; break;
		}
	}
};

const auto colisionDetector = [](cart_collection& v)
{
	std::set<std::pair<std::size_t, std::size_t>> temp;
	auto queue = getPriorityQueue(positions);
	while (!queue.empty())
	{
		auto c = queue.top();
		queue.pop();
		if (c.x == 41 && c.y == 17)
		{
			std::cout << "ZONK";
		}
		if (auto[_, isInserted] = temp.insert(std::make_pair(c.x, c.y)); !isInserted)
		{
			std::cout << c.x << " - " << c.y << std::endl;
			print(map);
			return true;
		}
	}
	return false;
};

int main()
{
	readFile(map);
	//print(map);
	unsigned counter = 1;
	while (!colisionDetector(positions))
	{
		//std::cout << counter << std::endl;
		auto queue = getPriorityQueue(positions);
		positions.clear();
		while (!queue.empty())
		{
			auto c = queue.top();
			moveCart(c, map);
			positions.push_back(c);
			queue.pop();
		}
		++counter;
	}

	//55,40 - NOK
	//41,17 -> should be like that!
	return 0;
}