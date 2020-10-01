//Leonardo Gonzalez Catalan - October/01/2020
#ifndef Poke_h
#define Poke_h
#include "Poke.c"

typedef struct Pokemon Pokemon;
typedef struct PokeNode PokeNode;

PokeNode create_PokeNode(PokeNode input);
Pokemon create_Pokemon(Pokemon input);
void addPoke(char* Name, char* kind, int uid, char* evolveFrom, char* evolvesIn, int poke_id, char* region, int pc, int ps, char* gender, List* Pokedex, HashMap* PokeBag);
void dex_search_byName(char* name,List* PokeDex);
void search_byKind(char* Kind,HashMap* Poke_byKind);
//void search_byName(char* Name,List* Pokemons);
//void exportCSV(char* name,List* Pokemons);
void importCSV(char* name,List* PokeBag,HashMap* PokeDex);
void print_All(List* Pokemons);


#endif