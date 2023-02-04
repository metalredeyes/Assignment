#include "cell.h"

#include "entity.h"

static const std::string sg_kstrFace[] = { "NORTH", "EAST", "SOUTH", "WEST" };

IEntity::IEntity()
: m_pCell(nullptr)
, m_eFace(FACE_NONE)
{
    // Constructor Invoked
}

IEntity::~IEntity()
{
    // Destructor Invoked
}

void
IEntity::Place(CCell* _pCell, const EFace& _rkeFace)
{
    if(_pCell)
    {
        if(_rkeFace > FACE_NONE && _rkeFace < FACE_MAX)
        {
            // Remove the entity from the old cell first (if there is one).
            if(m_pCell)
            {
                m_pCell->SetEntity(nullptr); // Can be extended to use a std::list to hold multiple entities in a single cell.
            }
            
            // Set the target cell's entity to point to this one.
            _pCell->SetEntity(this);
            
            // Lastly, set the new facing direction and cell reference for this entity.
            m_pCell = _pCell;
            m_eFace = _rkeFace;
        }
        else
        {
            std::cout << "ERROR: Facing direction is invalid!" << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: Placement coordinates are beyond the grid's extent!" << std::endl;
    }
}

void
IEntity::Move()
{
    if(m_pCell)
    {
        // If there is a neighbor in the facing direction, then we can move to the next cell.
        if(m_pCell->GetNeighbor(m_eFace))
        {
            Place(m_pCell->GetNeighbor(m_eFace), m_eFace);
        }
        else
        {
            std::cout << "ERROR: Cannot move further!" << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: Have not been placed on grid yet!" << std::endl;
    }
}

void
IEntity::RotateLeft()
{
    if(m_pCell)
    {
        m_eFace = EFace(static_cast<uint32_t>(m_eFace - 1) % FACE_MAX);
    }
    else
    {
        std::cout << "ERROR: Have not been placed on grid yet!" << std::endl;
    }
}

void
IEntity::RotateRight()
{
    if(m_pCell)
    {
        m_eFace = EFace(static_cast<uint32_t>(m_eFace + 1) % FACE_MAX);
    }
    else
    {
        std::cout << "ERROR: Have not been placed on grid yet!" << std::endl;
    }
}

void
IEntity::Report()
{
    if(m_pCell)
    {
        std::cout << "Output: " << m_pCell->GetIndex().x << ", " << m_pCell->GetIndex().y << ", " << sg_kstrFace[m_eFace] << std::endl;
    }
    else
    {
        std::cout << "ERROR: Have not been placed on grid yet!" << std::endl;
    }
}

CCell*
IEntity::GetCell() const
{
    return(m_pCell);
}

const EFace&
IEntity::GetFace() const
{
    return(m_eFace);
}

EFace
IEntity::ConvertStringToDirection(const std::string& _rkstrFace)
{
    for(auto face = FACE_NORTH; face < FACE_MAX; face = EFace(face + 1))
    {
        if(sg_kstrFace[face].length() == _rkstrFace.length())
        {
            if(std::equal(sg_kstrFace[face].begin(), sg_kstrFace[face].end(), _rkstrFace.begin(), _rkstrFace.end(), [](char a, char b){ return(tolower(a) == tolower(b)); }))
            {
                return(face);
            }
        }
    }
    return(FACE_NONE);
}
