#include <assert.h>
#include<iostream>
using namespace std;

struct vital
{
    float minLimit;
    float maxLimit;
};

vital BPM { 70, 150 }, SPO2{ 90,100 }, RESPRATE{30,95};

bool isOk(vital vital_passed, float val)
{
    if (val < vital_passed.minLimit || val > vital_passed.maxLimit) {
        return false;
    }
    return true;
}

int main() {
    
    assert(isOk(BPM, 80) == true);
    assert(isOk(BPM, 160) == false);

    assert(isOk(SPO2, 95) == true);
    assert(isOk(SPO2, 90) == true);
    assert(isOk(SPO2, 89) == false);

    assert(isOk(RESPRATE, 40) == true);
    assert(isOk(RESPRATE, 100) == false);

    return 0;
}
