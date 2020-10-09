#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lectura_csv.c"
#include "hashtable.h"
#include "list.h"
#include "Poke.h"
int main()
{
    init_var();
    HashMap* Poke_byName =createMap(90);
    HashMap* Poke_byKind =createMap(90);
    List* PokeDex =create_list();
    importCSV("PokeList1",PokeDex,Poke_byName,Poke_byKind);
    //importCSV("PokeList1",PokeDex,Poke_byName,Poke_byKind);
    search_byName("Charmander",Poke_byName);
    printf("\n\n");
    show_byPS();
    //dex_search_byName("Patamon",PokeDex);
    //search_byKind("Agua",Poke_byKind);
    //printf("\n\n");
    //show_fromRegion("Kanto",PokeDex);
    //print_All(PokeDex);
    HashMap* Mappy =createMap(7);
    //insertMap(Mappy,"helloThere","meow~♡\n ^ ^\n(°w°)↝\n ⎻⎻⎻");
    //printf ("%s\n",(char*)(searchMap(Mappy,"helloThere")));
    return(0);
}