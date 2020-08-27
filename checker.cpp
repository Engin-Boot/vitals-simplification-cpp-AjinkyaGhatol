#include <assert.h>
bool isBpmOk(float bpm)
{
  if(bpm < 70 || bpm > 150) {
    return false;
  }
  return true;
}
bool isSpo2Ok(float spo2)
{
  if(spo2 < 90) {
    return false;
  }
  return true;
}
bool isRespRateOk(float respRate)
{
  if(respRate < 30 || respRate > 95) {
    return false;
  }
  return true;
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
 
  return (isBpmOk(bpm) && isSpo2Ok(spo2) && isRespRateOk(respRate));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
