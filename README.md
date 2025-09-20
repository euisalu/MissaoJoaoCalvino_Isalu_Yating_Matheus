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
* Salve o código C fornecido em um arquivo chamado main.c
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
gcc -o main.exe main.c
```
Este comando compilará o código e criará um arquivo executável chamado main.exe.
### Passo 4: Executar o Programa
No terminal, execute o programa com:
```
main.exe
```
O programa lerá o arquivo entrada.txt, processará os dados e exibirá o resultado:
```
Chave encontrada no Edifício João Calvino!
```
### Passo 5: Testar com Outros Arquivos de Entrada
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
```
main.exe teste2.txt
```
A saída esperada será:
```
Não conseguimos encontrar a chave no Edifício João Calvino.
```
### Observações
1. Certifique-se de ter o GCC instalado no Windows. Se não tiver, você pode instalar o MinGW ou usar o WSL (Windows Subsystem for Linux).
2. O programa assume que o arquivo de entrada está no mesmo diretório que o executável.
3. Se encontrar erros de compilação, verifique se todas as bibliotecas necessárias estão incluídas no código.
4. O formato do arquivo de entrada deve ser:
   · Primeira linha: número de andares
   · Linhas seguintes: layout de cada andar
   · Última linha: posição inicial (linha e coluna)

Este guia fornece todas as etapas necessárias para compilar e executar o programa no Windows conforme especificado.
