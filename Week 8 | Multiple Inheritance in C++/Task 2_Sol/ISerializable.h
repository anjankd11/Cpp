#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

// This class provides interface for saving/loading
class ISerializable
{
public:
	virtual void Save(std::ostream&) = 0;
	virtual void Load(std::istream&) = 0;
};

#endif // SERIALIZABLE_H