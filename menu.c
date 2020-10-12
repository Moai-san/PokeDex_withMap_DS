#include <stdio.h>
#include "list.h"
#include "hashtable.h"
#include "Poke.h"

/*System Condition, only if it's Compiled in windows, includes the library*/
#ifdef _WIN32
    #include <windows.h>
#endif


/*Cleans The Screen (yup, i know that is obvious, but i have to comment that)*/
void clear_Screen()
{
    #ifdef _WIN32
    {
        system("cls");
    }
    #else
    {
        system("reset");
    }
    #endif
}

/*Menu (yup, i know that is obvious, but i have to comment that)*/
int menu ()
{
    printf("Bienvenid@ Pokemaster! OwO\nQue te gustaria hacer hoy?(\'w\')\na)Importar CSV\nb)Exportar CSV\nc)Atrapar un Pokemon\nd)Buscar Pokemon por tipo\ne)Buscar Pokemon por nombre\nf)Buscar Pokemon por nombre en la PokeDex\ng)Mostrar Pokemon de \"x\" region\nh)Mostrar Pokemon ordenados por PC\ni)Mostrar Pokemon ordenados por PS\nj)Mostrar todos los Pokemon de la PokeDex\nk)Liberar un Pokemon\nl)limpiar la pantalla\nSi no quieres nada, solo presiona la tecla enter uwu\n");
    char option;
    short int flag;
    flag =(-1);
    char garbageBin;//papelera para la basura que se situa en stdin
    do
    {
        if (flag==(1))
        {
            printf("Te gustaria Hacer algo Mas?(\'w\')\na)Importar CSV\nb)Exportar CSV\nc)Atrapar un Pokemon\nd)Buscar Pokemon por tipo\ne)Buscar Pokemon por nombre\nf)Buscar Pokemon por nombre en la PokeDex\ng)Mostrar Pokemon de \"x\" region\nh)Mostrar Pokemon ordenados por PC\ni)Mostrar Pokemon ordenados por PS\nj)Mostrar todos los Pokemon de la PokeDex\nk)Liberar un Pokemon\nl)limpiar la pantalla\nSi no quieres nada, solo presiona la tecla enter uwu\n");
        }
        scanf("%c",&option);
            switch (option)
            {
                case 'a': //caso a, importar archivo
                {
                    char* file;
                    file =((char*)calloc(105,sizeof(char)));
                    printf("Ingresa el nombre del archivo a importar! OwO (nombre sin el formato) uwu \n");
                    scanf("%c",&garbageBin);
                    scanf("%[^\n]",file);
                    clear_Screen();
                    importCSV(file);
                    break;
                }
                case 'b': //caso b, exportar archivo
                {
                    char* name;
                    name =((char*)calloc(105,sizeof(char)));
                    printf("Ingrese el nombre que desea que tenga el archivo a exportar! (nombre sin el formato) uwu \n");
                    scanf("%c",&garbageBin);
                    scanf("%[^\n]",name);
                    clear_Screen();
                    exportCSV(name);
                    break;
                }
                case 'c': //caso c, atrapar pokemon
                {
                    scanf("%c",&garbageBin);
                    char* name;
                    name =((char*)calloc(105,sizeof(char)));
                    char* kind;
                    kind =((char*)calloc(105,sizeof(char)));
                    char* region;
                    region =((char*)calloc(105,sizeof(char)));
                    char* evolveFrom;
                    evolveFrom =((char*)calloc(105,sizeof(char))); 
                    char* evolvesIn;
                    evolvesIn =((char*)calloc(105,sizeof(char)));
                    int pc;
                    int ps;
                    int uid;
                    int pokedex_id;
                    char* gender;
                    gender =((char*)calloc(105,sizeof(char)));
                    printf("Ingresa el nombre\n");
                    scanf("%[^\n]",name);
                    scanf("%c",&garbageBin);
                    printf("Ingresa el/los Tipo(s) (si es mas de un tipo, ingrese separados por coma, como en el ejemplo \"Fuego, Volador\", sin comillas)\n");
                    scanf("%[^\n]",kind);
                    scanf("%c",&garbageBin);
                    printf("Ingresa la ID del pokemon\n");
                    scanf("%d",&uid);
                    scanf("%c",&garbageBin);
                    printf("Ingresa la evolucion previa\n");
                    scanf("%[^\n]",evolveFrom);
                    scanf("%c",&garbageBin);
                    printf("Ingresa la evolucion posterior\n");
                    scanf("%[^\n]",evolvesIn);
                    scanf("%c",&garbageBin);
                    printf("Ingresa el numero en la pokedex del pokemon\n");
                    scanf("%d",&pokedex_id);
                    printf("Ingresa la region\n");
                    scanf("%c",&garbageBin);
                    scanf("%[^\n]",region);
                    printf("Ingresa los PC del pokemon\n");
                    scanf("%d",&pc);
                    printf("Ingresa los PS del pokemon\n");
                    scanf("%d",&ps);
                    printf("Ingresa el sexo del pokemon\n");
                    scanf("%c",&garbageBin);
                    scanf("%[^\n]",gender);
                    clear_Screen();
                    addPoke(name,kind,uid,evolveFrom,evolvesIn,pokedex_id,region,pc,ps,gender);
                    break;
                }
                case 'd': //caso d, buscar por tipo
                {
                    char kind [105];
                    printf("ingrese tipo de Pokemon!\n");
                    scanf("%c",&garbageBin);
                    scanf("%[^\n]",kind);
                    clear_Screen();
                    search_byKind(kind);
                    break;
                }
                case 'e': //caso e, buscar por nombre
                {
                    char name [105];
                    printf("ingrese nombre del Pokemon!\n");
                    scanf("%c",&garbageBin);
                    scanf("%[^\n]",name);
                    clear_Screen();
                    search_byName(name);
                    break;
                }
                case 'f': //caso f, buscar por nombre en la pokedex
                {
                    char dex_name [105];
                    printf("ingrese nombre del Pokemon!\n");
                    scanf("%c",&garbageBin);
                    scanf("%[^\n]",dex_name);
                    clear_Screen();
                    dex_search_byName(dex_name);
                    break;
                }
                case 'g': //caso g, mostrar por region
                {
                    char region [105];
                    printf("ingrese region!\n");
                    scanf("%c",&garbageBin);
                    scanf("%[^\n]",region);
                    clear_Screen();
                    show_fromRegion(region);
                    break;
                }
                case 'h': //caso h, mostrar por pc
                {
                    clear_Screen();
                    show_byPC();
                    break;
                }
                case 'i': //caso i, mostrar por ps
                {
                    clear_Screen();
                    show_byPS();
                    break;
                }
                case 'j': //caso j, mostrar pokedex completa
                {
                    clear_Screen();
                    print_dex();
                    break;
                }
                case 'k': //caso k, liberar pokemon
                {
                    int id;
                    printf("ingrese ID del pokemon a eliminar!\n");
                    scanf("%d",&id);
                    clear_Screen();
                    del_poke(id);
                    break;
                }
                case 'l': //caso l, limpiar pantalla
                {
                    clear_Screen();
                    break;
                }
                case '\n': //caso enter, cambia el flag
                {
                    flag =(0);
                    break;
                }
                default: //caso cualquier otra tecla (excepto la ñ, que no la toma como letra, me parece que por el numero en la tabla ascii)
                    clear_Screen();
                    printf("Entrada invalida!");
                    break;
            }
            if (flag!=0)
            {
                scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                flag =(1);
            }
    }
    while (flag!=(0)); //si el flag es 0 (apretaron enter), se corta el while y cierra el programa
    return(0);
}