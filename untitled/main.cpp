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
int demtrung(string arr_pwds[], int vitri,int num_pwds){
    string vitrixet = arr_pwds[vitri];
    int count = 0;
    for(int i = 0; i < num_pwds; i++){
        if (arr_pwds[i] == vitrixet){
            count++;
        }
    }
    return count;
}
int findCorrectPassword(string arr_pwds[], int num_pwds){
    int vitritra = 0;
    for(int i = 0; i < num_pwds;i++){
        int a = demtrung(arr_pwds, i, num_pwds);
        int b =demtrung(arr_pwds, vitritra, num_pwds);
        if (a > b){
            vitritra = i;
        }
        else if (a == b){
            if (arr_pwds[i].size() == arr_pwds[vitritra].size()){
                if (i < vitritra){
                    vitritra = i;
                }
            }
            else if (arr_pwds[i].size() > arr_pwds[vitritra].size()){
                vitritra = i;
            }
        }
    }
    return vitritra;
}
int main() {
    string arr_pwds[] = {"pink123", "xxxx@xxxx", "123xyz", "pink#pink", "pink#pink",
                         "pink123"};
    cout<< findCorrectPassword(arr_pwds, 6);
    return 0;
}
