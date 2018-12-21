#pragma once

#include"Point.h"

#include"Figure.h"

#include"Rectangle.h"

class Ellips : public Figure
{
public:
	Ellips();
	Ellips(const Point& point, const int widht, const int height);
	Ellips( Rectangle& other);
	void Print()override;
	void Save()override;
	void Load()override;
private:
	char figure = 'e';
	Point m_CentreEllips;
	int m_Width;
	int m_Height;
};

Ellips::Ellips()
{
}

Ellips::Ellips( Rectangle& other):
	m_CentreEllips(other.GetPoint()),
	m_Height(other.GetHeight()),
	m_Width(other.GetWidth())
	{
}

Ellips::Ellips(const Point& centr, const int widht, const int height):
	m_CentreEllips(centr),
	m_Height(widht),
    m_Width(height)
{
}

void Ellips::Print()
{
	m_CentreEllips.Show();
	std::cout << " Widht:" << m_Width;
	std::cout << " Height:" << m_Height << "\n";
}

void Ellips::Save()
{
	char x[3];
	char y[3];

	sprintf(x, "%d", m_CentreEllips.Get_X());
	sprintf(y, "%d", m_CentreEllips.Get_Y());

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
		sprintf(width, "%d", m_Width);
		fputs(width, file);
		fputc('.', file);
		char height[10];
		sprintf(height, "%d", m_Height);
		fputs(height, file);
		fputc('\n', file);
		fclose(file);
	}
}

void Ellips::Load()
{
	FILE* file = fopen("C:\\Users\\anaga\\Desktop\\Home Work Figure\\file.txt", "r");
	if (file != nullptr)
	{
		while (!feof(file))
		{
			if (getc(file) == 'e')
			{
				char temp[3];
				fseek(file, 1, SEEK_CUR);
				m_CentreEllips.SetX(atoi(fgets(temp, 3, file)));
				if (m_CentreEllips.Get_X() > 9)
				{
					fseek(file, 1, SEEK_CUR);
				}
				m_CentreEllips.SetY(atoi(fgets(temp, 3, file)));
				if (m_CentreEllips.Get_Y() > 9)
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