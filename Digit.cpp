/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: invitado
 *
 * Created on 19 de abril de 2017, 08:17 PM
 */

#include <cstdio>
#include <string.h>

using namespace std;

/*
 * 
 */

int tc, n;

int main(int argc, char** argv) {
    scanf("%d", &tc);
    while (tc--){
        int a[10];
        memset(a,0,sizeof(a));
        scanf("%d", &n);
        for (int i = 1; i <= 9 && i <= n; i++){
            a[i]++;
        }
        
        for (int i = 10; i <= n; i++){
            int aux = i;
            do{
                a[aux%10]++;
            }while(aux /= 10);
        }
        
        printf("%d", a[0]);
        for (int i = 1; i < 10; i++) printf(" %d", a[i]);
        printf("\n");
    }
    
    
    return 0;
}

