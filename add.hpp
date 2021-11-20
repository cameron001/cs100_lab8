#pragma once

#include "base.hpp"

class add : public Base {
    public:
        add(Base* value1, Base* value2) : Base() {
                x = value1;
                y = value2; }
        virtual double evaluate() { return x->evaluate() + y->evaluate(); }
        virtual std::string stringify() {
                        return "(" + x->stringify() + "+" + y->stringify() + ")"; }

	virtual int number_of_children() { return 2; }
	virtual Base* get_child(int i) { 
		if (i == 0) { return x; }
		else if (i == 1) { return y; }
		else { return nullptr; }
	}
	virtual void accept(Visitor* visitor, int index) {
		if (index == 0) { visitor->visit_add_begin(this); }
		else if (index == 1) { visitor->visit_add_middle(this); }
		else if (index == 2) { visitor->visit_add_end(this); }
	}
private:
        Base* x;
        Base* y;
};

