#include "Menu.h"
#include "Fases/Fase.h"
#include <fstream> 

Menu::Menu(int id,const char* png):
    Ente(id,png),
    Texto()
{
    pfase = nullptr;
    continuar = 0;
    menu = 1;
    fase = -1;
    selec = 0;
	fonte.loadFromFile(FONTES);
	setaTextos(1);
    seta.setSize(Vector2f(40.0f, 40.0f));
    seta.setTexture(&sprite);
    seta.setPosition(60.0f, 300.0f);
    timer.restart();
}

Menu::~Menu() {
	
}

void Menu::setFase(Fases::Fase* f) {
    pfase = f;
    pfase->setMenu(this);
    menu = 4;
}

void Menu::comandos() {

    int i = (int)nomes.size()-1;
    
    if (timer.getElapsedTime().asSeconds() > 0.15) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
            selec++;  
            if (selec > i) {
                selec = 0; 
            }
        }

        // Verifica se a seta para cima foi pressionada
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {  
            selec--;  
            if (selec < 0) {
                selec = i;  
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        
            if (menu == 1) {
                if (selec == i) {
                    setaTextos(2);
                    selec = 0;
                    menu =2;
                }
                else if (selec == 0) {
                    fase = 1;
                    setaTextos(3);
                    selec = 0;
                    menu = 3;
                }
                else if (selec == 2) {
                    setaTextos(5);
                    menu = 7;
                    continuar = 0;
                }
                else {
                    continuar = 1;
                }
            }
            else if (menu == 2) {
                if (selec == 0) {
                    setaTextos(3);
                    fase = 1;
                    selec = 0;
                    menu = 3;
                    continuar = 0;
                }
                else if(selec==1){
                    fase = 2;
                    setaTextos(3);
                    selec = 0;
                    menu = 3;
                    continuar = 0;
                }
            }
            else if (menu == 3) {
                continuar = 1;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            if (menu !=4) {
                menu = 1;
                setaTextos(1);
            }
        }

        seta.setPosition(60.0f, 300.0f + ((float)selec * 60.0f));
        timer.restart();
    }
}

void Menu::salvaScore(const string& nome, int pontos) {
    string filename = "Save/leader_board.json";
    json data;
    ifstream file(filename);
    if (file.is_open()) {
        file >> data;
        file.close();

        vector<json> leaderboard = data["leaderboard"].get<vector<json>>();

        vector<json> novoLeaderboard;
        string auxN = nome;
        int auxP = pontos;
        string Nome = "";
        int Pontos = 0;
        int ranking = 0;

        for (auto& jogador : leaderboard) {
            Nome = jogador["nome"].get<string>();
            Pontos = jogador["pontos"].get<int>();

            if (auxP >= Pontos) {
                jogador["nome"] = auxN;
                jogador["pontos"] = auxP;
                auxN = Nome;
                auxP = Pontos;
            }
            json novoJogador;
            novoJogador["nome"] = jogador["nome"];
            novoJogador["pontos"] = jogador["pontos"];
            novoJogador["ranking"] = jogador["ranking"];
            novoLeaderboard.push_back(novoJogador);

        }

        data["leaderboard"] = novoLeaderboard;


    }
    else {
        data["leaderboard"] = json::array();

        json jogador;
        jogador["nome"] = nome;
        jogador["pontos"] = pontos;
        jogador["ranking"] = 1;

        data["leaderboard"].push_back(jogador);

        for (int i = 2; i <= 5; i++) {
            jogador["nome"] = "----";
            jogador["pontos"] = 0;
            jogador["ranking"] = i;
            data["leaderboard"].push_back(jogador);
        }
    }

    ofstream o(filename);
    o << std::setw(4) << data << std::endl;
}

void Menu::setaTextos(int text) {
    limpaTextos();

    if (text == 1) {
        nomes.push_back("Novo Jogo");
        nomes.push_back("Recuperar Jogo");
        nomes.push_back("LeaderBoard");
        nomes.push_back("Selecionar Fase");

        textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

        for (int i = 0; i < nomes.size(); i++) {
            textos[i].setFont(fonte);
            textos[i].setString(nomes[i]);
            textos[i].setCharacterSize(50);
            textos[i].setFillColor(sf::Color::White);
            textos[i].setPosition(100, 300 + i * 60);
        }
    }
    else if (text == 2) {
        nomes.push_back("Floresta");
        nomes.push_back("Caverna");

        textos.resize(nomes.size());

        for (int i = 0; i < nomes.size(); i++) {
            textos[i].setFont(fonte);
            textos[i].setString(nomes[i]);
            textos[i].setCharacterSize(50);
            textos[i].setFillColor(sf::Color::White);
            textos[i].setPosition(100.0f, 300.0f + (float)i * 60.0f);
        }
    }
    else if (text == 3) {
        nomes.push_back("1 Jogador");
        nomes.push_back("2 Jogadores");

        textos.resize(nomes.size());

        for (int i = 0; i < nomes.size(); i++) {
            textos[i].setFont(fonte);
            textos[i].setString(nomes[i]);
            textos[i].setCharacterSize(50);
            textos[i].setFillColor(sf::Color::White);
            textos[i].setPosition(100.0f, 300.0f + (float)i * 60.0f);
        }
    }
    else if (text == 4) {
        nomes.push_back("Salvar");
        nomes.push_back("Sair do jogo");
        nomes.push_back("Voltar ao jogo");

        textos.resize(nomes.size());

        for (int i = 0; i < nomes.size(); i++) {
            textos[i].setFont(fonte);
            textos[i].setString(nomes[i]);
            textos[i].setCharacterSize(50);
            textos[i].setFillColor(sf::Color::White);
            textos[i].setPosition(100.0f, 300.0f + (float)i * 60.0f);
        }
    }
    else if (text == 5) {
        vector<string> tempNomes = lerScore();
        nomes.clear();

        for (const auto& nome : tempNomes) {
            std::cout << "Nome carregado: " << nome << std::endl;
            nomes.push_back(sf::String(nome));
        }

        textos.resize(nomes.size());

        for (int i = 0; i < nomes.size(); i++) {
            textos[i].setFont(fonte);
            textos[i].setString(nomes[i]);
            textos[i].setCharacterSize(50);
            textos[i].setFillColor(sf::Color::White);
            textos[i].setPosition(100.0f, 300.0f + (float)i * 60.0f);
        }
    }
}

const vector<string> Menu::lerScore() {
    vector<string> aux;
    string filename = "Save/leader_board.json";
    ifstream file(filename);

    if (file.is_open()) {
        json data;
        file >> data;
        file.close();

        for (const auto& jogador : data["leaderboard"]) {
            int ranking = jogador["ranking"].get<int>();
            string nome = jogador["nome"].get<string>();
            int pontos = jogador["pontos"].get<int>();

            aux.push_back(to_string(ranking) + ". " + nome + " : " + to_string(pontos));
        }
    }
    else {
        aux.push_back("Nenhum jogador no ranking");
    }

    return aux;
}

void Menu::Pause() {
    int i = (int)nomes.size() - 1;
    int zona = (float)pfase->getZona();

    seta.setPosition(60.0f + (zona * 1800), 300.0f + ((float)selec * 60.0f));

    for (int i = 0; i < textos.size(); i++) {
        textos[i].setPosition(100.0f+(zona*1800), 300.0f + (float)i * 60.0f);
        pGGrafico->window.draw(textos[i]);
    }

    pGGrafico->desenha(seta);
    pGGrafico->window.display();

    if (timer.getElapsedTime().asSeconds() > 0.5) {

            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            selec++;
            if (selec > i) {
                selec = 0;
            }
            seta.setPosition(60.0f + (zona * 1800), 300.0f + ((float)selec * 60.0f));
            timer.restart();
        }

        // Verifica se a seta para cima foi pressionada
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            selec--;
            if (selec < 0) {
                selec = i;
            }
            seta.setPosition(60.0f + (zona * 1800), 300.0f + ((float)selec * 60.0f));
            timer.restart();
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (selec == 0) {
                pfase->salvaFase();
            }
            else if(selec ==1){
                pGGrafico->window.close();
            }
            else {
                pfase->setPause(false);
            }
        }


    }
}



void Menu::executar() {

    desenhaTexto(pGGrafico);

    if (menu != 7){
        pGGrafico->desenha(seta);
    }
    pGGrafico->window.display();
    pGGrafico->clear();
    comandos();
    if (continuar == 1) {
        setaTextos(4);

    }

}

