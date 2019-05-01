#include <iostream>
using namespace std;

class QuackBehavior{
public:
	virtual void quack() = 0; //This is a pure virtual method (=0) which is not supposed to change the data of the class (const). 
};

class simplyQuack : public QuackBehavior{
public:
	virtual void quack(){
		cout<<"Quack"<<endl;
	}
};

class noQuack : public QuackBehavior{
public:
	virtual void quack(){
		cout<<"Can't quack"<<endl;
	}
};

class FlyBehavior{
public:
	virtual void fly() = 0;
}; 

class simplyFly : public FlyBehavior{
public:
	virtual void fly(){
		cout<<"can't fly"<<endl;
	}
};

class jetFly : public FlyBehavior{
public:
	virtual void fly(){
		cout<<"Fly like jet"<<endl;
	}
};

class Duck{
	QuackBehavior *qb;
	FlyBehavior *fb;
public:
	Duck(){}
	void set_fly(FlyBehavior *f){
		fb = f;
	}
	void set_quack(QuackBehavior *q){
		qb = q;
	}
	void performFly(){
		fb->fly();
	}
	void performQuack(){
		qb->quack();
	}
};

int main(){
	simplyQuack simply_q;
	simplyFly simply_f;
	noQuack n_q;
	jetFly j_f;
	Duck mallard, mallard1;
	mallard.set_fly(&simply_f);
	mallard.set_quack(&n_q);
	mallard.performFly();
	mallard.performQuack();
	return 0;
}