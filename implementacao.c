/*============================================================================*/
/* CSF13 - 2022-1 - PROJETO 2                                                 */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/**Adryan Castro Feres e Bruno Yamamoto */
/*============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "projeto2.h"

double medianaL3(double n1, double n2, double n3);

void mudaGanho (double* dados, int n_amostras, double ganho)
{
    int i;
    for(i=0; i<n_amostras; i++)
        dados[i] *= ganho;

}

void simulaSubAmostragem (double* dados, int n_amostras, int n_constantes)
{
    int valor_copiado, i, amostras_alteradas = 0;

    valor_copiado = 0;

    while(valor_copiado<n_amostras){

        for(i=0; i<n_constantes && amostras_alteradas<n_amostras; i++)
        {
            dados[i+valor_copiado] = dados[valor_copiado]; //Atribui o valor do vetor inicial da sequência aos vetores das posições seguintes.
            amostras_alteradas++;
        }

        valor_copiado += (n_constantes);//Garante que o vetor avançe n_constantes posições

    }
}

void estalos (double* dados, int n_amostras, int intervalo_max, double valor1)
{
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

void removeEstalos (double* dados, int n_amostras)
{
    int i;
    double *copia; /*copia o vetor'dados'*/

    copia = (double*) malloc(sizeof(double)*n_amostras);

    for(i=0; i<n_amostras; i++)
        copia[i]=dados[i];

    for(i=1; i<n_amostras-2; i++)
        dados [i] = medianaL3(copia[i-1], copia[i], copia[i+1]);

    free(copia);
}

void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq)
{
    int i, valor = 1, posicao = 0, contador = 0;
    float v_ciclo, meio_periodo, erro;

    meio_periodo = (taxa/freq)*0.5;

    v_ciclo = meio_periodo;

    while(posicao<n_amostras)
    {
        for(i=0; i<(int)v_ciclo && contador<n_amostras; i++)
        {
            dados[i+posicao] = valor;
            contador++;
        }

        posicao += (int)v_ciclo; //Garante que o vetor avançe corretamente

        erro = v_ciclo - (int)v_ciclo; //Atualização do erro após o ciclo
        v_ciclo = meio_periodo + erro;

        valor *= -1; //Altera entre -1 e 1


    }
}
void geraSenoide (double* dados, int n_amostras, int taxa, double freq, double fase)
{

    int i;
    float periodo_seno;

    //ADCIONAR ERRO!(IGUAL ERRO DA QUADRÁTICA)

    periodo_seno = (2*TRAB_PI*freq)/taxa; //Fórmula obtida igualando a fórmula geral do periódo a (taxa/freq) e isolando o p -> 2pi/p = taxa/freq

    for(i=0; i<n_amostras; i++)
    {
        dados[i] = sin(periodo_seno*i + fase);
    }

}



/* FUNÇOES AUXILIARES */


double medianaL3(double n1, double n2, double n3) /*calcula a mediana de largura 3. Funcao criada por autor.*/
{
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


