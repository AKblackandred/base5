#  Ogre Scene File Loader #

Another part-complete example, starting to load the scene from file. 

## scene ##

Data model for the application, currently contains:
* ```Scene``` - root element of the structure, describes the whole scene will hold a list nodes.
* ```Nodes``` - holds a list of notes (```std::vector```) also has an optimal position (```extendedTest.scene``` - created to test this).  
* ```Node``` - has position and a nested node, but many of the required and optional tags are not yet stored. 
* ```Entity``` - has a ```meshName```, but no other attributes are loaded. 

## loader ##

Uses ```Fetch_Content``` (CMake) to pull in the TinyXML libraries at configure time and build them.  Version is fixed in the file the latest is quite old (keeping pace with glew, so I'm using a more recent hash). 

Also has a class called ```TinyXMLPrototype``` 

Started creating the system, this iteration/sprint added parsing the Scene element from the file:

Classes:
* ```TinyXMLPrototype``` - this is to test how to get TinyXML working and check our environment. Also check that we can use the required functionality from the library. 
* ```SceneFileLoader``` - The **Controller** for the sub-system, loads, parses etc. 

## ui ##

Has a single ```main.cpp``` file with a ```main```, this is blank. The CMakeLists.txt has all the FetchContent(...) required to add GLEW and wxWidgets to the project. 

## assets ##

Contains a test file. 

## testfiles ##

Test files, some working and broken xml files and an extended ```.scene``` file. Note there is also a ```.dtd``` file in this folder. 

## gtest ##

An odd one, this one is automatically named after the project ... I should change that I've used the folder name everywhere else. Uses ```Fetch_Content``` to Google Test so we can just write test fixtures and not have to worry about running them etc. 

Tests added for: 
* ```TinyXMLPrototype```

Some tests added for * ```Scene```, ```Nodes``` and ```SceneFileTestHarness``` but these is very incomplete. 

