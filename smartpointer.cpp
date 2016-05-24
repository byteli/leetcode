#include<iostream>

using namespace std;

template<typename FriendClass , typename DataType>
class refPtr
{
private:
	friend FriendClass;

	refPtr():count(0),raw(NULL){}
	~refPtr(){delete raw;}
	int count;
	DataType* raw;
};


template<typename DataType>
class smPtr
{
private:
	refPtr<smPtr , DataType>* rp;
public:
	smPtr ():rp(){}

	smPtr (DataType* t):rp(new refPtr<smPtr ,DataType>()){
		rp->raw = t;
		rp->count = 1;
	}

	smPtr (const smPtr& sp){
		rp = sp.rp;
		++(rp->count);
	}   

	smPtr& operator=(const smPtr& sp){
		if(sp->rp==this->rp) return *this;

		rp = sp.rp;
		++(rp->count);
		return *this;
	}
	
	~smPtr(){
		if(--rp->count)
			delete rp;
	}


	int use_count(){
		return rp->count;
	}

	DataType* get(){
		return rp->raw;
	}



};

int main()
{
	smPtr<int>  s = new int(10);
	smPtr<int>  s2(s);
	cout<<s.use_count()<<endl;
	return 0;
}