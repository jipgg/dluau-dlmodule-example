#include "dlmodule.h"
#include <iostream>

static int add_numbers(lua_State* L) {
    const double a = luaL_checknumber(L, 1);
    const double b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a + b);
    return 1;
}

constexpr luaL_Reg functions[] = {
    {"add_numbers", add_numbers},
    {nullptr, nullptr}
};
DLMODULE_API int dlrequire(lua_State *L) {
    lua_newtable(L);
    luaL_register(L, nullptr, functions);
    return 1;
}

DLMODULE_API int dlexport_print_hello(lua_State *L) {
    std::cout << "Hello from mydlmodule!\n";
    return 0;
}
