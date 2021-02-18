 // Aluna: Bruna Ferreira dos Santos
#include <cstdio>
using namespace std;

struct No
{
 int info;
 No* esq;
 No* dire;
};

No* busca_novaraiz(int info)
{
 No* novaraiz = new No();
 novaraiz -> info = info;
 novaraiz -> esq = NULL;
 novaraiz -> dire = NULL;
 return novaraiz;
}

No* Inserir(No* raiz, int info)
{
 if(raiz == NULL){ //empty tree
  raiz = busca_novaraiz(info);
  return raiz;
 }else if(info <= raiz -> info){
  raiz -> esq = Inserir(raiz -> esq, info);
 }else{
  raiz -> dire = Inserir(raiz -> dire, info);
 }

 return raiz;
}

void printPreOrdem(struct No* raiz)
{
   if (raiz == NULL)
    return;
   printf(" %i", raiz -> info);
   printPreOrdem (raiz -> esq);
   printPreOrdem (raiz -> dire);
}

void printEmOrdem(struct No* raiz)
{
   if (raiz == NULL)
    return;
   printEmOrdem (raiz -> esq);
   printf(" %i", raiz -> info);
   printEmOrdem (raiz -> dire);
}

void printPosOrdem(struct No* raiz)
{
   if (raiz == NULL)
    return;
   printPosOrdem (raiz -> esq);
   printPosOrdem (raiz -> dire);
   printf(" %i", raiz -> info);
}

int main()
{
 int c, n, x, count = 1;

 scanf("%i", &c);

 for (int i = 0; i < c; ++i)
 {
  No* raiz = NULL;
  scanf("%i", &n);

  for (int j = 0; j < n; ++j)
  {
   scanf("%i", &x);
   raiz = Inserir(raiz, x);
  }

  printf("Case %i:\n", count);
  printf("Pre.:");
  printPreOrdem(raiz);
  printf("\n");

  printf("In..:");
  printEmOrdem(raiz);
  printf("\n");

  printf("Post:");
  printPosOrdem(raiz);
  printf("\n");

  count++;
  //if(i != (c - 1))
  printf("\n");
 }

 return 0;
}
