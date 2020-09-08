//limits are inclusive
#include"vital.h"
#include <assert.h>
int main() {
    
    alertSms sms;
    alertHorn horn;
    //AlertSystem object is created in vital.h
    AlertSystem.setAlertMethod(&sms);

    VitalList list1;
    list1.addVital("BPM",70, 150 );
    list1.addVital( "SPO2",90,1000 );
    list1.addVital( "RESPRATE",30,95 );

    assert(list1.checkVital("BPM", 80) == true);
    assert(list1.checkVital("BPM", 160) == false);

    assert(list1.checkVital("SPO2", 95) == true);
    assert(list1.checkVital("SPO2", 90) == true);
    assert(list1.checkVital("SPO2", 89) == false);

    AlertSystem.setAlertMethod(&horn);
    assert(list1.checkVital("RESPRATE", 40) == true);
    assert(list1.checkVital("RESPRATE", 100) == false);

    list1.addVital("BP", 100, 200);
    assert(list1.checkVital("BP", 150) == true);
    assert(list1.checkVital("BP", 80) == false);

    //check vital sugar without adding it first
    //limits for sugar are 100 to 200
    assert(list1.checkVital("SUGAR", 300) == false);
   
    assert(list1.checkVital("SUGAR", 200) == true);
    assert(list1.checkVital("SUGAR", 50) == false);

    //vital_array is data type defined in vital.h
    vital_array vital_array_to_pass[5];
   
    //all are within range
    vital_array_to_pass[0].string_id = "BPM";
    vital_array_to_pass[0].val = 140;
    vital_array_to_pass[1].string_id = "SPO2";
    vital_array_to_pass[1].val = 100; 
    vital_array_to_pass[2].string_id = "RESPRATE";
    vital_array_to_pass[2].val = 40;
    vital_array_to_pass[3].string_id = "BP";
    vital_array_to_pass[3].val = 150;
    vital_array_to_pass[4].string_id = "SUGAR";
    vital_array_to_pass[4].val = 200;

    assert(list1.checkVital(vital_array_to_pass,5)==true);

    //BPM and sugar not in limit
    vital_array_to_pass[0].string_id = "BPM";
    vital_array_to_pass[0].val = 69;
    vital_array_to_pass[1].string_id = "SPO2";
    vital_array_to_pass[1].val = 100;
    vital_array_to_pass[2].string_id = "RESPRATE";
    vital_array_to_pass[2].val = 40;
    vital_array_to_pass[3].string_id = "BP";
    vital_array_to_pass[3].val = 150;
    vital_array_to_pass[4].string_id = "SUGAR";
    vital_array_to_pass[4].val = 201;

    assert(list1.checkVital(vital_array_to_pass, 5) == false);

    return 0;
}
