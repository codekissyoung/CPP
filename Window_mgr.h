#ifndef CPP_WINDOW_MGR_H
#define CPP_WINDOW_MGR_H

#include "Screen.h"

#include <vector>

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    // 按照编号将指定的 Screen 重置为空白
    void clear(ScreenIndex);

    // 向窗口管理器中添加一个 screen
    ScreenIndex addScreen( const Screen &);

private:
    // 默认情况下，一个 window_mgr 包含一个标准尺寸的空白 Screen
    std::vector<Screen> screens { Screen( 24, 80, ' ' ) };
};

#endif //CPP_WINDOW_MGR_H
