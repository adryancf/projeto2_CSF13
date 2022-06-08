
/*Bruno Shinji Nishi Yamamoto  RA: 2449005*/
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
    if(ganho>0){
        for(i=0; i<n_amostras; i++)
            dados[i] *= ganho;
    }        
    else{                                 
        for(i=0;i<n_amostras; i++)
            dados[i]=0;
    }
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

void estalos (double* dados, int n_amostras, int intervalo_max, double valor1){
    int i,inter; //inter eh a posição dentro do intervalo entre 1 e intervalo_max

    inter = (rand()%intervalo_max)+1; //somar 1 pra garantir inter>0

    for(i=0; i<n_amostras; i++){
        if(i==inter-1 && inter<n_amostras){ /*i==inter-1, já que i começa no 0
                                              e inter, no 1*/
            valor1*=-1;
            dados[i] = valor1;
            inter+=(rand()%(intervalo_max)+1);
        }
    }
}

double medianaL3(float n1, float n2, float n3){ /*calcula a mediana de largura 3. Funcao criada por autor.*/
    if (n1 < n2 && n1 < n3)
    {
        if (n2 < n3)
            return n2;
        else
            return n3;
    }
    else if (n2 < n1 && n2 < n3)
    {
        if (n1 < n3)
            return n1;
        else
            return n3;
    }
    else
    {
        if (n1 < n2)
            return n1;
        else
            return n2;
    }

}


void removeEstalos (double* dados, int n_amostras){
    int i;
    double *copia; /*copia o vetor'dados'*/

    copia = (double*) malloc(sizeof(double)*n_amostras);

    for(i=0; i<n_amostras; i++){
        copia[i]=dados[i];
    }

    for(i=1; i<n_amostras-2; i++){
        dados [i] = medianaL3(copia[i-1], copia[i], copia[i+1]);
    }
}

void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq)
{

}
void geraSenoide (double* dados, int n_amostras, int taxa, double freq, double fase)
{
    int i;
    float periodo_seno;

    periodo_seno = (2*TRAB_PI*freq)/taxa;

    for(i=0; i<n_amostras; i++)
        dados[i] = sin(periodo_seno*i + fase);
                
}
