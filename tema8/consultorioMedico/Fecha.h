#ifndef FECHA_H
#define FECHA_H
#pragma once

class Fecha
{
private:
	int dia, hora, minuto;

public:
	Fecha(int _dia, int _hora, int _minuto) : dia(_dia), hora(_hora), minuto(_minuto);
	~Fecha();

	void getDia() { return dia; }
	void getHora() { return hora; }
	void getMinuto() { return minuto; }

	bool operator<(Fecha& f2) const{

		if (dia < f2.dia) return true;
		if (dia > f2.dia) return false;
		if (hora < f2.hora) return true;
		if (hora > f2.hora) return false;
		return minuto < f2.minuto;
	}
};
#endif