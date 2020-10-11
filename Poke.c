#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include <string.h>
#include "Poke.h"
#include "treemap.h"

typedef struct Pokemon Pokemon;
typedef struct PokeNode PokeNode;
typedef struct to_csv to_csv;

List* Bag; //Bolsa pokemon, se usa para guardar todo en orden de ingreso, se usa para la funcion exportar
to_csv* toExport; //Nodo con el cual se ingresan uno por uno los datos a la Bolsa pokemon para exportar

int bag_capac =(0); /*capacidad de almacenamiento ocupada, parte en 0 , y la funcion añadir lo usa como flag,
                     en caso de valer 100 (estar lleno el almacenamiento) se imprime un mensaje en pantalla y no se ingresa el pokemon*/
TreeMap* PS; //Arbol Binario de busqueda para funcion mostrar ordenado por PS
TreeMap* PC; //Arbol Binario de busqueda para funcion mostrar ordenado por PC
List* PokeDex; //Lista Pokedex, se usó esto ya que la pokedex no requiere un orden
HashMap* PokebyName; //Tabla Hash para Pokemon ordenados por nombre
HashMap* PokebyKind; //Tabla Hash para Pokemon ordenados por tipo
HashMap* PokebyID; //Tabla Hash para Pokemon ordenados por ID, se usa en la funcion de eliminar pokemon

/* DataType Pokemon: Contain (int)uid, (char*)name, (char*)gender, (int)ps, (int)pc*/
struct Pokemon //almacena datos de combate del pokemon
{
   char* name; //nombre
   int uid; //id bolsa/usuario
   int pc; //puntos de combate
   int ps; //puntos de salud
   char* gender; //sexo pokemon
};

/* DataType PokeNode: Contain (int)uid, (char*)name, (char*)gender, (int)ps, (int)pc*/
struct PokeNode //almacena datos generales del pokemon
{
   char* name; //nombre
   int have; //existencias/cantidad en bolsa
   char* kind; //tipo
   int uid; //id bolsa/usuario
   char* evolveFrom; //evolucion posterior
   char* evolvesIn; //evolucion previa
   int poke_id; //numero/id PokeDex
   char* region; //region
};

/* DataType to_csv: Contain (PokeNode*)gen_Stats, (Pokemon*)fight_Stats*/
struct to_csv //almacena un tipo Pokemon y un tipo PokeNode ,el DataType se llama to_csv porque representa una linea del archivo csv que se exportara
{
   PokeNode* gen_Stats;
   Pokemon* fight_Stats;
};

/* Se inicializan las variables globales para hacer uso de ellas*/
void init_var()
{
   PS =createTreeMap (lower_than_int);
   PC =createTreeMap(lower_than_int);
   Bag =((List*)calloc(1,sizeof(List)));
   PokeDex =create_list();
   PokebyName =((HashMap*)calloc(1,sizeof(HashMap)));
   PokebyKind =((HashMap*)calloc(1,sizeof(HashMap)));
   PokebyName =createMap(90);
   PokebyKind =createMap(90);
   PokebyID =(HashMap*)calloc(1,sizeof(HashMap));
   PokebyID =createMap(90);
}

/* initialize a DataType PokeNode Variable*/
PokeNode* create_PokeNode()
{
   PokeNode* output =((PokeNode*)calloc(1,sizeof(PokeNode)));
   output->name =(char*)calloc(25,sizeof(char));
   output->kind =(char*)calloc(50,sizeof(char));
   output->evolveFrom =(char*)calloc(40,sizeof(char));
   output->evolvesIn =(char*)calloc(40,sizeof(char));
   output->region =(char*)calloc(25,sizeof(char));
   return (output);
}

/* initialize a DataType Pokemon Variable*/
Pokemon* create_Pokemon(Pokemon* input)
{
   input->name =(char*)calloc(25,sizeof(char));
   input->gender =(char*)calloc(10,sizeof(char));
   return (input);
}

//añade un pokemon a las distintas estructuras de datos usadas, se usa para atrapar un pokemon y se llama dentro de la funcion de importar archivos
int addPoke(char* Name, char* kind, int uid, char* evolveFrom, char* evolvesIn, int poke_id, char* region, int pc, int ps, char* gender)
{
   toExport =((to_csv*)calloc(1,sizeof(to_csv)));
   int* pc_key =(int*)calloc(1,sizeof(int)); //
   int* ps_key =(int*)calloc(1,sizeof(int));
   int* uid_key =(int*)calloc(1,sizeof(int));
   short int flag =(1);
   PokeNode* aux =(first(PokeDex));
   *uid_key =uid;
   Pokemon* newPoke =((Pokemon*)calloc(1,sizeof(Pokemon)));
   create_Pokemon(newPoke);
   newPoke->name =(Name);
   newPoke->uid =(uid);
   newPoke->pc =(pc);
   newPoke->ps =(ps);
   newPoke->gender =(gender);
   PokeNode* newPokeNode =create_PokeNode();
   newPokeNode->name =(Name);
   if ((bag_capac)<100)
   {
      newPokeNode->have =(1);
   }
   else
   {
      newPokeNode->have =(0);
   }
   newPokeNode->kind =(kind);
   newPokeNode->uid =(uid);
   newPokeNode->evolveFrom =(evolveFrom);
   newPokeNode->evolvesIn =(evolvesIn);
   newPokeNode->poke_id =(poke_id);
   newPokeNode->region =(region);
   toExport->fight_Stats =newPoke;
   toExport->gen_Stats =newPokeNode;
   while(aux!=NULL) 
   {
      if((strcmp(Name,(aux->name)))==0)
      {
         flag=(0);
         break;
      }
      aux =next(PokeDex);
   }
   if (flag==(0))
   {
      if ((bag_capac)<100)
      {
         List* toMap =searchMap(PokebyID,uid_key);
         if (toMap!=NULL)
         {
            printf ("POKEMON NO AÑADIDO (ID REPETIDA)\n");
            return (-1);
         }
         else
         {
            toMap =create_list();
            push_back(toMap,newPoke);
            insertMap(PokebyID,uid_key,toMap);
         }
         push_back(Bag,toExport);
         aux->have =((aux->have)+1);
         toMap =searchMap(PokebyName,Name);
         *pc_key =pc;
         List* toTree =searchTreeMap(PC,pc_key);
         if (toTree!=NULL)
         {
            push_back(toTree,newPoke);
         }
         else
         {
            toTree =create_list();
            push_back(toTree,newPoke);
            insertTreeMap(PC,pc_key,toTree);
         }
         if (toMap!=NULL)
         {
            push_back(toMap,newPoke);
         }
         else
         {
            toMap =create_list();
            push_back(toMap,newPoke);
            insertMap(PokebyName,Name,toMap);
         }
         toMap =searchMap(PokebyKind,kind);
         *ps_key =ps;
         toTree =searchTreeMap(PS,ps_key);
         if (toTree!=NULL)
         {
            push_back(toTree,newPoke);
         }
         else
         {
            toTree =create_list();
            push_back(toTree,newPoke);
            insertTreeMap(PS,ps_key,toTree);
         }
         if (toMap!=NULL)
         {
            push_back(toMap,newPoke);
         }
         else
         {
            toMap =create_list();
            push_back(toMap,newPoke);
            insertMap(PokebyKind,kind,toMap);
         }
         printf("El Pokemon ya está en la Pokedex, asi que se añadio a tu bolsa y se actualizó el contador en la Pokedex c:\n");
         bag_capac =(bag_capac+1);
         return(0);
      }
      else
      {
         printf("Almacenamiento lleno! :c ,%s no se añadio a la bolsa\n",Name);
         return(-1);
      }
      
   }
   else
   {
      push_back(PokeDex,newPokeNode);
      List* toMap =searchMap(PokebyID,uid_key);
      if (toMap!=NULL)
      {
         printf ("POKEMON NO AÑADIDO (ID REPETIDA)\n");
         return (-1);
      }
      else
      {
         toMap =create_list();
         push_back(toMap,newPoke);
         insertMap(PokebyID,uid_key,toMap);
      }
      push_back(Bag,toExport);
      if ((bag_capac)<100)
      {
         toMap =searchMap(PokebyName,Name);
         *pc_key =pc;
         List* toTree =searchTreeMap(PC,pc_key);
         if (toTree!=NULL)
         {
            push_back(toTree,newPoke);
         }
         else
         {
            toTree =create_list();
            push_back(toTree,newPoke);
            insertTreeMap(PC,pc_key,toTree);
         }
         if (toMap!=NULL)
         {
            push_back(toMap,newPoke);
         }
         else
         {
            toMap =create_list();
            push_back(toMap,newPoke);
            insertMap(PokebyName,Name,toMap);
         }
         toMap =searchMap(PokebyKind,kind);
         *ps_key =ps;
         toTree =searchTreeMap(PS,ps_key);
         if (toTree!=NULL)
         {
            push_back(toTree,newPoke);
         }
         else
         {
            toTree =create_list();
            push_back(toTree,newPoke);
            insertTreeMap(PS,ps_key,toTree);
         }
         if (toMap!=NULL)
         {
            push_back(toMap,newPoke);
         }
         else
         {
            toMap =create_list();
            push_back(toMap,newPoke);
            insertMap(PokebyKind,kind,toMap);
         }
         printf("Pokemon Agregado Exitosamente!!!!\n");
         bag_capac =(bag_capac+1);
         return(0);
      }
      else
      {
         printf("%s no fue añadido a la bolsa, pero si a la pokedex, ya que no estaba registrado\n",Name);
         return(-1);
      }
      
   }
}

/*Prints All The Games In The List*/
void print_Pok(List* Pokemons)
{
   Pokemon* aux;
   aux =(first(Pokemons));
   while(aux!=NULL) 
   {
      printf("%-5d│%-25s│%-10s│%-6d│%-6d│\n",aux->uid,aux->name,aux->gender,aux->pc,aux->ps);
      aux =next(Pokemons);
   }
   free(aux);
}

void print_All(List* PokeNodes)
{
   PokeNode* aux;
   aux =(first(PokeNodes));
   aux =(next(PokeNodes));
   printf("%-25s│%-10s│%-28s│%-5s│%-40s│%-40s│%-14s│%s\n","Nombre","Tienes","Tipo(s)","Id","Pre-Evolucion","Evolucion","N° Pokedex ","Región");
   printf("⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼\n");
   while(aux!=NULL) 
   {
      printf("%-25s│%-10d│%-28s│%-5d│%-40s│%-40s│%-13d│%s\n",aux->name,aux->have,aux->kind,aux->uid,aux->evolveFrom,aux->evolvesIn,aux->poke_id,aux->region);
      aux =next(PokeNodes);
   }
   free(aux);
}

/*Search Functions*/


/*Receives a region and a GameList, Prints All the Games of that region, in case that there are no games made by that region, Prints a "sorry, there are no games of that region" style message*/
void dex_search_byName(char* name)
{
   int flag;
   flag =(-1);
   PokeNode* aux;
   aux =create_PokeNode();
   aux =(first(PokeDex));
   while(aux!=NULL) 
   {
      if((strcmp(name,(aux->name)))==0)
      {
         if (flag==(-1))
         {
            printf("%-25s│%-10s│%-28s│%-5s│%-40s│%-40s│%-14s│%s\n","Nombre","Tienes","Tipo(s)","Id","Pre-Evolucion","Evolucion","N° Pokedex ","Región");
            printf("⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼\n");
         }
         flag=(1);
         printf("%-25s│%-10d│%-28s│%-5d│%-40s│%-40s│%-13d│%s\n",aux->name,aux->have,aux->kind,aux->uid,aux->evolveFrom,aux->evolvesIn,aux->poke_id,aux->region);
      }
      aux =next(PokeDex);
   }
   if (flag==(-1))
   {
      printf ("Pucha, %s no esta registrado en la pokedex  ༼ ༎ຶ ෴ ༎ຶ༽｡\n",name);
   }
   free(aux);
}

/*Receives a Game Name, and a GameList, Prints All the Games that are called like this, in case that there are no games named like the input, Prints a "sorry, there are no games with that name" style message*/
void search_byName(char* Name)
{
   List* nameIs =searchMap(PokebyName,Name);
   if (nameIs ==NULL)
   {
      printf ("Pucha, no hay ningun Pokemon llamado %s en tu bolsa ༼ ༎ຶ ෴ ༎ຶ༽｡\n",Name);
      return;
   }
   else
   {
      printf("%-5s│%-25s│%-10s│%-6s│%-6s│\n","Id","Nombre","Sexo","PC","PS");
      printf("⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼\n");
      print_Pok(nameIs);
      return;
   }
}


void search_byKind(char* Kind)
{
   List* kindIs =searchMap(PokebyKind,Kind);
   if (kindIs ==NULL)
   {
      printf ("Pucha, no hay ningun Pokemon de tipo %s en tu bolsa ༼ ༎ຶ ෴ ༎ຶ༽｡\n",Kind);
      return;
   }
   else
   {
      printf("%-5s│%-25s│%-10s│%-6s│%-6s│\n","Id","Nombre","Sexo","PC","PS");
      printf("⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼\n");
      print_Pok(kindIs);
      return;
   }
}

void show_fromRegion(char* Region,List* PokeDex)
{
   PokeNode* pokeInfo =create_PokeNode();
   pokeInfo =(first(PokeDex));
   pokeInfo =(next(PokeDex));
   printf("%-25s│%-10s│%-28s│%-5s│%-40s│%-40s│%-14s│%s\n","Nombre","Tienes","Tipo(s)","Id","Pre-Evolucion","Evolucion","N° Pokedex ","Región");
   printf("⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼\n");
   char* a =(char*)calloc(50,sizeof(char));
   while (pokeInfo!=NULL)
   {
      memcpy(a,pokeInfo->region,sizeof(char)*(strlen(Region)));
      if (is_equal(Region,a))
      {
        printf("%-25s│%-10d│%-28s│%-5d│%-40s│%-40s│%-13d│%s\n",pokeInfo->name,pokeInfo->have,pokeInfo->kind,pokeInfo->uid,pokeInfo->evolveFrom,pokeInfo->evolvesIn,pokeInfo->poke_id,pokeInfo->region);
        pokeInfo =next(PokeDex);  
      }
      else
      {
         pokeInfo =next(PokeDex);
      }
      
   }
}

void exportCSV(char* name)
{  
   FILE* output;
   char fileName[105];
   snprintf(fileName,sizeof(fileName),"%s%s",name,".csv");
   output =fopen(fileName,"w");
   if (Bag->current->data ==NULL)
   {
      printf("Sin Registros de Pokemon, se ha creado un archivo vacio");
      return;
   }
   to_csv* aux;
   aux =(first(Bag));
   char cadena[110];
   while(aux!=NULL) 
   {
      //id,nombre,tipos,pc,ps,sexo,evolucion previa,evolucion posterior,numero pokedex,region;
      snprintf(cadena,sizeof(cadena),"%d,%s,\"%s\",%d,%d,\"%s\",\"%s\",\"%s\",%d,%s\n",aux->fight_Stats->uid,aux->gen_Stats->name,aux->gen_Stats->kind,aux->fight_Stats->pc,aux->fight_Stats->ps,aux->fight_Stats->gender,aux->gen_Stats->evolveFrom,aux->gen_Stats->evolvesIn,aux->gen_Stats->poke_id,aux->gen_Stats->region);
      fputs(cadena,output);
      aux =next(Bag);
   }
   fclose(output);
   free(aux);
}

/*Import Function From a (.csv) File*/
void importCSV(char* name)
{
   FILE* input;
   char fileName[105];
   snprintf(fileName,sizeof(fileName),"%s%s",name,".csv");
   input =fopen(fileName,"r");
   if (input==NULL)
   {
      printf("Pucha, No Existe El Archivo Especificado! (ΠΦΠ)/\n");
      return;
   }
   char line[105];
   PokeNode* datosDex;
   Pokemon* datos;
   int flag;
   flag =(0);
   while(fgets(line, 104,input) != NULL) 
   {
      datos =((Pokemon*)calloc(1,sizeof(Pokemon)));
      datos =(create_Pokemon(datos));
      datosDex =create_PokeNode();
      datosDex->uid =(atol(get_csv_field(line,0)));
      strcpy((datosDex->name),((char*)get_csv_field(line,1)));
      strcpy((datosDex->kind),((char*)get_csv_field(line,2)));
      datos->pc =(atol(get_csv_field(line,3)));
      datos->ps =(atol(get_csv_field(line,4)));
      strcpy((datos->name),((char*)get_csv_field(line,1)));
      strcpy((datos->gender),((char*)get_csv_field(line,5)));
      strcpy((datosDex->evolveFrom),((char*)get_csv_field(line,6)));
      strcpy((datosDex->evolvesIn),((char*)get_csv_field(line,7)));
      datosDex->poke_id =(atol(get_csv_field(line,8)));
      strcpy((datosDex->region),((char*)get_csv_field(line,9)));
      if(strcmp(datosDex->name,"nombre")!=0)
      {
         if (flag==(0))
         {
            flag =addPoke(datosDex->name,datosDex->kind,datosDex->uid,datosDex->evolveFrom,datosDex->evolvesIn,datosDex->poke_id,datosDex->region,datos->pc,datos->ps,datos->gender);
         }
         else
         {
            addPoke(datosDex->name,datosDex->kind,datosDex->uid,datosDex->evolveFrom,datosDex->evolvesIn,datosDex->poke_id,datosDex->region,datos->pc,datos->ps,datos->gender);
         }
      }
   }
   fclose(input);
   free(datos);
   if (flag!=(-1))
   {
      system("reset");
      printf("Archivo Importado Exitosamente!!!\n");
   }
}

void show_byPS()
{
   Pair* output;
   output =(last_tree(PS));
   printf("%-5s│%-25s│%-10s│%-6s│%-6s│\n","Id","Nombre","Sexo","PC","PS");
   printf("⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼\n");
   while(1)
   {
      if (output==NULL)
      {
         break;
      }
      print_Pok((List*)output->value);
      output =(prev_tree(PS));
   }
}

void show_byPC()
{
   Pair* output;
   output =(last_tree(PC));
   printf("%-5s│%-25s│%-10s│%-6s│%-6s│\n","Id","Nombre","Sexo","PC","PS");
   printf("⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼\n");
   while(1)
   {
      if (output==NULL)
      {
         break;
      }
      print_Pok((List*)output->value);
      output =(prev_tree(PC));
   }
}

void del_poke(int id)
{
   List* Poke_list =searchMap(PokebyID,&id);
   if (PokebyID->current==-1)
   {
      printf("POKEMON NO SE ENCUENTRA EN LA BOLSA");
      return;
   }
   Pokemon* del_id =(Pokemon*)calloc(1,sizeof(Pokemon));
   memcpy(del_id,(first(Poke_list)),sizeof(Pokemon));
   eraseMap(PokebyID,&id);
   Poke_list =searchTreeMap(PS,&(del_id->ps));
   Pokemon* del_PS =first(Poke_list);
   while ((del_PS!=NULL)&&(del_PS->uid!=del_id->uid))
   {
      del_PS =(next(Poke_list));
   }
   pop_current(Poke_list);
   Poke_list =searchTreeMap(PC,&(del_id->pc));
   del_PS =first(Poke_list);
   while ((del_PS!=NULL)&&(del_PS->uid!=del_id->uid))
   {
      del_PS =(next(Poke_list));
   }
   pop_current(Poke_list);
   Poke_list =searchMap(PokebyName,del_id->name);
   del_PS =first(Poke_list);
   while ((del_PS!=NULL)&&(del_PS->uid!=id))
   {
      del_PS =(next(Poke_list));
   }
   pop_current(Poke_list);
   PokeNode* dex_del =first(PokeDex);
   while ((dex_del!=NULL)&&(dex_del->name!=del_id->name))
   {
      dex_del =(next(PokeDex));
   }
   dex_del->have =dex_del->have-1;
   Poke_list =searchMap(PokebyKind,dex_del->kind);;
   del_PS = first(Poke_list);
   while ((del_PS!=NULL)&&(del_PS->uid!=id))
   {
      del_PS =(next(Poke_list));
   }
   pop_current(Poke_list);
   toExport =first(Bag);
   while ((toExport!=NULL)&&(toExport->fight_Stats->uid!=id))
   {
      toExport =(next(Bag));
   }
   pop_current(Bag);
   free(del_id);
   bag_capac =bag_capac-1;
   return;
}