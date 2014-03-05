#include <iostream>

using namespace std;

class Character {
	public:
		Character(int = 2);
		void HighKick();
		void LowKick();
		void HighPunch();
		void LowPunch();
		void Block();
		void Jump();
		void MoveLeft();
		void MoveRight();
		void SpecialAttack();		

	protected:
		int height;
};
