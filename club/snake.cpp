//
// Created by algasami on 2022/12/20.
//

#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> int2d;

int height, width;
int2d dat;

inline bool walked(int x, int y)
{
    return dat[y][x] != -1;
}

inline bool inbound(int x, int y)
{
    if (y < height && y >= 0 && x < width && x >= 0 && !walked(x, y))
    {
        return true;
    }
    return false;
}

inline void printMap()
{
    for (const auto &line : dat)
    {
        for (const auto val : line)
        {
            cout << val << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int x, int y, int steps)
{
    if (!inbound(x, y))
    {
        return;
    }
    if (walked(x, y))
    {
        // not complete...
        return;
    }
    dat[y][x] = steps;
    if (steps >= width * height)
    {
        printMap();
        return;
    }
    //    cout << "(" << x << ", " << y << ")" << endl;
    //    printMap();

    // right
    int cache;
    if (inbound(x + 1, y))
    {
        cache = dat[y][x + 1];
        dfs(x + 1, y, steps + 1);
        dat[y][x + 1] = cache;
    }
    if (inbound(x, y + 1))
    {
        cache = dat[y + 1][x];
        dfs(x, y + 1, steps + 1);
        dat[y + 1][x] = cache;
    }
    if (inbound(x - 1, y))
    {
        cache = dat[y][x - 1];
        dfs(x - 1, y, steps + 1);
        dat[y][x - 1] = cache;
    }
    if (inbound(x, y - 1))
    {
        cache = dat[y - 1][x];
        dfs(x, y - 1, steps + 1);
        dat[y - 1][x] = cache;
    }
}

int main()
{
    cout << "Height: ";
    cin >> height;
    cout << "Width: ";
    cin >> width;
    dat = int2d(height, vector<int>(width, -1));
    int start_x, start_y;
    cout << "Start X:";
    cin >> start_x;
    cout << "Start Y:";
    cin >> start_y;
    start_x--;
    start_y--;
    if (height * width == 1)
    {
        cout << "1";
        return 0;
    }
    dfs(start_x, start_y, 1);

    return 0;
}