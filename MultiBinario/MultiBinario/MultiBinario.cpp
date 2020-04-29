#include <iostream>       
#include <string>         
#include <bitset>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <ctime>

using namespace std;

int num = 0, opand, opxor, extra, extra1, add;
unsigned int n;
bitset<32> A(0);
bitset<32> bit;
bitset<32> bit1;
bitset<32> C(bit1);
bitset<32> N(1);

void sumarBits()
{
    cout << "Ingresa un numero binario( multiplicando): ";
    cin >> bit;
    cout << "Ingresa otro numero binario( multiplicando): ";
    cin >> bit1;

    for (int i = 0; i < bit.size(); i++) {
        opxor = bit[i] ^ bit1[i];
        opand = bit[i] & bit1[i];
        extra = opxor ^ num;
        extra1 = opxor & num;
        add = extra1 | opand;
        A[i] = extra;
        num = add;
    }

}

void restaBits() {
    num = 0;
    for (int i = 0; i < C.size(); i++) {
        opxor= C[i] ^ N[i];
        extra1 = opxor ^ num;
        opand = opxor & num;
        add = opand | extra;
        C[i] = extra1;
        num= add;
    }
    for (int i = 0; i < C.size(); i++) {
        opxor = C[i] ^ bit[i];
        extra1 = opxor ^ num;
        opand = opxor & num;
        extra = C[i] & bit[i];
        add = opand | extra;
    }
}

void complementoA2() {
    for (int i = 0; i < C.size(); i++) {
        opxor = C[i] ^ N[i];
        extra1 = opxor ^ num;
        opand = opxor & num;
        extra = N[i] & C[i];
        add = opand | extra;
        C[i] = extra1;
    }
}

void multiplicacionConSigno() {
    const bitset<32> M(C);
    for (int i = 0; i < M.size(); i++) {
        opxor = M[i] ^ A[i];
        opand = opxor & num;
        extra = A[i] & M[i];
        extra1 = opxor ^ num;
        add = opand | extra;
        C[i] = extra1;
    }
    cout << "Multiplicacion de complemento a 2: " << C << endl;

    int numberE;
    int incr = A.size();
    while (incr != 0) {
        if (bit1[0] == 1) {
            num = 0;
            for (int i = 0; i < C.size(); i++) {
                opxor = C[i] ^ A[i];
                opand = opxor & num;
                extra1 = C[i] & A[i];
                add = opand | extra;
                A[i] = extra1;
            }
        }
        if (bit1[0] == 0 ) {
            for (int i = 0; i < C.size(); i++) {
                opxor = C[i] ^ A[i];
                opand = opxor & num;
                extra = C[i] & A[i];
                add = opand | extra;
                A[i] = extra1;
            }
        }
    }
}

int main() {
    sumarBits();
    restaBits();
    complementoA2();
    multiplicacionConSigno();
}