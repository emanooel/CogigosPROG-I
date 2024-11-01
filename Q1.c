/*
 * Leia uma cadeia de caracteres no formato “DD/MM/AAAA” e copie o dia, mês e
 * ano para 3 variáveis inteiras. Antes disso, verifique se as barras estão no lugar
 * certo, e se DD, MM AAAA são numéricos, podendo fazer implementando uma função chamada is_digit.
 */
#include <stdio.h>
#include <string.h>

// DD/MM/AAAA
/*
 * Função que converte strings de até 4 digitos em inteiros.
 * Depois verificar uma possibilidade de aumentar para dezena de milhar, ou seja, 5 digitos
 */
int potB10(int); // Assinatura da função como é recomendado em C, pois estou chamando a função potB10 "antes" do compilador ver a implementação dela.

/*
* Nesta primeira versão da função toInt que converte uma string em um inteiro tem uma questão chata, eu sempre tenho que dizer quantos digitos tem
* o numero que estou passando na string :( isso será corrigido no proximo commit.
* chat numero[]: String que irei converter em inteiro
* n: tamanho da string.
-------- Resolvendo questão de ter que passar a quantidade de digitos quem o inteiro que digitei possui -----
*/

int dma_is_digit(char data[])
{
    int tam = strlen(data);
    int qtd_digitos = 0;
    for (int i = 0; i < tam; i++)
    {
        if ((i == 2 || i == 5) && data[i] == '/')
        {
            continue;
        }
        else
        {
            if (data[i] >= '0' && data[i] <= '9')
            {
                qtd_digitos++;
            }
            else
            {
                qtd_digitos--;
            }
        }
    }

    if (qtd_digitos == 8)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int toInt(char numero[])
{
    int qtd_dgts_num = strlen(numero);
    int inteiro = 0;
    for (int i = 0; i < qtd_dgts_num; i++)
    {
        inteiro += (int)(numero[i] - '0') * potB10(qtd_dgts_num - (i + 1));
    }
    // ano = (int) ((data[0] - '0') * potB10(3)) + ((data[1] - '0') * potB10(2)) + ((data[2] - '0') * potB10(1)) + ((data[3] - '0') * potB10(0));
    // printf("%d\n", ano);
    // mes = (int) ((data[3] - '0') * 10) + (data[4] - '0');
    // printf("%d\n",mes);
    // dia = ((data[0] - '0') * 10) + (data[1] - '0');
    // printf("%d\n",dia);
    return inteiro;
}

/*
 * Observando (int) ((data[6] - '0') * 1000) + ((data[7] - '0') * 100) + ((data[8] - '0') * 10) + ((data[9] - '0') * 1);
 * 1,10,100,1000 - São resultados de potencias de base 10, ou seja, base 10 potencia 0 = 1, base 10 potencia 1 = 10, base 10 potencia de 2 = 100
 * Repare, a quantidade de 0s, influencia no número da potência, 1000 tem 3 zeros, potencia 3, base 10 potencia 3 = 1000.
 * Então farei uma função no qual a unica coisa que irei calcular, é a potencia na base 10, já que quero fazer apenas potencias na base 10, não
 * preciso fazer uma função com 2 parâmetros, apenas um parametro potência será o suficiente.
 */
int potB10(int pot)
{
    int res = 1;
    int base = 10;
    for (int i = 1; i <= pot; i++)
    {
        res = res * base;
    }
    return res;
}

int main()
{
    char data[11];
    int dia, mes, ano;

    // para determinar se as barras estão na posição correta.
    /*
     * Em termos de acesso a indice de vetor (pois a string é um vetor de caracter) qual o lugar correto da barra ?
     * O lugar correto da barra é no indice 2 e 5.
     * sabendo disso, faça o script executar e prosseguir apenas se as barras estiverem no lugar correto.
     */
    scanf("%s", data);
    
    if ((data[2] == '/' && data[5] == '/') && dma_is_digit(data) == 1){ // Testar se o codigo executa com as barras no lugar errado;
        // int ch = (int) 'A';
        // printf("%d\n", ch);
        /* 1. fazendo um casting, converter um caractere de digito em um inteiro.
         * 1.1 para isso pegue o caractere do tipo digito que quer transformar em inteiro e subtraia pelo menor valor de inteiro da tabela ASCII.
         * 2. Relembrar os conceitos de UDCM (Unidade, Dezena, Centena e Milhar) -> 1, 10, 100, 1000.
         * 2.1. Usando os conceitos de UDCM, decompor o dia.
         * 2.2. Usando os conceitos de UDCM, decompor o mês.
         * 2.3 Usando os conceitos de UDCM, decompor o ano.
         */

        char dia_string[] = "00";
        char mes_string[] = "00";
        char ano_string[] = "0000";

        dia_string[0] = data[0];
        dia_string[1] = data[1];

        mes_string[0] = data[3];
        mes_string[1] = data[4];

        ano_string[0] = data[6];
        ano_string[1] = data[7];
        ano_string[2] = data[8];
        ano_string[3] = data[9];

        dia = toInt(dia_string);
        mes = toInt(mes_string);
        ano = toInt(ano_string);

        printf("%d\n", dia);
        printf("%d\n", mes);
        printf("%d\n", ano);

    }else{
        puts("PERA LÁ AMIGO(A)");
    }
}