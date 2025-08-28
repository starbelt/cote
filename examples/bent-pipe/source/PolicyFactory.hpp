#ifndef POLICY_FACTORY_HPP
#define POLICY_FACTORY_HPP

#include <memory>
#include <string>
#include "SchedulingPolicy.hpp"
#include "GreedyPolicy.hpp"

class PolicyFactory {
public:
    static std::unique_ptr<SchedulingPolicy> createPolicy(const std::string& policyName) {
        if(policyName == "greedy") {
            return std::make_unique<GreedyPolicy>();
        }
        // Default to greedy
        return std::make_unique<GreedyPolicy>();
    }
};

#endif
