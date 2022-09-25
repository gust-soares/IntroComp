#include <stdio.h>
    /*funcao que calcula a raiz cubica*/
      double RaizCubica(double x){
      double r, rant, dif;
        rant = x;
        dif = 1;

       while(dif >= 1E-8 && x > 0){
        r = 2.0 * rant  / 3.0 + x / (3.0 * rant * rant);
        dif = r - rant;
          if (dif < 0)
           dif = -dif;
           rant = r;
}
    return rant;
}
    /*funcao que calcula a funcao chao*/
       int chao(double num){
       int piso;

           piso = (int)num;

    return piso;
}
    /*funcao responsavel pelo valor das cartas*/
       int carta(double caixa){
       int card;

       card = chao(caixa * 10 + 1);

    return card;
}
     /*funcao responsavel por atualizar o valor de caixa e realizar bons sorteios*/
       double NovaCaixa(double caixa){
       double rifa, caixinha;

        rifa = 9821.0 * RaizCubica(caixa) + 0.211327;
        caixinha = rifa - chao(rifa);

    return caixinha;
}

    /* cartinha representa a carta gerada pelo valor de caixa; numderrotas eh o numero de derrotas da banca; numcartasjog eh o numero de cartas que o jogador
sorteou; numcartasbanca eh o numero de cartas que a banca sorteou, N eh quantas rodadas de jogo foram realizadas; estrelas eh a quantidade de asteriscos
a serem impressos pra formar a curva; pontcarta eh a pontuacao das cartas sorteadas; pontjogador eh a pontuacao do jogador; pontbanca eh a pontuacao
da banca*/

   int main()
{
     int semente, cartinha, numderrotas = 0,numcartasjog = 0, numcartasbanca = 0,  N, estrelas, asterisco;
     double caixa, box, teto , pontcarta, pontjogador = 0, pontbanca = 0;

     printf("Digite uma semente: ");
     scanf("%d", &semente);

        box =(double)semente / 10;
        caixa = semente;
     while(caixa >= 1){
        caixa = box / 10;
        box = caixa;
     }
     for(teto = 0.5; teto <= 7.5; teto = teto + 0.5){          /*obtencao dos sorteios das cartas */
         numderrotas = 0;
        for(N = 1; N <= 10000; N++){
            pontbanca = 0; pontjogador = 0; numcartasjog = 0; numcartasbanca = 0;
             while(pontjogador < teto){
               cartinha = carta(caixa);
                 if(cartinha <= 7)
                    pontcarta = cartinha;
                 else
                    pontcarta = 0.5;
                    pontjogador = pontjogador + pontcarta;
                    caixa = NovaCaixa(caixa);
                    numcartasjog++;
     }
       if(pontjogador <= 7.5){
         while(pontbanca < pontjogador){
          cartinha = carta(caixa);

           if(cartinha <= 7)
             pontcarta = cartinha;
           else
             pontcarta = 0.5;
             pontbanca = pontbanca + pontcarta;
             caixa = NovaCaixa(caixa);
             numcartasbanca++;
          }
          if((pontbanca > 7.5) || (pontbanca < pontjogador) || (pontbanca == pontjogador && numcartasjog < numcartasbanca) ) {
             numderrotas++;
      }
    }
  }
            printf("%.1f %d ", teto, numderrotas);

            estrelas = chao(100 * numderrotas / 10000.0 + 0.5);

             for(asterisco = 1; asterisco <= estrelas; asterisco++){
                printf("*");
       }
                printf("\n");
    }
        return 0;
}


