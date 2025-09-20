# MissaoJoaoCalvino_Isalu_Yating_Matheus
Solução do desafio "Missão João Calvino"

Universidade Presbiteriana Mackenzie
Algoritmos e Programação II — Projeto 1 (Missão João Calvino)

**Turma 04N**

## Integrantes
    - Isadora Luisa Candini Marques — 10730955
    - Yating Zheng 10439511
    - Matheus Hidalgo do Nascimento Fest Ferreira - 10390172
    
## Passo a Passo para Executar o Programa
Aqui está um guia detalhado para executar o programa de encontrar a chave perdida:
### Passo 1: Preparar o Arquivo de Código
* Salve o código C fornecido em um arquivo chamado encontrar_chave.c
### Passo 2: Preparar o Arquivo de Entrada
* Crie um arquivo de texto chamado entrada.txt
* Copie o seguinte conteúdo para o arquivo:
```
5
HVVVHV
HHVVVV
HVHVVH
*HVVHV
HHHVHH
0 0
```
### Passo 3: Compilar o Programa
Abra o terminal ou prompt de comando, navegue até o diretório onde salvou o código e execute:
```bash
gcc -o encontrar_chave encontrar_chave.c
```
Isso compilará o código e criará um arquivo executável chamado encontrar_chave (no Windows, será encontrar_chave.exe).
### Passo 4: Executar o Programa
No terminal, execute o programa com:
```bash
./encontrar_chave
```
Ou, se quiser especificar o arquivo de entrada explicitamente:
```bash
./encontrar_chave entrada.txt
```
### Passo 5: Verificar a Saída
O programa processará o arquivo de entrada e exibirá o resultado. Para a entrada de exemplo, a saída será:
```
Chave encontrada no Edifício João Calvino!
```
Testando com Diferentes Arquivos de Entrada
Você pode criar outros arquivos de entrada para testar o programa. Por exemplo, crie um arquivo teste2.txt com:
```
5
HVVVHV
HHVVVV
HVHVVH
*HVVHV
HHHVHH
0 4
```
Execute com:
```bash
./encontrar_chave teste2.txt
```
A saída esperada será:
```
Não conseguimos encontrar a chave no Edifício João Calvino.
```
