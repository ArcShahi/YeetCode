// 1603. Design Parking System


class ParkingSystem {
public:
     ParkingSystem(int big, int medium, int small)
     {
          slots[0] = big;
          slots[1] = medium;
          slots[2] = small;
     }

     bool addCar(int carType) {

          auto& slot{ slots[carType - 1] };
          if (slot == 0)return false;

          --slot;
          return true;
     }

private:
     int slots[3]{};
};