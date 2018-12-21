#pragma once

#include<iostream>

#include<cstdio>

class Figure
{
public:
	 Figure();
     
	 virtual void Load();
	 virtual void Print();
	 virtual  void Save();
private:
	Figure* array = nullptr;
};

Figure::Figure()
{
}

void Figure::Load()
{
}

void Figure::Print()
{
}

void Figure::Save()
{
}