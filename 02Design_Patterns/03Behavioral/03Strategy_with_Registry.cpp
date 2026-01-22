#include <iostream>
#include <unordered_map>
using namespace std;

enum class TransportMode{
    CAR,
    BIKE,
    WALK
};

class PathCalculationStrategy{
public:
    virtual void calculatePath(string from, string to) = 0;
    virtual ~PathCalculationStrategy() = default;
};

class CarPathCalculationStrategy : public PathCalculationStrategy{
public:
    void calculatePath(string from, string to) override{
        cout << "Calculating path for Car..." << endl;
    }
};

class BikePathCalculationStrategy : public PathCalculationStrategy{
public:
    void calculatePath(string from, string to) override{
        cout << "Calculating path for Bike..." << endl;
    }
};

class WalkPathCalculationStrategy : public PathCalculationStrategy{
public:
    void calculatePath(string from, string to) override{
        cout << "Calculating path for Walk..." << endl;
    }
};

class PathCalculationStrategyRegistry{

private:
    unordered_map<TransportMode, PathCalculationStrategy *> strategies;

public:
    void registerStrategy(TransportMode mode, PathCalculationStrategy *strategy){
        strategies[mode] = strategy;
    }

    PathCalculationStrategy *get(TransportMode mode){
        auto it = strategies.find(mode);
        if (it == strategies.end()){
            return nullptr;
        }

        return it->second;
    }
};

class GoogleMap{
private:
    PathCalculationStrategyRegistry *pathCalculationStrategyRegistry;

public:
    GoogleMap(PathCalculationStrategyRegistry *registry){
        this->pathCalculationStrategyRegistry = registry;
    }

    void findPath(string from, string to, TransportMode mode){
        PathCalculationStrategy *strategy = pathCalculationStrategyRegistry->get(mode);
        strategy->calculatePath(from, to);
    }
};

int main(){
    PathCalculationStrategyRegistry *pathCalculationStrategyRegistry = new PathCalculationStrategyRegistry();

    pathCalculationStrategyRegistry->registerStrategy(
        TransportMode::CAR, new CarPathCalculationStrategy());

    pathCalculationStrategyRegistry->registerStrategy(
        TransportMode::BIKE, new BikePathCalculationStrategy());

    pathCalculationStrategyRegistry->registerStrategy(
        TransportMode::WALK, new WalkPathCalculationStrategy());

    GoogleMap *googleMap = new GoogleMap(pathCalculationStrategyRegistry);
}