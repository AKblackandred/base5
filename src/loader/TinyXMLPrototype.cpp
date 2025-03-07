#include "TinyXMLPrototype.hpp"
#include <filesystem>

#include "tinyxml2.h"
using tinyxml2::XMLDocument;
using tinyxml2::XMLElement;
using tinyxml2::XMLError;

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

// Constructor
TinyXMLPrototype::TinyXMLPrototype(const std::string& name) : filename(name) 
{

}

// Constructor
TinyXMLPrototype::TinyXMLPrototype() 
{
    filename = "not set";
}

TinyXMLPrototype::~TinyXMLPrototype()
{

}

// Getter for name
std::string TinyXMLPrototype::getFilename() const 
{
    return filename;
}

// Setter for name
void TinyXMLPrototype::setFilename(const std::string& name) 
{
    this->filename = name;
}

// Method to check for the existence of dream.xml in assets folder
bool TinyXMLPrototype::checkFile() const 
{
    return std::filesystem::exists(filename);
}

bool TinyXMLPrototype::testFileLoad() const
{
    tinyxml2::XMLDocument doc;
	doc.LoadFile( filename.c_str() );

    if(doc.ErrorID() != 0)
    {
        std::cout << "Can't read the doc!" << std::endl;
        return false;
    }
    return true;
}

// Can we load a tag
bool TinyXMLPrototype::testTagRead() const
{
    tinyxml2::XMLDocument doc;
	doc.LoadFile( filename.c_str() );

    if(doc.ErrorID() != 0)
    {
        std::cout << "Can't read the doc!" << std::endl;
        return false;
    }

    // get the outer tag
    tinyxml2::XMLElement* playElement = doc.FirstChildElement("PLAY");

    // get a nested tag
    tinyxml2::XMLElement* titleElement = playElement->FirstChildElement( "TITLE" );

    // get the text in a tag
	const char* title = titleElement->GetText();
	std::cout << "Name of play (1):" << title << std::endl;

    return true;
}

// Can we load a attribute
bool TinyXMLPrototype::testAttributeRead() const
{
    tinyxml2::XMLDocument doc;
	doc.LoadFile( filename.c_str() );

    if(doc.ErrorID() != 0)
    {
        std::cout << "Can't read the doc!" << std::endl;
        return false;
    }

    // get the outer tag
    tinyxml2::XMLElement* sceneElement = doc.FirstChildElement("scene");

    std::string version = sceneElement->Attribute("formatVersion");
    
    std::cout << "Version is :" << version << std::endl;

    if(version.compare("1.1") == 0)
        return true;
    else 
        return false;
}

// Can we load a attribute
bool TinyXMLPrototype::testAttributeRead2() const
{
    tinyxml2::XMLDocument doc;
	doc.LoadFile( filename.c_str() );

    if(doc.ErrorID() != 0)
    {
        std::cout << "Can't read the doc!" << std::endl;
        return false;
    }

    // get the outer tag
    tinyxml2::XMLElement* sceneElement = doc.FirstChildElement("scene");

    float version = sceneElement->FloatAttribute("formatVersion");
    
    std::cout << "Version is :" << version << std::endl;

    if(fabs(version - 1.1f) < 0.0001f)
        return true;
    else 
        return false;
}