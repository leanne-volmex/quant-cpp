#include<vector>
#include<memory>

class ChartDisplay;

class SimpleDerivativeContract{
    public:
    virtual void chartProfitLoss(std::shared_ptr<ChartDisplay> c) = 0;
};

class ChartDisplay{
    public:
    virtual void display(std::shared_ptr<std::vector<SimpleDerivativeContract>> contracts) = 0;
    virtual void addToChart(std::shared_ptr<SimpleDerivativeContract> c) = 0;
};