#include"alert.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;
System AlertSystem;
struct vital
{
    string vital_id;
    float minLimit;
    float maxLimit;
};

struct vital_array
{
    string string_id;
    float val;
};
class VitalList
{
    vector<vital> vital_list;
    public:
    void addVital(string string_id, float min, float max);
    bool checkVital(string string_id, float val);
    bool isOk(int string_index, float val);
    int getIndex(string string_id);
    int addVital(string string_id);
    bool checkVital(vital_array vt_array[],int size);
};
void VitalList::addVital(string string_id, float min, float max)
{
    vital_list.push_back({ string_id,min,max });
}
bool VitalList::checkVital(string string_id, float val)
{
    int index = getIndex(string_id);
    if (index != -1)
    {
        return isOk(index, val);
    }
    else
    {
        int index_of_added;
        index_of_added =addVital(string_id);
        return isOk(index_of_added, val);
    }
}
bool VitalList::isOk(int string_index, float val)
{
    
    //return(val >= vital_list[id].minLimit && val <= vital_list[id].maxLimit);
    if (val < vital_list[string_index].minLimit)
    {
        string message="";
        message = message + "Patients " + vital_list[string_index].vital_id + " is low:" + to_string(val);;
        AlertSystem.alertNow(message);
        return false;
    }
    else if (val > vital_list[string_index].maxLimit)
    {
        string message = "";
        message = message + "Patients " + vital_list[string_index].vital_id + " is high:"+to_string(val);
        AlertSystem.alertNow(message);
        return false;
    }
    return true;
}
int VitalList::getIndex(string string_id)
{
    int id = -1;
    for (unsigned int i = 0; i < vital_list.size(); i++)
    {
        if (vital_list[i].vital_id == string_id)
        {
            id = i;
            break;
        }
    }
    return id;
}
int VitalList::addVital(string string_id)
{
    float min, max;
    cout << "Enter min limit of vital:enterd 100" << endl;
    //cin >> min;
    min = 100;
    max = 200;
    cout << "Enter max limit of vital:enterd 200" << endl;
    //cin >> max;
    vital_list.push_back({ string_id,min,max });
    return (vital_list.size()-1);
}
bool VitalList::checkVital(vital_array vt_array[],int size)
{
    bool result = true;
    for (int i = 0; i < size; i++)
    {
        if (checkVital(vt_array[i].string_id, vt_array[i].val) == false)
            result = false;
    }
    return result;
}