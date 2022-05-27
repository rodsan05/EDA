#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include "Fecha.h"

using namespace std;

using Paciente = string;
using Medico = string;

class consultorio
{
private:
	using Citas = unordered_map<Fecha, Paciente>;

	unordered_map<Medico, Citas> medicos;

public:
	consultorio(){};
	~consultorio();

	void nuevoMedico(Medico m)
	{
		Citas citas;
		medicos.insert({m, citas});
	};

	void pideConsulta(Paciente p, Medico m, Fecha f)
	{
		unordered_map<Medico, Citas>::iterator it = medicos.find(m);
			
		if (it == medicos.end()) throw "Medico no existente";

		if (it->second.count(f)) throw "Fecha ocupada";

		it->second.insert({f, p});
	};
};