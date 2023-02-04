#pragma once

#include "entity.h"

class CCell
{
    // Member Functions
public:
    CCell(const TVec2<uint32_t>& _rkuiIndex)
    : m_uiIndex(_rkuiIndex)
    , m_pEntity(nullptr)
    {
        // Constructor Invoked
    }
    
    ~CCell()
    {
        // Destructor Invoked
    }
    
    void SetEntity(IEntity* _pEntity)
    {
        m_pEntity = _pEntity;
    }
    
    CCell* GetNeighbor(const EFace& _rkeFace) const
    {
        return((_rkeFace > FACE_NONE && _rkeFace < FACE_MAX) ? m_pNeighbors[_rkeFace] : nullptr);
    }
    
    const TVec2<uint32_t>& GetIndex() const
    {
        return(m_uiIndex);
    }
    
protected:
    void SetNeighbor(const EFace& _rkeFace, CCell* _pCell)
    {
        m_pNeighbors[_rkeFace] = _pCell;
    }
    
private:
    CCell (const CCell&) = delete;
    CCell& operator = (const CCell&) = delete;
    
    // Member Variables
public:
    friend class CGrid; // Only allow the grid to call SetNeighbor() during initialization.
    
protected:
    
private:
    CCell* m_pNeighbors[FACE_MAX]{nullptr};
    TVec2<uint32_t> m_uiIndex;
    IEntity* m_pEntity;
};
