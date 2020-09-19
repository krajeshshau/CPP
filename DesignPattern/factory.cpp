#include<iostream>

using namespace std;

class vehicle{
    public:
    virtual void vehicleInfo() = 0;
};

class twoWheeler : public vehicle{
    public:
    virtual void vehicleInfo(){
        cout<<"twoWheeler"<<endl;
    }
};

class fourWheeler : public vehicle{
    public:
    virtual void vehicleInfo(){
        cout<<"fourWheeler"<<endl;
    }
};

enum vehicleType{
  vt_twoWheeler = 2, vt_fourWheeler = 4
};

class factory{
    public:
    static vehicle* createVehicleInstance(vehicleType vtype){
        if(vtype == 2)
            return new twoWheeler();
        else if(vtype == 4)
            return new fourWheeler();
        else{
            cout<<"Invalid input"<<endl;
            return nullptr;
        }
    }
};

int main(){
    cout<<"Factory design pattern"<<endl;
    vehicle *veh = factory::createVehicleInstance(vt_twoWheeler);
    veh->vehicleInfo();
    veh = factory::createVehicleInstance(vt_fourWheeler);
    veh->vehicleInfo();
    
    return 0;
}
