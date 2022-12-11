//都是要包含这3个头文件的。
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
#include "minheap.h"

void reg_luaminheap(lua_State *L);
//编译：gcc test-luaminheap.c -I/usr/include/lua5.3 -llua5.3
int main(int argc, char const *argv[])
{
    lua_State *L = luaL_newstate();//创建一个lua虚拟机
    //然后要打开lua自带的所有标准库。

    luaL_openlibs(L);
    // 载入minheap的库
    reg_luaminheap(L);
    luaL_dofile(L, "test-luaminheap.lua");
    lua_close(L);
    return 0;
}

