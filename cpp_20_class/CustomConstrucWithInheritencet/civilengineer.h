#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream&, const CivilEngineer& operand);
    public:
        CivilEngineer();
        CivilEngineer(std::string_view fullname,int age,
        std::string_view address,int contract_count, std::string_view speciality);
        ~CivilEngineer() ;
        
        void build_road(){
            add(10,2);
            add(10,2,4);
        }

        
    private : 
        std::string m_speciality{"None"};

};

#endif // CIVIL_ENGINEER_H