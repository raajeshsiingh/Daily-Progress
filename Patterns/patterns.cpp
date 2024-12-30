#include<iostream>
using namespace std;

int main() {

    int len = 4;

    /*
    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4
    */

    for(char i=1; i<=len; i++) {
        for(int j=1; j<=len; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

cout << "----------------" << endl;

    /*
    1
    1 2
    1 2 3
    1 2 3 4
    */

   for(char i=1; i<=len; i++) {
        for(int j=1; j<=i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

cout << "----------------" << endl;

    /*
    1
    2 3
    4 5 6
    7 8 9 10
    */

   int start = 1;

   for(char i=1; i<=len; i++) {
        for(int j=1; j<=i; j++) {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }

cout << "----------------" << endl;

     /*
    1
    2 3
    3 4 5
    4 5 6 7
    */

   for(char i=1; i<=len; i++) {
    int start = i;
        for(int j=1; j<=i; j++) {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }

cout << "----------------" << endl;

     /*
    A
    B C
    C D E
    D E F G
    */

   for(char i=1; i<=len; i++) {
    int start = 'A' + i - 1 ;
        for(int j=1; j<=i; j++) {
            cout << char(start) << " ";
            start++;
        }
        cout << endl;
    }

    cout << "----------------" << endl;

     /*
          *
        * *
      * * *
    * * * *
    */

   for(char i=1; i<=len; i++) {
        int space = len-i;
        for(int j=1; j<=space; j++) {
            cout << " " << " ";
        }
        for(int j=1; j<=i; j++) {
            cout << "*" << " ";
        }
        space--;
        cout << endl;
    }
}