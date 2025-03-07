#ifndef SCENE_EXCEPTIONS_H_
#define SCENE_EXCEPTIONS_H_

#include <exception>

class SceneExceptions: public std::exception{
    const char* what() const noexcept override {
        return "Model exception";
    }
};

class NodeIndexOutOfRange : public SceneExceptions {
    const char* what() const noexcept override {
        return "Index into the node list is out of range!";
    }
};



#endif