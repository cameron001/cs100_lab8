#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

class Op;
class Rand;
class add;
class sub;
class mult;
class Div;
class exponent;

class Visitor{
    public:
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) = 0;
        virtual void visit_rand(Rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(add* node) = 0;
        virtual void visit_add_middle(add* node) = 0;
        virtual void visit_add_end(add* node) = 0;
        virtual void visit_sub_begin(sub* node) = 0;
        virtual void visit_sub_middle(sub* node) = 0;
        virtual void visit_sub_end(sub* node) = 0;
        virtual void visit_mult_begin(mult* node) = 0;
        virtual void visit_mult_middle(mult* node) = 0;
        virtual void visit_mult_end(mult* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
        virtual void visit_pow_begin(exponent* node) = 0;
        virtual void visit_pow_middle(exponent* node) = 0;
        virtual void visit_pow_end(exponent* node) = 0;
};

#endif //__VISITOR_HPP__
