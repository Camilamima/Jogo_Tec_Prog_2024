#pragma once
#include "Inimigo.h"
#include "../Projetil.h"
#include "../Listas/Lista.h"
#include "Efeitos.h"
#include <set>

namespace Personagens {
	class Yokai : public Inimigo
	{
	private:
		//Listas::Lista<Projetil*>* ListProj;//transformar em um set
		std::set<Projetil*> ListProj;
		//int danoProjetil; n usei
		bool turno;
		Clock relogio1;
		bool atirou;
		Clock relogioProjetil;
		static const int max_projetil;
		int num_projetil;
		int num_proj_salvamento;
		bool ativo;
		int iniZona;
		int finalZona;
		float pos_inicial;
		
	public:
		Yokai(int id, const char* png = "");
		~Yokai();
		void executar();
		void teletransportar();
		void criaProjeteis(Projetil* proj);
		void criaProjeteisSalv(Projetil* proj);
		void apagaProjetil();
		void setTurno(bool turno1) { turno = turno1; }
		static int getMaxProjetil() { return max_projetil; }
		int getNum_Projetil()const { return num_projetil; }
		void setNum_Projetil(int a) { num_projetil = a; }
		int getNum_Proj_Salv() { return num_proj_salvamento; }
		void operator++();
		bool zonaYokai(Heroi* jog);
		void zonaYokai();
		void setAtivo(bool x) { ativo = x; }
		bool getAtivo() { return ativo; }
		void setPosInicialX(float x) { pos_inicial = x; }
		float getPosInicial() { return pos_inicial; }
		int getFinalZona() { return finalZona; }
		void setFinalZona(int fim) { finalZona = fim; }
		int getIniZona() { return iniZona; }
		void setIniZona(int inicio) { iniZona = inicio; }
		json salvar()const;
		void animacao(int num, int limite);
	};
}