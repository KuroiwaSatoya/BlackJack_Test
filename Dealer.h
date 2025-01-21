#pragma once

#include "Person.h"

//ディーラークラス
class Dealer : public Person 
{
private:
	const char* name[];
public:
	Dealer();
	//ゲーム実行
	void playBase(Shoe* shoe);
	void printName();
};