#include <vector>
#include <iostream>
using namespace std;

template <class T>
class RingBuffer {
private:
    std::vector<T> buffer;
    int back = -1, front = 0, sz = 0;
    int capacity;
public:
    RingBuffer(int capacity): capacity(capacity), buffer(vector<T>(capacity)) {}
    bool push(T x) {
        if(sz == capacity) return false;
        sz++;
        back = (back + 1) % capacity;
        buffer[back] = x;
        return true;
    }
    bool pop() {
        if(sz == 0) return false;
        sz--;
        front = (front + 1) % capacity;
        return true;
    }
    T first() {
        return (sz == 0) ? -1: buffer[front];
    }
};

int main(int argc, char* argv[]) {
    
}
