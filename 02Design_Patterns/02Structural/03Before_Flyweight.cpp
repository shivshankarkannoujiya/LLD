#include <iostream>
#include <vector>
using namespace std;

enum class BulletType{
    FIVE_MM,
    SEVEN_MM,
    NINE_MM
};

enum class BulletStatus{
    FIRED,
    NON_FIRED
};

class Bullet{
    private:
        double radius;
        double weight;
        double speed;
        long userId;
        double x_coordinate;
        double y_coordinate;
        double z_coordinate;
        double x_direction;
        double y_direction;
        double z_direction;
        BulletType bulletType;
        BulletStatus bulletStatus;
        vector<uint8_t> image;
};

int main(){

    vector<Bullet *> bullets;

    for (int i = 0; i < 20000; i++){
        Bullet *bullet = new Bullet();
        bullets.push_back(bullet);
    }
}