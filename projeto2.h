/*============================================================================*/
/* CSF13 - 2022-1 - PROJETO 2                                                 */
/*----------------------------------------------------------------------------*/
/* Bogdan T. Nassu - btnassu@utfpr.edu.br                                     */
/* Leyza E. B. Dorini - leyza@utfpr.edu.br                                    */
/*============================================================================*/
/** Funções pedidas para o 2o projeto da disciplina Fundamentos de Programação
 * 1, 1o semestre de 2022, prof. Bogdan T. Nassu e Leyza E. B. Dorini,
 * Universidade Tecnológica Federal do Paraná. */
/*============================================================================*/

#ifndef __PROJETO2_H
#define __PROJETO2_H

/*============================================================================*/

#define TRAB_PI 3.1415926536

/*============================================================================*/

void mudaGanho (double* dados, int n_amostras, double ganho);
void simulaSubAmostragem (double* dados, int n_amostras, int n_constantes);
void estalos (double* dados, int n_amostras, int intervalo_max, double valor1);
void removeEstalos (double* dados, int n_amostras);
void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq);
void geraSenoide (double* dados, int n_amostras, int taxa, double freq, double fase);

/*============================================================================*/
#endif /* __PROJETO2_H */
