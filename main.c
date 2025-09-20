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



#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// limite máximo de linhas (andares) — bem folgado
#define MAXR 100
// limite máximo de colunas — folgadinha também
#define MAXC 100      // limite máximo de colunas — folgadinha também

// Matriz do prédio e controle de visitados
static char  grid[MAXR][MAXC];
static bool  visited[MAXR][MAXC];

// Dimensões efetivas lidas do arquivo
static int R = 0;     // número de linhas (andares)
static int C = 0;     // número de colunas


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
            dest[k++] = ch;
        }
	// qualquer outra coisa (espaço, tab, etc.) eu ignoro belamente
    }
    dest[k] = '\0'; // Adiciona o terminador de string
    return k;
}



/*
  backtrack(r, c):
  —  recursivaaaaaaaa
  — Tenta alcançar '*' partindo de (r, c).
  — Respeita as regras da célula atual (H = horizontal, V = vertical).
  — Usa 'visited' para não repetir posição e evitar ciclos (backtracking comportado).
*/

static bool backtrack(int r, int c) {
    // 1) conferinfo se esta fora do predio
    if (r < 0 || r >= R || c < 0 || c >= C) return false;

    // 2) Já passei por aqui neste caminho?
    if (visited[r][c]) return false;

    // 3) Cheguei na estrela? 
    if (grid[r][c] == '*') return true;

    // 4) Marco como visitado antes de expandir 
    visited[r][c] = true;

    // 5) Expando conforme a REGRA da célula atual HORIZONTAL E VERTICAL:
    if (grid[r][c] == 'H') {
        // Só me permito ir pros lados: esquerda e direita
        if (backtrack(r, c - 1)) return true;  // tenta esquerda
        if (backtrack(r, c + 1)) return true;  // tenta direita
    } else if (grid[r][c] == 'V') {
        // Só subo/desço, elegante e vertical
        if (backtrack(r - 1, c)) return true;  // tenta cima
        if (backtrack(r + 1, c)) return true;  // tenta baixo
    }

    visited[r][c] = false; // Desmarca (o backtrack)
    return false;
}


int main(int argc, char *argv[]) {
    
    // Abrir o ARQUIVO .txt BOTEI ENTRADA
    const char *path = (argc >= 2) ? argv[1] : "entrada.txt";
    FILE *in = fopen(path, "r");
    if (!in) { // Falha ao abrir o arquivo
    
        if (argc >= 2) in = fopen("entrada.txt", "r"); // Tenta abrir o arquivo sem especificar caminho, apenas no path onde o código está armazenado
        if (!in) { // Não foi possivel retornar o arquivo
            return 0;
        }
    }


    /* Ler n (número de linhas/andares) */
    if (fscanf(in, "%d", &R) != 1) { fclose(in); return 0; }

    /* resto da linha para usar fgets a seguir */
    int ch;
    while ((ch = fgetc(in)) != '\n' && ch != EOF) {}
  
    /* linhas do edifício  */
    char raw[999], clean[MAXC];
  
    for (int i = 0; i < R; i++) {
        if (fgets(raw, sizeof(raw), in) == NULL) {
             // Tratamento de erro se o arquivo terminar antes
             fclose(in); return 0;
        }
        int cols = parse_line(raw, clean);
        if (i == 0) {
            C = cols; // Define o número de colunas na primeira linha
        }
        strcpy(grid[i], clean); // Copia a linha limpa para a matriz final
    }
  
    /* Ler posição inicial linha, coluna */
    int sr = 0, sc = 0;
    if (fscanf(in, "%d %d", &sr, &sc) != 2) { fclose(in); return 0; }

    fclose(in);

    /* Resolver com backtracking*/
    bool ok = backtrack(sr, sc);

    if (ok)
        printf("Chave encontrada no Edifício João Calvino!\n");
    else
        printf("Não conseguimos encontrar a chave no Edifício João Calvino.\n");

    return 0;
}





