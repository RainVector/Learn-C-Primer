#include <iostream>
#include <string>

class Screen{
public:
	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos ht, pos wd):height(ht),width(wd),contents(ht*wd,' '){}
	Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht*wd,c){}

	char get() const { return contents[cursor];}
	inline char get(pos r, pos c) const;
	Screen move(pos r, pos c);
	Screen set(char c);
	Screen set(pos r,pos c, char ch);
	
	Screen display(std::ostream &os)
			{ do_display(os); return *this;}
	const Screen display(std::ostream &os) const
			{ do_display(os); return *this;}
	void countCallBack() const;

private:
	void do_display(std::ostream &os) const { os << contents;}
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t access_ctr;
};

char Screen::get(pos r, pos c) const
{
	pos row = width * r; //cal row pos
	return contents[row + c]; // return the character of wd column
}

Screen Screen::move(pos r, pos c)
{
	pos row = width * r;
	cursor = row + c;
	return *this;
}

void Screen::countCallBack() const
{
	//incress one if the object is called everytime 
	++access_ctr;
}
Screen Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
	
Screen Screen::set(pos r,pos c, char ch)
{
	contents[r*width+c] = ch;
	return *this;
}

int main()
{
	Screen myscreen(5,5, 'X');
	myscreen.move(4,0).set('#').display(std::cout);
	std::cout<<std::endl;

	myscreen.display(std::cout);

	std::cout<<std::endl;

	return 0;
}
