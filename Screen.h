#ifndef CPP_SCREEN_H
#define CPP_SCREEN_H

#include <string>
#include <vector>

// 表示显示器的一个窗口
class Screen
{
    friend class Window_mgr; // window_mgr对象可以访问 Screen 类的私有部分

public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen( pos ht, pos wd ) : height(ht), width(wd), contents( ht * wd, ' ') { }
    Screen( pos ht, pos wd, char c ) : height(ht), width(wd), contents( ht * wd, c ) { }

    // 获取当前光标处字符
    char get() const { return contents[cursor]; }

    // 获取指定位置处字符
    char get( pos ht, pos wd ) const;

    pos get_high() { return height; }

    pos size() const;

    // 设置当前光标处字符
    Screen &set( char );

    // 设置指定位置处字符
    Screen &set( pos, pos, char );

    // 移动当前光标到此位置
    Screen &move( pos r, pos c );

    Screen &display( std::ostream &os )
    {
        do_display(os);
        return *this;
    }

    const Screen &display( std::ostream &os ) const
    {
        do_display(os);
        ++access_ctr;
        return *this;
    }

private:
    pos cursor = 0;                 // 光标位置
    pos height = 0;                 // 高
    pos width  = 0;                 // 宽
    std::string contents;           // 屏幕的内容
    mutable size_t access_ctr = 0;  // mutable 声明的成员变量，即使在常量对象中，也可以被修改值
                                    // 用于计数，某成员函数被调用的次数

    void do_display( std::ostream &os ) const
    {
        os << contents;
    }
};

#endif //CPP_SCREEN_H
