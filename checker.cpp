//limits are inclusive
#include <assert.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class alertMethod
{
public:
    virtual void alert(string alertMessage) = 0;
}; 
class System
{
    alertMethod* alertmehod;
public:
    void setAlertMethod(alertMethod* alertmethodtoset)
    {
        alertmehod = alertmethodtoset;
    }
    void alertNow(string message)
    {
        alertmehod->alert(message);
    }
};

class alertSms:public alertMethod
{
public:
    void alert(string alertMessage)
    {
        cout << "send message:" << alertMessage << endl;
    }
};
class alertHorn :public alertMethod
{
public:
    void alert(string alertMessage)
    {
        cout << "Sound horn:" << alertMessage << endl;
    }
};

System s;
struct vital
{
    string vital_id;
    float minLimit;
    float maxLimit;
};
vector<vital> vital_list;

int getIndex(string string_id)
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
bool isOk(int string_index, float val)
{
    
    //return(val >= vital_list[id].minLimit && val <= vital_list[id].maxLimit);
    if (val < vital_list[string_index].minLimit)
    {
        string message="";
        message = message + "Patients " + vital_list[string_index].vital_id + " is low:" + to_string(val);;
        s.alertNow(message);
        return false;
    }
    else if (val > vital_list[string_index].maxLimit)
    {
        string message = "";
        message = message + "Patients " + vital_list[string_index].vital_id + " is high:"+to_string(val);
        s.alertNow(message);
        return false;
    }
    return true;
}
void addVital(string string_id, float min, float max)
{
    vital_list.push_back({ string_id,min,max });
}
int addVital(string string_id)
{
    float min, max;
    cout << "Enter min limit of vital:" << endl;
    cin >> min;
    cout << "Enter max limit of vital:" << endl;
    cin >> max;
    vital_list.push_back({ string_id,min,max });
    return (vital_list.size()-1);
}
bool checkVital(string string_id, float val)
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
int main() {
    
    alertSms sms;
    alertHorn horn;
    s.setAlertMethod(&sms);
    addVital("BPM",70, 150 );
    addVital( "SPO2",90,100 );
    addVital( "RESPRATE",30,95 );

    assert(checkVital("BPM", 80) == true);
    assert(checkVital("BPM", 160) == false);

    assert(checkVital("SPO2", 95) == true);
    assert(checkVital("SPO2", 90) == true);
    assert(checkVital("SPO2", 89) == false);

    s.setAlertMethod(&horn);
    assert(checkVital("RESPRATE", 40) == true);
    assert(checkVital("RESPRATE", 100) == false);

    addVital("BP", 100, 200);
    assert(checkVital("BP", 150) == true);
    assert(checkVital("BP", 80) == false);

    //check vital sugar without adding it first
    assert(checkVital("SUGAR", 300) == false);
   
    assert(checkVital("SUGAR", 200) == true);
   
    return 0;
}
