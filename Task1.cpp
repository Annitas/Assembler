#include <iostream>
using namespace std;

int charsWithEqualNeighbors(const char* s, int length) {
    int len = length;
    int countOfChars = 2;
    __asm {
        mov eax, len
        mov ebx, countOfChars
        mov ecx, 0
        mov edx, 0
        cmp eax, ebx
        jle SMALL_STR
        cmp eax, ebx
        jnle NORMAL_STR

    SMALL_STR:
        jmp FIN

    NORMAL_STR:
        mov ecx, eax
        dec ecx
        xor eax, eax
        mov eax, ebx
        xor ebx, ebx
        mov ebx, s
        mov esi, 0

    FOR:
        inc esi
        mov dh, [ebx][esi-1]
        mov dl, [ebx][esi+1]
        cmp dh, dl 
        je INC_COUNTER
        cmp esi, ecx
        jl FOR
        cmp esi, ecx
        jnl FIN

    INC_COUNTER:
        inc eax
        cmp esi, ecx
        jl FOR
        cmp esi, ecx
        jnl FIN

    FIN:
    }
}

int main() {
    const char* s = "korovaa";
    cout << "Count of chars with equal neighbors: " 
        << charsWithEqualNeighbors(s, 7) << endl; 
}