#include <SFML/Graphics.hpp>
#include <iostream>

class Shape {

public:
     Shape(const sf::Color& color): m_color(color) {};
     virtual void draw(sf::RenderWindow& window) = 0;
     virtual sf::Color& getColor() {
     	return m_color;
     }
     virtual void setPosition(float x, float y) = 0;
 private:
     sf::Color m_color;
};

class Circle: public Shape {
 public:
    Circle(float radius, const sf::Color& color):
    Shape(color)
    , m_radius(radius) {
    	m_shape.setRadius(radius);
    	m_shape.setFillColor(color);
    }
    void draw(sf::RenderWindow& window) override {
    	window.draw(m_shape);
    }
    
    void setPosition(float x, float y) override {
    	m_shape.setPosition(x,y);
    }
    float radius() const {
    	return m_radius;
    }
     
 private:
    float m_radius;
    sf::CircleShape m_shape;
 };

class Square : public Shape {
public:
  Square(float side, const sf::Color& color) : 
  Shape(color)
  , m_side(side) {
    m_shape.setSize(sf::Vector2f(m_side, m_side));
    m_shape.setFillColor(color);
    m_shape.setOrigin(side / 2, side / 2); // Устанавливаем центр квадрата
  }

  void draw(sf::RenderWindow& window) override {
    window.draw(m_shape);
  }

  void setPosition(float x, float y) override {
    m_shape.setPosition(x,y);
  }
  float side() const {
     return m_side;
  }
private:
  float m_side;
  sf::RectangleShape m_shape;
};

class Triangle : public Shape {
public:
  Triangle(float base, float height, const sf::Color& color) : 
  Shape(color)
  , m_base(base)
  , m_height(height) {
    m_shape.setPointCount(3);
    m_shape.setPoint(0, sf::Vector2f(0, height));
    m_shape.setPoint(1, sf::Vector2f(base / 2, 0));
    m_shape.setPoint(2, sf::Vector2f(base, height));
    m_shape.setFillColor(color);
    m_shape.setOrigin(base / 2, height / 2); // Устанавливаем центр треугольника
  }

  void draw(sf::RenderWindow& window) override {
    window.draw(m_shape);
  }
  
  void setPosition(float x, float y) override {
    m_shape.setPosition(x,y);
  }
  
  float height() const {
     return m_height;
  }
  
  float base() const {
     return m_base;
  }		
private:
  float m_base;
  float m_height;
  sf::ConvexShape m_shape;
};

class Rectangle : public Shape {
public:
  Rectangle(float width, float height, const sf::Color& color) : 
  Shape(color)
  , m_width(width)
  , m_height(height) {
    m_shape.setSize(sf::Vector2f(width, height));
    m_shape.setFillColor(color);
    m_shape.setOrigin(width / 2, height / 2); // Устанавливаем центр прямоугольника
  }

  void draw(sf::RenderWindow& window) override {
    window.draw(m_shape);
  }
  void setPosition(float x, float y) override {
    m_shape.setPosition(x,y);
  }

  float width() const {
     return m_width;
  }
  float height() const {
     return m_height;
  }	
private:
  float m_width;
  float m_height;
  sf::RectangleShape m_shape;
};
int main() {
 // Создаем окно
  sf::RenderWindow window(sf::VideoMode(800, 600), "Геометрические фигуры");

  // Создаем объекты фигур
  Circle circle(25, sf::Color::Red);
  circle.setPosition(0, 25);
  
  Square square(50, sf::Color::Green);
  square.setPosition(100, 50);
  
  Triangle triangle(50, 50, sf::Color::Blue);
  triangle.setPosition(150,50);
  
  Rectangle rectangle(100, 50, sf::Color::Yellow);
  rectangle.setPosition(250,50);
  // Основной цикл приложения
  while (window.isOpen()) {
    // Обработка событий
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Очистка окна
    window.clear(sf::Color::White);

    // Рисование фигур
    circle.draw(window);
    square.draw(window);
    triangle.draw(window);
    rectangle.draw(window);
    
    // Отображение окна
    window.display();
  }

  return 0;
}
