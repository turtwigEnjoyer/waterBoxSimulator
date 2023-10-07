#include "Dependencies.h"

class ParticlePos{ 
    public:
        int ownerId;
        vector<TPrecisionInfo> position;
    public:
        ParticlePos(float* pos);
        virtual ~ParticlePos();
        TPrecisionInfo CalculateDistance(ParticlePos& other);
        void setOwner(int ownerId);
};