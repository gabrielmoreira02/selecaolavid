
#include <lua.h>                                /* Always include this when calling Lua */
#include <lauxlib.h>                            /* Always include this when calling Lua */
#include <lualib.h>                             /* Prototype for luaL_openlibs(), */
                                                /*   always include this when calling Lua */

#include <stdlib.h>                             /* For function exit() */
#include <stdio.h>                              /* For input/output */
#include <desafio3x.h>


int mensagens()
{
    lua_State *L;

    L = luaL_newstate();                        /* Create Lua state variable */
    luaL_openlibs(L);                           /* Load Lua libraries */

    if (luaL_loadfile(L, "../nclua/event/desafio3.lua")) /* Load but don't run the Lua script */
        return 0;      /* Error out if file can't be read */

    if (lua_pcall(L, 0, 0, 0))                  /* PRIMING RUN. FORGET THIS AND YOU'RE TOAST */
        return 0;          /* Error out if Lua file has an error */

 

    lua_getglobal(L, "msg");                 /* Tell it to run callfuncscript.lua->square() */
    lua_pushstring(L, "Oi lua, essa eh uma mensagem de C");                       /* Submit 6 as the argument to square() */
    if (lua_pcall(L, 1, 1, 0))                  /* Run function, !!! NRETURN=1 !!! */
	   return 0; 

    printf("Voltamos pro C\n");

    char *resposta  = lua_tostring(L, -1);
    printf("%s", resposta);
    printf("------------ mensagem enviada por LUA e printada por C\n\n\n");
    lua_close(L); 
                                  /* Clean up, free the Lua state var */
    return 1;
}