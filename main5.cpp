#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
    Set<int> set1;
    for (int i = 1; i <= 5; i++)
    {
        set1+i;
    }
    set1 + 1;
    set1 + 3;
    set1 + 5;
    set1 + 6;
    set1 + 7;

    cout << "Set1: " << endl;
    cout<< set1;

    cout << endl;
    cout << "Creating set2, copying the former set. (Testing copy constructor)" << endl;
    Set<int> set2(set1);
    cout << "Set2: " << endl;
    cout << set2;
    cout << endl;

    int arr1[4] = {0, 1, 4, 9};
    Set<int> set3(arr1, 4);
    cout << "Set3: {0, 1, 4, 9}" << endl;
    cout << "The union of set1 and set3 is: " << endl;
    Set<int> unionSet = set1 + set3;
    cout << unionSet;

    cout << "The intersection of set1 and set3 is: " << endl;
    Set<int> intersectSet = set1 ^ set3;
    cout << intersectSet;

    cout <<"Enter an element to add to set3: ";
    cin >> set3;
    cout << set3;

// Chars
    Set<char> cset1;
    cset1 + 'a';
    cset1 + 'b';
    cset1 + 'y';
    cset1 + 'd';
    cset1 + 'v';
    cset1 + 'd';
    cset1 + 'e';
    cset1 + 'f';


    cout << "cSet1: " << endl;
    cout<< cset1;

    cout << endl;
    cout << "Creating cset2, copying the former set. (Testing copy constructor)" << endl;
    Set<char> cset2(cset1);
    cout << "cSet2: " << endl;
    cout << cset2;
    cout << endl;

    char carr1[4] = {'x', 'y', 'v', 'w'};
    Set<char> cset3(carr1, 4);
    cout << "cSet3: {'x', 'y', 'v', 'w'}" << endl;
    cout << "The union of set1 and set3 is: " << endl;
    Set<char> cunionSet = cset1 + cset3;
    cout << cunionSet;

    cout << "The intersection of set1 and set3 is: " << endl;
    Set<char> cintersectSet = cset1 ^ cset3;
    cout << cintersectSet;

    cout <<"Enter an element to add to cset3: ";
    cin >> cset3;
    cout << cset3;

// string
    cout<<"STRING START!!!!\n";
    Set<string> sset1;
    sset1 + "a1";
    sset1 + "b1";
    sset1 + "y1";
    sset1 + "d1";
    sset1 + "v1";
    sset1 + "d1";
    sset1 + "e1";


    cout << "sSet1: " << endl;
    cout<< sset1;

    cout << endl;
    cout << "Creating sset2, copying the former set. (Testing copy constructor)" << endl;
    Set<string> sset2(sset1);
    cout << "sSet2: " << endl;
    cout << sset2;
    cout << endl;

    string sarr1[4] = {"x1", "y1", "v1", "w1"};
    Set<string> sset3(sarr1, 4);
    cout << "string Set3: {'x1', 'y1', 'v1', 'w1'}" << endl;
    cout << "The union of sset1 and sset3 is: " << endl;
    Set<string> sunionSet = sset1 + sset3;
    cout << sunionSet; //TYPO

    cout << "The intersection of sset1 and sset3 is: " << endl;
    Set<string> sintersectSet = sset1 ^ sset3;
    cout << sintersectSet;

    cout <<"Enter an element to add to sset3: ";
    cin >> sset3;
    cout << sset3;

    return 0;

}
