#include <iostream>
using namespace std;

enum class TransportMode{
    CAR,
    BIKE,
    WALK
};

// <<interface>>
class PathCalculationStrategy{
    public:
        virtual void calculatePath(string from, string to) = 0;
        virtual ~PathCalculationStrategy() = default;
};


class CarPathCalculationStrategy  : public PathCalculationStrategy {
    public:
        void calculatePath(string from, string to) override {
            cout << "Finding path for Car..." << endl;
        }
};


class BikePathCalculationStrategy : public PathCalculationStrategy {
    public:
        void calculatePath(string from, string to) override {
            cout << "Finding path for Bike..." << endl;
        }
};


class WalkPathCalculationStrategy : public PathCalculationStrategy {
    public:
        void calculatePath(string from, string to) override {
            cout << "Finding path for Walk..." << endl;
        }
};


// factory
class PathCalculationStrategyFactory{
    public:
        PathCalculationStrategy* getPathCalculationStrategyForMode(TransportMode mode){
            switch(mode){
                case TransportMode::WALK:
                    return new WalkPathCalculationStrategy();
                case TransportMode::BIKE:
                    return new BikePathCalculationStrategy();
                case TransportMode::CAR:
                    return new CarPathCalculationStrategy();
                default:
                    return nullptr;
            }
        }
};

class GoogleMap{

    private:
        PathCalculationStrategyFactory *pathCalculationStrategyFactory = new PathCalculationStrategyFactory();

    public:
        void findPath(string from, string to, TransportMode mode){

            PathCalculationStrategy *pathCalculationStrategy = pathCalculationStrategyFactory->getPathCalculationStrategyForMode(mode);

            if(pathCalculationStrategy){
                pathCalculationStrategy->calculatePath(from, to);
            }
        }

        ~GoogleMap(){
            delete pathCalculationStrategyFactory;
        }
};
