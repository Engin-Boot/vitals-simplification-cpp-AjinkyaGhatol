#include <assert.h>
#include<iostream>
#include<vector>
using namespace std;

struct vital
{
    string vital_id;
    float minLimit;
    float maxLimit;
};
vector<vital> vital_list;

int getID(string string_id)
{
    int id = 10000;
    for (int i = 0; i < vital_list.size(); i++)
    {
        if (vital_list[i].vital_id == string_id)
        {
            id = i;
            break;
        }
    }
    return id;
}
bool isOk(string string_id, float val)
{
    int id = getID(string_id);
    
    return(val >= vital_list[id].minLimit && val <= vital_list[id].maxLimit);
}
void addVital(string string_id, float min, float max)
{
    vital_list.push_back({ string_id,min,max });
}

int main() {
    
    addVital("BPM",70, 150 );
    addVital( "SPO2",90,100 );
    addVital( "RESPRATE",30,95 );

    assert(isOk("BPM", 80) == true);
    assert(isOk("BPM", 160) == false);

    assert(isOk("SPO2", 95) == true);
    assert(isOk("SPO2", 90) == true);
    assert(isOk("SPO2", 89) == false);

    assert(isOk("RESPRATE", 40) == true);
    assert(isOk("RESPRATE", 100) == false);

    addVital("BP", 100, 200);
    assert(isOk("BP", 150) == true);
    assert(isOk("BP", 80) == false);
    
    return 0;
}
