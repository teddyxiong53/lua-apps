#define QUOTE(...) #__VA_ARGS__
static const char *lua_code = QUOTE(
print("Hello, Lua C API")\n
print("Hello, Lua C API")\n
print("Hello, Lua C API")\n
);

int main(int argc, char const *argv[])
{
    printf("%s", lua_code);
    return 0;
}
