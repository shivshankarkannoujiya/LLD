#include <iostream>
#include <vector>
#include <unordered_map>
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
    BulletType bulletType;
    vector<uint8_t> image;

public:
    void setBulletType(BulletType type){
        this->bulletType = type;
    }

    void setBulletRadius(double radius){
        this->radius = radius;
    }

    void setBulletWeight(double weight){
        this->weight = weight;
    }

    BulletType getBulletType(){
        return this->bulletType;
    }

    double getBulletRadius(){
        return this->radius;
    }

    double getBulletWeight(){
        return this->weight;
    }
};

class FlyingBullet{
private:
    double x_coordinate;
    double y_coordinate;
    double z_coordinate;
    double x_direction;
    double y_direction;
    double z_direction;
    double speed;
    long userId;
    BulletStatus bulletStatus;
    Bullet *bullet;

public:    
    void setX_Coordinate(double x_coordinate) {
        this->x_coordinate = x_coordinate;
    }
    
    void setY_Coordinate(double y_coordinate) {
        this->y_coordinate = y_coordinate;
    }

    void setZ_Coordinate(double z_coordinate) {
        this->z_coordinate = z_coordinate;
    }

    void setX_Direction(double x_direction) {
        this->x_direction = x_direction;
    }

    void setY_Direction(double y_direction) {
        this->y_direction = y_direction;
    }

    void setZ_Direction(double z_direction) {
        this->z_direction = z_direction;
    }

    void setSpeed(double speed){
        this->speed = speed;
    }

    void setUserId(long userId){
        this->userId = userId;
    }

    void setBullet(Bullet *bullet){
        this->bullet = bullet;
    }

};

/*
    NOTE:
        - Now we do not need to create 2000000 `Bullet` object
        - create #Bullet: #ButtetType eg:- 3

        - We need only `1 object`/type of bullet.
            - Those 3 types of bullets are going to use across all the bullets in PUBG
            - Even if i create NEW `FLYING BULLET`: i will use that existing one
            - Where can i store these bullets, so that i can retrive then later
            <REGISTRY>: BULLET_REGISTRY
            PURPOSE:
                1. Store the Bullet Object
                2. Allow us to use them later
*/

class BulletRegistry
{
private:
    unordered_map<BulletType, Bullet> bullets;

public:
    void registerBullet(BulletType type, const Bullet &bullet){
        bullets[type] = bullet;
    }

    Bullet *getBullet(BulletType type){
        auto it = bullets.find(type);
        if (it == bullets.end()){
            return nullptr;
        }
        return &it->second;
    }
};

int main(){

    // NOTE:
    // - Before start to create FLYINGBULLET
    // 1. Create different type of BULLET
    // 2. PUT them into BulletRegistry

    BulletRegistry *bulletRegistry = new BulletRegistry();

    // 5mm
    Bullet *FIVE_MM_BULLET = new Bullet();
    FIVE_MM_BULLET->setBulletType(BulletType::FIVE_MM);
    bulletRegistry->registerBullet(BulletType::FIVE_MM, *FIVE_MM_BULLET);

    // 7mm
    Bullet *SEVEN_MM_BULLET = new Bullet();
    SEVEN_MM_BULLET->setBulletType(BulletType::SEVEN_MM);
    bulletRegistry->registerBullet(BulletType::SEVEN_MM, *SEVEN_MM_BULLET);

    // 9mm
    Bullet *NINE_MM_BULLET = new Bullet();
    NINE_MM_BULLET->setBulletType(BulletType::NINE_MM);
    bulletRegistry->registerBullet(BulletType::NINE_MM, *NINE_MM_BULLET);

    // Start creating flying bullets

    vector<FlyingBullet *> flyingBullets;

    for (int i = 0; i < 200000; i++){
        FlyingBullet *flyingBullet = new FlyingBullet();
        flyingBullet->setSpeed(120.0);
        //.... set all Extrinsic properties
        flyingBullet->setBullet(bulletRegistry->getBullet(BulletType::FIVE_MM));
        flyingBullets.push_back(flyingBullet);
    }

    // NOTE:
    // CREATED:
        // 3 Types of Bullets in Memory
        // flyingBullets: 200000
}