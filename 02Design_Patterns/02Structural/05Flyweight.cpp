#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
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

// Intrinsic state - shared across multiple bullets
class Bullet{
private:
    double radius;
    double weight;
    BulletType bulletType;
    vector<uint8_t> image;

public:
    Bullet() : radius(0.0), weight(0.0), bulletType(BulletType::FIVE_MM) {}

    void setBulletType(BulletType type){
        this->bulletType = type;
    }

    void setBulletRadius(double radius){
        this->radius = radius;
    }

    void setBulletWeight(double weight){
        this->weight = weight;
    }

    void setImage(const vector<uint8_t> &img){
        this->image = img;
    }

    BulletType getBulletType() const{
        return this->bulletType;
    }

    double getBulletRadius() const{
        return this->radius;
    }

    double getBulletWeight() const{
        return this->weight;
    }
};

// Extrinsic state - unique to each flying bullet
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
    shared_ptr<Bullet> bullet; // Shared ownership

public:
    FlyingBullet() : x_coordinate(0.0), y_coordinate(0.0), z_coordinate(0.0),
                     x_direction(0.0), y_direction(0.0), z_direction(0.0),
                     speed(0.0), userId(0), bulletStatus(BulletStatus::NON_FIRED) {}

    void setX_Coordinate(double x) { this->x_coordinate = x; }
    void setY_Coordinate(double y) { this->y_coordinate = y; }
    void setZ_Coordinate(double z) { this->z_coordinate = z; }
    void setX_Direction(double x) { this->x_direction = x; }
    void setY_Direction(double y) { this->y_direction = y; }
    void setZ_Direction(double z) { this->z_direction = z; }
    void setSpeed(double s) { this->speed = s; }
    void setUserId(long id) { this->userId = id; }
    void setBulletStatus(BulletStatus status) { this->bulletStatus = status; }
    void setBullet(shared_ptr<Bullet> b) { this->bullet = b; }

    double getSpeed() const { return speed; }
    shared_ptr<Bullet> getBullet() const { return bullet; }
};

// Registry to store and manage shared Bullet objects (Flyweight Factory)
class BulletRegistry{
private:
    unordered_map<BulletType, shared_ptr<Bullet>> bullets;

public:
    void addBullet(BulletType type, double radius, double weight){
        auto bullet = make_shared<Bullet>();
        bullet->setBulletType(type);
        bullet->setBulletRadius(radius);
        bullet->setBulletWeight(weight);
        bullets[type] = bullet;
    }

    shared_ptr<Bullet> getBullet(BulletType type){
        auto it = bullets.find(type);
        if (it != bullets.end()){
            return it->second;
        }
        return nullptr;
    }

    size_t getBulletCount() const{
        return bullets.size();
    }
};

int main(){
    // Create bullet registry
    BulletRegistry bulletRegistry;

    // Register different bullet types with their properties
    bulletRegistry.addBullet(BulletType::FIVE_MM, 2.5, 4.0);
    bulletRegistry.addBullet(BulletType::SEVEN_MM, 3.5, 8.0);
    bulletRegistry.addBullet(BulletType::NINE_MM, 4.5, 12.0);

    cout << "Bullet types registered: " << bulletRegistry.getBulletCount() << endl;

    // Create flying bullets
    vector<unique_ptr<FlyingBullet>> flyingBullets;

    for (int i = 0; i < 200000; i++){
        auto flyingBullet = make_unique<FlyingBullet>();
        flyingBullet->setSpeed(120.0);
        flyingBullet->setX_Coordinate(i * 1.0);
        flyingBullet->setY_Coordinate(i * 0.5);
        flyingBullet->setZ_Coordinate(100.0);
        flyingBullet->setBulletStatus(BulletStatus::FIRED);

        // All flying bullets share the same Bullet object
        flyingBullet->setBullet(bulletRegistry.getBullet(BulletType::FIVE_MM));

        flyingBullets.push_back(move(flyingBullet));
    }

    cout << "Flying bullets created: " << flyingBullets.size() << endl;
    cout << "Memory saved: Only 3 Bullet objects created for 200000 flying bullets!" << endl;

    // Automatic cleanup - no memory leaks
    // unique_ptr and shared_ptr handle memory automatically

    return 0;
}