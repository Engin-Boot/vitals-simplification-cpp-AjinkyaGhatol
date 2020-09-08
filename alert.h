#include<string>
#include<iostream>
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
