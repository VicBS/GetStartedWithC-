#ifndef __PAR_H
#define __PAR_H

template <typename T1, typename T2>
class par 
{
	T1 primero;
	T2 segundo;

	public:
	
		par();
		par(const T1 &c1, const T2 &c2);
		par(const par<T1,T2> &p);

		T1& First();
		T2& Second();
		
		bool operator< (const par<T1,T2> & p) const;
		par<T1,T2> & operator= (const par<T1,T2>& p);
};

#include "par.hxx"
#endif
