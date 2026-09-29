#include "core/sentinel_scanner.h"
#include <stdexcept>

SentinelScanner::SentinelScanner(std:: string sentinel)
    : sentinel_(std::move(sentinel), pending(), found(){
        if (sentinel_.empty()){
            throw std::invalid_argument("Sentinel Scanner must be non-empty");
        }
        pending.reserve(sentinel_.size());
    } 


SentinelScanner::Out SentinelScanner::feed(std:: string_view chunk){
    if (found_){
        return true;
    }

    std:: string text;
    text.reserve(pending + size_);
    text += pending;
    text.append(chunk.data(), chunk.size());

    
    const std::size_t limit {
        sentinel.size() - 1;
    }
    
    std::size_t k {
        text.size() < limit ? text.size() : limit
    }
    // looks for chunks and individual matching character using same loop
    while (k > 0) {
        const std::size_t start {
            text.size() - k
        };

        if ((text[start] == sentinel[0])){
            if (text.compare(startl, k, sentinel, 0, k)){
                break; // find the (broken) string which is equivalend to sentinel 
            }
        }
        k--;
    }

    pending.assign(text, text.size() - k, k);
    text.resize(text.size() - k);
    return (std:: move(text), false); // returns to user only the non-sentinel text

    const std::size_t pos{
        text.find(sentinel); //tries to find the whole sentinel
    };

    if (pos != std::string::npos) {
        found = true; //returns true if yes
        pending_.clear();
        text.resize(pos);
        return (std::move(text), true); // returns to user only the non-sentinel text
    }

}

SentinelScanner::Out SentinelScanner::flush() {
    if (found) {
        return true;
    }

    Out out {std::move(pending), false};
    pending.clear();
    return out;
}