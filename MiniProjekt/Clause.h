#pragma once
class Clause
{
private:

	// numer 
	int st;
	int nd;
	int rd;

	// wartoœæ
	bool stV;
	bool ndV;
	bool rdV;

public:
	Clause();
	Clause(int st, int nd, int rd);
	Clause(int st, int nd, int rd, bool stV, bool ndV, bool rdV);

	void show();

	int getSt();
	int getNd();
	int getRd();
	int getStV();
	int getNdV();
	int getRdV();

	void setSt(int st);
	void setNd(int nd);
	void setRd(int rd);
	void setStV(bool v);
	void setNdV(bool v);
	void setRdV(bool v);
};

