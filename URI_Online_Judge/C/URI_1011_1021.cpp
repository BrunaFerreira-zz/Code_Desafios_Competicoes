#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void esfera_uri_1011 (){
    double raio;
    cin>>raio;
    cout <<fixed << setprecision(3) << "VOLUME = "<< 3.14159 * (4/3.0) * pow(raio,3)<<endl;
}

// https://www.urionlinejudge.com.br/judge/pt/problems/view/1012
void area_uri_1012 (){

    double A, B, C;
    //Entrada: O arquivo de entrada contém três valores com um dígito após o ponto decimal.
    cin>>fixed>>setprecision(1)>>A>>B>>C;

    // Saida:
    // Area do triangulo retangulo = (base (A) * altura (C))/2
    cout <<fixed << setprecision(3) << "TRIANGULO: "<< (A * C)/2 <<endl;

    // Area do circulo  = (pi = 3.14159) * raio(C) ^2
    cout <<fixed << setprecision(3) << "CIRCULO: " << 3.14159 * pow(C,2) <<endl;

    //Area do trapézio = ((Base maior (A) + base menor(B) ) *  altura(C))/2
    cout <<fixed << setprecision(3) << "TRAPEZIO: "<< ((A + B)*C)/2 <<endl;

    //Area do quadrado  = lado(B) ^ 2
    cout <<fixed << setprecision(3) << "QUADRADO: "<< B*B <<endl;

    //Area do retângulo = lado(A) * lado(B)
    cout <<fixed << setprecision(3) << "RETANGULO: "<< A*B <<endl;
}

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1013
void maior_uri_1013 (){
    int A,B,C,D,maior;
    cin>>A>>B>>C;
    D = (A+B+abs(A-B))/2;
    maior = (D+C+abs(D-C))/2;
    cout<<maior<<" eh o maior"<<endl;
}

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1014
void consumo_uri_1014(){
    int X;
    double Y;

    cin>>X;
    cin>>fixed>>setprecision(1)>>Y;

    cout<<fixed<<setprecision(3)<< X/Y<<" km/l"<<endl;

}

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1015
void distancia_dois_pontos_uri_1015(){
    float x1,y1,x2,y2,distancia;

    cin>>x1>>y1;
    cin>>x2>>y2;

    distancia = sqrt(pow((x2-x1),2) + pow((y2-y1),2));

    cout<<fixed<<setprecision(4)<<distancia<<endl;
}

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1016
void distancia_uri_1016(){
    int X;
    cin>>X;

    cout<<(X*60)/30<<" minutos"<<endl;
}

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1017
void gasto_combustivel_uri_1017(){
    int tempo, velocidade;

    cin>>tempo;
    cin>>velocidade;

    cout<<fixed<<setprecision(3)<<(tempo*velocidade)/12.0<<endl;
}

void cedulas_uri_1018(){

}

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1019
void conversao_tempo_uri_1019(){
    int N,horas,tempo,minutos,segundos;
    cin>>N;

    horas = N/(60*60);
    tempo = horas*60*60;
    minutos = (N-tempo)/60;
    tempo = tempo+(minutos*60);
    segundos = N-tempo;

    cout<<horas<<":"<<minutos<<":"<<segundos<<endl;
}

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1020
void idade_em_dias_uri_1020(){
    int N,anos,meses,dias;
    cin>>N;

    anos = N/365;
    meses = (N-(anos*365))/30;
    dias = N-(anos*365 + meses*30);

    cout<<anos<<" ano(s)"<<endl;
    cout<<meses<<" mes(es)"<<endl;
    cout<<dias<<" dia(s)"<<endl;
}

int main()
{
    //esfera_uri_1011();
    //area_uri_1012();
    //maior_uri_1013 ();
    //consumo_uri_1014();
    //distancia_dois_pontos_uri_1015();
    //distancia_uri_1016();
    //gasto_combustivel_uri_1017();
    //conversao_tempo_uri_1019();
    idade_em_dias_uri_1020();
    return 0;
}
