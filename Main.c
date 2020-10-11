#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lectura_csv.c"
#include "hashtable.h"
#include "list.h"
#include "Poke.h"
//#include "menu.c"
int main()
{
    init_var();
    //importCSV("PokeList1");
    importCSV("PokeList1");
    printf("\n");
    //menu();
    del_poke(64);
    //dex_search_byName("Snorlax");
    printf("\n\n");
    search_byKind("Normal, Fuego, Agua, Planta");
    printf("\n\n");
    search_byName("Snorlax");
    show_byPC();
    exportCSV("cocos");
    //printf("\n\n");
    //show_fromRegion("Kanto",PokeDex);
    //print_All(PokeDex);
    HashMap* Mappy =createMap(7);
    //insertMap(Mappy,"helloThere","meow~♡\n ^ ^\n(°w°)↝\n ⎻⎻⎻");
    //printf ("%s\n",(char*)(searchMap(Mappy,"helloThere")));
    return(0);
}