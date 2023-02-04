#pragma once

#include <iostream>

enum EFace
{
    // DO NOT alter the order of this enumeration!!!
    FACE_NONE = -1,
    FACE_NORTH,
    FACE_EAST,
    FACE_SOUTH,
    FACE_WEST,
    FACE_MAX
};

template<typename TYPE>
struct TVec2
{
    TYPE x, y;
};

class CCell;

class IEntity
{
    // Member Functions
public:
    IEntity();
    virtual ~IEntity() = 0;
    
    void Place(CCell* _pCell, const EFace& _rkeFace);
    void Move();
    void RotateLeft();
    void RotateRight();
    void Report();
    
    CCell* GetCell() const;
    const EFace& GetFace() const;
    
    static EFace ConvertStringToDirection(const std::string& _rkstrFace);
    
protected:
    
private:
    IEntity (const IEntity&) = delete;
    IEntity& operator = (const IEntity&) = delete;
    
    // Member Variables
public:
    
protected:
    
private:
    CCell* m_pCell;
    EFace m_eFace;
};
