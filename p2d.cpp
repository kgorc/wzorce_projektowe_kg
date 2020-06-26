#include <iostream>

class iPoint2d{

public:
	virtual void writePoint() const = 0;
	virtual double getX() const = 0;
	virtual double getY() const = 0;
};



class Point2d : public iPoint2d{
protected:
	double x;
	double y;

public:
	Point2d(double x, double y) : x(x), y(y){}



	virtual void writePoint() const {
		std::cout<<"Punkt 2W: {"<<x<<", "<<y<<"}"<<std::endl;
	}



	inline virtual double getX() const{
		return x;
	}

	inline virtual double getY() const{
		return y;
	}

};

class iPoint3d{

public:
	virtual double getZ() const = 0;
	virtual void writePoint() const = 0;
	virtual double getX() const = 0;
	virtual double getY() const = 0;
};

class Vector3d : public iPoint3d, private Point2d{

public:
	Vector3d(const iPoint2d* p2d) : Point2d(p2d->getX(), p2d->getY()){
		std::cout<<"Create adapter"<<std::endl<<std::endl;
	}

	virtual void writePoint() const{
		std::cout<<"Punkt 3W: {"<<x<<", "<<y<<", 0}"<<std::endl;
	}

	inline virtual double getZ() const{
		return 0;

	}



	inline virtual double getX() const{

		return x;

	}



	inline virtual double getY() const{

		return y;

	}

};



int main(){

	iPoint2d* p2d = new Point2d(100,100);



	p2d->writePoint();



	std::cout<<std::endl;



	iPoint3d* p3d = new Vector3d(p2d);



	p3d->writePoint();



	if(p3d){

		delete p3d;

		p3d = NULL;

	}



	if(p2d){

		delete p2d;

		p2d = NULL;

	}



	std::cin.get();

	return 0;

}
