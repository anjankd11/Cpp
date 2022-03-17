#ifndef COMPARABLE_H
#define COMPARABLE_H

// This class provides interface for comparing ('equality' check, 'greater than' check)
class IComparable
{
public:
	virtual bool operator ==(const IComparable&) = 0;
	virtual bool operator >(const IComparable&) = 0;
};

#endif //COMPARABLE_H
