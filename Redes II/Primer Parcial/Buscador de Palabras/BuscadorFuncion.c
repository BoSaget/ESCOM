#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
      FILE *Fd;

      char archivo[30],palabra[30],texto[80];

      int i,tmp1,tmp2,contador=0;


      printf("Mete el nombre del fichero en el que buscaremos: \n");

      scanf("%s", archivo);

      printf("Mete la palabra a buscar en ese fichero: \n");

      scanf("%s", palabra);


      Fd=fopen(archivo,"r");

      if (Fd==NULL)

         printf("Error abriendo el fichero");


      while (feof(Fd)==0)

      {
            fgets(texto,80,Fd);

            for(i=0;i<strlen(texto);i++)

            {

               if (palabra[0]==texto[i])

               {

                  tmp1=0;

                  tmp2=i;

                  while ((palabra[tmp1]==texto[tmp2])&&(tmp2<strlen(texto))&&(tmp1!=strlen(palabra)))

                  {
                        tmp1++;

                        tmp2++;

                        if (tmp1==strlen(palabra))

                           contador++;
                  }
               }
            }
      }
      printf("La palabra se repite en el texto %d veces \n",contador);

      getchar();
}
