#ifndef _LOADER_EXCEPTIONS_H_
#define _LOADER_EXCEPTIONS_H_

#include <exception>

class LoaderException: public std::exception{
    const char* what() const noexcept override {
        return "Loader exception";
    }
};

class DocumentLoadFailed : public LoaderException {
    const char* what() const noexcept override {
        return "Failed to load the scene!";
    }
};

class RootParseFailed : public LoaderException {
    const char* what() const noexcept override {
        return "Failed to Parse root element!";
    }
};


#endif