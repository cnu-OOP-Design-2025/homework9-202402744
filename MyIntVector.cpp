#include <iostream>
#include <list>
#include <stdexcept>
using namespace std;

class MyIntVector {
private:
    int* data;
    size_t capacity;
    size_t length;

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

        size_t new_capacity = capacity * 2;
        int* new_data = new int[new_capacity];

        for (size_t i = 0; i < length; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    MyIntVector() : capacity(2), length(0) {
        data = new int[capacity];
    }

    ~MyIntVector() {
        delete[] data;
    }

    void push_back(const int& value) {
        if (length == capacity) {
            resize();
        }
        data[length++] = value;
    }

    int pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length];
    }

    int& operator[](const int index){
        return data[index];
    }

    size_t size() const {
        return length;
    }

};

void testVector(const string& name, std::list<int> values) {

    cout << "------------------" << endl;
    MyIntVector vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector("IntVec", {1, 2, 3, 4, 5, 6});
    return 0;
}