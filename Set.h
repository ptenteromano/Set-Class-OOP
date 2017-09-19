//Philip Tenteromano 4/1/2017
//Set.h header file - class declaration

//Template class ** specification and implementation combined

#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
using namespace std;

template <class Varr>
class Set {
    private:
        Varr *set;           //pointer to array
        int pSize;          //physical size of array
        int numElements;    //number of elements in the set
        const static int DEFAULT_SIZE = 5;    //defaulted size//Philip Tenteromano 5/11/2017

    public:
        Set(int memory = DEFAULT_SIZE);   //default constructor
        Set(Varr a[], int size);    //constructor takes array
        Set(const Set &origset);      //copy Constructor
        Set& operator=(const Set<Varr>& origset); //copy assignment operator
        Set operator+(const Set<Varr>& rhs);  //union operator
        Set operator+(Varr ele);         //add new element operator
        Set operator^(const Set<Varr>& rhs);  //intersect operator
        template <class IO>
        friend std::ostream& operator<<(std::ostream &out,  //friend
                                        const Set<IO> &obj);    //o/i stream
        template <class IO>
        friend std::istream& operator>>(std::istream &in,   //operators
                                        Set<IO> &obj);
        bool checkElement(Varr element); //checks for duplicates
        void addNew(Varr element);   //adds new client-side integer
        void inputSet();        //asks for user input
        void checkSize();       //checks size, resizes if needed
        Set unionSet(Set obj);     //union set function
        Set intersectSet(const Set &obj); //intersection set function
        void printSet();        //prints the set
        ~Set();                 //destructor
};

//default constructor with option to add array memory argument
template <class Varr>
Set<Varr>::Set(int memory)
{
    pSize = memory;     //pSize is DEFAULT_SIZE without argument
    set = new Varr[pSize];
    numElements = 0;
}

//overloaded constructor taking in array and size
template <class Varr>
Set<Varr>::Set(Varr a[], int size)
{
    //pSize will always be a factor of 5
    pSize = (size/DEFAULT_SIZE) * DEFAULT_SIZE + DEFAULT_SIZE;
    set = new Varr[pSize];
    numElements = 0;        //no elements until populated
    bool check = false;     //bool to check population

    for(int i=0; i<size; i++) {    //populate to *set
        check = checkElement(a[i]); //check for duplicates
        if(check) {
            *(set+numElements) = a[i];
            numElements++;
        }
    }
}

//copy constructor
template <class Varr>
Set<Varr>::Set(const Set<Varr> &origset)
{
    pSize = origset.pSize;      //copy all data members
    set = new Varr[pSize];
    numElements = origset.numElements;

    for(int i=0; i<numElements; i++) {  //copy ptr array
        *(set+i) = *(origset.set+i);    //populate
    }
}

//overloaded assignment operator
template <class Varr>
Set<Varr>& Set<Varr>::operator=(const Set<Varr> &origset)
{
    if (this != &origset){      //check for self-assignment
        pSize = origset.pSize;
        numElements = origset.numElements;
        delete set;                    //copy data members
        set = new Varr[pSize];

        for(int u=0; u<numElements; u++)        //copy and populate
            *(set+u) = *(origset.set+u);
    }
    return *this;
}

//overloaded addition operator (union)
template <class Varr>
Set<Varr> Set<Varr>::operator+(const Set &rhs)
{
    return this->unionSet(rhs);     //return the union of two sets
}

//overloaded addition operator (add new element);
template <class Varr>
Set<Varr> Set<Varr>::operator+(Varr ele)
{
    this->addNew(ele);    //call addNew(element)
    return *this;       //return the new set
}

//overloaded caret operator (intersection)
template <class Varr>
Set<Varr> Set<Varr>::operator^(const Set &rhs)
{
    return this->intersectSet(rhs); //return the intersection of two sets
}

//overloaded output operator (friend)
template <class IO>
ostream& operator<<(ostream &out, const Set<IO> &obj)
{
    out<<"{ ";  //use ostream parameter
    for(int pos=0; pos<obj.numElements; pos++) {
        out<<*(obj.set+pos);
        if(pos < obj.numElements-1 )    //print in proper set notation
            out<<", ";             //last element does not print comma
    }
    out<<" }"<<endl;
    return out;     //return parameter to string outputs
}

//overloaded input operator (friend)
template <class IO>
istream& operator>>(istream &in, Set<IO> &obj)
{
    IO ele;             //create variable
    in >> ele;          //user input variable
    obj.addNew(ele);    //call the addNew() function
    return in;          //return parameter
}

//add an element function, checks for duplicates
template <class Varr>
void Set<Varr>::addNew(Varr element)
{
    bool check = false;

    cout<<"Set is attempting to add element "
        <<element<<"..."<<endl;
    check = checkElement(element);      //check for duplicates
    if(check) {         //if no duplicates, add element and cout confirm
        *(set+numElements) = element;
            numElements++;
            cout<<"Element ADDED, no duplicates found."<<endl<<endl;
    }
    else        //if duplicate, do not add, cout message
        cout<<"Duplicate found, element NOT ADDED."<<endl<<endl;
    checkSize();    //call checksize to resize if needed
}

//input function to ask user to create varying sets
template <class Varr>
void Set<Varr>::inputSet()
{
    int add = 0;    //potential # of elements variable
    Varr element;    //individual elements
    bool check = false;
    cout<<"How many elements do you want to add to the set?";
    cin>>add;   //set potential number of elements

    for(int c=0; c<add; c++) {  //running for loop based on additions
        cout<<"Input a value, duplicates will not be added: ";
        cin>>element;

        check = checkElement(element);  //call duplicate function
        if(check) {
                *(set+numElements) = element; //if no duplicates, add and
                numElements++;       //increment number of elements
        }
        checkSize();    //check for physical array size
    }                   //resize if needed
}

//resizing if number of elements catch physical array size
template <class Varr>
void Set<Varr>::checkSize()
{
    if (numElements >= pSize) {  //increase physical size by DEFAULTSIZE
        int incSize = pSize+DEFAULT_SIZE;

        Varr *tempset = new Varr[pSize];  //allocate for tempset

        cout<<"Increasing the set size..."<<endl; //program acknowledges
        for(int pos=0; pos<numElements; pos++)    //copy original set
            *(tempset+pos) = *(set+pos);

        delete[] set;                 //delete small, original set

        set = new Varr[incSize];     //create larger set
        for(int pos=0; pos<numElements; pos++)
            *(set+pos) = *(tempset+pos);        //copy elements back

        delete[] tempset;   //delete the tempset pointer

        pSize = incSize;    //set new physical array size
    }
}

//check for duplicate, return false if duplicate found
template <class Varr>
bool Set<Varr>::checkElement(Varr element)
{
    bool value = true;      //element added unless duplicate found

    for(int k=0; k<numElements; k++) {
        if(element == *(this->set+k))
            value = false;  //if duplicate is in set, return false
    }
    return value;           //return duplicate or not (f/t)
}

//union of sets
template <class Varr>
Set<Varr> Set<Varr>::unionSet(Set obj)
{
    Set<Varr> uSet(*this);        //create object using ucopy contructor
    uSet.pSize = this->pSize + obj.pSize;    //combine phys array sizes
    uSet.~Set();            //deallocate
    uSet.set = new Varr[uSet.pSize];  //allocate union set
    int index = 0;          //needed to increment uSet
    bool check = false;

    for(int i=0; i<numElements; i++)    //copy the first set
        *(uSet.set+i) = *(set+i);
    //next, copy non-duplicates from another object
    for(int j=0; j<obj.numElements; j++) {
        check = checkElement(*(obj.set+j));
        if(check) {
            *(uSet.set+numElements+index) = *(obj.set+j);
            index++;    //index counts up the uSet array if valid input
            uSet.numElements++;  //increment number of elements
        }
    }
    return uSet;    //return the union set
    uSet.~Set();
}

//intersection of sets
template <class Varr>
Set<Varr> Set<Varr>::intersectSet(const Set &obj)
{
    Set<Varr> iSet(obj);        //create copied object
    iSet.numElements = 0;   //reset number of elements
    delete[] iSet.set;      //delete copied set
    iSet.set = new Varr[obj.pSize];  //reallocate set
    bool check = false;
    //run loop checking for like elements, add to iSet
    for(int k=0; k<obj.numElements; k++) {
        check = this->checkElement(*(obj.set+k));
        if(!check) {    //check for duplicates and increment
                *(iSet.set+iSet.numElements) = *(obj.set+k);
                iSet.numElements++;
        }
    }
    return iSet;
    iSet.~Set();
}

//print function
template <class Varr>
void Set<Varr>::printSet()
{
    cout<<"{ ";
    for(int pos=0; pos<numElements; pos++) {
        cout<<*(set+pos);
        if(pos < numElements-1 )    //print in proper set notation
            cout<<", ";             //last element does not print ','
    }
    cout<<" }"<<endl;

    cout<<"Physical array size: "<<pSize<<endl
        <<"Number of elements in set: "<<numElements<<endl<<endl;
}

//destructor
template <class Varr>
Set<Varr>::~Set()
{
    delete[] set;   //delete dynamic array
}


#endif // SET



