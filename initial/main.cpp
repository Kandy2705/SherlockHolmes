/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"

using namespace std;
// tra hp ve dung trang thai
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
///////////////////////////////////////////////////////////////
//nhiem vu 1
int firstMeet(int &EXP1, int &EXP2, int E1){
    if (E1 < 0 || E1 > 99){
        return -99;
    }
    else if (E1 >= 0 && E1 <= 3){
        if (E1 == 0){
            EXP2 += 29;
        }
        else if (E1 == 1){
            EXP2 += 45;
        }
        else if (E1 == 2){
            EXP2 += 75;
        }
        else if (E1 == 3){
            EXP2 += 29 + 45 + 75;
        }
        EXP2 = traexp(EXP2);

        int D = E1 * 3 + EXP1*7;
        if (D % 2 == 0){
            EXP1 = ((EXP1 + (double)D/200)*100)/100;
        }
        else{
            EXP1 = ceil((EXP1 - (double)D/100)*100)/100;
        }
        EXP1 = traexp(EXP1);
    }
    else{
        if (E1 >= 4 && E1 <= 19){
            EXP2 += ceil(((double)E1/4 + 19)*100)/100;
        }
        else if (E1 >= 20 && E1<= 49){
            EXP2 += ceil(((double)E1/9 + 21)*100)/100;
        }
        else if (E1 >= 50 && E1 <= 65){
            EXP2 += ceil(((double)E1/16 + 17)*100)/100;
        }
        else if (E1 >= 66 && E1 <= 79){
            EXP2 += ceil(((double)E1/4 + 19)*100)/100;
            if (EXP2 > 200){
                EXP2 += ceil(((double)E1/9 + 21)*100)/100;
            }
        }
        else{
            EXP2 += ceil(((double)E1/4 + 19)*100)/100;
            EXP2 += ceil(((double)E1/9 + 21)*100)/100;
            if (EXP2 > 400){
                EXP2 += ceil(((double)E1/16 + 17)*100)/100;
                EXP2 = ceil(((double)EXP2*1.15)*100)/100;
            }
        }
        EXP2 = traexp(EXP2);
        EXP1 -= E1;
    }

    return EXP1 + EXP2;
}
///////////////////////////////////////////////////////////////////
// nhiem vu 2
double tinhxacsuat(int &EXP1){
    double giatri = sqrt(EXP1);
    int S;
    double P1;
    int a = pow(ceil(giatri*100)/100,2) - EXP1;
    int b = -pow(floor(giatri*100)/100,2) + EXP1;
    if (a < b) S = pow(ceil(giatri*100)/100,2);
    else S = pow(floor(giatri),2);
    if ( S <= EXP1){
        P1 = 100;
    }
    else{
        P1 = ((double)EXP1/S + 80)/ 123 * 100;
    }
    return P1;
}
int traceLuggage(int&HP1, int&EXP1, int&M1, int E2){
    // duong thu 1
    double P1 = tinhxacsuat(EXP1);
    // duong thu 2
    int tienbd = M1*0.5;
    while(E2 % 2 != 0 && E2 != 0) {
        if (HP1 < 200) {
            HP1 = ceil((double) HP1 * 1.3*100)/100;
            M1 -= 150;
        } else {
            HP1 = ceil((double) HP1 * 1.1*100)/100;
            M1 -= 70;
        }
        tram(M1);
        tradunghp(HP1);
        if (M1 > tienbd){
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil((double) EXP1 * 1.13*100)/100;
            tram(M1);
            traexp(EXP1);
            if (M1 > tienbd){
                if (EXP1 < 300) {
                    M1 -= 100;
                } else {
                    M1 -= 120;
                }
                EXP1 = ceil((double) EXP1 * 0.9*100)/100;
                tram(M1);
                traexp(EXP1);
                if (M1 <= tienbd){
                    break;
                }
            }
            else{
                HP1 = ceil(HP1*0.83*100)/100;
                EXP1 = ceil(EXP1*1.17*100)/100;
                traexp(EXP1);
                tradunghp(HP1);
                break;
            }
        }
        else{
            HP1 = ceil(HP1*0.83*100)/100;
            EXP1 = ceil(EXP1*1.17*100)/100;
            traexp(EXP1);
            tradunghp(HP1);
            break;
        }
    }
    if (E2 % 2 == 0){
        if (HP1 < 200) {
            HP1 = ceil((double) HP1 * 1.3*100)/100;
            M1 -= 150;
        } else {
            HP1 = ceil((double) HP1 * 1.1*100)/100;
            M1 -= 70;
        }
        tram(M1);
        tradunghp(HP1);

        if (M1 != 0){
            if (EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            EXP1 = ceil((double) EXP1 * 1.13*100)/100;
            tram(M1);
            traexp(EXP1);

            if(M1 != 0){
                if (EXP1 < 300) {
                    M1 -= 100;
                } else {
                    M1 -= 120;
                }
                EXP1 = ceil((double) EXP1 * 0.9*100)/100;
                tram(M1);
                traexp(EXP1);
            }
        }
    }
    double P2 = tinhxacsuat(EXP1);
    //con duong 3
    int P3;
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >= 0 && E2 <= 9){
        P3 = P[E2];
    }
    else {
        P3 = P[(E2%10 + E2/10)%10];
    }
    if (P1 == 1 && P2 == 1 && P3 == 100){
        EXP1 = ceil((double)EXP1*0.75*100)/100;
    }
    else{
        int P = (P1 + P2 + P3)/3;
        if (P < 50){
            HP1 = ceil((double)HP1*0.85*100)/100;
            EXP1 = ceil((double)EXP1*1.15*100)/100;
        }
        else{
            HP1 = ceil((double)HP1*0.9*100)/100;
            EXP1 = ceil((double)EXP1*1.2*100)/100;
        }
        EXP1 = traexp(EXP1);
    }
    return HP1 + EXP1 + M1;
}
//////////////////////////////////////////////////////////////////
// nhiem vu 3
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
//////////////////////////////////////////////////////////////////
// nhiem vu 4
int checkPassword(string s,string email){
    int vitria = s.find('@');
    string se = s.substr(0,vitria);

}
void sa_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
        return;
    }

    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    int result = firstMeet(EXP1, EXP2, E1);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;
}

int main(int argc, const char * argv[]) {
    sa_tc_01();
    return 0;
}