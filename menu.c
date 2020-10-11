#include <stdio.h>
#include "list.h"
#include "hashtable.h"
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
int menu (List* PokeDex, HashMap* Poke_byName,HashMap* Poke_byKind)
{
    printf("Bienvenid@ Pokemaster! OwO\nQue te gustaria hacer hoy?(\'w\')\na)Importar CSV\nb)Exportar CSV\nc)Atrapar un Pokemon\nd)Buscar Pokemon por tipo\ne)Buscar Pokemon por nombre\nf)Buscar Pokemon por nombre en la PokeDex\ng)Mostrar Pokemon de \"x\" region\nh)Mostrar Pokemon ordenados por PC\ni)Mostrar Pokemon ordenados por PS\nj)Mostrar todos los Pokemon de la PokeDex\nk)Liberar un Pokemon\nSi no quieres nada, solo presiona la tecla enter uwu\n");
    char option;
    short int flag;
    flag =(-1);
    char garbageBin;//papelera para la basura que se situa en stdin
    do
    {
        /*a)Importar CSV b)Exportar CSV c)Atrapar un Pokemon d)Buscar Pokemon por tipo e)Buscar Pokemon por nombre f)Buscar Pokemon por nombre en la PokeDex 
        g)Mostrar Pokemon de x region h)Mostrar Pokemon ordenados por PC i)Mostrar Pokemon ordenados por PS j)Mostrar todos los Pokemon de la PokeDex k)Liberar un Pokemon*/
        if (flag==(1))
        {
            printf("Te gustaria Hacer algo Mas?(\'w\')\na)Importar juegos\nb)Exportar juegos\nc)Agregar juego\nd)Buscar juegos para 'x' cantidad de jugadores\ne)Buscar juegos de 'x' marca\nf)Buscar un juego\ng)Buscar juego por tipo\nh)Busqueda Avanzada\ni)Mostrar todos los juegos\nj)Mostrar expansiones\nSi no quieres nada, solo presiona la tecla enter uwu\n");
        }
        scanf("%c",&option);
            switch (option)
            {
                case 'a':
                {
                    char* file;
                    file =((char*)calloc(105,sizeof(char)));
                    printf("Ingresa el nombre del archivo a importar! OwO (nombre sin el formato) uwu \n");
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    scanf("%[^\n]",file);
                    clear_Screen();
                    importCSV(file,,PokeDex,Poke_byName,Poke_byKind);
                    break;
                }
                case 'b':
                {
                    char* name;
                    name =((char*)calloc(105,sizeof(char)));
                    printf("Ingrese el nombre que desea que tenga el archivo a exportar! (nombre sin el formato) uwu \n");
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    scanf("%[^\n]",name);
                    clear_Screen();
                    exportGames(name,Juegos);
                    printf("Se exportaron los Juegos al archivo %s.csv\n",name);
                    break;
                }
                case 'c':
                {
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    char* name;
                    name =((char*)calloc(105,sizeof(char)));
                    char* brand;
                    brand =((char*)calloc(105,sizeof(char)));
                    char* kind;
                    kind =((char*)calloc(105,sizeof(char)));
                    int min;
                    int max;
                    char* expansion;
                    expansion =((char*)calloc(105,sizeof(char)));
                    printf("Ingresa el nombre\n");
                    scanf("%[^\n]",name);
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    printf("Ingresa La Marca\n");
                    scanf("%[^\n]",brand);
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    printf("Ingresa El tipo de Juego\n");
                    scanf("%[^\n]",kind);
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    printf("Ingresa el numero minimo de Jugadores\n");
                    scanf("%d",&min);
                    printf("Ingresa el numero maximo de Jugadores\n");
                    scanf("%d",&max);
                    printf("Ingresa el juego base en caso de ser una expansion, si no lo es, escribe \"No aplica\" (sin las comillas)\n");
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    scanf("%[^\n]",expansion);;
                    clear_Screen();
                    addGames(name,brand,kind,min,max,expansion,Juegos);
                    break;
                }
                case 'd':
                {
                    int range;
                    printf("ingrese la cantidad de jugadores!\n");
                    scanf("%d",&range);
                    clear_Screen();
                    search_byRange(range,Juegos);
                    break;
                }
                case 'e':
                {
                    char* brand =((char*)calloc(100,sizeof(char)));
                    printf("ingrese la marca a filtrar!\n");
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    scanf("%[^\n]",brand);
                    clear_Screen();
                    search_byBrand(brand,Juegos);
                    break;
                }
                case 'f':
                {
                    char* name =((char*)calloc(100,sizeof(char)));
                    printf("ingrese el nombre a filtrar!\n");
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    scanf("%[^\n]",name);
                    clear_Screen();
                    search_byName(name,Juegos);
                    break;
                }
                case 'g':
                {
                    char* kind =((char*)calloc(100,sizeof(char)));
                    printf("Escriba el tipo de juego a buscar! =o= (si buscas juegos que sean de 2 o mas tipos a la vez, debes escribirlos en el siguiente formato \"tipo1, tipo2, tipoN\" (sin las comillas) ), con otro formato no encontrara\n");
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    scanf("%[^\n]",kind);
                    clear_Screen();
                    search_byKind(kind,Juegos);
                    break;
                }
                case 'h':
                {
                    char* kind =((char*)calloc(100,sizeof(char)));
                    int range;
                    printf("Escriba el tipo de juego a buscar! =o=\n");
                    scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
                    scanf("%[^\n]",kind);
                    printf("Escriba el numero de jugadores! (=w=)7\n");
                    scanf("%d",&range);
                    clear_Screen();
                    advanced_Search(kind,range,Juegos);
                    break;
                }
                case 'i':
                {
                    clear_Screen();
                    print_All(Juegos);
                    break;
                }
                case 'j':
                {
                    clear_Screen();
                    print_Expansions(Juegos);
                    break;
                }
                case '\n':
                {
                    flag =(0);
                    break;
                }
                default:
                    //scanf("%c",&garbageBin);//llamada a la papelera para la basura que se situa en stdin
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
    while (flag!=(0));
    return(0);
}