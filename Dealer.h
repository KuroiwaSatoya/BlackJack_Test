#pragma once

#include "Person.h"

//�f�B�[���[�N���X
class Dealer : public Person 
{
private:
	const char* name[];
public:
	Dealer();
	//�Q�[�����s
	void playBase(Shoe* shoe);
	void printName();
};