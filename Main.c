#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lectura_csv.c"
#include "hashtable.h"
#include "list.h"
#include "Poke.h"
#include "menu.c"
int main()
{
    init_var(); //inicializar variables globales
    menu(); //entrar al menu
    return(0);
}