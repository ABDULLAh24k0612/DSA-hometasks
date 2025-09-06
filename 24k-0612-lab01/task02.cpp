#include<iostream>
using namespace std;

class box{
    private:
    int *volume; 

    public:

    box(){
        volume=new int(0);

    }

    box(int v){
        volume=new int(v);
    }

    box(const box& other) {
        volume = new int(*(other.volume)); 
    }

    ~box() {
        delete volume;
    }

    void setVolume(int vol) {
        *volume = vol;
    }

    int getVolume() const {
        return *volume;
    }

    void printVolume(const string& name) const {
        cout << name << " Volume: " << *volume << endl;
    }
};


int main() {
    
    box box1;
    box1.printVolume("Box1 (Default)");

    
    box box2(100);
    box2.printVolume("Box2 (Parameterized)");

    box box3 = box2;
    box3.printVolume("Box3 (Copied from Box2)");

    box3.setVolume(200);
    cout << "\nAfter modifying Box3:\n";
    box3.printVolume("Box3");
    box2.printVolume("Box2 (Should remain unchanged)");

    return 0;
}


