#pragma once

#include "Person.h"

//�v���C���[�N���X
class Player : public Person
{
private:
	const char* name[];
public:
	Player();
	//�Q�[�����s
	void playBase(Shoe* shoe);
	void printName();
};
