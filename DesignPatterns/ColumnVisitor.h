#pragma once
#include <numeric>

class IntC

class ColumnVisitor {
    public:
        virtual void visit(IntColumn& column) = 0;
        virtual void visit(StringColumn& column) = 0;
};

class SumVisitor : public ColumnVisitor {
    public:
        void visit(IntColumn& column) override {
            sum_ += std::accumulate(column.begin(), column.end(), 0);
        }
        void visit(StringColumn& column) override {
            // do nothing
        }
    private:
        int sum_ = 0;
};