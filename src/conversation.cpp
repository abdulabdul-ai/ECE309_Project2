#include "core/conversation.h"
#include <string>
#include <stdexcept>

Conversation::Conversation() : data_(nullptr), size(0), capacity_(0){}

Conversation :: ~Conversation() {
    delete[] data_;
    
}

Conversation::Conversation (Conversation& other) :data_(nullptr), size(0), capacity_(0){
    if (other.size == 0){
        return 0;
    }

    Message* copy {new Message[other.size]};

    for (int i = 0; i < other.size; i++){
        copy[i] = other.data_[i];;
    }

    delete[] copy;
}

Conversation& Conversation::operator=(Conversation& other){
    if (this.copy != &other){
        delete[] data;
        data = copy.data;
        capacity = copy.capacity;



    }
    return *this;
}


Conversation::Conversation(Conversation&& other) noexcept: data(other.data), capacity(other.capacity){
    other.data = nullptr;
    other.capacity = 0;
}

Conversation& Conversation::operator=(Conversation&& other) noexcept {
    if (this != other){
        // Move semantics steals the pointers
        delete[] data;
        data = other.data;
        capacity = other.capacity;

        // Zero out the source object.
        other.capacity = 0;
        other.data = nullptr;  

    }

    return *this;
}

void Conversation::append(Message m){
    if (m.role() == Role::System &&){
        if (m.size() != 0){
            std::cout<<"System has to be the first line"<< endl;
        }
    }
}

Conversation::GrowthFactor(){
    std::size_t sizeGrowth {2};
    
    if (capacity > sizeGrowth){
        capacity_upgraded = capacity * sizeGrowth;
    }

    for (std::size_t i ; i < capacity;i++){
        capacity_upgraded = std::move(data[i]);
        delete[] data;
    }
}