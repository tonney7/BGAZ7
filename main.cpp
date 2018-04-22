#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

struct Node{
    string FoodName;
    int Category;
    int Calories;
    bool Favorite;
};


int main() {
    ifstream ifs("FoodCaloriesList.txt");
    map<string,Node> A;
    string temp;
    string temp2;
    string temp3;
    string temp4;
    
    int phase = 1;
    bool phaseBegin = true;
    while (getline(ifs,temp)){
        for (int i = 0; i < temp.size(); i++) {
            if ((temp[i] != ' ' && temp[i] !='\t')){
                phaseBegin = true;
                if (phase == 1) {
                    temp2 += temp[i];
                }
                else if (phase == 2){
                    temp3 += temp[i];
                }
                else if (phase == 3){
                    temp4 += temp[i];
                }
            }
            else if ((temp[i] == ' ' || temp[i] =='\t') && phaseBegin){ //if encounter a space
                if (phase == 1){
                }
                phase += 1;
                phaseBegin = false;
            }
        }
        phase = 1;
        phaseBegin = true;
        auto& record = A[temp2];
        record.FoodName = temp2;
        record.Category = stoi(temp4);
        record.Calories = stoi(temp3);
        record.Favorite = false;
        temp2 = "";
        temp3 = "";
        temp4 = "";
    }
    return 0;
}
