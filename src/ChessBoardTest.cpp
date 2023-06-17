#include <graphics.h>
#include <conio.h>
#include <iostream>

#define GRID_SIZE 8  // 棋盘格子的数量
#define GRID_WIDTH 50  // 棋盘格子的宽度

struct BUTTON
{
    int left;
    int top;
    int right;
    int bottom;
    bool visible;
    TCHAR caption[256];
};

bool isPointInButton(int x, int y, const BUTTON& btn)
{
    return (x >= btn.left && x <= btn.right && y >= btn.top && y <= btn.bottom);
}

void drawButton(const BUTTON& btn)
{
    setfillcolor(WHITE);
    fillrectangle(btn.left, btn.top, btn.right, btn.bottom);
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, _T("宋体"));
    outtextxy((btn.left + btn.right) / 2 - textwidth(btn.caption) / 2, (btn.top + btn.bottom) / 2 - textheight(btn.caption) / 2, btn.caption);
}

int main()
{
    initgraph(800, 600);  // 创建绘图窗口

    BUTTON buttons[GRID_SIZE][GRID_SIZE];

    // 初始化按钮
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = (GRID_SIZE - i + 2 * j) * GRID_WIDTH / 2;
            int y = (i + 1) * GRID_WIDTH;

            BUTTON& btn = buttons[i][j];
            btn.left = x - GRID_WIDTH / 2;
            btn.top = y - GRID_WIDTH / 2;
            btn.right = x + GRID_WIDTH / 2;
            btn.bottom = y + GRID_WIDTH / 2;
            btn.visible = true;
            _stprintf_s(btn.caption, _T(""));

            drawButton(btn);
        }
    }

    MOUSEMSG m;
    while (true)
    {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN)
        {
            for (int i = 0; i < GRID_SIZE; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    BUTTON& btn = buttons[i][j];
                    if (btn.visible && isPointInButton(m.x, m.y, btn))
                    {
                        // 按钮被点击，执行相应的逻辑
                        // 在这里添加按钮点击的处理代码
                        // 例如，可以在控制台输出按钮的坐标
                        _tprintf(_T("Button clicked: (%d, %d)\n"), i, j);
                    }
                }
            }
        }
    }

    closegraph();  // 关闭绘图窗口
    return 0;
}
