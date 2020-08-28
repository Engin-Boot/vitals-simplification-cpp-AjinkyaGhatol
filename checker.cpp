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
   
    //return(val >= vital_list[id].minLimit && val <= vital_list[id].maxLimit);
    if (val < vital_list[id].minLimit)
    {
        string message="";
        message = message + "Patients " + vital_list[id].vital_id + " is low:" + to_string(val);;
        s.alertNow(message);
        return false;
    }
    else if (val > vital_list[id].maxLimit)
    {
        string message = "";
        message = message + "Patients " + vital_list[id].vital_id + " is high:"+to_string(val);
        s.alertNow(message);
        return false;
    }
    return true;
}
void addVital(string string_id, float min, float max)
{
    vital_list.push_back({ string_id,min,max });
}

int main() {
    
    alertSms sms;
    alertHorn horn;
    s.setAlertMethod(&sms);
    addVital("BPM",70, 150 );
    addVital( "SPO2",90,100 );
    addVital( "RESPRATE",30,95 );

    assert(isOk("BPM", 80) == true);
    assert(isOk("BPM", 160) == false);

    assert(isOk("SPO2", 95) == true);
    assert(isOk("SPO2", 90) == true);
    assert(isOk("SPO2", 89) == false);

    s.setAlertMethod(&horn);
    assert(isOk("RESPRATE", 40) == true);
    assert(isOk("RESPRATE", 100) == false);

    addVital("BP", 100, 200);
    assert(isOk("BP", 150) == true);
    assert(isOk("BP", 80) == false);
   
    return 0;
}
