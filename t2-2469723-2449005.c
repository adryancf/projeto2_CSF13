/*============================================================================*/
/* CSF13 - 2022-1 - PROJETO 2                                                 */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/**  */
/*============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#include "projeto2.h"

void mudaGanho (double* dados, int n_amostras, double ganho)
{
    int i;
    for(i=0; i<n_amostras; i++)
        dados[i] *= ganho;

}
void simulaSubAmostragem (double* dados, int n_amostras, int n_constantes)
{
    //n_constantes -> quantas amostras vao ter o valor da primeira
    //copiar o valor da primeira pras n_constantes seguintes...
    //apos essas n_constantes, pega o proximo valor e replica mais n_constantes

     int valor_copia, i, contador = 0;

    //VARIAVEL AUXILIAR
    valor_copia = 0;

    while(contador<n_amostras){
        for(i=0; i<n_constantes; i++) //Repete n_constantes vezes
        {
            //Avança as posições da sequência do vetor.
            //Atribui o valor do vetor inicial da sequência aos vetores das posições seguintes.
            dados[i+valor_copia] = dados[valor_copia];
            //Conta os vetores alterados
            contador++;
        }

        //Avança n_constantes posições
        valor_copia += (n_constantes);

    }
}
}
void estalos (double* dados, int n_amostras, int intervalo_max, double valor1)
{

}
void removeEstalos (double* dados, int n_amostras)
{

}
void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq)
{

}
void geraSenoide (double* dados, int n_amostras, int taxa, double freq, double fase)
{

}
