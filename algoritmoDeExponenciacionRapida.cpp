#include <iostream>
using namespace std;

long long exponenciacionModularRapida(long base, long exponente, long modulo) 
{
    long long resultado = 1;
    base = base % modulo;  

    while (exponente > 0)
    {
        if (exponente % 2 == 1) 
        {
            resultado = (resultado * base) % modulo;
        }
        base = (base * base) % modulo;
        exponente /= 2;
    }

    return resultado;
}

int main() 
{
    long a = 5;
    long b = 23;
    long n = 11;

    long long resultado = exponenciacionModularRapida(a, b, n);
    cout << "Resultado de " << a << "^" << b << " mod " << n << " es: " << resultado << endl;

    return 0;
}
