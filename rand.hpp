#pragma once
#include "base.hpp"
#include <cstdlib>
#include <ctime>
class Rand : public Base {
    public:
        Rand() : Base() { 
		srand(time(0));
		x = rand() % 100;
	 }
        virtual double evaluate() { return x; }
        virtual std::string stringify() { return std::to_string(x); }
	virtual int number_of_children() { return 0; }
	virtual Base* get_child(int i) { return nullptr; }
	virtual void accept(Visitor* visitor, int index) { visitor->visit_rand(this); }
    private:
	double x;
};

