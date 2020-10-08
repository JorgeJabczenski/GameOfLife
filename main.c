#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define VIVO '@'
#define MORTO ' '

/* Aloca espaço para uma matriz */
int **alocar_matriz(int lin, int col)
{
  int **matriz;
  matriz = malloc(sizeof(int *) * lin);
  for (int i = 0; i < lin; i++)
    matriz[i] = malloc(sizeof(int) * col);
  return matriz;
}

void conta_vizinhos(int **mundo, int **passado, int lin, int col)
{
  for (int i = 0; i < lin; i++)
  {
    for (int j = 0; j < col; j++)
    {
      int vizinhos = 0;
      for (int k = -1; k < 2; k++)
      {
        for (int l = -1; l < 2; l++)
        {
          vizinhos += passado[(i + k + lin) % lin][(j + l + col) % col];
        }
      }

      //vizinhos -= passado[i][j];

      if ((passado[i][j] == 1) && (vizinhos < 2 || vizinhos > 3))
        mundo[i][j] = 0;
      else if ((passado[i][j]  == 0) && (vizinhos == 3))
          mundo[i][j] == 1;
        else
          mundo[i][j] = passado[i][j];
    }
  }
}

void imprime_mundo(int **matriz, int lin, int col)
{
  for (int i = 0; i < lin; i++)
    for (int j = 0; j < col; j++)
      matriz[i][j] ? mvaddch(i, j, VIVO) : mvaddch(i, j, MORTO);
}

void copia_mundos(int **mundo, int **passado, int lin, int col)
{
  for (int i = 0; i < lin; i++)
    for (int j = 0; j < col; j++)
      passado[i][j] = mundo[i][j];
}

int main(int argc, char **argv)
{
  srand(time(NULL));

  /* Inicio de Tela do ncurses */
  initscr();

  int **mundo, **passado;
  int col, lin;

  /* Descobre o tamanho do terminal */
  //getmaxyx(stdscr, lin, col);
  lin = 10;
  col = 10;

  /* Aloca as matrizes onde acontecerá o jogo */
  mundo = alocar_matriz(lin, col);
  passado = alocar_matriz(lin, col);

  /* Constroi um mundo aleatório */
  for (int i = 0; i < lin; i++)
    for (int j = 0; j < col; j++)
      passado[i][j] = rand() % 2;


  while (1)
  {
    imprime_mundo(passado, lin, col);
    conta_vizinhos(mundo, passado, lin, col);
    copia_mundos(mundo, passado, lin, col);
    getch();
    refresh();
  }


  /* Encerra o ncurses */
  endwin();
  return 0;
}
