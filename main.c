include <stdio.h>
include <stdbool.h>
include <string.h>

define MAXR 300 // MAXIMO DE ANDARES (LINHAS)
define MAXC 300 // MAXIMO DE COLUNAS 


// Matriz do prédio e controle de visitados
static char grid[MAXR][MAXC];
static bool visited[MAXR][MAXC];

// Dimensões efetivas lidas
static int R = 0;  // número de linhas
static int C = 0;  // número de colunas
