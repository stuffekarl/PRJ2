/*
 * Codelock.h
 *
 * Created: 2014-11-27 14:39:00
 *  Author: Snufkin
 */ 


#ifndef CODELOCK_H_
#define CODELOCK_H_


class Codelock{
private:

public:
	Codelock( ){}
	bool locked(){
		
		return true;
	}

};

Codelock * getMyCodelock();

#endif /* CODELOCK_H_ */