#pragma once

#include <vector>

#include "cell.h"

class CGrid
{
    // Member Functions
public:
    CGrid(const uint32_t& _rkuiWidth, const uint32_t& _rkuiHeight)
    : m_uiSize{_rkuiWidth, _rkuiHeight}
    {
        // Constructor Invoked
        m_vecCells.reserve(_rkuiWidth * _rkuiHeight);
        for(uint32_t row = 0; row < _rkuiHeight; ++row)
        {
            for(uint32_t col = 0; col < _rkuiWidth; ++col)
            {
                m_vecCells.push_back(std::unique_ptr<CCell>(new CCell(TVec2<uint32_t>{col, row})));
            }
        }
        for(uint32_t row = 0; row < _rkuiHeight; ++row)
        {
            for(uint32_t col = 0; col < _rkuiWidth; ++col)
            {
                // Compute the index of the current cell.
                uint32_t idx = row * _rkuiWidth + col;
                
                // Set the cardinal (N, E, S, W) neighbors for each cell.
                m_vecCells[idx]->SetNeighbor(FACE_NORTH, (row >= _rkuiHeight - 1) ? nullptr : GetCell(TVec2<uint32_t>{col, row + 1}));
                m_vecCells[idx]->SetNeighbor(FACE_EAST,  (col >= _rkuiWidth  - 1) ? nullptr : GetCell(TVec2<uint32_t>{col + 1, row}));
                m_vecCells[idx]->SetNeighbor(FACE_SOUTH, (row == 0)               ? nullptr : GetCell(TVec2<uint32_t>{col, row - 1}));
                m_vecCells[idx]->SetNeighbor(FACE_WEST,  (col == 0)               ? nullptr : GetCell(TVec2<uint32_t>{col - 1, row}));
            }
        }
    }
    
    ~CGrid()
    {
        // Destructor Invoked
    }
    
    CCell* GetCell(const uint32_t& _rkuiIndex) const
    {
        return((_rkuiIndex < m_vecCells.size()) ? m_vecCells[_rkuiIndex].get() : nullptr);
    }
    
    CCell* GetCell(const TVec2<uint32_t>& _rkuiIndex) const
    {
        return(GetCell(_rkuiIndex.y * m_uiSize.x + _rkuiIndex.x)); // row * width + column
    }
    
    const TVec2<uint32_t>& GetSize() const
    {
        return(m_uiSize);
    }
    
protected:
    
private:
    CGrid (const CGrid&) = delete;
    CGrid& operator = (const CGrid&) = delete;
    
    // Member Variables
public:
    
protected:
    
private:
    std::vector<std::unique_ptr<CCell>> m_vecCells;
    TVec2<uint32_t> m_uiSize;
};
