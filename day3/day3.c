#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file = fopen("input.txt", "r"); /* should check the result */
    // char line[256];
    char line[300][256];
    int prioridade = 0;

    /*
    while (fgets(line, sizeof(line), file))
    {
        int tamanho = 0;
        while (line[tamanho] != '\0')
        {
            tamanho++;
        }

        int metade = tamanho / 2;
        int encontrado = 0;

        for (int i = 0; i < metade; i++)
        {
            if (encontrado)
                break;
            for (int j = metade; j < tamanho; j++)
            {
                if (encontrado)
                    break;
                if (line[i] == line[j])
                {
                    if (line[i] < 91)
                    {
                        prioridade += line[i] - 38;
                    }
                    else
                    {
                        prioridade += line[i] - 96;
                    }
                    encontrado = 1;
                }
            }
        }
    }
    */

    for (int a = 0; a < 300; a++)
    {
        fgets(line[a], 255, file);
    }

    int a = 0;
    while (a < 300)
    {

        int encontrado = 0;

        for (int i = 0; i < strlen(line[a]); i++)
        {
            if (encontrado)
                break;
            for (int j = 0; j < strlen(line[a + 1]); j++)
            {
                if (encontrado)
                    break;
                for (int k = 0; k < strlen(line[a + 2]); k++)
                {
                    if (encontrado)
                        break;

                    if (line[a][i] == line[a + 1][j] && line[a + 1][j] == line[a + 2][k])
                    {
                        if (line[a][i] < 91)
                        {
                            prioridade += line[a][i] - 38;
                        }
                        else
                        {
                            prioridade += line[a][i] - 96;
                        }
                        encontrado = 1;
                    }
                }
            }
        }
        a += 3;
    }

    fclose(file);

    printf("%d", prioridade);

    return 0;
}
