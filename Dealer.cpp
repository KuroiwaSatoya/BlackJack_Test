#include <iostream>

#include "Dealer.h"
#include "Shoe.h"

using namespace std;

Dealer::Dealer() {
	*name = "dealer";
}

//�Q�[�����s
void Dealer::playBase(Shoe* shoe) {
	cout << *name << "�̃^�[��" << endl;
	//�X�R�A��16�ȉ��̏ꍇhit�𑱂���
	while (getScore() < 17 && getScore() > 0) {
		//�q�b�g����
		hit(shoe);
		cout << "hit" << endl;
		//��D�̕\��
		cout << "====================" << endl;
		cout << *name << endl;
		showHand();
		cout << "====================" << endl;
	}
}

void Dealer::printName() {
	cout << *name;
}