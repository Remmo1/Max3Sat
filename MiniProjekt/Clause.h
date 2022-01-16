#pragma once
class Clause
{
private:
	// numer 
	int st; // first
	int nd; // second
	int rd; // third

public:
	Clause();
	Clause(int _st, int _nd, int _rd);

	~Clause();

	void show();

	int getSt();
	int getNd();
	int getRd();

	void setSt(int _st);
	void setNd(int _nd);
	void setRd(int _rd);
};