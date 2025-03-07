#ifndef TINYXMLPROTOYPE_H
#define TINYXMLPROTOYPE_H

#include <string>

class TinyXMLPrototype
{
private:
    std::string filename;

public:
    // Constructors
    TinyXMLPrototype();
    TinyXMLPrototype(const std::string& name);

    // Destructor 
    ~TinyXMLPrototype();

    // Getter for name
    std::string getFilename() const;

    // Setter for name
    void setFilename(const std::string& name);

    // Method to check for the existence of 'filename' in testfiles folder
    bool checkFile() const;

    // See if we can read a scene
    bool testFileLoad() const;

    // Can we load a tag
    bool testTagRead() const;

    // Can we load a attribute
    bool testAttributeRead() const;

    // Can we load a attribute
    bool testAttributeRead2() const;
};

#endif // TINYXMLPROTOYPE_H