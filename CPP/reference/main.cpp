#include <iostream>
void swapC(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
void swapCPP(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}
int main(){
    int i=5, j=6, &k = j;
    std::cout << j << " " << k++ << std::endl;
    std::cout << j << " " << k << std::endl;
    swapC(&i, &j);
    std::cout << j << " " << k << std::endl;
    swapCPP(i, j);
    std::cout << j << " " << k << std::endl;
}
