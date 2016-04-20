#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

template<unsigned W, unsigned H>
class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(char c) : contents(width * height, c) { }
	char get() const { return contents[curr]; }
	Screen &set(char);
	Screen &set(char, pos, pos);
	Screen &move(pos w, pos h);
	Screen &clear();
private:
	pos cursor = 0;
	pos width = W, height = H;
	std::string contents;
};

template<unsigned W, unsigned H>
Screen<W, H> &Screen<W, H>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template<unsigned W, unsigned H>
Screen<W, H> &Screen<W, H>::set(char c, pos w, pos h)
{
	contents[h * width + w] = c;
	return *this;
}

template<unsigned W, unsigned H>
Screen<W, H> &Screen<W, H>::move(pos w, pos h)
{
	cursor = h * width + w;
	return *this;
}

template<unsigned W, unsigned H>
Screen<W, H> &Screen<W, H>::clear()
{
	contents = std::string(height * width, " ");
	return *this;
}


#endif