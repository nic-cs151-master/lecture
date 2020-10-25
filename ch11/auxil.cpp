#include "auxil.h"
#include "budget3.h"  

/**
 * @brief This function is declared as a friend of the Budget
 *        class. It adds the value of argument b to the 
 *        static corpBudget class member variable of the 
 *        Budget class.
 * 
 * @param b  value added to Aux class auxBudget member variable
 *           and value is added to Budget class static corpBudget
 *           member variable
 */
void Aux::addBudget(double b)
{
    auxBudget += b;
    Budget::corpBudget += auxBudget;
}