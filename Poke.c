#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include <string.h>
#include "Poke.h"
#include "treemap.h"
typedef struct Pokemon Pokemon;
typedef struct PokeNode PokeNode;

int bag_capac =(0);
TreeMap* PS;
TreeMap* PC;

void init_var()
{
   PS =createTreeMap (lower_than_int);
   PC =createTreeMap(lower_than_int);
}
/* DataType Pokemon: Contain (int) uid y (int) poke_id, (char*)name, (char*)region, (char*)kind, y (char*)expansions*/
struct Pokemon
{
   char* name; //nombre
   int uid;
   int pc;
   int ps;
   char* gender; //marca
};

struct PokeNode
{
   char* name; //nombre
   int have;
   char* kind; //tipo
   int uid;
   char* evolveFrom;
   char* evolvesIn;
   int poke_id;
   char* region; //marca
};
//- cp -hp - evolvesIn - evolveFrom - gender
/* initialize a DataType PokeNode Variable for our pokedex  (list)*/
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

/*Adds a Game into a List*/
int addPoke(char* Name, char* kind, int uid, char* evolveFrom, char* evolvesIn, int poke_id, char* region, int pc, int ps, char* gender, List* Pokedex, HashMap* Poke_byName, HashMap* Poke_byKind)
{
   short int flag;
   flag =(1);
   PokeNode* aux;
   aux =(first(Pokedex));
   int* pc_key;
   pc_key =(int*)calloc(1,sizeof(int));
   int* ps_key;
   ps_key =(int*)calloc(1,sizeof(int));
   while(aux!=NULL) 
   {
      if((strcmp(Name,(aux->name)))==0)
      {
         flag=(0);
         break;
      }
      aux =next(Pokedex);
   }
   if (flag==(0))
   {
      if ((bag_capac)<100)
      {
         aux->have =((aux->have)+1);
         Pokemon* newPoke;
         newPoke =((Pokemon*)calloc(1,sizeof(Pokemon)));
         create_Pokemon(newPoke);
         newPoke->name =(Name);
         newPoke->uid =(uid);
         newPoke->pc =(pc);
         newPoke->ps =(ps);
         newPoke->gender =(gender);
         List* toMap =searchMap(Poke_byName,Name);
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
            insertMap(Poke_byName,Name,toMap);
         }
         toMap =searchMap(Poke_byKind,kind);
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
            insertMap(Poke_byKind,kind,toMap);
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
      PokeNode* newPokeNode;
      newPokeNode =create_PokeNode();
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
      Pokemon* newPoke;
      newPoke =((Pokemon*)calloc(1,sizeof(Pokemon)));
      create_Pokemon(newPoke);
      push_back(Pokedex,newPokeNode);
      if ((bag_capac)<100)
      {
         newPoke->name =(Name);
         newPoke->uid =(uid);
         newPoke->pc =(pc);
         newPoke->ps =(ps);
         newPoke->gender =(gender);
         List* toMap =searchMap(Poke_byName,Name);
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
            insertMap(Poke_byName,Name,toMap);
         }
         toMap =searchMap(Poke_byKind,kind);
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
            insertMap(Poke_byKind,kind,toMap);
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
void dex_search_byName(char* name,List* PokeDex)
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
void search_byName(char* Name,HashMap* PokeNames)
{
   List* nameIs =searchMap(PokeNames,Name);
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


void search_byKind(char* Kind,HashMap* PokeKinds)
{
   List* kindIs =searchMap(PokeKinds,Kind);
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

/*void exportCSV(char* name,List* Pokemons)
{
   FILE* output;
   char fileName[105];
   snprintf(fileName,sizeof(fileName),"%s%s",name,".csv");
   output =fopen(fileName,"w");
   Pokemon* aux;
   aux =(first(Pokemons));
   char cadena[105];
   while(aux!=NULL) 
   {
      snprintf(cadena,sizeof(cadena),"\"%s\",%s,\"%s\",%d,%d,%s\n",aux->name,aux->region,aux->kind,aux->uid,aux->poke_id,aux->expansions);
      fputs(cadena,output);
      aux =next(Pokemons);
   }
   fclose(output);
   free(aux);
}*/

/*Import Function From a (.csv) File*/
void importCSV(char* name,List* PokeDex,HashMap* PokebyName,HashMap* PokebyKind)
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
            flag =addPoke(datosDex->name,datosDex->kind,datosDex->uid,datosDex->evolveFrom,datosDex->evolvesIn,datosDex->poke_id,datosDex->region,datos->pc,datos->ps,datos->gender,PokeDex,PokebyName,PokebyKind);
         }
         else
         {
            addPoke(datosDex->name,datosDex->kind,datosDex->uid,datosDex->evolveFrom,datosDex->evolvesIn,datosDex->poke_id,datosDex->region,datos->pc,datos->ps,datos->gender,PokeDex,PokebyName,PokebyKind);
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
   output =(last(PS));
   printf("%-5s│%-25s│%-10s│%-6s│%-6s│\n","Id","Nombre","Sexo","PC","PS");
   printf("⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼\n");
   while(1)
   {
      if (output==NULL)
      {
         break;
      }
      print_Pok((List*)output->value);
      output =(prev(PS));
   }
}

void show_byPC()
{
   Pair* output;
   output =(last(PC));
   printf("%-5s│%-25s│%-10s│%-6s│%-6s│\n","Id","Nombre","Sexo","PC","PS");
   printf("⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼⎼⎼⎼⎼⎼⎼┼\n");
   while(1)
   {
      if (output==NULL)
      {
         break;
      }
      print_Pok((List*)output->value);
      output =(prev(PC));
   }
}