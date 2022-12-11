//都是要包含这3个头文件的。
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

int callLuaAdd(lua_State *L, int x, int y)
{
    int sum = 0;
    int ret =0;
    //先拿到名字为lua_add的lua函数。并把它放到栈顶。
	ret = lua_getglobal(L, "luaAdd");
    if (ret != LUA_OK) {
        printf("getglobal fail:%d", ret);
        return -1;
    }
	//往lua栈里push 2个参数。
	//从左往右的顺序。
	lua_pushnumber(L, x);
	lua_pushnumber(L, y);
	//调用函数，参数里的2表示参数的个数，1是表示返回值的个数。
	ret = lua_pcall(L, 2, 1, 0);
    if (ret != LUA_OK) {
        printf("pcall fail:%d\n", ret);
        return -1;
    }
	//然后就可以读取放在栈顶的结果了。
	sum = lua_tointeger(L, -1);//-1表示栈顶。
	//最后把结果从栈顶pop掉。
	lua_pop(L, 1);//1表示1个结果。
	return sum;
}
//编译：gcc 02-call-a-lua-func.c -I/usr/include/lua5.3 -llua5.3
int main(int argc, char const *argv[])
{
    lua_State *L = luaL_newstate();//创建一个lua虚拟机
    //然后要打开lua自带的所有标准库。
    luaL_openlibs(L);
    //然后读取执行文件。
    int status = luaL_loadfile(L, "add.lua");
    int ret = 0;
    if (status == LUA_OK) {
        printf("load lua file ok\n");
        ret = callLuaAdd(L, 1,2);
        printf("add result:%d\n", ret);
    } else {
        printf("load lua file fail\n");
    }
    lua_close(L);
    return 0;
}

