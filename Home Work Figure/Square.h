#pragma once

#include"Point.h"

#include"Figure.h"

class Square : public Rectangle
{
public:
	Square();
	Square(const Point& UpperLeftCorner, const int lenght);
	void Print()override;
	void Save()override;
	void Load()override;
;

private:
	char figure = 's';
	Point m_UpperLeftCorner;
	int m_Length;
};
Square::Square()
{
}

Square::Square(const Point& point, const int lenght):
	m_UpperLeftCorner(point),
	m_Length(lenght)
{
}

void Square:: Print()
{
	m_UpperLeftCorner.Show();
	std::cout << "Lenght:" << m_Length << "\n";
}

void Square::Save()
{
	char x[3];
	char y[3];

	sprintf(x, "%d", m_UpperLeftCorner.Get_X());
	sprintf(y, "%d", m_UpperLeftCorner.Get_Y());

	FILE* file = fopen("C:\\Users\\anaga\\Desktop\\Home Work Figure\\file.txt", "a");
	if (file != nullptr)
	{
					fputc(figure, file);
					fputc('/', file);
					fputs(x, file);
					fputc('.', file);
					fputs(y, file);
					fputc('.', file);
					char length[10];
					sprintf(length, "%d", m_Length);
					fputs(length, file);
					fputc('\n', file);
					fclose(file);
	}
}

void Square::Load()
{
	FILE* file = fopen("C:\\Users\\anaga\\Desktop\\Home Work Figure\\file.txt", "r");
	if (file != nullptr)
	{
		while (!feof(file))
		{
			if (fgetc(file) == 's')
			{
				char temp[3];
				fseek(file, 1, SEEK_CUR);
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
				m_Length = atoi(fgets(temp, 3, file));
				fclose(file);
				break;
			}
		}
	}
}