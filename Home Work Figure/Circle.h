#pragma once

#include"Point.h"

#include"Ellips.h"

class Circle : public Ellips
{
public:
	Circle();
	Circle(const Point point, const int radius);
	void Print()override;
	void Save()override;
	void Load()override;

private:
	char figure = 'c';
	Point m_Centre;
	int m_Radius;
};

Circle::Circle()
{
}

Circle::Circle(const Point point, const int radius):
	m_Centre(point),
	m_Radius(radius)
{
}

void Circle::Print()
{
	m_Centre.Show();
	std::cout << "Radius:" << m_Radius << "\n";
}

void Circle::Save()
{
	char x[3];
	char y[3];

	sprintf(x, "%d", m_Centre.Get_X());
	sprintf(y, "%d", m_Centre.Get_Y());
	FILE* file = fopen("C:\\Users\\anaga\\Desktop\\Home Work Figure\\file.txt", "a");
	if (file != nullptr)
	{
				fputc(figure, file);
				fputc('/', file);
				fputs(x, file);
				fputc('.', file);
				fputs(y, file);
				fputc('.', file);
				char radius[10];
				sprintf(radius, "%d", m_Radius);
				fputs(radius, file);
				fputc('\n', file);
				fclose(file);
	}
}

void Circle::Load()
{
	FILE* file = fopen("C:\\Users\\anaga\\Desktop\\Home Work Figure\\file.txt", "r");
	if (file != nullptr)
	{
		while (!feof(file))
		{
			if (fgetc(file) == 'c')
			{
				char temp[3];
				fseek(file, 1, SEEK_CUR);
				m_Centre.SetX(atoi(fgets(temp, 3, file)));
				if (m_Centre.Get_X() > 9)
				{
					fseek(file, 1, SEEK_CUR);
				}
				m_Centre.SetY(atoi(fgets(temp, 3, file)));
				if (m_Centre.Get_Y() > 9)
				{
					fseek(file, 1, SEEK_CUR);
				}
				m_Radius = atoi(fgets(temp, 3, file));
				fclose(file);
				break;
			}
		}
	}
}