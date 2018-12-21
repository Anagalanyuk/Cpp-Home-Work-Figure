#pragma once

#include"Figure.h"

#include"Point.h"

class Rectangle :public Figure
{
public:
	Rectangle();
	Rectangle(const Point& point, const int Width, const int Height);
	int GetWidth();
	int GetHeight();
	Point GetPoint();
	void Print()override;
	void Save()override;
	void Load()override;
private:
	char figure = 'r';
	Point m_UpperLeftCorner;
	int m_Width;
	int m_Height;

};

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(const  Point& point, const int Width, const int Height):
	m_UpperLeftCorner(point),
	m_Width(Width),
	m_Height(Height)
{
}

void Rectangle::Print()
{
	m_UpperLeftCorner.Show();
	std::cout << " Width:" << m_Width <<" ";
	std::cout << "Height:" << m_Height <<"\n";
}


int Rectangle::GetWidth()
{
	return m_Width;
}

int Rectangle::GetHeight()
{
	return m_Height;
}

Point Rectangle::GetPoint()
{
	return m_UpperLeftCorner;
}

void Rectangle::Save()
{
	char x[3];
	char y[3];

	sprintf(x, "%d", GetPoint().Get_X());
	sprintf(y, "%d", GetPoint().Get_Y());
	FILE* file = fopen("C:\\Users\\anaga\\Desktop\\Home Work Figure\\file.txt", "a");
	if (file != nullptr)
	{
			fputc(figure, file);
			fputc('/', file);
			fputs(x, file);
			fputc('.', file);
			fputs(y, file);
			fputc('.', file);
			char width[10];
			sprintf(width, "%d", GetWidth());
			fputs(width, file);
			fputc('.', file);
			char height[10];
			sprintf(height, "%d", GetHeight());
			fputs(height, file);
			fputc('\n', file);
			fclose(file);
	}
}

void Rectangle::Load()
{
	FILE* file = fopen("C:\\Users\\anaga\\Desktop\\Home Work Figure\\file.txt", "r");
	if (file != nullptr)
	{
		while (!feof(file))
		{
			if (fgetc(file) == 'r')
			{
				fseek(file, 1, SEEK_CUR);
				char temp[3];
				m_UpperLeftCorner.SetX(atoi(fgets(temp, 3, file)));
				if (m_UpperLeftCorner.Get_X() > 9)
				{
					fseek(file, 1, SEEK_CUR);
				}
				m_UpperLeftCorner.SetY(atoi(fgets(temp, 3, file)));
				if (m_UpperLeftCorner.Get_Y() > 9)
				{
					fseek(file, 1, SEEK_CUR);
				}
				m_Width = atoi(fgets(temp, 3, file));
				if (m_Width > 9)
				{
					fseek(file, 1, SEEK_CUR);
				}
				m_Height = atoi(fgets(temp, 3, file));
				fclose(file);
				break;
			}
		}
	}
}