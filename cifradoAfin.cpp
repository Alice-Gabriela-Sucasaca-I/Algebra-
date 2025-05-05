#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int modInverse(int a, int m) 
{
    for (int i = 1; i < m; ++i) 
    {
        if ((a * i) % m == 1)
            return i;
    }
    return -1; 
}

string cifrarAfin(const string& mensaje, int a, int b)
{
    string resultado = "";
    for (char c : mensaje)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;
            int cifrado = (a * x + b) % 26;
            resultado += char(cifrado + base);
        }
        else 
        {
            resultado += c; 
        }
    }
    return resultado;
}

string descifrarAfin(const string& mensaje, int a, int b)
{
    string resultado = "";
    int a_inv = modInverse(a, 26);
    for (char c : mensaje)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            int y = c - base;
            int descifrado = (a_inv * (y - b + 26)) % 26;
            resultado += char(descifrado + base);
        }
        else 
        {
            resultado += c;
        }
    }
    return resultado;
}

int main() {
    int a = 3, b = 5;

    string mensajeClaro = "Buenas noches";
    string mensajeCifrado = cifrarAfin(mensajeClaro, a, b);
    string mensajeADescifrar = "Avmf, lvpv rhkfh";
    string mensajeDescifrado = descifrarAfin(mensajeADescifrar, a, b);

    cout << "Mensaje cifrado de \"" << mensajeClaro << "\": " << mensajeCifrado << endl;
    cout << "Mensaje descifrado de \"" << mensajeADescifrar << "\": " << mensajeDescifrado << endl;

    return 0;
}
