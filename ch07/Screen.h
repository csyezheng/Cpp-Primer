#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};

class Screen
{
public:
	friend void Window_mgr::clear(ScreenIndex);
	using pos = std::string::size_type;
	
	// constructor functions
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd) { }
	Screen(pos ht, pos wd, char ch) :
		height(ht), width(wd), contents(std::string(ht*wd, ch)) { }
	
	// members functions
	char get() const 
	{ 
		return contents[cursor]; 
	}
	char get(const pos r, const pos c) const
	{
		pos rows = r * width;
		return contents[rows];
	}
	Screen &move(const pos r, const pos c)
	{
		cursor = r * width + c;
		return *this;
	}
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}
	Screen &set(char ch)
	{
		contents[cursor] = ch;
		return *this;
	}
	Screen &set(pos wd, pos ht, char ch)
	{
		contents[wd * ht] = ch;
		return *this;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const
	{
		os << contents;
	}
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

#endif