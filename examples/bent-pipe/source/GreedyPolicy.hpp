#ifndef GREEDY_POLICY_HPP
#define GREEDY_POLICY_HPP

#include "SchedulingPolicy.hpp"

class GreedyPolicy : public SchedulingPolicy {
public:
    cote::Satellite* selectSatellite(
        const std::vector<cote::Satellite*>& visibleSats,
        const std::map<uint32_t,cote::Sensor*>& satId2Sensor,
        const std::map<uint32_t,bool>& satId2Occupied,
        const cote::DateTime& currentTime,
        uint32_t groundStationId
    ) override {
        cote::Satellite* bestSat = NULL;
        uint64_t bestSatBuffer = 0;
        
        for(size_t j=0; j<visibleSats.size(); j++) {
            cote::Satellite* satj = visibleSats.at(j);
            const uint32_t SAT_ID = satj->getID();
            const uint64_t BUF = satId2Sensor.at(SAT_ID)->getBitsBuffered();
            
            if(!satId2Occupied.at(SAT_ID) && BUF > bestSatBuffer) {
                bestSat = satj;
                bestSatBuffer = BUF;
            }
        }
        
        return bestSat;
    }
    
    std::string getPolicyName() override {
        return "greedy";
    }
};

#endif
