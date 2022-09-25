/***************************************************************/
/**                                                           **/
/**   Gustavo Soares da Silva Oliveira      11261812          **/
/**   Exercício-Programa 01                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

/* Descrição: Resolver um problema semelhante ao jogo Senha (Mastermind), no qual o desafiado deve dar palpites para acertar a senha escolhido por outra pessoa, considerando
              apenas os pinos pretos que significa que está com a cor certa na posição certa. */

/* Variáveis de entrada:

		k - Número de digitos da senha;
	c - Número de cores possiveis;
		qnt_Palpites - quantos palpites serão dados;
		senha - pode ser escolhida por alguém, ou gerada aleatoriamente para inicio do jogo;
		palpite - Tentativa de acertar a senha.
*/

/*Contadores:

		i - Para estruturas de repetição;
		cont - quantidade de pinos pretos relativos ao palpite.
*/

/* Variáveis auxiliares/calculos:

		refSenha - Variavel auxiliar para não perder a senha original;
		refPalpite - Mesmo motivo do acima;
		DigitoPalpite - Usado para o calculo de comparar os digitos;
		DigitoSenha - Mesmo do acima.*/


#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
  int k, c, qnt_palpites, senha, i, palpite, cont = 0, refSenha, refPalpite;
  int DigitoPalpite, DigitoSenha;
  printf("Entre com o numero de digitos: ");
  scanf("%d", & k);
  printf("Entre com o numero de cores: ");
  scanf("%d", & c);
  printf("Entre com o numero maximo de palpites: 	");
  scanf("%d", & qnt_palpites);
  printf("Entre com a senha de %d digitos (0 para valor aleatorio): ", k);
  scanf("%d", & senha);

  /* Código dado no documento do exercício programa */
  if (senha == 0) {
    srand(time(NULL));
    for (i = 0; i < k; i++) {
      senha = senha * 10 + (rand() % c + 1);
    }
  }


  for (i = 0; i < qnt_palpites; i++) {
    printf("Digite o seu palpite: ");
    scanf("%d", & palpite);
    refPalpite = palpite;
    refSenha = senha;
    while ((refSenha > 0) && (refPalpite > 0)) {
      DigitoPalpite = refPalpite % 10;
      refPalpite = refPalpite / 10;
      DigitoSenha = refSenha % 10;
      refSenha = refSenha / 10;
      if (DigitoPalpite == DigitoSenha) {
        cont++;
      }
    }
    if (cont == k) {
      printf("Voce descobriu a senha em %d tentativas!", i + 1);
      return 0;
    }
    printf("\n %d pinos pretos \n", cont);
    cont = 0;
  }
    return 0;
}






