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
	Clause(int st, int nd, int rd);

	~Clause();

	void show();

	int getSt();
	int getNd();
	int getRd();

	void setSt(int st);
	void setNd(int nd);
	void setRd(int rd);
};