#include <SFML/Graphics.hpp>

class Jugador
{
public:
    Jugador() : personaje(sf::Vector2f(50.0f, 50.0f))
    {
        personaje.setFillColor(sf::Color::Red);
        personaje.setPosition(400.0f, 300.0f);
    }

    void mover(sf::Vector2f direccion)
    {
        personaje.move(direccion);
    }

    void dibujar(sf::RenderWindow &ventana)
    {
        ventana.draw(personaje);
    }

private:
    sf::RectangleShape personaje;
};

class Juego
{
public:
    Juego() : ventana(sf::VideoMode(800, 600), "Metroid")
    {
        // Inicializar el juego
        jugador = Jugador();
    }

    void ejecutar()
    {
        while (ventana.isOpen())
        {
            procesarEventos();
            actualizar();
            renderizar();
        }
    }

private:
    sf::RenderWindow ventana;
    Jugador jugador;

    void procesarEventos()
    {
        sf::Event evento;
        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                ventana.close();
            }
        }
    }

    void actualizar()
    {
        // Actualizar el estado del juego
        sf::Vector2f direccion(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direccion.y -= 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direccion.y += 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direccion.x -= 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direccion.x += 1.0f;
        }

        jugador.mover(direccion);
    }

    void renderizar()
    {
        ventana.clear();
        // Dibujar elementos del juego
        jugador.dibujar(ventana);
        ventana.display();
    }
};

class Personaje
{
public:
    Personaje(sf::Vector2f size, sf::Texture &texture) : sprite(texture), currentFrame(0), frameCount(0), animationSpeed(0.2f)
    {
        sprite.setTexture(texture);
    }

    void update(float deltaTime)
    {
        frameCount += deltaTime;
        if (frameCount >= animationSpeed)
        {
            frameCount = 0;
            currentFrame++;
            if (currentFrame >= frames.size())
            {
                currentFrame = 0;
            }
        }
    }

    void draw(sf::RenderWindow &window)
    {
        sprite.setTextureRect(frames[currentFrame]);
        window.draw(sprite);
    }

    void addFrame(sf::IntRect frame)
    {
        frames.push_back(frame);
    }

private:
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;
    int currentFrame;
    float frameCount;
    float animationSpeed;
};

class Enemigo : public Personaje
{
public:
    Enemigo(sf::Vector2f size, sf::Texture &texture) : Personaje(size, texture)
    {
        // Constructor de la clase Enemigo
    }

    // Métodos adicionales de la clase Enemigo

private:
    // Atributos adicionales de la clase Enemigo
};

class Samus : public Personaje
{
public:
    Samus(sf::Vector2f size, sf::Texture &texture) : Personaje(size, texture)
    {
        // Constructor de la clase Samus
    }

    // Métodos adicionales de la clase Samus

private:
    // Atributos adicionales de la clase Samus
};

int main()
{
    Juego juego;
    juego.ejecutar();

    return 0;
}
