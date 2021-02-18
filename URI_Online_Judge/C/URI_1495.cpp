// Trabalho 2
// Disciplina de Analise de Algoritmo - EACH 2/2020
// Aluna: Bruna Ferreira dos Santos

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool compare(int a, int b) {
    return (a > b);
    }

int main()
{

// n = número de partidas que o time jogou
// g = número de gols que  time pode comprar
// s = gols marcados pelo time
// r = gols sofridos pelo time
 int n, g, s, r, c, i, saldo_gol;
 bool b;

 // Leitura dos valores
 while(scanf("%d %d", &n, &g) == 2)
 {
  c = 0;
  v.clear();

  // Para cada partida ler o saldo de gol
  // e já gera a pontuação:
  // + 3 para vitoria
  // + 1 para empate
  // + 0 para derrota

  for (i = 0; i < n; ++i)
  {
   scanf("%d %d", &s, &r);
   if(s > r) c += 3;
   else v.push_back(s - r);
  }

  // Ordena a lista de valores das partidas
  sort(v.begin(), v.end(), compare);
  saldo_gol = v.size();
  b = false;

  // Verifica a melhor maneira de comprar novos gols
  // e aumenta a quantidade de pontos
  for (i = 0; i < saldo_gol; ++i)
  {
   if(b){
    if(v[i] == 0) c++;
    else break;
   }else{
    if(g <= 0) b = true;

    if((1 - v[i]) <= g){
     g -= (1 - v[i]);
     c += 3;
    }else if((0 - v[i]) == g){
     c++;
     g -= (0-v[i]);
    }else{
     b = true;
    }
   }
  }

  printf("%d\n", c);
 }

 return 0;
}

