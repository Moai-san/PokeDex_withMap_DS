# PokeDex_withMap_DS
//CODING - WORK IN PROGRESS//

//AUN NO SE IMPLEMENTA MENÚ, ESTE SERA EL PASO FINAL//

//FUNCIONES TACHADAS ESTAN LISTAS Y FUNCIONALES//

Se propone el siguiente menú para la aplicación:

1̶ ̶I̶m̶p̶o̶r̶t̶a̶r̶/Exportar desde un archivo CSV (char* nombre_archivo): ​ La aplicación importa/exporta todos los pokémon desde/hacia un archivo csv, se puede cargar mas de un archivo.
 
2̶ ̶P̶o̶k̶é̶m̶o̶n̶ ̶a̶t̶r̶a̶p̶a̶d̶o̶ ̶(̶i̶n̶t̶ ̶P̶C̶,̶ ̶i̶n̶t̶ ̶P̶S̶,̶ ̶c̶h̶a̶r̶*̶ ̶s̶e̶x̶o̶,̶ ̶c̶h̶a̶r̶*̶ ̶e̶v̶o̶l̶u̶c̶i̶o̶n̶P̶r̶e̶v̶i̶a̶,̶ ̶c̶h̶a̶r̶*̶ ̶e̶v̶o̶l̶u̶c̶i̶o̶n̶P̶o̶s̶t̶e̶r̶i̶o̶r̶,̶ ̶i̶n̶t̶ ̶n̶u̶m̶e̶r̶o̶P̶o̶k̶é̶d̶e̶x̶,̶ ̶c̶h̶a̶r̶*̶ ̶r̶e̶g̶i̶ó̶n̶)̶:̶ ̶​̶L̶a̶ ̶a̶p̶l̶i̶c̶a̶c̶i̶ó̶n̶ ̶d̶e̶b̶e̶r̶á̶ ̶i̶n̶g̶r̶e̶s̶a̶r̶ ̶u̶n̶ ̶p̶o̶k̶e̶m̶o̶n̶ ̶n̶u̶e̶v̶o̶,̶ ̶e̶s̶t̶e̶ ̶s̶e̶ ̶a̶g̶r̶e̶g̶a̶ ̶a̶ ̶t̶u̶ ̶a̶l̶m̶a̶c̶e̶n̶a̶m̶i̶e̶n̶t̶o̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶(̶a̶s̶e̶g̶u̶r̶á̶n̶d̶o̶s̶e̶ ̶d̶e̶ ̶n̶o̶ ̶e̶x̶c̶e̶d̶e̶r̶ ̶e̶l̶ ̶m̶á̶x̶i̶m̶o̶)̶ ̶y̶ ̶a̶ ̶l̶a̶ ̶p̶o̶k̶é̶d̶e̶x̶ ̶e̶n̶ ̶c̶a̶s̶o̶ ̶d̶e̶ ̶n̶o̶ ̶e̶x̶i̶s̶t̶i̶r̶,̶ ̶s̶i̶ ̶y̶a̶ ̶e̶x̶i̶s̶t̶e̶,̶ ̶s̶e̶ ̶s̶u̶m̶a̶r̶á̶ ̶u̶n̶o̶ ̶a̶ ̶e̶x̶i̶s̶t̶e̶n̶c̶i̶a̶.̶
 
3̶ ̶B̶u̶s̶c̶a̶r̶ ̶m̶i̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶p̶o̶r̶ ̶t̶i̶p̶o̶ ̶(̶c̶h̶a̶r̶*̶ ̶t̶i̶p̶o̶)̶:̶​̶ ̶L̶a̶ ̶a̶p̶l̶i̶c̶a̶c̶i̶ó̶n̶ ̶b̶u̶s̶c̶a̶ ̶y̶ ̶m̶u̶e̶s̶t̶r̶a̶ ̶p̶o̶r̶ ̶p̶a̶n̶t̶a̶l̶l̶a̶ ̶t̶o̶d̶o̶s̶ ̶t̶u̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶(̶y̶ ̶s̶u̶ ̶i̶n̶f̶o̶r̶m̶a̶c̶i̶ó̶n̶ ̶d̶e̶ ̶c̶o̶m̶b̶a̶t̶e̶)̶ ̶d̶e̶l̶ ̶t̶i̶p̶o̶ ̶e̶s̶p̶e̶c̶i̶f̶i̶c̶a̶d̶o̶,̶ ̶d̶e̶ ̶n̶o̶ ̶e̶x̶i̶s̶t̶i̶r̶ ̶e̶l̶ ̶t̶i̶p̶o̶,̶ ̶d̶e̶b̶e̶ ̶m̶o̶s̶t̶r̶a̶r̶ ̶u̶n̶ ̶m̶e̶n̶s̶a̶j̶e̶ ̶p̶o̶r̶ ̶p̶a̶n̶t̶a̶l̶l̶a̶ ̶i̶n̶d̶i̶c̶a̶n̶d̶o̶l̶o̶.̶
 
4̶ ̶B̶u̶s̶c̶a̶r̶ ̶m̶i̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶p̶o̶r̶ ̶n̶o̶m̶b̶r̶e̶ ̶(̶c̶h̶a̶r̶*̶ ̶n̶o̶m̶b̶r̶e̶)̶:̶​̶ ̶L̶a̶ ̶a̶p̶l̶i̶c̶a̶c̶i̶ó̶n̶ ̶b̶u̶s̶c̶a̶ ̶y̶ ̶m̶u̶e̶s̶t̶r̶a̶ ̶p̶o̶r̶ ̶p̶a̶n̶t̶a̶l̶l̶a̶ ̶t̶o̶d̶o̶s̶ ̶t̶u̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶(̶y̶ ̶s̶u̶ ̶r̶e̶s̶p̶e̶c̶t̶i̶v̶a̶ ̶i̶n̶f̶o̶r̶m̶a̶c̶i̶ó̶n̶ ̶d̶e̶ ̶c̶o̶m̶b̶a̶t̶e̶)̶ ̶c̶o̶n̶ ̶e̶s̶e̶ ̶n̶o̶m̶b̶r̶e̶,̶ ̶d̶e̶ ̶n̶o̶ ̶e̶x̶i̶s̶t̶i̶r̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶c̶o̶n̶ ̶e̶s̶e̶ ̶n̶o̶m̶b̶r̶e̶ ̶d̶e̶b̶e̶ ̶m̶o̶s̶t̶r̶a̶r̶ ̶u̶n̶ ̶m̶e̶n̶s̶a̶j̶e̶ ̶p̶o̶r̶ ̶p̶a̶n̶t̶a̶l̶l̶a̶.̶

5̶ ̶B̶u̶s̶c̶a̶r̶ ̶p̶o̶r̶ ̶n̶o̶m̶b̶r̶e̶ ̶e̶n̶ ̶p̶o̶k̶é̶d̶e̶x̶ ̶(̶c̶h̶a̶r̶*̶ ̶n̶o̶m̶b̶r̶e̶)̶:̶​̶ ̶L̶a̶ ̶a̶p̶l̶i̶c̶a̶c̶i̶ó̶n̶ ̶b̶u̶s̶c̶a̶ ̶y̶ ̶m̶u̶e̶s̶t̶r̶a̶ ̶p̶o̶r̶ ̶p̶a̶n̶t̶a̶l̶l̶a̶ ̶e̶l̶ ̶p̶o̶k̶e̶m̶o̶n̶ ̶(̶y̶ ̶s̶u̶ ̶r̶e̶s̶p̶e̶c̶t̶i̶v̶a̶ ̶i̶n̶f̶o̶r̶m̶a̶c̶i̶ó̶n̶ ̶d̶e̶ ̶p̶o̶k̶é̶d̶e̶x̶)̶,̶ ̶d̶e̶ ̶n̶o̶ ̶e̶x̶i̶s̶t̶i̶r̶ ̶i̶n̶f̶o̶r̶m̶a̶c̶i̶ó̶n̶ ̶d̶e̶l̶ ̶p̶o̶k̶é̶m̶o̶n̶,̶ ̶d̶e̶b̶e̶ ̶m̶o̶s̶t̶r̶a̶r̶ ̶u̶n̶ ̶m̶e̶n̶s̶a̶j̶e̶ ̶p̶o̶r̶ ̶p̶a̶n̶t̶a̶l̶l̶a̶.̶

6̶ ̶M̶o̶s̶t̶r̶a̶r̶ ̶t̶o̶d̶o̶s̶ ̶l̶o̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶d̶e̶ ̶l̶a̶ ̶p̶o̶k̶é̶d̶e̶x̶ ̶(̶)̶:̶​̶ ̶L̶a̶ ̶a̶p̶l̶i̶c̶a̶c̶i̶ó̶n̶ ̶m̶u̶e̶s̶t̶r̶a̶ ̶p̶o̶r̶ ̶p̶a̶n̶t̶a̶l̶l̶a̶ ̶t̶o̶d̶o̶s̶ ̶l̶o̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶r̶e̶g̶i̶s̶t̶r̶a̶d̶o̶s̶ ̶e̶n̶ ̶l̶a̶ ̶p̶o̶k̶é̶d̶e̶x̶ ̶(̶y̶ ̶s̶u̶ ̶r̶e̶s̶p̶e̶c̶t̶i̶v̶a̶ ̶i̶n̶f̶o̶r̶m̶a̶c̶i̶ó̶n̶ ̶d̶e̶ ̶p̶o̶k̶é̶d̶e̶x̶)̶,̶ ̶p̶o̶r̶ ̶o̶r̶d̶e̶n̶ ̶d̶e̶l̶ ̶n̶ú̶m̶e̶r̶o̶ ̶d̶e̶ ̶l̶a̶ ̶p̶o̶k̶é̶d̶e̶x̶.̶

7̶ ̶M̶o̶s̶t̶r̶a̶r̶ ̶t̶u̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶p̶o̶r̶ ̶m̶a̶y̶o̶r̶ ̶P̶C̶ ̶(̶)̶:̶ ̶L̶a̶ ̶a̶p̶l̶i̶c̶a̶c̶i̶ó̶n̶ ̶m̶u̶e̶s̶t̶r̶a̶ ̶l̶o̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶ ̶d̶e̶ ̶t̶u̶ ̶a̶l̶m̶a̶c̶e̶n̶a̶m̶i̶e̶n̶t̶o̶ ̶o̶r̶d̶e̶n̶a̶d̶o̶s̶ ̶d̶e̶s̶d̶e̶ ̶e̶l̶ ̶m̶a̶y̶o̶r̶ ̶a̶l̶ ̶m̶e̶n̶o̶r̶ ̶P̶C̶.̶ *available on next commit

8̶ ̶M̶o̶s̶t̶r̶a̶r̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶p̶o̶r̶ ̶m̶a̶y̶o̶r̶ ̶P̶S̶ ̶(̶)̶:̶ ̶L̶a̶ ̶a̶p̶l̶i̶c̶a̶c̶i̶ó̶n̶ ̶m̶u̶e̶s̶t̶r̶a̶ ̶l̶o̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶ ̶d̶e̶ ̶t̶u̶ ̶a̶l̶m̶a̶c̶e̶n̶a̶m̶i̶e̶n̶t̶o̶ ̶o̶r̶d̶e̶n̶a̶d̶o̶s̶ ̶d̶e̶s̶d̶e̶ ̶e̶l̶ ̶m̶a̶y̶o̶r̶ ̶a̶l̶ ̶m̶e̶n̶o̶r̶ ̶P̶S̶ *available on next commit

9 Liberar pokémon (int id): La aplicación elimina al pokémon de tu almacenamiento y resta uno a la existencia en la pokédex (si la existencia queda en 0, NO se debe eliminar al pokémon de la pokédex).

1̶0̶ ̶M̶o̶s̶t̶r̶a̶r̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶p̶o̶r̶ ̶r̶e̶g̶i̶ó̶n̶ ̶(̶c̶h̶a̶r̶*̶ ̶r̶e̶g̶i̶ó̶n̶)̶:̶ ̶E̶s̶t̶a̶ ̶o̶p̶c̶i̶ó̶n̶ ̶m̶u̶e̶s̶t̶r̶a̶ ̶e̶l̶ ̶n̶o̶m̶b̶r̶e̶ ̶d̶e̶ ̶l̶a̶ ̶r̶e̶g̶i̶ó̶n̶,̶ ̶c̶u̶á̶n̶t̶o̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶d̶e̶ ̶e̶s̶a̶ ̶r̶e̶g̶i̶ó̶n̶ ̶t̶e̶n̶g̶o̶ ̶e̶n̶ ̶m̶i̶ ̶a̶l̶m̶a̶c̶e̶n̶a̶m̶i̶e̶n̶t̶o̶ ̶y̶ ̶m̶e̶ ̶m̶u̶e̶s̶t̶r̶a̶ ̶l̶a̶ ̶i̶n̶f̶o̶r̶m̶a̶c̶i̶ó̶n̶ ̶d̶e̶ ̶l̶a̶ ̶p̶o̶k̶é̶d̶e̶x̶ ̶d̶e̶ ̶l̶o̶s̶ ̶p̶o̶k̶é̶m̶o̶n̶ ̶d̶e̶ ̶e̶s̶a̶ ̶r̶e̶g̶i̶ó̶n̶.