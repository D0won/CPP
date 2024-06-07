#include<iostream>
using namespace std;

class Array{
    int *data;
    int size;

    public:
    Array(int size = 10);
    ~Array();
    friend ostream& operator<<(ostream& os, const Array& arr);
    int& operator[](int idx);     
    Array& operator=(const Array& arr);
    bool operator==(const Array& arr);
    bool operator!=(const Array& arr);
    
};

Array::Array(int s){
    size = s;
    data = new int[size];

    for(int i = 0; i < size; i++)
        data[i] = 0; 
}

Array::~Array(){
    delete[] data;
}

ostream& operator<<(ostream& os, const Array& arr){
    for(int i = 0; i < arr.size; i++)
        os << arr.data[i] << " ";
    return os;
}


int &Array::operator[](int idx){
    return data[idx];
}

Array& Array::operator=(const Array& arr){
    if(this != &arr){
        int* newData = new int[arr.size];
        for(int i = 0; i < arr.size; i++)
            newData[i] = arr.data[i];

        delete[] data;
        data = newData;
        size = arr.size;
    }
    return *this;
}

bool Array::operator==(const Array& arr){
    if(size != arr.size)
        return false;
    for(int i = 0; i < size; i++)
        if(data[i] != arr.data[i])
            return false;
    return true;
}

bool Array::operator!=(const Array& arr){
    return !(*this == arr);
}

int main(void)
{
        Array a1(10), a2(10), a3(10);
        a1[0] = 1; a1[1] = 2; a1[2] = 3; a1[3] = 4;
        a2[0] = 1; a2[1] = 2; a2[2] = 3; a2[3] = 4;
        a3 = a1; a3[3] = 5;
        cout << "a1 배열은 : " << a1 << "\n"; // 1 2 3 4 0 0 ...
        cout << "a2 배열은 : " << a2 << "\n"; // 1 2 3 4 0 0 ...
        cout << "a3 배열은 : " << a3 << "\n"; // 1 2 3 5 0 0 ...
        cout << "a1 == a2 을 중복 정의 : " << (a1 == a2) << "\n"; // 1
        cout << "a1 != a3 을 중복 정의 : " << (a1 != a3) << "\n"; // 1
        cout << "a3 = a1 을 중복 정의 : " << (a3 = a1) << "\n"; // 1 2 3 4 0 0 ...
        return 0;
}

