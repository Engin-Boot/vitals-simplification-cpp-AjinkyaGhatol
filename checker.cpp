#include <assert.h>
enum { bpm, spo2, respRate };
//int bpmLimit[2] = { 70,150 };
//int respLimit[2] = { 30,95 };
//int spo2Limit[2] = { 90,1000 };

int limit[3][2] = { {70,150},{30,95},{90,1000} };
bool isOk(int vital,int val)
{
    if (val < limit[vital][0] || val > limit[vital][1]) {
        return false;
    }
    return true;
}

bool isOk(int bpm)
{
    if (bpm < 70 || bpm > 150) {
        return false;
    }
    return true;
}
bool isSpo2Ok(float spo2)
{
    if (spo2 < 90) {
        return false;
    }
    return true;
}
bool isRespRateOk(float respRate)
{
    if (respRate < 30 || respRate > 95) {
        return false;
    }
    return true;
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {

    return (isOk(bpm) && isSpo2Ok(spo2) && isRespRateOk(respRate));
}

int main() {
    assert(vitalsAreOk(80, 95, 60) == true);
    assert(vitalsAreOk(60, 90, 40) == false);
    assert(isOk(bpm, 80) == true);
    assert(isOk(bpm, 160) == false);

}
