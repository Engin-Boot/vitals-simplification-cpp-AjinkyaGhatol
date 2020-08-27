#include <assert.h>
enum { bpm, spo2, respRate };


int limit[3][2] = { {70,150},{90,1000} ,{30,95}};
bool isOk(int vital,int val)
{
    if (val < limit[vital][0] || val > limit[vital][1]) {
        return false;
    }
    return true;
}

int main() {
    
    assert(isOk(bpm, 80) == true);
    assert(isOk(bpm, 160) == false);

    assert(isOk(spo2, 95) == true);
    assert(isOk(spo2, 90) == true);
    
    assert(isOk(respRate, 40) == true);
    assert(isOk(respRate, 100) == false);
       
    
    

}
