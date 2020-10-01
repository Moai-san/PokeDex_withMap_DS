#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lectura_csv.c"
#include "hashtable.h"
#include "list.h"
#include "Poke.h"
int main()
{
    HashMap* Poke_byKind =createMap(30);
    List* a =create_list();
    importCSV("PokeList1",a,Poke_byKind);
    print_All(a);
    HashMap* Mappy =createMap(7);
    insertMap(Mappy,"helloThere","meow~♡\n ^ ^\n(°w°)↝\n ⎻⎻⎻");
    printf ("%s\n",(char*)(searchMap(Mappy,"helloThere")));
    return(0);
}