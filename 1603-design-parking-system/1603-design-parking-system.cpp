class ParkingSystem {
    private:
    int bigslots;
    int mediumslots;
    int smallslots;

public:
    ParkingSystem(int big, int medium, int small) {
        bigslots = big;
        mediumslots =medium;
        smallslots =small;
    }
    
    bool addCar(int carType) {
        switch(carType){
            case 1:
            if(bigslots>0) {bigslots--;  return true;}
            break;
             case 2:
            if(mediumslots>0) {mediumslots--;  return true;}
            break;
            case 3:
            if(smallslots>0) {smallslots--;  return true;}
            break;

        }
        return false;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */