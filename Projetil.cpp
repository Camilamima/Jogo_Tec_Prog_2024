#include "Projetil.h"
#include <iostream>

Projetil::Projetil(int id, const char* png):
	Entidade(id, png)
{
    relogio.restart();
	//setCoordenadas(7100, 450);
    chao = 825.0;
    //setCorpo(64, 32);
    noChao = false;
    seguindo = false;
    //segue = 0;
    velocidadeX = 300;
    velocidadeY = 0;
	posX = 0;
    posY = 0;
    seguiu = false;
    //segue = false;
    apareceu = false;
    cont = 0;
    val = 0;
    apagado = false;
    corpo.setTexture(&sprite);
    corpo.setTextureRect(IntRect(567, 631, 827, 469));
}

Projetil::~Projetil()
{
}

void Projetil::executar()
{
    cont++;
    pGGrafico->desenha(corpo);

    if ((corpo.getPosition().y + corpo.getSize().y) >= chao) {
        noChao = true;
    }

    if (apareceu == true) {
        setCoordenadas(posX, posY);
        setSoCorpo(200, 113.42);
    }

}


void Projetil:: setVelocidade(float x, float y) {
    velocidadeX = x;
    velocidadeY = y;
}

bool Projetil::segueQuem(Personagens::Slime* jog) {//no gerenciador de colisoes

    RectangleShape aux = jog->getCorpo();

    float Projetil_x, Projetil_y, Jog_x, Jog_y;

    Projetil_x = corpo.getPosition().x + (corpo.getSize().x / 4);
    Projetil_y = corpo.getPosition().y + (corpo.getSize().y / 4);

    Jog_x = aux.getPosition().x + (aux.getSize().x / 2);
    Jog_y = aux.getPosition().y + (aux.getSize().y / 2);

    float dx = Jog_x - Projetil_x;
    float dy = Jog_y - Projetil_y;

    //hipotenusa
    float dist = std::sqrt(dx * dx + dy * dy);

    if (dist <= 650) {
        return true;
    }
   
    return false;
}

float Projetil::atualizaFPS()
{

    float deltaTimeAtual = relogio.restart().asSeconds();
    float minimoDeltaTime = 0.0667f;
    float maximoDeltaTime = 0.0167f;

    deltaTimeAtual = std::max(deltaTimeAtual, minimoDeltaTime);  // Limita para não ser menor que 15 FPS
    deltaTimeAtual = std::min(deltaTimeAtual, maximoDeltaTime);  // Limita para não ser maior que 60 FPS

    return deltaTimeAtual;
}

void Projetil::moverSeguindo(float aux) {
    if (!noChao)
    {
        if (cont % 5 == 0) {
            animacao(5);
            val++;
        }

        /*=== aplicando a gravidade */
        velocidadeY += (gravidade * atualizaFPS());//aplico a gravidade
        velocidadeY += (forcaMistica * atualizaFPS());//aplico a força mistica

        corpo.move(aux, velocidadeY*atualizaFPS());
    }
}

void Projetil::mover() {

    if (!noChao)//se nao ta no chao
    {
        /*=== se o projetil ainda nao seguiu o jogador ===*/
        if (seguiu == false) {//se ele nao seguiu
            setVelocidade(velocidadeX, 1);

            /*=== aplicando a gravidade */
            velocidadeY += (gravidade * atualizaFPS());//aplico a gravidade
            velocidadeY += (forcaMistica * atualizaFPS());//aplico a força mistica
            if(cont % 5 == 0) {
                animacao(5);
                val++;
            }
            corpo.move(-velocidadeX * atualizaFPS(), velocidadeY * atualizaFPS());
        }

        /*=== se o projetil ja seguiu o jogador ===*/
        if(seguiu == true) {
         
            if (cont % 5 == 0) {
                animacao(5);
                val++;
            }

            setVelocidade(velocidadeX, 250);

            /*=== aplicando a gravidade */
            velocidadeY += (gravidade * atualizaFPS());//aplico a gravidade
            velocidadeY += (forcaMistica * atualizaFPS());//aplico a força mistica

            corpo.move(-velocidadeX * atualizaFPS(), velocidadeY * atualizaFPS());
        }
        
	}

	else {
		setVelocidade(0, 0);
	}
}


void Projetil::seguir(float x_alvo, float y_alvo) {

    float xP = corpo.getPosition().x + (corpo.getSize().x / 2);
	float yP = corpo.getPosition().y + (corpo.getSize().y / 2);

    if (seguindo == true) {

        if (xP != x_alvo) {//se nao estao na mesma posicao

			if (xP > x_alvo && yP < y_alvo) {
                setVelocidade(velocidadeX, 250);

                /*=== aplicando a gravidade */
                velocidadeY += (gravidade * atualizaFPS());//aplico a gravidade
                velocidadeY += (forcaMistica * atualizaFPS());//aplico a força mistica


                moverSeguindo(atualizaFPS() * -velocidadeX);
                posX = corpo.getPosition().x;
                posY = corpo.getPosition().y;
			}

            else if (xP > x_alvo && yP >= y_alvo) {
                setVelocidade(velocidadeX, 1);

                /*=== aplicando a gravidade */
                velocidadeY += (gravidade * atualizaFPS());//aplico a gravidade
                velocidadeY += (forcaMistica * atualizaFPS());//aplico a força mistica

                moverSeguindo(atualizaFPS() * -velocidadeX);
                posX = corpo.getPosition().x;
                posY = corpo.getPosition().y;
            }

            else if (xP < x_alvo) {
	
                /*=== aplicando a gravidade */
                velocidadeY += (gravidade * atualizaFPS());//aplico a gravidade
                velocidadeY += (forcaMistica * atualizaFPS());//aplico a força mistica

				mover();
				posX = corpo.getPosition().x;
				posY = corpo.getPosition().y;
            }

			if (corpo.getPosition().y + corpo.getSize().y > chao) {
                setVelocidade(0, 0);
			}
        }

    }
}
    void Projetil::danifica(Personagens::Slime* jog) {
        if (relogioVida.getElapsedTime().asSeconds() >= 1.5) {
            jog->animacao(4, 1);
            jog->operator-=(10);
            std::cout << "Num vida do jog: " << jog->getVidas() << std::endl;
            relogioVida.restart();
        }
    }

    void Projetil::animacao(int limite) {
        if (val >= limite) {
            val = 0;
        }

        if (val == 0) {
            //sprite.loadFromFile("assets/proj/1.png");
            try {
                if (!sprite.loadFromFile("assets/proj/1.png")) {  // Se o arquivo não for encontrado
                    throw std::runtime_error("Erro ao carregar a textura: assets/proj/1.png");
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Excecao capturada: " << e.what() << std::endl;
            }
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(567, 631, 827, 469));
            //setSoCorpo(100, 56.71);
        }

        else if (val == 1) {
            //sprite.loadFromFile("assets/proj/2.png");
            try {
                if (!sprite.loadFromFile("assets/proj/2.png")) {  // Se o arquivo não for encontrado
                    throw std::runtime_error("Erro ao carregar a textura: assets/proj/2.png");
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Excecao capturada: " << e.what() << std::endl;
            }
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(567, 631, 827, 469));
        }

        else if (val == 2) {
            //sprite.loadFromFile("assets/proj/3.png");
            try {
                if (!sprite.loadFromFile("assets/proj/3.png")) {  // Se o arquivo não for encontrado
                    throw std::runtime_error("Erro ao carregar a textura: assets/proj/3.png");
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Excecao capturada: " << e.what() << std::endl;
            }
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(567, 631, 827, 469));
        }

        else if (val == 3) {
            //sprite.loadFromFile("assets/proj/4.png");
            try {
                if (!sprite.loadFromFile("assets/proj/4.png")) {  // Se o arquivo não for encontrado
                    throw std::runtime_error("Erro ao carregar a textura: assets/proj/4.png");
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Excecao capturada: " << e.what() << std::endl;
            }
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(567, 631, 827, 469));
        }

        else {
            //sprite.loadFromFile("assets/proj/5.png");
            try {
                if (!sprite.loadFromFile("assets/proj/5.png")) {  // Se o arquivo não for encontrado
                    throw std::runtime_error("Erro ao carregar a textura: assets/proj/5.png");
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Excecao capturada: " << e.what() << std::endl;
            }
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(567, 631, 827, 469));
        }
    }

    const float Projetil::gravidade = (9.8*1000);
    const float Projetil::forcaMistica = (-9.8*1000);

    json Projetil::salvar() const {
        json entidadeJson;
        entidadeJson["id"] = id;
        entidadeJson["x"] = corpo.getPosition().x;
        entidadeJson["y"] = corpo.getPosition().y;
        entidadeJson["velocidadeY"] = velocidadeY;
        entidadeJson["velocidadeX"] = velocidadeX;
        entidadeJson["noChao"] = noChao;
        entidadeJson["chao"] = chao;
        entidadeJson["seguindo"] = seguindo;
        entidadeJson["seguiu"] = seguiu;
        entidadeJson["cont"] = cont;
        entidadeJson["apagado"] = apagado;
		entidadeJson["val"] = val;
		entidadeJson["apareceu"] = apareceu;
		entidadeJson["posX"] = posX;
		entidadeJson["posY"] = posY;
		//entidadeJson["segue"] = segue;
        
        return entidadeJson;
    }


