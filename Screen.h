#ifndef CPP_SCREEN_H
#define CPP_SCREEN_H

#include <string>
#include <vector>


// 表示显示器的一个窗口
class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen( pos ht, pos wd, char c );

    // 读取光标处字符
    inline char get() const { return contents[cursor]; }
    inline char get( pos ht, pos wd ) const;

    // 设置光标所在处的字符
    Screen &set(char);

    inline Screen &set( pos, pos, char );

    Screen &move( pos r, pos c );

    Screen &display( std::ostream &os )
    {
        do_display(os);
        return *this;
    }

    pos get_high() { return high; }

    const Screen &display( std::ostream &os ) const
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos high   = 0;
    pos width  = 0;
    std::string contents;

    void do_display( std::ostream &os ) const
    {
        os << contents;
    }
};

class Window_mgr
{
private:
    std::vector<Screen> screens { Screen(24, 80, ' ') };
};

#endif //CPP_SCREEN_H
