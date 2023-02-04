#pragma once

#include "entity.h"

class CRobot : public IEntity
{
    // Member Functions
public:
    CRobot(const std::string& _rkstrName)
    : m_strName(_rkstrName)
    {
        // Constructor Invoked
        std::cout << "DEBUG: " << _rkstrName << " created!" << std::endl;
    }
    
    virtual ~CRobot()
    {
        // Destructor Invoked
        std::cout << "DEBUG: " << m_strName << " destroyed!" << std::endl;
    }
    
protected:
    
private:
    CRobot (const CRobot&) = delete;
    CRobot& operator = (const CRobot&) = delete;
    
    // Member Variables
public:
    
protected:
    
private:
    std::string m_strName;
};
