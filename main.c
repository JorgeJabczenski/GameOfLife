#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define VIVO  '@'
#define MORTO ' '

int
main (int argc, char **argv)
{
  srand (time (NULL));

  /* Inicio de Tela do ncurses */
  initscr ();

  int **mundo, **passado;
  int col, lin;

  /* Descobre o tamanho do terminal */
  getmaxyx (stdscr, lin, col);
  printf ("%d %d\n", lin, col);

  /* Aloca as matrizes onde acontecerá o jogo */
  mundo = malloc (sizeof (int *) * lin);
  passado = malloc (sizeof (int *) * lin);
  for (int i = 0; i < lin; i++)
  {
    mundo[i] = malloc (col * sizeof (int));
    passado[i] = malloc (col * sizeof (int));
  }

  /* Constroi um mundo aleatório */
  for (int i = 0; i < lin; i++)
    for (int j = 0; j < col; j++)
      passado[i][j] = rand () % 2;


  while (1)
  {
    // int vizinhos_vivos = 0;
    // /* Calcula o novo estado */
    // for (int i = 0; i < lin; i++)
    //   for (int j = 0; j < col; j++)
    //   {
    //     if (i < 1) /* primeira linha */
    //     {
    //       if (j < 1) /* canto superior esquerdo*/
    //       {
    //         vizinhos_vivos += passado[i+1][j];
    //         vizinhos_vivos += passado[i+1][j+1];
    //         vizinhos_vivos += passado[i][j+1];
    //       }
    //       if (j > col-2) /* canto superior direito */
    //       {
    //         vizinhos_vivos += passado[i][j-1];
    //         vizinhos_vivos += passado[i+1][j-1];
    //         vizinhos_vivos += passado[i+1][j];
    //       }
    //     }
    
    for (int i = 0; i < lin; i++)
    {
      for (int j = 0; j < col; j++)
      {
        int vizinhos = 0;
        for (int k = -1; k < 2; k++)
        {
          for (int l = -1; l < 2; l++)
          {
            if ()
          }
        }
      }
    }

    }

  /* Imprime o mundo */
    for (int i = 0; i < lin; i++)
      for (int j = 0; j < col; j++)
        mundo[i][j] ? mvaddch (i, j, VIVO) : mvaddch (i, j, MORTO);

    
    refresh ();
  }


  /* Encerra o ncurses */
  endwin ();
  return 0;
}
