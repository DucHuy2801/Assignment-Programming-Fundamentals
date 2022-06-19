/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//--------------------------------NHIEM VU 1-----------------------------------
bool checkValid(string s){
    for (size_t i = 0; i < s.size(); i++){
        if (s[i] >= '0' && s[i] <= '9') continue;
        else return false;
    }
    return true;
}
string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream ifs(ntb1);
    string line;
    string arr[2];
    int i = 0;
    while (getline(ifs, line)){
        arr[i] = line;
        i++;
    }
    string line1 = arr[0], line2 = arr[1];
    int find1 = line1.find('/');
    find1 = line1.find('/', find1 + 1);
    string n1 = line1.substr(find1 + 1);
    if (!checkValid(n1) || stoi(n1) < 1 || stoi(n1) > 999) return "0000000000";
    else{
        int nums[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int len = 2 * stoi(n1) - 1;
        for (int i = 0; i < len; i += 2){
            string temp = "";
            temp += line2[i];
            nums[stoi(temp)]++;
        }
        string res = "";
        for (int i = 0; i < 10; i++){
            res += to_string(nums[i] % 10);
        }
        return res;
    }
    //return "000000000";
}

bool checkStringPink(string s){
    if (s == "pink" || s == "Pink") return true;
    return false;
}
string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream ifs(ntb2);
    string n2;
    getline(ifs, n2);
    if (!checkValid(n2) || stoi(n2) < 5 || stoi(n2) > 100) return "1111111111";
    else{
        string arr[stoi(n2)];
        string line;
        int i = 0;
        while (getline(ifs, line)){
            arr[i] = line;
            i++;
        }
        int cntP = 0;
        for (int i = 0; i < stoi(n2); i++){
            string temp = arr[i];
            int count = 0;
            for (int j = 0; j < temp.size() - 3; j++){
                if (temp[j] != 'p' && temp[j] != 'P') continue;
                if (temp[j] == 'p' || temp[j] == 'P'){
                    if (checkStringPink(temp.substr(j, 4))) {count++; j += 3;}
                }
            }
            cntP += count;   
        }
        string res = "";
        if (cntP < 10000) cntP *= cntP;
        if (to_string(cntP).size() < 10){
            res = to_string(cntP);
            for (int i = 0; i < 10 - to_string(cntP).size(); i++){
                res += '9';
            }
        }
        return res;
    }
}
bool checkPrimeNumber(int n){
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    for (int i = 2; i < n; i++){
        if (n % i == 0) return false;
    }
    return true;
}
void sortArray(int arr[], int start, int end){
    for (int i = start; i <= end; i++){
        for (int j = i + 1; j <= end; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int calcFib(int n){
    if (n == 1 || n == 2) return 1;
    return calcFib(n - 1) + calcFib(n - 2);
}
bool isFib(int n){
    int i = 1;
    while (n > calcFib(i)) i++;
    if (n == calcFib(i)) return true;
    return false;
}
int findMax(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++) max = arr[i];
    return max;
}
string notebook3(string ntb3) {
    // Complete this function to gain point
    ifstream ifs(ntb3);
    int arr[10][10];
    string line;
    int i = 0;
    while (getline(ifs, line)){
        string temp = line;
        int j = 0;
        while (temp.find('|') != string::npos){
            string str = temp.substr(0, temp.find('|'));
            if (stoi(str) < 0) arr[i][j] = -stoi(str);
            else arr[i][j] = stoi(str);
            temp = temp.substr(temp.find('|') + 1);
            j++;
        }
        arr[i][j] = abs(stoi(temp));
        i++;
    }
    //----------STEP 1---------------------
    i = 0;
    for ( ; i < 10; i++){
        for (int j = i + 1; j < 10; j++){
            if (checkPrimeNumber(arr[i][j])) continue;
            else{
                while (!checkPrimeNumber(arr[i][j])) arr[i][j]++;
            }
        }
    }
    //--------------STEP 2----------------------
    i = 0;
    for (; i < 10; i++){
        for (int j = i - 1; j >= 0; j--){
            if (isFib(arr[i][j])) continue;
            else {
                while (!isFib(arr[i][j])) arr[i][j]++;
            }
        }
    }
    //--------------STEP 3-----------------------
    for (int i = 0; i < 10; i++) sortArray(arr[i], 7, 9);
    string res = "";
    for (int i = 0; i < 10; i++){
        int idx = 0, max = arr[i][0];
        for (int j = 1; j < 10; j++){
            if (arr[i][j] >= max) {
                max = arr[i][j];
                idx = j;
            }
        }
        res += to_string(idx);
    }
    return res;
}

void strToNum(int arr[10],string s){
    for (int i=0; i<10; i++) arr[i] = (int)(s[i]) - 48; 
}
string numToStr(int arr[10], string res){
    for (int i=0; i < 10; i++) res += to_string(arr[i]);
    return res;
}
string addStr(int arr1[10], int arr2[10],string res){
    int arr3[10];
    int temp = 0;
    for (int i=0;i<10;i++){
        arr3[i] = (arr1[i] + arr2[i] + temp) % 10;
        if (arr1[i] + arr2[i] + temp >= 10) temp = 1;
        else temp = 0;
    }
    res = numToStr(arr3, res);
    return res;
}
string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    int arr1[10], arr2[10], arr3[10], arr12[10], arr23[10], arr13[10];
    string res;
    strToNum(arr1, pwd1);
    strToNum(arr2, pwd2);
    strToNum(arr3, pwd3);
    strToNum(arr12, addStr(arr1, arr2, res));
    strToNum(arr13, addStr(arr1, arr3, res));
    strToNum(arr23, addStr(arr2, arr3, res));
    string final_res = "";
    final_res = pwd1 + ";" + pwd2 + ";" + pwd3 + ";" + addStr(arr1, arr2, res) + ";" + addStr(arr1, arr3, res) + ";" +
    addStr(arr2, arr3, res) + ";" + addStr(arr12, arr3, res) + ";" + addStr(arr1, arr23, res) + ";" + addStr(arr12, arr13, res);
    return final_res;
}
//-----------------------------NHIEM VU 2-----------------------------------
bool checkPoint(int row[], int col[], int x, int y){
    for (int i = 0; i < 100; i++){
        if (x == row[i] && y == col[i]) return true; 
    }
    return false;
}
bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    //---------------------------STEP 1---------------------------
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++) arr[i][j] = -9;
    }
    //---------------------------STEP 2---------------------------
    //-------------------------Handle moves-----------------------
    arr[0][0] = 0;
    int val = 0;
    int x = 0, y = 0;
    for (size_t i = 0; i < moves.size(); i++){
        if (moves[i] == 'U'){
            if (x != 0) { val += 9; x -= 1; arr[x][y] = val;}
            else continue;
        }
        else if (moves[i] == 'D') {
            if (x != 99) {val += 9; x += 1; arr[x][y] = val;}
            else continue;
        }
        else if (moves[i] == 'R'){
            if (y != 99) {val += 9; y += 1; arr[x][y] = val;}
            else continue;
        }
        else{
            if (y != 0) {val += 9; y -= 1; arr[x][y] = val;}
            else continue;
        }
    }
    //-------------------------STEP 3-----------------------------
    //-------------------------Handle points----------------------
    // Declare array of x_Points and y_Points
    int sizeArr = 0;
    for (size_t i = 0; i < points.size(); i++){
        if (points[i] == '(') sizeArr++;
        else continue;
    }
    int arrX[sizeArr], arrY[sizeArr];
    int idx = 0;
    while (points.find('-') != string::npos){
        string temp = points.substr(0, points.find('-'));
        arrX[idx] = stoi(temp.substr(1, temp.find(',') - 1));
        arrY[idx] = stoi(temp.substr(temp.find(',') + 1, temp.find(')') - temp.find(',') - 1));
        idx++;
        points = points.substr(points.find('-') + 1);
    }
    arrX[idx] = stoi(points.substr(1, points.find(',') - 1));
    arrY[idx] = stoi(points.substr(points.find(',') + 1, points.find(')') - points.find(',') - 1));
    
    //------------------------------Catch TAXI-------------------------------------
    int distance = 14 * (abs(arrX[0]) + abs(arrY[0]));
    if (arr[arrX[0]][arrY[0]] < distance){
        outTimes += to_string(distance);
        outCatchUps += 'N';
    }
    else{
        outTimes += to_string(distance);
        outCatchUps += 'Y';
    }
    for (int i = 1; i < sizeArr; i++){
        distance += 14 * (abs(arrX[i] - arrX[i - 1]) + abs(arrY[i] - arrY[i - 1]));
        if (outCatchUps.find('Y') != string::npos) {
            outTimes += ";-";
            outCatchUps += ";-";
        }
        else {
            if (distance <= arr[arrX[i]][arrY[i]]){
                outTimes += ";" + to_string(distance);
                outCatchUps += ";Y";
            }
            else{
                outTimes += ";" + to_string(distance);
                outCatchUps += ";N";
            }
        }     
    }
    return outCatchUps.find('Y') != string::npos;
}
//----------------NHIEM VU 3---------------------------
string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream ifs(tag);
    string line;
    string arr[2];
    while (getline(ifs, line)){
        arr[0] = line;
        getline(ifs, line);
        arr[1] = line;
    }
    int idx = arr[0].find(' ');
    string res1 = arr[0].substr(idx + 1);
    int idx1 = -1;
    for (int i = 0; i < arr[1].size(); i++) {
        if (arr[1][i] == ' ') {idx1 = i; break;}
    }
    int idx2 = arr[1].find(' ', idx1 + 1);
    int n3 = stoi(arr[1].substr(idx1, idx2 - idx1));
    string res = res1 + ";";
    for (int i = 0; i < n3; i++) res += message;
    return res;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */

