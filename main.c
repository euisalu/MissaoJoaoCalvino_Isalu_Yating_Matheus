/*
  Universidade Presbiteriana Mackenzie
  Algoritmos e Programação II — Projeto 1 (Missão João Calvino)

  Integrantes:
    - Isadora Luisa Candini Marques — 10730955
    - Yating Zheng 10439511
    - Matheus Hidalgo do Nascimento Fest Ferreira - 10390172


  COMPILAR (Windows, conforme enunciado):
    gcc -o main.exe *.c *.h

  EXECUTAR (lendo de arquivo .txt):
    main.exe entrada.txt
    // Se não passar argumento, tenta abrir "entrada.txt" no diretório.

  ENTRADA (no arquivo .txt):
    n
    n linhas com H/V/* (podem estar separadas por espaço)
    linhaInicial colunaInicial

  SAÍDA (exatamente como o enunciado):
    "Chave encontrada no Edifício João Calvino!"
    ou
    "Não conseguimos encontrar a chave no Edifício João Calvino."
*/



include <stdio.h>    
include <stdbool.h> 
include <string.h>   

define MAXR 100      // limite máximo de linhas (andares) — bem folgado
define MAXC 100      // limite máximo de colunas — folgadinha também

// Matriz do prédio e controle de visitados (pra não andar em loop, né?)
static char  grid[MAXR][MAXC];
static bool  visited[MAXR][MAXC];

// Dimensões efetivas lidas do arquivo
static int R = 0;     // número de linhas (andares)
static int C = 0;    


/*
  parse_line:
  — Recebe uma linha crua do arquivo (pode ter espaços).
  — Copia para 'dest' SOMENTE os caracteres válidos: 'H', 'V' ou '*'.
  — Retorna quantos caracteres válidos foram copiados (isso vira C, a quantidade de colunas).
  Motivo: o PDF fala “separados por espaço”, mas às vezes a gente recebe sem espaços
  então aqui nosso codigo aceita os dois jeitos :) 
*/ 


static int parse_line(const char *src, char *dest) {
    int k = 0;
    for (int i = 0; src[i]; i++) {
        char ch = src[i];
        if (ch == 'H' || ch == 'V' || ch == '*') {
            dest[k++] = ch;     // peguei só o que interessa
        }
        // qualquer outra coisa (espaço, tab, etc.) eu ignoro belamente
    }
    return k; // “k” é quantas colunas válidas encontramos nessa linha
}


