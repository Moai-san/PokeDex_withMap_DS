//Leonardo Gonzalez Catalan - October/01/2020
#ifndef Poke_h
#define Poke_h
#include "Poke.c"

typedef struct Pokemon Pokemon;
typedef struct PokeNode PokeNode;

PokeNode* create_PokeNode();
Pokemon* create_Pokemon(Pokemon* input);
int addPoke(char* Name, char* kind, int uid, char* evolveFrom, char* evolvesIn, int poke_id, char* region, int pc, int ps, char* gender);
void dex_search_byName(char* name);
void search_byKind(char* Kind);
void search_byName(char* Name);
void exportCSV(char* name);
void importCSV(char* name);
void print_All(List* Pokemons);


#endif