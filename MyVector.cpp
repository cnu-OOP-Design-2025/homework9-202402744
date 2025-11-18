#include <iostream>
#include <string>
#include <list>
#include <stdexcept> 
#include <iterator>  
using namespace std;

template<typename T>
class MyVector {
private:
    T* data;
    size_t capacity;
    size_t length;

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;
        
        size_t new_capacity = capacity * 2;
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < length; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    MyVector() : capacity(2), length(0) {
        data = new T[capacity];
    }

    ~MyVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (length == capacity) {
            resize();
        }
        data[length++] = value;
    }

    T pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length]; 
    }

    T& operator[](const size_t index){
        return data[index];
    }
    
    const T& operator[](const size_t index) const {
        return data[index];
    }

    size_t size() const {
        return length;
    }
    
    T* begin() {
        return data;
    }

    const T* begin() const {
        return data;
    }

    T* end() {
        return data + length;
    }

    const T* end() const {
        return data + length;
    }
};

template<typename T>
void testVector(const string& name, std::list<T> values) {

    cout << "------------------" << endl;
    MyVector<T> vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    
    for (auto& e : vec) {
        cout << e << " ";
    }

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector<int>("IntVec", {1, 2, 3, 4, 5, 6});
    testVector<double>("DoubleVec", {1.1, 2.2, 3.3, 4.4, 5.5});
    testVector<char>("CharVec", {'A', 'B', 'C', 'D', 'E', 'F'});
    testVector<string>("StringVec", {"Hello", "World", "C++", "Template", "Vector"});
    return 0;
}