class ParkingSystem {
private:
    int parking_lot[4];
public:
    ParkingSystem(int big, int medium, int small) {
        parking_lot[1] = big;
        parking_lot[2] = medium;
        parking_lot[3] = small;
    }
    
    bool addCar(int carType) {
        return parking_lot[carType]&&parking_lot[carType]--;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */