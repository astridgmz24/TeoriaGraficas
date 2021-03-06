#include "Grafica.hpp"
#include "Funciones.hpp"

Grafica::Grafica(){
}

Grafica::Grafica(std::vector<std::string> n,std::vector<std::string> e,std::vector<std::string> s)
	:nodos{n}, entradas{e}, salidas{s} {
}

std::vector<std::string> Grafica::get_nodos(){
	return nodos;
}

void Grafica::set_nodos(std::vector<std::string> nodos){
	this->nodos = nodos;
}

std::vector<std::string> Grafica::get_entradas(){
	return entradas;
}

void Grafica::set_entradas(std::vector<std::string> entradas){
	this->entradas = entradas;
}

std::vector<std::string> Grafica::get_salidas(){
	return salidas;
}

void Grafica::set_salidas(std::vector<std::string> salidas){
	this->salidas = salidas;
}

size_t Grafica::str_nodo_mas_grande(){
	size_t tamanio {};
	
	for(size_t i{};i < nodos.size();i++)
		if(nodos[i].size() > tamanio)
			tamanio = nodos[i].size();

	return tamanio;
}

std::string Grafica::imprimir_linea(size_t e, size_t tamanio){
	std::string linea {"+"};

	for(size_t i{};i < e;i++){
		for(size_t j {};j < tamanio;j++)
			linea += "-";
		linea += "+";
	}

	return linea + "\n";
}

std::string Grafica::accesibilidad(){
	Matriz m_aux {ad};
	Matriz acumulada {ad};

	for(size_t i{1};i < nodos.size();i++){
		m_aux = Matriz {m_aux.matriz_x_matriz(ad.matriz),true};
		acumulada = Matriz {acumulada.matriz_s_matriz(m_aux.matriz),true};
	}
	ac = acumulada;

	return ac.imprimir_tabla_matriz();
}

std::string Grafica::conectada_desconectada(){
	for(size_t i{};i < ac.matriz.size();i++){
		for(size_t j{};j < ac.matriz[i].size();j++){
			if(ac.matriz[i][j] == 0){
				c = false;
				return "Es una grafica desconectada\n";
			}
		}
	}
	c = true;
	return "Es una grafica conectada\n";
}

std::string Grafica::completa(){
	if(s_g == 'g')
		return "No es es completa\n";
	for(size_t i{};i < ad.matriz.size();i++){
		for(size_t j{};j < ad.matriz[i].size();j++){
			if(i == j)
				;
			else if(ad.matriz[i][j] != 1)
				return "No es es completa\n";
		}
	}

	return "Es completa\n";
}
