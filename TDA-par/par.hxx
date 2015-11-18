//constructor
template <typename T1,typename T2>
par<T1,T2>::par()
{

}

//constructor with parameters
template <typename T1,typename T2>
par<T1,T2>::par(const T1 &c1, const T2 &c2)
{
	primero = c1;
	segundo = c2;
}

//copy constructor
template <typename T1,typename T2>
par<T1,T2>::par(const par<T1,T2> &p)
{
	primero = p.primero;
	segundo = p.segundo;
}

//get the first element
template <typename T1,typename T2>
T1& par<T1,T2>::First()
{
	return primero;
}

//get the second element
template <typename T1,typename T2>
T2& par<T1,T2>::Second(){
	return segundo;
}

//operator '<'
template <typename T1,typename T2>
bool par<T1,T2>::operator<(const par<T1,T2> &p) const 
{
	if( primero > p.primero )
		return false;
	else if( primero == p.primero)
	{
		if(segundo > p.segundo)
			return false;
		else if(segundo == p.segundo)
			return false;
	}

	return true;
}

//operator '='
template <typename T1,typename T2>
par<T1,T2>& par<T1,T2>::operator=(const par<T1,T2> &p)
{
	primero = p.primero;
	segundo = p.segundo;
}
