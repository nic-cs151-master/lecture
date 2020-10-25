#ifndef BUDGET_H
#define BUDGET_H  

class Budget
{
public:
    Budget() 
    { 
        divBudget = 0; 
    }

    void addBudget(double b)
    { 
        divBudget += b; 
        corpBudget += divBudget; 
    }

    double getDivBudget() const 
    { 
        return divBudget; 
    }

    static double getCorpBudget() 
    { 
        return corpBudget; 
    }

private:
    static double corpBudget;
    double divBudget;
};

// Definition of the static member of the Budget class.
double Budget::corpBudget = 0.0; 

#endif