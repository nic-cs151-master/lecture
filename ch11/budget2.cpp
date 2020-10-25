#include "budget2.h" 

// Definition of the static member of Budget class
double Budget::corpBudget = 0;

/**
 * @brief Definition of static member function mainOffice
 *        This function adds the main office's budget request to
 *        the corpBudget variable.
 * 
 * @param budReq 
 */
void Budget::mainOffice(double budReq)
{
    corpBudget += budReq;
}