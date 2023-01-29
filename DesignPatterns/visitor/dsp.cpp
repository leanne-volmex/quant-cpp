#include "dsp.h"

class option: public SimpleDerivativeContract{
    public:
    void chartProfitLoss(std::shared_ptr<ChartDisplay> c){
        c->addToChart(std::make_shared<option>(*this));
    };
};

class HTMLDisplay: public ChartDisplay{
    public:
    virtual void display(std::shared_ptr<std::vector<SimpleDerivativeContract>> &contracts){
        for(auto &c: *contracts){};
    };
    
    virtual void addToChart(std::shared_ptr<SimpleDerivativeContract> c) {};
};
