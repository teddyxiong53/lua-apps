//都是要包含这3个头文件的。
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

//编译：gcc 01-load-lua.c -I/usr/include/lua5.3 -llua5.3
int main(int argc, char const *argv[])
{
    lua_State *L = luaL_newstate();//创建一个lua虚拟机
    //然后要打开lua自带的所有标准库。
    luaL_openlibs(L);
    //然后读取执行文件。
    int status = luaL_loadfile(L, "helloworld.lua");
    int ret = 0;
    if (status == LUA_OK) {
        printf("load lua file ok\n");
        ret = lua_pcall(L, 0, 0, 0);
        printf("lua_pcall ret:%d\n", ret);
    } else {
        printf("load lua file fail\n");
    }
    lua_close(L);
    return 0;
}

