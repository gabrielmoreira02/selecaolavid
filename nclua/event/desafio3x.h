
#include <lua.h>                                
#include <lauxlib.h>                        
#include <lualib.h>                             
#include <stdlib.h>                           
#include <stdio.h>                            


/* O CODIGO ESTÁ INSERIDO NO .H POIS NÃO CONSEGUI QUE O GNU RECONHECESSE O .C NESSA PASTA 
(EMBORA EM TODAS OUTRAS EU TENHA FEITO, POR ALGUM MOTIVO, MANIPULAR ESTE MAKEFILE.AM FOI MAIS
COMPLICADO*/

int mensagens(){
    lua_State *L;

    L = luaL_newstate();                        // Cria uma varivel Lua State 
    luaL_openlibs(L);                           // Carrega as bibliotecas de lua

    if (luaL_loadfile(L, "../nclua/event/desafio3.lua")) // Lemos o arquivo lua porém não executa
        return 0;                                        // Erro 1: Não foi possivel ler o arquivo

    if (lua_pcall(L, 0, 0, 0))                  // PRIMING RUN, por algum motivo é importante (?)
        return 0;                               // Erro 2: Arquivo LUA tem erros

 

    lua_getglobal(L, "msg");                    // Chamamos a função MSG dentro de lua
    lua_pushstring(L, "Oi lua, essa eh uma mensagem de C"); //Passamos a string pra pilha (parametro)
    if (lua_pcall(L, 1, 1, 0))                  // Rodamos a função
	   return 0; 

    printf("Voltamos pro C\n");

    char *resposta  = lua_tostring(L, -1);
    printf("%s", resposta);
    printf("------------ mensagem enviada por LUA e printada por C\n\n\n");
    lua_close(L);                               //Garbage collector
    return 1;
}