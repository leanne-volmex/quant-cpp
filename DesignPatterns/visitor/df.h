#include<vector>
#include<memory>
#include<numeric>
#include<functional>

class IntColumn;
class StringColumn;
class ColumnVisitor {
    public:
        virtual void visit(IntColumn& column) = 0;
        virtual void visit(StringColumn& column) = 0;
};


class Column {
    public:
        virtual void accept(ColumnVisitor& v) = 0;
};

class IntColumn : public Column {
    public:
        std::vector<int> data_;
        void accept(ColumnVisitor& v) override {
            v.visit(*this);
        }
        // auto begin() { return data_.begin(); }
        // auto end() { return data_.end(); }
};

class StringColumn : public Column {
    public:
        std::vector<std::string> data_;
        void accept(ColumnVisitor& v) override {
            v.visit(*this);
        }
        // auto begin() { return data_.begin(); }
        // auto end() { return data_.end(); }
};

class DataFrame {
    public:
        template <typename Visitor>
        void visit(Visitor& v) {
            for (auto& column : columns_) {
                column->accept(v);
            }
        }
    private:
        std::vector<std::unique_ptr<Column>> columns_;
};

/*
The visitor pattern is a design pattern in which an object, 
called a visitor, is used to perform operations on the elements of an object structure, 
such as a collection of objects. 
The elements in the structure do not need to be of the same type, and the visitor 
can perform different operations 
depending on the type of the element it is visiting.

In building a dataframe in C++, 
the visitor pattern can be useful when we want to perform different operations 
on different types of columns, such as performing a mathematical operation on a numerical column 
and concatenating string values in a string column.


In this code, the DataFrame class has a visit method 
that takes a Visitor object and calls the accept method 
on each of its columns. The Column class is an abstract base 
class for different types of columns, such as IntColumn and 
StringColumn, each of which override the accept method to 
call the appropriate visit method on the visitor. 
The ColumnVisitor class is an abstract base class 
for visitor classes, such as SumVisitor, which overrides the visit method 
for different types of columns to perform 
the appropriate operation.

The DataFrame class has a polymorphic method (visit) 
that takes a ColumnVisitor object and iterates through 
its columns, calling the accept method on each Column object. 
The Column class is an abstract base class with a pure virtual 
accept method, which is overridden by the IntColumn and StringColumn 
classes to call the visit method on the ColumnVisitor object passed to 
their accept method.

To fix the issue with polymorphic methods interacting with each other, 
we can use virtual dispatch to ensure that the correct visit method is called 
on the ColumnVisitor object based on the type of the Column object. This can be done 
by making the visit method in the ColumnVisitor class virtual and adding the override 
keyword in the visit method of the derived classes (SumVisitor, etc.).

*/

// https://godbolt.org/z/TdWdaexT1
