#include "budget3.h" 

/**
 * @brief Initialize corpBudget static class variable
 *        to zero.
 * 
 */
double Budget::corpBudget = 0; 

/**
 * @brief This function adds the main office's budget request
 *        to the corpBudget static class variable.
 * 
 * @param budReq  value is added to corpBudget
 */
void Budget::mainOffice(double budReq)
{
    corpBudget += budReq;
}