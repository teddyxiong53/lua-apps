#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
#include "mylog.h"
#include "minheap.h"
#define LUAMINHEAP_METATABLE "luaminheap_metatable"

typedef struct {
    minheap_t m;
} *lua_minheap_t ;

struct stluaheap_ele {
    struct heapele base;
    uint64_t n;
    // luaRef_t luaObj;
};

static inline lua_getluaminheap(lua_State *L, int index)
{
    return (lua_minheap_t)luaL_testudata(L, index, LUAMINHEAP_METATABLE);
}

static int destroy_minheap(lua_State *L)
{
    lua_minheap_t m = lua_getluaminheap(L, 1);
    mylogd("");
    //在这里进行释放内存等操作。
    return 0;
}

static int _insert(lua_State *L)
{
    lua_minheap_t m = lua_getluaminheap(L, 1);
    mylogd("");
    return 0;
}
static int _remove(lua_State *L)
{
    lua_minheap_t m = lua_getluaminheap(L, 1);
    mylogd("");
    return 0;
}
static int _pop(lua_State *L)
{
    lua_minheap_t m = lua_getluaminheap(L, 1);
    mylogd("");
    return 0;
}
static int _change(lua_State *L)
{
    lua_minheap_t m = lua_getluaminheap(L, 1);
    mylogd("");
    return 0;
}
static int8_t less(struct heapele*l,struct heapele*r){//if l < r return 1,else return 0
	return ((struct stluaheap_ele*)l)->n < ((struct stluaheap_ele*)r)->n ? 1:0;
}


static int luaminheap_new(lua_State *L)
{
    lua_minheap_t m = (lua_minheap_t)lua_newuserdata(L, sizeof(*m));
    m->m = minheap_create(100, less);
    luaL_getmetatable(L, LUAMINHEAP_METATABLE);
    lua_setmetatable(L, -2);
    mylogd("");
    return 1;
}

void reg_luaminheap(lua_State *L)
{
    //mt表示metatable
    luaL_Reg minheap_mt[] = {
        {"__gc", destroy_minheap},
        {NULL, NULL}
    };
    //
    luaL_Reg minheap_methods[] = {
        {"Insert", _insert},
        {"Remove", _remove},
        {"Pop", _pop},
        {"Change", _change},
        {NULL, NULL}
    };
    //注册元表
    luaL_newmetatable(L,LUAMINHEAP_METATABLE );
    luaL_setfuncs(L, minheap_mt, 0);
    //注册库
    luaL_newlib(L, minheap_methods);
    lua_setfield(L, -2, "__index");
    lua_pop(L, 1);

    //
    luaL_Reg l[] = {
        {"New", luaminheap_new},
        {NULL, NULL}
    };
    luaL_newlib(L, l);
    lua_setglobal(L, "CMinHeap");
}