/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <climits>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int tradunghp(int hp){
    if (hp > 666) return 666;
    else if (hp < 0) return 0;
    return hp;
}
// tra exp ve dung trang thai
int traexp(int i){
    if (i > 600) return 600;
    else if (i < 0) return 0;
    return i;
}
// tra M ve dung trang thai
int tram(int i){
    if (i> 3000) return 3000;
    else if ( i < 0) return 0;
    return i;
}
int tinhgiatri(int E3, int i, int j){
    return ((E3*j) + (i*2))*(i-j);
}
int chaseTaxi(int &HP1 , int & EXP1, int &HP2, int &EXP2, int E3){
    int P[10][10];
    memset(P, 0, sizeof(P));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            P[i][j]=tinhgiatri(E3, i, j);
        }
    }
    int giatridiemduong = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <= i; j++){
            if (P[i][j] > (E3*2)){
                giatridiemduong+=1;
            }
        }
    }
    if (giatridiemduong >= 10){
        giatridiemduong = (giatridiemduong%10) + (giatridiemduong/10);
        if (giatridiemduong >= 10){
            giatridiemduong = (giatridiemduong%10) + (giatridiemduong/10);
        }
    }
    int giatridiemam = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 9; j >= i; j--){
            if (P[i][j] < (-E3)){
                giatridiemam+=1;
            }
        }
    }
    if (giatridiemam >= 10){
        giatridiemam = (giatridiemam%10) + (giatridiemam/10);
        if (giatridiemam >= 10){
            giatridiemam = (giatridiemam%10) + (giatridiemam/10);
        }
    }
    int diemgap = P[giatridiemduong][giatridiemam];
    int gtlonnhat = diemgap;
    int i = giatridiemduong;
    int j = giatridiemam;
    //if (giatridiemduong == 0 || giatridiemam == 0 || giatridiemduong == 9 || giatridiemam == 9)
    while(i != -1 && j != -1 && i != 10 && j != 10){
        if (gtlonnhat < P[i][j]){
            gtlonnhat = P[i][j];
        }
        i--;
        j--;
    }
    i = giatridiemduong;
    j = giatridiemam;
    while(i != -1 && j != -1 && i != 10 && j != 10){
        if (gtlonnhat < P[i][j]){
            gtlonnhat = P[i][j];
        }
        i--;
        j++;
    }
    i = giatridiemduong;
    j = giatridiemam;
    while(i != -1 && j != -1 && i != 10 && j != 10){
        if (gtlonnhat < P[i][j]){
            gtlonnhat = P[i][j];
        }
        i++;
        j--;
    }
    i = giatridiemduong;
    j = giatridiemam;
    while(i != -1 && j != -1 && i != 10 && j != 10){
        if (gtlonnhat < P[i][j]){
            gtlonnhat = P[i][j];
        }
        i++;
        j++;
    }
    i = giatridiemduong;
    j = giatridiemam;
    if(abs(diemgap) > gtlonnhat){
        EXP1=ceil((double)EXP1*0.88*100)/100;
        EXP2=ceil((double)EXP2*0.88*100)/100;
        HP1=ceil((double)HP1*0.9*100)/100;
        HP2=ceil((double)HP2*0.9*100)/100;
    }
    else{
        EXP1=ceil((double)EXP1*1.12*100)/100;
        EXP2=ceil((double)EXP2*1.12*100)/100;
        HP1=ceil((float)HP1*1.1*100)/100;
        HP2=ceil((double)HP2*1.1*100)/100;
    }
    cout<<EXP1<<" "<<EXP2<< " "<< HP1<<" "<<" "<<HP2<<endl;
    EXP1=traexp(EXP1);
    EXP2=traexp(EXP2);
    HP1= tradunghp(HP1);
    HP2 = tradunghp(HP2);
    int ketqua;
    if(abs(diemgap) > gtlonnhat){
        ketqua = diemgap;
    }
    else{
        ketqua = gtlonnhat;
    }
    return ketqua;
}
int main()
{
    int E3=59;
    int HP1= 400;
    int EXP1= 600;
    int HP2=350;
    int EXP2=500;
    cout<<chaseTaxi(HP1 ,EXP1,HP2,EXP2,E3);


    return 0;
}
