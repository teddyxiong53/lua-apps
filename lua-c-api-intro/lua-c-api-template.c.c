#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define QUOTE(...) #__VA_ARGS__
static const char *lua_code = QUOTE(
  print("Hello, Lua C API")
);
/* Output
Hello, Lua C API
*/

int main(int argc, char* argv[]) {
  int status = 0;

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  status = luaL_loadstring(L, lua_code) || lua_pcall(L, 0, 0, 0);
  if (status) {
    fprintf(stderr, "%s", lua_tostring(L, -1));
    lua_pop(L, 1);
  }

  lua_close(L);
  return status;
}
